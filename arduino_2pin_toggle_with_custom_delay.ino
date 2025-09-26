nMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void loop() {
  int delayMicros = 0;
  Serial.println("Enter delay in microseconds:");
  while (Serial.available() == 0) { }
    delayMicros = Serial.parseInt();  // Read integer delay

    // Toggle first pin
    digitalWrite(pin1, LOW);

    // Wait for the specified delay
    delayMicroseconds(delayMicros);

    // Toggle second pin
    digitalWrite(pin2, HIGH);

    Serial.print("Received delay: ");
    Serial.println(delayMicros);
    
    Serial.println("Type C to clear:");
  while (Serial.available() > 0) {
    Serial.read();
  }
  while (Serial.available() == 0) { }
  while (Serial.available() > 0) {
    Serial.read();
  }
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}
