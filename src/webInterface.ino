
    void handleButtonSave(){

    if (server.arg("Button")=="Water"){
      if(operating){
        if(irrigating){
        closeValve();
        Serial.println("water off");
        irrigating = false;
      }
      else{
        openValve();
        irrigating = true;
        needWater= false;
        valveOnTime = currentTime;
        Serial.println("water on");
      }
    }
  }

    if (server.arg("Button")=="Start"){
      if(operating){
      operating = false;
      closeValve();
      irrigating = false;
      Serial.println("Stopped");
    }
    else{
      operating = true;
      Serial.println("Started");
    }
}
/*
String json = "{";
json += "\"watering\":"+ String(irrigating) ;
json += ", \"operating\":"+String(operating);
json += "}";
*/
server.send(200, "text/html");
}
    void handleVariablesSave(){

      String varPeriod = server.arg("period");
      if(varPeriod !=""){
      period = varPeriod.toInt();
      Serial.print("the period is ");
      Serial.println(period);
      }

      String varInterval = server.arg("interval");
      if(varInterval !=""){
      interval = varInterval.toInt();
      Serial.print("the interval is ");
      Serial.println(interval);
      }

      String varSInterval = server.arg("sInterval");
      if(varSInterval !=""){
      sInterval = varSInterval.toInt();
      Serial.print("the sensro interval is ");
      Serial.println(sInterval);
      }

      String varThreshold = server.arg("threshold");
      if(varThreshold !=""){
      threshold = varThreshold.toInt();
      Serial.print("the threshold is ");
      Serial.println(threshold);
      }

      saveConfig();
      server.send(200, "text/html");

      //DBG_OUTPUT_PORT.println(period + interval);
   }



void allowWebInterface(){
  server.on("/buttons/save",  handleButtonSave);

  server.on("/variables/save",  handleVariablesSave);

  //get heap status, analog input value and all GPIO statuses in one json call
  server.on("/all", HTTP_GET, [](){
    String json = "{";
    json += "\"heap\":"+String(ESP.getFreeHeap());
    json += ", \"analog\":"+String(analogRead(A0));
    json += ", \"gpio\":"+String((uint32_t)(((GPI | GPO) & 0xFFFF) | ((GP16I & 0x01) << 16)));
    json += "}";
    server.send(200, "text/json", json);
    json = String();
  });

      //get analog input value in json call
  server.on("/sensor", HTTP_GET, [](){
    String json = "{";
    json += "\"sensor\":"+ String(sensorValue) ;
    json += "}";
    server.send(200, "text/json", json);
    json = String();
  });

  //get analog input value in json call
  server.on("/variables", HTTP_GET, [](){
  /*  String json = "{";
    json += "\"period\":"+ String(period) ;
    json += ",\"interval\":"+ String(interval) ;
    json += ", \"sInterval\":"+ String(sInterval) ;
    json += ", \"threshold\":"+ String(threshold) ;
    json += ", \"irrigating\":"+ String(irrigating) ;
    json += ", \"operating\":"+ String(operating) ;
    json += ", \"needWater\":"+ String(needWater) ;
    json += "}";
*/
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();
    json["period"] = period;
    json["interval"] = interval;
    json["sInterval"] = sInterval;
    json["threshold"] = threshold;
    json["operating"] = operating;
    json["irrigating"] = irrigating;
    json["needWater"] = needWater;
    char buffer[256];
    json.printTo(buffer, sizeof(buffer));
    server.send(200, "text/json", buffer);
  });

  server.on("/buttons",HTTP_GET, [](){
  String json = "{";
  json += "\"watering\":"+ String(irrigating) ;
  json += ", \"operating\":"+String(operating);
  json += "}";
  server.send(200, "text/json", json);
  json = String();
});

  }
