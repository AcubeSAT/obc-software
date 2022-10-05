#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"
#include "Helpers/TimeGetter.hpp"
#include "CommonParameters.hpp"

namespace CANApplicationLayer {
    static CANMessage message = {};

    void sendPingMessage() {
        outgoingMessages.push({PingMessageID});
    }

    void sendPongMessage() {
        outgoingMessages.push({PongMessageID});
    }

    void sendHeartbeatMessage() {
        uint16_t id = getHeartbeatID(CAN::NodeID);
        outgoingMessages.push({id});
    }

    void sendBusSwitchoverMessage() {
        uint16_t id = getBusSwitchoverID(CAN::NodeID);
        etl::vector<uint8_t, CANMessage::MaxDataLength> data = {getBusToSwitchover()};

        outgoingMessages.push({id, data});
    }

    void sendUTCTimeMessage() {
        auto now = TimeGetter::getCurrentTimeDefaultCUC();

        std::chrono::duration<uint64_t, std::milli> msOfDay = now.asDuration(); //@todo This doesn't reset every day, only since epoch.

        uint16_t id = getTimeID(CAN::NodeID);

        UTCTimestamp utc = now.toUTCtimestamp();
        etl::vector<uint8_t, CANMessage::MaxDataLength> data = {0, 0, static_cast<uint8_t>(msOfDay.count()),
                                                                static_cast<uint8_t>(msOfDay.count() >> 8),
                                                                static_cast<uint8_t>(msOfDay.count() >> 16),
                                                                static_cast<uint8_t>(msOfDay.count() >> 24), 0,
                                                                utc.day}; //@todo days parameter should not be uint8_t

        outgoingMessages.push({id, data});
    }
}
