#ifndef OBC_SOFTWARE_CANAPPLICATIONLAYER_H
#define OBC_SOFTWARE_CANAPPLICATIONLAYER_H

#include "CAN/Message.hpp"
#include "CANTPMessage.hpp"
#include "etl/queue.h"

namespace CANApplicationLayer {
    /**
     * A queue that holds messages that are waiting to be sent via the CAN Bus.
     */
    inline etl::queue<CAN::Message, CAN::MessageQueueSize> outgoingMessages;

    /**
     * A queue that holds messages that have been received via the CAN Bus, and are awaiting parsing.
     */
    inline etl::queue<CAN::Message, CAN::MessageQueueSize> incomingMessages;

    /**
     * Parses an incoming message and calls the appropriate functions for it's handling.
     * @param message A CAN::Message object with an ID and a Data field.
     */
    void parseMessage(CAN::Message message);

    /**
     * Splits a CAN-TP Message into a collection of CAN Messages and adds them to the outgoing queue.
     * @param id The ID that will be used for the messages.
     * @param messagePayload A vector containing the data part of the CAN-TP Message.
     */
    void finalizeMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);
}

#endif //OBC_SOFTWARE_CANAPPLICATIONLAYER_H
