#ifndef OBC_SOFTWARE_DUMMYECSS_H
#define OBC_SOFTWARE_DUMMYECSS_H

#include "lib/ecss-services/inc/Service.hpp"
/**
 * This is a dummy Service used during testing. Its functionality is to contain LOG_ data but be sent through CAN bus.
 * During the environmental tests, we will use both CAN and UART to send data from the MCU to the PC. However, the
 * current CAN protocol does not accomodate random data strings. Therefore, we will use this dummy service to send such
 * messages.
 */
class DummyECSS : public Service {
private:
    String<LoggerMaxMessageSize> data;
    Message message;
public:
    inline static const uint8_t ServiceType = 255;
    enum MessageType : uint8_t {
        DataString = 1,
    };

    /**
     * Sets the current dat
     * @param logData
     */
    inline void setData(String<LoggerMaxMessageSize> logData) {
        data = logData;
    }

    inline void appendData(String<LoggerMaxMessageSize> logData) {
        data.append(logData);
    }

    inline void clearData() {
        data.clear();
    }

    inline String<LoggerMaxMessageSize> getData() {
        return data;
    }
};


#endif //OBC_SOFTWARE_DUMMYECSS_H
