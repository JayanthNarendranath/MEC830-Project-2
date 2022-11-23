
//Motor 1
const int motor1_Pin1 = 5;  // Pin 14 of L293
const int motor1_Pin2 = 6;  // Pin 10 of L293
const int motor1_speed = 7;
//Motor 2
const int motor2_Pin1 = 10;  // Pin  7 of L293
const int motor2_Pin2 = 9;   // Pin  2 of L293
const int motor2_speed = 8;
int repeat;

//remote setup
#include <IRremote.h>

char command;
int receiver_pin = 13;  //Connect the output pin of IR receiver at pin 4


IRrecv irrecv(receiver_pin);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  //Set pins as outputs
  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  pinMode(motor2_Pin2, OUTPUT);
  pinMode(motor1_speed, OUTPUT);
  pinMode(motor2_speed, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {



    irrecv.resume();

    if (results.value == 0xFF18E7) {  // type button 2 forward robot control

      forward();


    } else if (results.value == 0xFF30CF) {  // type button 1 rotate left robot control

      left();

    } else if (results.value == 0xFF7A85) {  // type button 3 rotate right robot control

      // this function will run motor A  in backward directions  motor B in forward directions
      right();

    } else if (results.value == 0xFF4AB5) {  // type button 8 backward robot control

      // this function will run motor A and motor B in backward directions
      reverse();
    } else if (results.value == 0xFF38C7) {  // type button 5 stop robot control

      // this function will stop both motor A and motor B
      stop();
    }
  }
}

void stop() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 0);
  analogWrite(motor1_speed, 0);
}

void reverse() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 180);
  analogWrite(motor1_speed, 180);
}

void forward() {
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
  analogWrite(motor2_speed, 150);
  analogWrite(motor1_speed, 150);
}

void left() {
  digitalWrite(motor1_Pin1, HIGH);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 150);
  analogWrite(motor1_speed, 150);
}
