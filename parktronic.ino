int const trigPin = 9;
int const echoPin = 10;
int const buzzPin = 8;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  if (distance <= 10 && distance > 6) {
    tone(buzzPin, 10000, 1000);
    delay(250);
    noTone(buzzPin);
  } else if (distance <= 6 && distance > 3) {
    tone(buzzPin, 10000, 1000);
    delay(100);
    noTone(buzzPin);
  } else if (distance <= 3 && distance > 0) {
    tone(buzzPin, 10000, 1000);
  }
}
