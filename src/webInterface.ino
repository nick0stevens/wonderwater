
void handleWaterOn(){

  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage LOW
  openValve();
  server.send(200, "text/plain", "");

  }

  void handleWaterOff(){
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  closeValve();
  server.send(200, "text/plain", "");
  }
/*
  void handleButtonPage(){

      if (server.hasArg("LED")){
Serial.println("yup");
}
  DBG_OUTPUT_PORT.println("handleButtonPage  ");
     // server.send(200, "text/html", "<INPUT type=\"button\" name=\"LED\" value=\"LED\"><BR>");

     server.send(200, "text/html", "<form method='POST' action='/buttonPage/ONgg' <a href=\"ONbbb\"  value=\"LED\" button style=\"display: block; width: 10%;\">ON</button></a> <form method='GET' action='/buttonPage' <a href=\"off\"><button style=\"display: block; width: 100%;\">OFF</button></a>");

 // server.send(200, "text/html", "<form method='GET'  <a href=\"ONbbb\"  value=\"IT\" button style=\"display: block; width: 10%;\">ON</button></a> <form method='GET' action='/buttonPage' <a href=\"off\"><button style=\"display: block; width: 100%;\">OFF</button></a>");
  //server.send(200, "text/html", "<FORM><input type=\"button\" value=\"Add Students\" onclick=\"window.location.href='ON';\"></FORM>");

    }

*/
    void handleButtonPage(){

      if(server.hasArg("Water")){
        DBG_OUTPUT_PORT.println("handleWater ");

    if (server.arg("Water")=="false"){
      digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
      closeValve();
      Serial.println("water off");
    }
    if (server.arg("Water")=="true"){
      digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on by making the voltage LOW
      openValve();
      Serial.println("water on");
    }
}

if(server.hasArg("Start")){
  DBG_OUTPUT_PORT.println("handleStart ");

if (server.arg("Start")=="false"){

Serial.println("Stopped");
}
if (server.arg("Start")=="true"){

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
    json += "\"analog\":"+ String(sensorValue) ;
    json += "}";
    server.send(200, "text/json", json);
    json = String();
  });


  server.on("/buttonPage",  handleButtonPage);


//  server.on("/buttonPage?Water",  handleWater);


//  server.on("/buttonPage?Start",  handleStart);


  server.on("/variables/save",  handleVariablesSave);

   //server.on("/change", handleFileRead("/change"));

    server.on("/variables",HTTP_GET, [](){
    String json = "{";
    json += "\"period\":"+ String(period) ;
    json += ", \"interval\":"+String(interval);
    json += ", \"sInterval\":"+String(sInterval);
    json += ", \"threshold\":"+String(threshold);
    json += "}";
    server.send(200, "text/json", json);
    json = String();
  });

  }
