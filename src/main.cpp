#include "inc/main.h"
#include "Services/EventReportService.hpp"

extern "C" void main_cpp(){
    EventReportService *ers = new EventReportService();
    ers->getStateOfEvents();
}
