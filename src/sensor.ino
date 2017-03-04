
void initSensor(){


}

void readSensor(){
  sensorValue = analogRead(sensor);
  sensorValue = map(sensorValue,0,1024,0,100);
  //Serial.println(sensorValue);
  
  }
