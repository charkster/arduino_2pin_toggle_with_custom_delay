// RP2350 Seeed Xiao 300MHz overclock
const int d1 = 26;  // Xiao D0, First  pin to toggle immediately

int pulse1_Micros;
int d1_initial_level;

void setup() {
  pulse1_Micros = 0;
  d1_initial_level = 0;
  
  Serial.begin(115200);    // Open USB serial terminal
  while (Serial.available() == 0) { }
  Serial.readString();
  Serial.println("Enter D1 inital level (0 or 1), don't hit Enter when done:");
  while (Serial.available() == 0) { }
  d1_initial_level = Serial.parseInt();  // Read D1 initial level
  while (Serial.available() > 0) {
    Serial.read();
  }
  Serial.print("D1 initial level is: ");
  Serial.println(d1_initial_level);
  
  Serial.println("Enter pulse width in microseconds, don't hit Enter when done");
  while (Serial.available() == 0) { }
  pulse1_Micros = Serial.parseInt();  // Read pulse1
  while (Serial.available() > 0) {
    Serial.read();
  }
  Serial.print("Pulse width is: ");
  Serial.println(pulse1_Micros);
  
  pinMode(d1, OUTPUT);
  if (d1_initial_level == 1) {
    digitalWrite(d1, HIGH);
  } else {
    digitalWrite(d1, LOW);
  }
}

void loop() {
  
  Serial.println("Hit Enter to Trigger:");
  while (Serial.available() == 0) { }
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Toggle pin, wait pulse delay, return to initial level
  if (d1_initial_level == 1) {
    digitalWrite(d1, LOW);
    delayMicroseconds(pulse1_Micros);
    digitalWrite(d1, HIGH);
  } else {
    digitalWrite(d1, HIGH);
    delayMicroseconds(pulse1_Micros);
    digitalWrite(d1, LOW);
  }

}
