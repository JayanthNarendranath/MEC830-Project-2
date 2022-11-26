#define trigPin1 6
#define echoPin1 7

int motor1_Pin1 = 2;
int motor1_Pin2 = 3;

int motor2_Pin1 = 4;
int motor2_Pin2 = 5;

int motor1_speed = 9;
int motor2_speed = 10;

int straight_time = 750;
int turn_time = 675;

long duration, distance, FrontSensor;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  pinMode(motor2_Pin2, OUTPUT);

  pinMode(motor1_speed, OUTPUT);
  pinMode(motor2_speed, OUTPUT);
}

void loop() {
  task3();
}

void stop() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 0);
  analogWrite(motor1_speed, 0);
}

void straightLine(int time) {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 125);
  analogWrite(motor1_speed, 125);
  delay(time);
  stop();
}

void forward(int time) {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 125);
  analogWrite(motor1_speed, 125);
  delay(time);
  stop();
  delay(time);
  
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

void left90(int time) {
  digitalWrite(motor1_Pin1, HIGH);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 200);
  analogWrite(motor1_speed, 200);
  delay(time);
  stop();
}

void right90(int time) {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, HIGH);
  analogWrite(motor2_speed, 200);
  analogWrite(motor1_speed, 200);
  delay(time);
  stop();
}

void ultrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
}


//this is a function that just does task 3
void task3() {
  
  forward(100); // go forward for 100ms
  ultrasonic(trigPin1, echoPin1);// use ultra sonic sensor to detect object ahead
  FrontSensor = distance; //put the distance into the varible FrontSensor
  if (FrontSensor <= 15) { //if there is an object within 15 cm
    stop(); // stop
    delay(1000); // 1s delay
    left90(turn_time); // turn left 90 degrees
    delay(1000);// 1s delay
    straightLine(straight_time);// go straight
    delay(1000); // 1s delay
    right90(turn_time);// turn right 90 degrees
    delay(1000); // 1s delay
    straightLine(straight_time); // go straight
    delay(1000); // 1s delay
    right90(turn_time); // turn right 90 degrees
    delay(1000);// 1s delay
    straightLine(straight_time);// go straight
    delay(1000);// 1s delay
    left90(turn_time);// turn left 90 degrees
  }
  
}
