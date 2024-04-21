const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    Serial.print("Received: ");
    Serial.println(incomingByte);

    if (incomingByte == 'A') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED turned ON");
      delay(1000);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned OFF");
    }
}
}