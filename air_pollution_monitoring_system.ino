#include <ESP8266WiFi.h>

int redLed=4;
int greenLed=5;
int buzzer=10;
#define analog A0
int sensorThres=500;


const char *ssid =  "Aanchal";     
const char *pass =  "aa301209";

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 

      pinMode(redLed,OUTPUT);
      pinMode(greenLed,OUTPUT);
      pinMode(buzzer,OUTPUT);
      pinMode(analog,INPUT);
      Serial.begin(9600);
}

void loop() {
 
  int analogSensor=analogRead(analog);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if(analogSensor>sensorThres)
  {
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    tone(buzzer,3000,300);
  }
  else
  {
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    noTone(buzzer);
  }
  delay(100);

}
