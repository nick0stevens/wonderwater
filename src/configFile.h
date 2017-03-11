//---------------------LIBRARIES

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <ArduinoJson.h>

//---------------------WIFI DETAILS

const char* host = "wonderWater"; // name for mDNS
//const char* ssid = "thebakery.no";
//const char* password = "morethanjustbread";
const char* ssid = "Zhone169537";
const char* password = "Conrad1sgat3";


//---------------------PIN NUMBERS FOR SENSOR AND VALVE

#define sensor A0
#define sensorPower D6
#define valuePowerPin D2
#define valueDirectionPin D4
int sensorValue ;
int seconds;


//---------------------MISC

bool debug = true;
#define DBG_OUTPUT_PORT Serial


int period; // period of each watering in seconds
int interval; // period between waterings in minutes
int sInterval; // period between checking moisture // not needed??
int threshold; // threshold below which watering commences from 0-100. 100 is very wet
bool operating; // if conmplete unit is operational
bool irrigating; // if unit is currently irrigating
bool needWater; //
long currentTime; // holds currentTime in miilis
long lastSensorCheck; // holds time of last sensor check
long valveOnTime; // holds time of last sensor check


ESP8266WebServer server(80);

File fsUploadFile;
