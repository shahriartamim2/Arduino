#define BUZZER_PIN 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue> 300){
    analogWrite(BUZZER_PIN, 50);
  }
  else{
    analogWrite(BUZZER_PIN, 0);
  }
  delay(1000);
}
