#include "RequestParamADCSTask.hpp"

void RequestParamADCSTask::execute() {

    while (true) {

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            11,
            12,
            13,
            1000,
            1001,
            1002,
            1003,
            1004,
            1005,
            1006}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1007,
            1008,
            1009,
            1010,
            1011,
            1012,
            1013,
            1014,
            1015,
            1016}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1017,
            1018,
            1019,
            1020,
            1021,
            1022,
            1023,
            1024,
            1025,
            1026}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1027,
            1028,
            1029,
            1030,
            1031,
            1032,
            1033,
            1034,
            1035,
            1036}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1037,
            1038,
            1039,
            1040,
            1041,
            1042,
            1043,
            1044,
            1045,
            1046}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1048,
            1050,
            1052,
            1052,
            1054,
            1056}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1058,
            1060,
            1062,
            1064,
            1066}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1068,
            1070,
            1071,
            1072,
            1073,
            1074,
            1075,
            1076}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1077,
            1078,
            1079,
            1080,
            1081,
            1082,
            1083,
            1084,
            1085,
            1086}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1087,
            1088,
            1089,
            1090,
            1091,
            1092,
            1093,
            1094,
            1095,
            1096}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1097,
            1098,
            1099,
            1100,
            1101,
            1102,
            1103,
            1104,
            1105,
            1106}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1107,
            1108,
            1109,
            1110,
            1111,
            1112,
            1113,
            1114,
            1115,
            1116}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1117,
            1118,
            1119,
            1120,
            1121,
            1122,
            1123,
            1124,
            1125,
            1126}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1127,
            1128,
            1129,
            1130,
            1131,
            1132,
            1133,
            1134,
            1135,
            1136}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1137,
            1138,
            1139,
            1140,
            1141,
            1142,
            1143,
            1144,
            1145,
            1146}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1147,
            1148,
            1149,
            1150,
            1151,
            1152,
            1153,
            1154,
            1155,
            1156}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1157,
            1158,
            1159,
            1160,
            1161,
            1162,
            1163,
            1164,
            1165,
            1166}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1167,
            1168,
            1169,
            1170,
            1171,
            1172,
            1173,
            1174 ,
            1175,
            1176}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1177,
            1178,
            1179,
            1180,
            1181,
            1182,
            1183,
            1184,
            1185,
            1186}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1187,
            1188,
            1189,
            1190,
            1191,
            1192,
            1193,
            1194,
            1195,
            1196}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1197,
            1198,
            1999,
            1200,
            1201,
            1202,
            1203,
            1204,
            1205,
            1206}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{1207,
            1208,
            1209,
            1210,
            1211,
            1212,
            1213,
            1214,
            1215,
            1216}, false);
        vTaskDelay(pdMS_TO_TICKS(20));

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
            1217,
            1218,
            1219,
            1220,
            1221,
            1222,
            1223,
            1224,
            1225,
            1226}, false);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{
        1227,
        1228}, false);

        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}