


// Test code to check ultaonic values



#include <NewPingESP8266.h>


#define TRIGGER_PIN1  4   // Arduino pin tied to trigger pin on the ultrasonic sensor                                  
#define ECHO_PIN1     5   // Arduino pin tied to echo pin on the ultrasonic sensor

#define TRIGGER_PIN2  14
#define ECHO_PIN2     12   

#define MAX_DISTANCE 200    // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400cm





NewPingESP8266 sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);   // NewPingESP8266 setup of pins and maximum distance
NewPingESP8266 sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);


void setup() {
  Serial.begin(115200);        // Open serial monitor at 115200 baud to see ping results

}

void loop() {
  delay(50);                        // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings
  Serial.print("Ping1: ");
  Serial.print(sonar1.ping_cm());    // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  delay(2000);

  
  delay(50);                     
  Serial.print("Ping2: ");
  Serial.print(sonar2.ping_cm()); 
  Serial.println("cm");
  delay(2000);
             
  
}
