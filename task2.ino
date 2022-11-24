int motor1_Pin1 = 2;
int motor1_Pin2 = 3;

int motor2_Pin1 = 4;
int motor2_Pin2 = 5;

int motor1_speed = 9;
int motor2_speed = 10;

int straight_time = 1000;
int turn_time = 800;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  pinMode(motor2_Pin2, OUTPUT);

  pinMode(motor1_speed, OUTPUT);
  pinMode(motor2_speed, OUTPUT);

  // left90();
  // delay(500);
  // right90();
  forward(straight_time);
 
  delay(1000);
  right90(turn_time);


  delay(1000);
  forward(straight_time);
  

  delay(1000);
  left90(turn_time);

  delay(1000);
  forward(straight_time);
}

void loop() {
}

void stop() {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, LOW);
  digitalWrite(motor2_Pin1, LOW);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 0);
  analogWrite(motor1_speed, 0);
}

void forward(int time) {
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
  digitalWrite(motor2_Pin1, HIGH);
  digitalWrite(motor2_Pin2, LOW);
  analogWrite(motor2_speed, 225);
  analogWrite(motor1_speed, 225);
  delay(time);
  stop();
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
