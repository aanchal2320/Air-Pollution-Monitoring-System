int redLed=12;
int greenLed=8;
int buzzer=10;
#define analog A0
int sensorThres=500;
void setup() {
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
  if(analogSensor>
  sensorThres)
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
