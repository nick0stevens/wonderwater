
void initValve(){
pinMode(valuePowerPin,OUTPUT);
pinMode(valueDirectionPin,OUTPUT);
digitalWrite(valuePowerPin,LOW);
digitalWrite(valueDirectionPin,HIGH);
}

void checkValve(){
if(needWater){
  if(debug) Serial.println("needs water");
  if(!irrigating && operating){
  openValve();
  irrigating = true;
  needWater= false;
  valveOnTime = currentTime;
}
}
if(irrigating){
if(currentTime > valveOnTime + (period*1000)) {
  closeValve();
  irrigating = false;
}
}
}

void openValve(){
  digitalWrite(valueDirectionPin,LOW);
  digitalWrite(valuePowerPin,HIGH);
  delay(100);
  digitalWrite(valuePowerPin,LOW);

  if(debug) {
    Serial.println("opening valve");
    digitalWrite(LED_BUILTIN, LOW);
}
  }

void closeValve(){
  digitalWrite(valueDirectionPin,HIGH);
  digitalWrite(valuePowerPin,HIGH);
  delay(100);
  digitalWrite(valuePowerPin,LOW);
  digitalWrite(valueDirectionPin,LOW);

  if(debug) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("closing valve");
}
  }
