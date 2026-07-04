#include <Servo.h> 

// --- Pin Definitions ---
const int trigPin = 11;
const int echoPin = 12;
const int laserPin = 8;
const int buzzerPin = 7;
const int servoPin = 9;

Servo myServo;

void setup() {
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(115200);
  
  digitalWrite(buzzerPin, HIGH); 
  delay(500); 
  digitalWrite(buzzerPin, LOW);
  
  Serial.println("Dual-Scan Radar System Initialized.");
}

void loop() {
  // --- Scan from 0 to 180 degrees ---
  for (int i = 0; i <= 180; i++) {
    performScan(i);
    delay(30);
  }
  
  // --- Scan from 180 to 0 degrees ---
  for (int i = 180; i >= 0; i--) {
    performScan(i);
    delay(30);
  }
}

// --- Shared Function to Perform Scan at a Specific Angle ---
void performScan(int angle) {
  myServo.write(angle);
  int distance = calculateDistance();
  
  // Detection Logic (30 cm limit)
  if (distance > 0 && distance < 30) { 
    digitalWrite(laserPin, LOW);   // Target detected
    digitalWrite(buzzerPin, HIGH); // Alarm ON
  } else {
    digitalWrite(laserPin, HIGH);  // Clear
    digitalWrite(buzzerPin, LOW);  // Alarm OFF
  }
  
  Serial.print("Angle: "); Serial.print(angle);
  Serial.print(" | Distance: "); Serial.print(distance);
  Serial.println(" cm");
}

// --- Distance Calculation ---
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
