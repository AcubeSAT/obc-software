#include "definitions.h"
#include <iostream>

#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#include "catch2/catch.hpp"

extern "C" {

void main_cpp() {
    std::cout << "DIAGNOSTICS:" << std::endl;
    std::cout << "  CPU clock: " << CPU_CLOCK_FREQUENCY / 1e6 << " MHz" << std::endl;
    std::cout << std::endl;

    std::cout << "[" << SYSTICK_TimerCounterGet() << "] Initializing tests..." << std::endl;

    static Catch::Session session; // There must be exactly one instance

    // This is the equivalent of passing command-line argument
    auto configData = Catch::ConfigData();
    configData.showDurations = Catch::ShowDurations::Always;
    configData.useColour = Catch::UseColour::Yes;
    session.useConfigData(configData);

    std::cout << "[" << SYSTICK_TimerCounterGet() << "] Running tests..." << std::endl;

    int numFailed = session.run();
    if (numFailed == 0) {
        std::cerr << "Success" << std::endl;
    } else {
        std::cerr << "Failed" << std::endl;
    }

    std::cerr << "@RETURN " << +numFailed << std::endl;
}

}
