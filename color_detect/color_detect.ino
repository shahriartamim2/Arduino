/*
  Arduino Code to Measure Pulse Widths and Send to Python
*/

// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Threshold for color detection
int threshold = 200;

void setup() {
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read Red Pulse Width
  redPW = getRedPW();
  delay(200); // Delay to stabilize sensor
  
  // Read Green Pulse Width
  greenPW = getGreenPW();
  delay(200); // Delay to stabilize sensor
  
  // Read Blue Pulse Width
  bluePW = getBluePW();
  delay(200); // Delay to stabilize sensor
  
  // Send pulse widths to Python over Serial
  Serial.print("R:");
  Serial.print(redPW);
  Serial.print(" G:");
  Serial.print(greenPW);
  Serial.print(" B:");
  Serial.println(bluePW);

  delay(200);
}

// Function to read Red Pulse Widths
int getRedPW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  return pulseIn(sensorOut, LOW);
}

// Function to read Green Pulse Widths
int getGreenPW() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}

// Function to read Blue Pulse Widths
int getBluePW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}
