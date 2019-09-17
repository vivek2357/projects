 #include<ESP8266WiFi.h>
 #include"Adafruit_MQTT_Client.h"
 #define ldr A0
 #define wifi "Agela"
 #define password "agelaaaa"
 #define server "io.adafruit.com"
 #define port 1883
 #define username "saishruthi"
 #define key "dd831290c1fd4ff892741057fc888b4e"
 WiFiClient esp;
 Adafruit_MQTT_Client mqtt(&esp,server,port,username,key);
 Adafruit_MQTT_Publish feed=Adafruit_MQTT_Publish(&mqtt,username"/feeds/ldr");
 
 
 void setup() 
 {
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit MQTT demo");
  Serial.print("connecting to ");
  Serial.println(wifi);
  WiFi.begin(wifi,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());
  Serial.print("connecting to mqtt");
  while(mqtt.connect())
  {
    Serial.print(".");
  }
 }

void loop() { 
  if(mqtt.connected())
{
  int data=analogRead(ldr);
  Serial.print("/nSending ldr value");
  Serial.print(data);
  Serial.print("...");
  if(feed.publish(data)){
    Serial.println("sucess");
  }
  else
  {
    Serial.println("Fail");
  }
  delay(2000);
}
