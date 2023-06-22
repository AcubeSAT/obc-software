from os.path import join

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy
from conan.tools.scm import Git


class OBCSoftwareRecipe(ConanFile):
    name = "obc-sw"
    version = "1.0"
    revision_mode = "scm"

    # Optional metadata
    license = "MIT"
    author = "SpaceDot - AcubeSAT, acubesat.obc@spacedot.gr"
    url = "gitlab.com/acubesat/obc/ecss-services"
    description = "ECSS Services implementation for the AcubeSAT nanosatellite"
    topics = ("satellite", "acubesat", "obc", "obc-software")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": False}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "inc/*", "lib/*"
    generators = "CMakeDeps"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def source(self):
        git = Git(self)
        git.clone(url="git@gitlab.com:acubesat/obc/cross-platform-software.git", target=join(str(self.source_folder), "lib/cross-platform-software"))
        self.run("cd lib/cross-platform-software && git submodule update --init --recursive")
        git = Git(self)
        git.clone(url="git@gitlab.com:acubesat/obc/atsam-component-drivers.git", target=join(str(self.source_folder), "lib/atsam-component-drivers"))

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
        self.requires("etl/20.32.1")
        self.requires("logger/1.0:f91b723d0b55712e7d6f0118e5cb59f81adbe135:385b15d0b0bb5f862216059a3f10fb1d0bd1a13f")
        self.requires("ecss-services/1.0")