#define trigPin1 6
#define echoPin1 7
#define trigPin2 12
#define echoPin2 13
#define trigPin3 8
#define echoPin3 11

long duration, distance, RightSensor,FrontSensor,LeftSensor;


void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}

void loop() {
ultrasonic(trigPin1, echoPin1);
RightSensor = distance;
ultrasonic(trigPin2, echoPin2);
LeftSensor = distance;
ultrasonic(trigPin3, echoPin3);
FrontSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.print(FrontSensor);
Serial.print(" - ");
Serial.println(RightSensor);
}

void ultrasonic(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
