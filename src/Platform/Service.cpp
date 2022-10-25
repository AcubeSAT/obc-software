#include <etl/String.hpp>
#include <Logger.hpp>
#include "OBC_Definitions.hpp"
#include "Service.hpp"
#include "MessageParser.hpp"

void Service::storeMessage(Message &message) {
    // appends the remaining bits to complete a byte
    message.finalize();

    etl::format_spec formatSpec;
    auto serviceType = String<MaxTypeIDStringSize>("");
    auto messageType = String<MaxTypeIDStringSize>("");

    etl::to_string(message.serviceType, serviceType, formatSpec, false);
    etl::to_string(message.messageType, messageType, formatSpec, false);

    auto output = etl::string<ECSSMaxMessageSize>("New ");
    (message.packetType == Message::TM) ? output.append("TM[") : output.append("TC[");
    output.append(serviceType);
    output.append(",");
    output.append(messageType);
    output.append("] message! ");

//    auto data = String<CCSDSMaxMessageSize>("");
    etl::string<ECSSMaxMessageSize> data;
    String<CCSDSMaxMessageSize> createdPacket = MessageParser::compose(message);
    for (unsigned int i = 0; i < createdPacket.size(); i++) {
//        etl::to_string(createdPacket[i], data, formatSpec, true);
        output.push_back(createdPacket[i]);
        output.push_back(' ');
    }

    output.append(data.c_str());

    LOG_DEBUG << output.c_str();
}
