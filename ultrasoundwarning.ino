int const trigPin = 13;
int const echoPin = 12;
int const buzzPin = 6;
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
  if (distance <= 10 && distance >= 0) {
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }
  delay(60);
}
