// Motor Pins for L298 Motor Driver
int motorPin1 = 8;  // IN1 (Motor 1)
int motorPin2 = 9;  // IN2 (Motor 1)
int motorPin3 = 10; // IN3 (Motor 2)
int motorPin4 = 11; // IN4 (Motor 2)

// Ultrasonic Sensor Pins
int trigPin = 6;
int echoPin = 7;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Set motor pins as OUTPUT
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the TRIG pin to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance based on the speed of sound (343 m/s)
  distance = duration * 0.0344 / 2;

  // Display distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // If an obstacle is detected (distance < threshold), stop the motors
  if (distance < 12) { // Adjust threshold as needed
    stopMotors();
    Serial.println("Obstacle detected! Motors stopped.");
  } else {
    moveForward();
    Serial.println("Moving forward...");
  }

  delay(500); // Delay for stability
}

void moveForward() {
  // Move Motor 1 and Motor 2 forward
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);

  // Assuming Motors 3 and 4 are connected in parallel to the L298's second channel
  // Move Motor 3 and Motor 4 forward
  digitalWrite(motorPin1, HIGH);  // Motor 3
  digitalWrite(motorPin2, LOW);   // Motor 3
  digitalWrite(motorPin3, HIGH);  // Motor 4
  digitalWrite(motorPin4, LOW);   // Motor 4
}

void stopMotors() {
  // Stop all motors
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
