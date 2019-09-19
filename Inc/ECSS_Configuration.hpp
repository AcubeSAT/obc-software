#ifndef OBC_SOFTWARE_ECSS_CONFIGURATION_H
#define OBC_SOFTWARE_ECSS_CONFIGURATION_H

/**
 * @file
 * The configuration file for this ECSS Services platform.
 *
 * @see GlobalLogLevels Define the minimum level for logged messages
 * @see ServiceDefinitions Define the service types that will be compiled
 */

// Log all levels of messages
#define LOGLEVEL_TRACE

// Do not compile any services
#undef SERVICES_ALL

#endif //OBC_SOFTWARE_ECSS_CONFIGURATION_H
