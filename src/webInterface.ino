
    void handleButtonSave(){

      if(server.hasArg("Water")){
        DBG_OUTPUT_PORT.println("handleWater ");

    if (server.arg("Water")=="false"){
      closeValve();
      irrigating = false;
      Serial.println("water off");
    }
    if (server.arg("Water")=="true"){
      openValve();
      irrigating = true;
      needWater= false;
      valveOnTime = currentTime;
      Serial.println("water on");
    }
}

if(server.hasArg("Start")){
  DBG_OUTPUT_PORT.println("handleStart ");

if (server.arg("Start")=="false"){
  operating = false;
  closeValve();
  irrigating = false;

Serial.println("Stopped");
}
if (server.arg("Start")=="true"){
  operating = true;

Serial.println("Started");
}
}

       // server.send(200, "text/html", "<INPUT type=\"button\" name=\"LED\" value=\"LED\"><BR>");

       server.send(200, "text/html", "<form method='POST' action='/buttonPage/ONgg' <a href=\"ONbbb\"  value=\"LED\" button style=\"display: block; width: 10%;\">ON</button></a> <form method='GET' action='/buttonPage' <a href=\"off\"><button style=\"display: block; width: 100%;\">OFF</button></a>");

   // server.send(200, "text/html", "<form method='GET'  <a href=\"ONbbb\"  value=\"IT\" button style=\"display: block; width: 10%;\">ON</button></a> <form method='GET' action='/buttonPage' <a href=\"off\"><button style=\"display: block; width: 100%;\">OFF</button></a>");
    //server.send(200, "text/html", "<FORM><input type=\"button\" value=\"Add Students\" onclick=\"window.location.href='ON';\"></FORM>");

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

     server.send(200, "text/plain", "");

      //DBG_OUTPUT_PORT.println(period + interval);
   }







void allowWebInterface(){

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

  server.on("/buttons",HTTP_GET, [](){
  String json = "{";
  json += "\"watering\":"+ String(irrigating) ;
  json += ", \"operating\":"+String(operating);
  json += "}";
  server.send(200, "text/json", json);
  json = String();
});


  server.on("/buttons/save",  handleButtonSave);


  server.on("/variables/save",  handleVariablesSave);




  }
