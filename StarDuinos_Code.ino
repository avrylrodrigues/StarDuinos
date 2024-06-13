// Header files
#include <Servo.h>
// Ultrasonic sensor
int triggerPin = 9; 
int echoPin = 10; 
float pulse_width, distance; 
// LEDs
int RedPin = 7; 
int GreenPin = 6; 
// Buzzer
int buzzerPin = 5; 
// Servo motor
Servo myservo1;
Servo myservo2;
int pos = 0; 
void setup() { 
 // Servo motor
 myservo1.attach(8);
 myservo2.attach(4);
 // Ultrasonic sensor
 pinMode(triggerPin, OUTPUT);
 pinMode(echoPin, INPUT); 
 // LEDs
 pinMode(RedPin, OUTPUT); 
 pinMode(GreenPin, OUTPUT); 
 // Buzzer
 pinMode(buzzerPin, OUTPUT); 
 Serial.begin(9600);
 digitalWrite(triggerPin, LOW); 
 delayMicroseconds(2);
} 
void loop() {
 digitalWrite(triggerPin, HIGH); 
 delayMicroseconds(10);
 digitalWrite(triggerPin, LOW); 
 pulse_width = pulseIn(echoPin, HIGH);
 // Calculates the distance of the train
 distance = (pulse_width * .0343) / 2; 
 Serial.print("Distance = ");
 Serial.print(distance); 
8 
 Serial.print (" cm");
 Serial.println (" ");
 // When the train gets detected by the sensor
 if (distance <= 10) { 
 // Red LED lighs up
 digitalWrite(GreenPin, LOW); 
 digitalWrite(RedPin, HIGH);
 // Buzzer starts ringing
 tone(buzzerPin, 1000);
 for (pos = 90; pos >= 0; pos -=1) 
 // Servo motor makes barriers go down
 myservo1.write(pos); 
 myservo2.write(pos); 
 delay(1000);
 delay(5000);
 } 
 // When the train passes by and is at a safe distance
 else { 
 // Green LED lights up
 digitalWrite(RedPin, LOW);
 digitalWrite(GreenPin, HIGH); 
 // Buzzer stops ringing
 noTone(buzzerPin); 
 for (pos = 0; pos <= 90; pos +=1) 
 // Servo motor makes barriers go up
 myservo1.write(pos);
 myservo2.write(pos);
 delay(700);
 delay(700);
 } 
} 