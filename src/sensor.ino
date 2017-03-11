
void initSensor(){
pinMode(sensorPower, OUTPUT);

}

void checkSensor(){
  if(currentTime>lastSensorCheck + (interval*1000*60)){
readSensor();
lastSensorCheck = currentTime;
 checkLevel();
  }
}

void readSensor(){
  digitalWrite(sensorPower, HIGH);
  sensorValue = analogRead(sensor);
  digitalWrite(sensorPower, LOW);
  sensorValue = map(sensorValue,0,1024,0,100);
  //if(debug){Serial.print("sensor value: ");Serial.println(sensorValue);}

  }
