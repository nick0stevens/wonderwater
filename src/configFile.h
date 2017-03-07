//---------------------LIBRARIES

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <ArduinoJson.h>

//---------------------WIFI DETAILS

const char* host = "wonderWater"; // name for mDNS
const char* ssid = "thebakery.no";
const char* password = "morethanjustbread";
//const char* ssid = "Zhone169537";
//const char* password = "Conrad1sgat3";


//---------------------PIN NUMBERS FOR SENSOR AND VALVE

#define sensor A0
#define valuePowerPin D2
#define valueDirectionPin D4
int sensorValue ;
int seconds;


//---------------------MISC
#define DBG_OUTPUT_PORT Serial


int period = 245; // period of each watering
int interval = 20; // period between waterings
int sInterval = 30; // period between checking moisture
int threshold = 30; // threshold below which watering commences


ESP8266WebServer server(80);

File fsUploadFile;
