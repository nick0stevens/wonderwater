

#include "configFile.h"


void setup(void){



initSerial();
initSpiffs();
initSensor();
initValve();
initWifi();
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);

}

void loop(void){
  server.handleClient();


seconds = ceil(millis()/1000);
/*
if(seconds % 10 == 0){
  openValve();
  readSensor();
  delay(3000);
  closeValve();
}
 */
}
