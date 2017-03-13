void initVariables(){
  if (!loadConfig()) {
    Serial.println("Failed to load config");
  } else {
    Serial.println("Config loaded");
  }
}

bool loadConfig() {
  File configFile = SPIFFS.open("/variables.json", "r");
  if (!configFile) {
    Serial.println("Failed to open config file");
    return false;
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }

    period = json["period"];
    interval = json["interval"];
    sInterval= json["sInterval"];
    threshold= json["threshold"];
    operating= json["operating"];
    irrigating= json["irrigating"];
    needWater= json["needWater"];
  // Real world application would store these values in some variables for
  // later use.

  Serial.print("period: ");
  Serial.println(period);
  Serial.print("interval: ");
  Serial.println(interval);
  Serial.print("sInterval: ");
  Serial.println(sInterval);
  Serial.print("operating: ");
  Serial.println(operating);
  Serial.print("irrigating: ");
  Serial.println(irrigating);
  Serial.print("needWater: ");
  Serial.println(needWater);
  return true;
}

bool saveConfig() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["period"] = period;
  json["interval"] = interval;
  json["sInterval"] = sInterval;
  json["threshold"] = threshold;
  json["operating"] = operating;
  json["irrigating"] = irrigating;
  json["needWater"] = needWater;

  File configFile = SPIFFS.open("/variables.json", "w");
  if (!configFile) {
    Serial.println("Failed to open variables file for writing");
    return false;
  }

  json.printTo(configFile);
  return true;
}
