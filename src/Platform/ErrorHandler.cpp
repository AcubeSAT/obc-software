#include <ErrorHandler.hpp>
#include <Message.hpp>
#include <Logger.hpp>

template void ErrorHandler::logError(const Message &, ErrorHandler::AcceptanceErrorType);

template void ErrorHandler::logError(const Message &, ErrorHandler::ExecutionStartErrorType);

template void ErrorHandler::logError(const Message &, ErrorHandler::ExecutionProgressErrorType);

template void ErrorHandler::logError(const Message &, ErrorHandler::ExecutionCompletionErrorType);

template void ErrorHandler::logError(const Message &, ErrorHandler::RoutingErrorType);

template void ErrorHandler::logError(ErrorHandler::InternalErrorType);

template<typename ErrorType>
void ErrorHandler::logError(const Message &message, ErrorType errorType) {
    LOG_ERROR << "Error " << static_cast<int>(errorType) << " on " << "[" << message.serviceType << "," << message.messageType
              << "]";
}

template<typename ErrorType>
void ErrorHandler::logError(ErrorType errorType) {
    LOG_ERROR << "Error " <<  static_cast<int>(errorType);
}
