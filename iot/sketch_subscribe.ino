#include<ESP8266WiFi.h>
#include"Adafruit_MQTT_Client.h"
#define wifi "Agela"
#define password "agelaaaa"
#define server "io.adafruit.com"
#define port 1883
#define username "saishruthi"
#define key "dd831290c1fd4ff892741057fc888b4e"
 WiFiClient esp;
 Adafruit_MQTT_Client mqtt(&esp,server,port,username,key);
 Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt,username"/feeds/ldr");
 
void setup() {
pinMode(16,OUTPUT);
Serial.begin(115200);
delay(10);
Serial.println("Adafruit MQTT");
Serial.println();
Serial.print("connecting to");
Serial.println(wifi);
WiFi.begin(wifi,password);
while(WiFi.status()!=WL_CONNECTED)
{delay(500);
Serial.print(".");
}
Serial.println();
Serial.println("Wifi Connected");
Serial.println("IP Address:");
Serial.println(WiFi.localIP());
mqtt.subscribe(&feed);
Serial.println("connnecting to MQTT");
while(mqtt.connect())
{delay(500);
 Serial.print(".");
}


}

void loop() {
  // put your main code here, to run repeatedly:
while(mqtt.readSubscription(5000))
{Serial.print("got :");
 Serial.print((char*)feed.lastread);
 int a = atoi((char*)feed.lastread);
 Serial.print(" ");
 Serial.println(a);
 if(a==0)
  {digitalWrite(16,0);
  }
 else
  {digitalWrite(16,1);
  }
}
}
