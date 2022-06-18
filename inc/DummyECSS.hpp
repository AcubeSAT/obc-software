#ifndef OBC_SOFTWARE_DUMMYECSS_H
#define OBC_SOFTWARE_DUMMYECSS_H

#include "Service.hpp"
#include "Logger_Definitions.hpp"

/**
 * This is a dummy Service used during testing. Its functionality is to contain LOG_ data but be sent through CAN bus.
 * During the environmental tests, we will use both CAN and UART to send data from the MCU to the PC. However, the
 * current CAN protocol does not accommodate random data strings. Therefore, we will use this dummy service to send such
 * messages.
 *
 * Per the ECSS-E-ST-70-41C standard, p. 27-28, custom Services and Messages should start above 127.
 */
class DummyECSS : public Service {

public:
    inline static const uint8_t ServiceType = 128;
    enum MessageType : uint8_t {
        DataString = 128,
    };

    /**
     * Send data as a part of a custom ECSS Message
     * Creates a TM[128, 128]
     */
    inline void logAsECSSMessage(etl::string<LOGGER_MAX_MESSAGE_SIZE> data) {
        Message log(ServiceType, MessageType::DataString, Message::TM, 1);
        log.appendString(data);
        storeMessage(log);
    }
};

#endif //OBC_SOFTWARE_DUMMYECSS_H
