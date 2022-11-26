#include <arduino.h>
#include <avr/wdt.h>
const int right_IR = A1; //right IR sensor
const int middle_IR = A2; // middle IR sensor 
const int left_IR = A3;// left IR sensor pin

//below are the pins for the motors
int motor1_Pin1 = 2;
int motor1_Pin2 = 3;

int motor2_Pin1 = 4;
int motor2_Pin2 = 5;

//these are the pins for the speed of the motors
int motor1_speed = 9;
int motor2_speed = 10;


void setup() {

  //this is just seting up the pins as output or input
  pinMode(left_IR, INPUT);
  pinMode(middle_IR, INPUT);
  pinMode(right_IR, INPUT);

  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  pinMode(motor2_Pin2, OUTPUT);

  pinMode(motor1_speed, OUTPUT);
  pinMode(motor2_speed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int left_Sensor = analogRead(left_IR); //read left IR store it in int varible left_Sensor
  int middle_Sensor = analogRead(middle_IR); //read middle IR store it in int varible middle_Sensor
  int right_Sensor = analogRead(right_IR); //read right IR store it in int varible right_Sensor


  if ((left_Sensor < 550) && (middle_Sensor > 550) && (right_Sensor < 550)) { //if only the middle sensor is detecting a line go forward
    forward();
  } else if ((left_Sensor > 550) && (right_Sensor < 550)) { // if the left sensor is detecting a line turn left
    left();
  } else if ((left_Sensor < 550) && (right_Sensor > 550)) { //if the right sensor is detecting a line turn right
    right();
  }
  
}


//below are funstions used to direct the robot forward, reverse turn left, turn right, and stop

void forward() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 100);
  analogWrite(motor1_speed, 100);
  // delay(100);
  // stop();
}

void reverse() {
  digitalWrite(motor1_Pin1, HIGH);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, HIGH);
  analogWrite(motor2_speed, 180);
  analogWrite(motor1_speed, 180);
}

void right() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, HIGH);
  analogWrite(motor2_speed, 100);
  analogWrite(motor1_speed, 100);
  // delay(250);
  // stop();
}

void left() {
  digitalWrite(motor1_Pin1, HIGH);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 125);
  analogWrite(motor1_speed, 125);
  // delay(250);
  // stop();
}
void stop() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 0);
  analogWrite(motor1_speed, 0);
}
