
#include "DHT.h"
#define DHTPIN 2

#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

int fan11 = 3;
int fan12 = 4;
int heater = 5;
int LEDrow1=6;
int LEDrow2=7;
int LEDrow3=8;
void ht(){
float h = dht.readHumidity();
float t= dht.readTemperature();

if (isnan(h) || isnan(t)){
  Serial.println("failed to read from DHT sensor!");
  return;
}

Serial.print("humidity:");
Serial.print(h);
Serial.print("%\t");
Serial.print("temperature:");
Serial.print(t);
if(t>25){
  digitalWrite(heater,LOW);
  digitalWrite(fan11,HIGH);
  digitalWrite(fan12,LOW);
}

  
  else if(t<15){
 digitalWrite(heater,HIGH);
 digitalWrite(fan11,LOW);
 digitalWrite(fan12,LOW);
  }
}


void light(){
  
float ldrdata=analogRead(A0);
Serial.println(ldrdata);
float resistorVolt=(1024-ldrdata)/1024.0*5.0;
float ldrVolt=5.0-resistorVolt;
float ldrResistance= ldrVolt/resistorVolt*5000.0;
float lux = (12518931)*(pow(ldrResistance,-1.405));
float photons= lux*0.019;
Serial.println(photons);
//delay(1000);

if(photons<50){
  digitalWrite(LEDrow1,HIGH);
  digitalWrite(LEDrow2,HIGH);
  digitalWrite(LEDrow3,HIGH);
  
}
else if(photons>100){
  digitalWrite(LEDrow1,LOW);
  digitalWrite(LEDrow2,LOW);
  digitalWrite(LEDrow3,LOW);
  
}}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHTxx test");
pinMode(fan11,OUTPUT);
pinMode(fan12,OUTPUT);
pinMode(LEDrow1,OUTPUT);
pinMode(LEDrow2,OUTPUT);
pinMode(LEDrow3,OUTPUT);
pinMode(heater,OUTPUT);
dht.begin();
}
void loop() {
  
ht();
light();
  
  // put your main code here, to run repeatedly:

}
