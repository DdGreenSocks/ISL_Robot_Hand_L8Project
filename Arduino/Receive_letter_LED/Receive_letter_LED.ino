// Define the pin connected to the onboard LED
const int LED_PIN = 13;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Check if data is available to read from the serial port
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingByte = Serial.read();

    // Print the received byte to the serial monitor for debugging
    Serial.print("Received: ");
    Serial.println(incomingByte);

    // Check if the received byte is 'A'
    if (incomingByte == 'A') {
      // Turn on the LED if 'A' is received
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED turned ON");
    } else {
      // Turn off the LED for any other letter received
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED turned OFF");
    }
  }
}
