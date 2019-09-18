// Here i have used two nodemcu .1st node mcu is connected to two ultrasonic sensor and two led's.upload this code to 1st nodemcu 

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <NewPingESP8266.h>


#define led1 13
#define led2 15

#define TRIGGER_PIN1  4      // Arduino pin tied to trigger pin on the ultrasonic sensor
#define ECHO_PIN1     5      // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN2  14               
#define ECHO_PIN2     12
 
#define MAX_DISTANCE 200         // Maximum distance we want to ping for (in centimeters) Maximum sensor distance is rated at 400cm


NewPingESP8266 sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); 
NewPingESP8266 sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);         // NewPingESP8266 setup of pins and maximum distance



#define FIREBASE_HOST "enter host key"                // should not have http:// and the end /
#define FIREBASE_AUTH "enter auth key"                 // go to settings in firebase,select project settings and service account, secrets auth key
#define WIFI_SSID "enter ssid"                        // enter your wifi ssid
#define WIFI_PASSWORD "enter wifi password"           // enter your wifi password




void setup() {
  Serial.begin(115200);                                                           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // connect to wifi.
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("slot_1",1);
  Firebase.set("slot_2",1);

 
}
void firebasereconnect(){
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  }

void loop() {
  
  if (Firebase.failed()) {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());  
      firebasereconnect();
      return;
  }
  

      int a1,b1;
      
      int a=sonar1.ping_cm();             //here i assumed the maximum distance to be  15cm change the value if you need
      if(a<15){
      digitalWrite(led1,1);
      a1=1;}
      else{
      digitalWrite(led1,0);
      a1=0;}
      
      int b=sonar2.ping_cm();
      if(b<15){
      digitalWrite(led2,1);
      b1=1;}
      else{
      digitalWrite(led2,0);
      b1=0;}
      
      Firebase.set("slot_1",a1);
      Firebase.set("slot_2",b1);
    
      delay(1000);

  
  
}
