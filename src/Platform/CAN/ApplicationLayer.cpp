#include "CAN/ApplicationLayer.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN::Application {
    void sendPingMessage() {
        canGatekeeperTask->addToQueue({MessageIDs::Ping + CAN::NodeID});
    }

    void sendPongMessage() {
        canGatekeeperTask->addToQueue({MessageIDs::Pong + CAN::NodeID});
    }

    void sendHeartbeatMessage() {
        canGatekeeperTask->addToQueue({MessageIDs::Heartbeat + CAN::NodeID});
    }

    void sendBusSwitchoverMessage() {
        etl::vector<uint8_t, CAN::Packet::MaxDataLength> data = {toggleBusSwitchover()};

        canGatekeeperTask->addToQueue({MessageIDs::BusSwitchover + CAN::NodeID, data});
    }

    void sendUTCTimeMessage() {
        auto now = TimeGetter::getCurrentTimeDefaultCUC();

        std::chrono::duration<uint64_t, std::milli> msOfDay = now.asDuration(); //@todo This doesn't reset every day, only since epoch.

        UTCTimestamp utc = now.toUTCtimestamp();
        etl::vector<uint8_t, CAN::Packet::MaxDataLength> data = {0, 0, static_cast<uint8_t>(msOfDay.count()),
                                                                 static_cast<uint8_t>(msOfDay.count() >> 8),
                                                                 static_cast<uint8_t>(msOfDay.count() >> 16),
                                                                 static_cast<uint8_t>(msOfDay.count() >> 24), 0,
                                                                 utc.day}; //@todo days parameter should not be uint8_t

        canGatekeeperTask->addToQueue({MessageIDs::UTCTime + CAN::NodeID, data});
    }
}
