import os
from os.path import join

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy
from conan.tools.scm import Git
from conan.tools.files import get, chdir, mkdir

class OBCSoftwareRecipe(ConanFile):
    name = "obc-sw"
    version = "1.0"
    revision_mode = "scm"

    # Optional metadata
    license = "MIT"
    author = "SpaceDot - AcubeSAT, acubesat.obc@spacedot.gr"
    url = "gitlab.com/acubesat/obc/obc-software"
    description = "Software for the OBC subsystem of the AcubeSAT nanosatellite."
    topics = ("satellite", "acubesat", "obc", "obc-software", "embedded")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": False, "ecss-services/*:ecss_config_file_path": os.path.abspath("inc/Platform/")}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "inc/*", "lib/*"
    generators = "CMakeDeps"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def source(self):
        repos = [
            {"url": "git@gitlab.com:acubesat/obc/cross-platform-software.git", "path": "lib/cross-platform-software"},
            {"url": "git@gitlab.com:acubesat/obc/atsam-component-drivers.git", "path": "lib/atsam-component-drivers"}
        ]

        for repo in repos:
            repo_path = os.path.join(self.source_folder, repo["path"])
            mkdir(self, repo_path)
            git = Git(self, repo_path)
            if not os.listdir(repo_path):
                git.clone(repo["url"])
            else:
                git.checkout()
            with chdir(self, repo_path):
                git.run("submodule update --init --recursive")
    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["NO_SYSTEM_INCLUDE"] = True
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("etl/20.37.2")
        self.requires("logger/1.0")
        self.requires("ecss-services/1.1")