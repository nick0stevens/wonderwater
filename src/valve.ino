
void initValve(){
pinMode(valuePowerPin,OUTPUT);
pinMode(valueDirectionPin,OUTPUT);
digitalWrite(valuePowerPin,LOW);
digitalWrite(valueDirectionPin,HIGH);
}

void openValve(){
  digitalWrite(valueDirectionPin,LOW);
  digitalWrite(valuePowerPin,HIGH);
  delay(100);
  digitalWrite(valuePowerPin,LOW);
  Serial.println("opening valve");

  }

void closeValve(){
  digitalWrite(valueDirectionPin,HIGH);
  digitalWrite(valuePowerPin,HIGH);
  delay(100);
  digitalWrite(valuePowerPin,LOW);
  digitalWrite(valueDirectionPin,LOW);
  Serial.println("closing valve");
  }
