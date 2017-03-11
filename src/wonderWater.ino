

#include "configFile.h"


void setup(void){



initSerial();
initSpiffs();
//saveConfig();
initVariables();
initSensor();
initValve();
initWifi();
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);
checkSensor();

}

void loop(void){
  //digitalWrite(sensorPower,HIGH);

currentTime = millis();
server.handleClient();


if(operating){
 checkSensor();
}
 checkValve();

//seconds = ceil(millis()/1000);
/*
if(seconds % 10 == 0){
  openValve();
  readSensor();
  delay(3000);
  closeValve();
}
 */
}
