#include<ESP8266WebServer.h>
ESP8266WebServer server;
const char username[] ="sai";
const char password[] ="raksha1999";
#define pin 16

void setup() 
{
 pinMode(pin,OUTPUT);
 Serial.begin(115200);
 WiFi.softAP(username,password);
 IPAddress myIP=WiFi.softAPIP();
 Serial.print("AP IP address :");
 Serial.println(myIP);
 server.begin();
 server.on("/led",led);
}
void loop() 
{
  server.handleClient();
}
void led()
{
  String myhtml ="<html><head><title>my first web</title></head><body style=\"background-color: blue\"><h1><center>led</center><h1><form>what do u want to do<br><button type=\"submit\" name=\"state\" value=\"0\">on</button><button type=\"submit\" name=\"state\" value=\"1\">off</button></form></body></html>";
  server.send(200,"text/html",myhtml);
  if(server.arg("state")=="0")
  {
  digitalWrite(pin,LOW);
  }
  else
  {
    digitalWrite(pin,1);
  }
}


