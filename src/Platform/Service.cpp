#include <etl/String.hpp>
#include <Logger.hpp>
#include "OBC_Definitions.hpp"
#include "Service.hpp"

void Service::storeMessage(Message &message) {
    // appends the remaining bits to complete a byte
    message.finalize();

    etl::format_spec formatSpec;
    auto serviceType = String<MaxTypeIDStringSize>("");
    auto messageType = String<MaxTypeIDStringSize>("");

    etl::to_string(message.serviceType, serviceType, formatSpec, false);
    etl::to_string(message.messageType, messageType, formatSpec, false);

    auto output = String<ECSSMaxMessageSize>("New ");
    (message.packetType == Message::TM) ? output.append("TM[") : output.append("TC[");
    output.append(serviceType);
    output.append(",");
    output.append(messageType);
    output.append("] message! ");

    auto data = String<ECSSMaxStringSize>("");
    for (unsigned int i = 0; i < message.dataSize; i++) {
        etl::to_string(static_cast<int>(message.data[i]), data, formatSpec, true);
        data.append(" ");
    }
    output.append(data.c_str());

    LOG_DEBUG << output.c_str();
}
