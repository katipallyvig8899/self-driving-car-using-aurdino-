#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int Front_D = 0;
int Left_D = 0;
int Right_D = 0;
int m1a = 6;
int m1b = 5;
int m2a = 4;
int m2b = 3;
int temp;
//int pos = 93;    // variable to store the servo position
const int trigPin = 10;
const int echoPin = 11;
// defines variables
long duration;
int distance;
void setup() {
  Front_D = get_d();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(m1a, OUTPUT);  
  pinMode(m1b, OUTPUT); 
  pinMode(m2a, OUTPUT);  
  pinMode(m2b, OUTPUT); 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.write(83);
  Serial.begin(9600);// Starts the serial communication
  
  delay(500);
  front();
  delay(200);
}

 
void loop() {
Front_D = get_d();
if (Front_D < 7) {
  stop1();
  delay(500);
  myservo.write(180);
  delay(1000);
  Left_D = get_d();
  if(Left_D > 20 ) {
    left();
    delay(500);
  }
  else {
   myservo.write(0);
   delay(1000);
   Right_D = get_d();
   if (Right_D < 20 ) {
    stop1(); 
    delay(500);
   myservo.write(83);
   Front_D = get_d();
   }
   else {
    right();
    delay(100);
   }
  }
}
}
int get_d() {
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
return distance;
}
void front() {
     digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW); 
}
void stop1(){
     digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW); 
}
void right(){
  
   digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    delay(700);
    front();
    myservo.write(83);
}
void left(){
 
   digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    delay(675);
    front();
    myservo.write(83);
}
