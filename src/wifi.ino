void initWifi(){
  
    WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);

  if(WiFi.waitForConnectResult() == WL_CONNECTED){
    MDNS.begin(host);

    allowFlashOverWeb();  // pull pin GPIO0 (D3) and GPIO2 (D4)HIGH it auto reset !! 
    allowFileUploadOverWeb();
    allowWebInterface();
    server.begin();
    MDNS.addService("http", "tcp", 80);
  
    Serial.printf("Ready! Open http://%s.local in your browser\n", host);
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi Failed");
  }
  
  }
