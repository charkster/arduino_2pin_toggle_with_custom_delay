// RP2350 Seeed Xiao 300MHz overclock
const int d1 = 26;  // Xiao D0, First  pin to toggle immediately
const int d2 = 27;  // Xiao D1, Second pin to toggle after delay1
const int d3 = 28;  // Xiao D2, Thrid  pin to toggle after delay2
const int d4 = 5;   // Xiao D3, Fourth pin to toggle after delay3 

int delay1_Micros;
int delay2_Micros;
int delay3_Micros;
int num_pins;
int d1_initial_level;
int d2_initial_level;
int d3_initial_level;
int d4_initial_level;

void setup() {
  delay1_Micros = 0;
  delay2_Micros = 0;
  delay3_Micros = 0;
  num_pins      = 5;
  d1_initial_level = 0;
  d2_initial_level = 0;
  d3_initial_level = 0;
  d4_initial_level = 0;
  
  Serial.begin(115200);    // Open USB serial terminal
  while ((num_pins > 4) || (num_pins < 2)) {
    Serial.println("Enter number of pins:");
    while (Serial.available() == 0) { }
      num_pins = Serial.parseInt();  // Read number of pins
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
  Serial.print("Number of pins: ");
  Serial.println(num_pins);
    
  Serial.println("Enter D1 inital level (0 or 1):");
  while (Serial.available() == 0) { }
  d1_initial_level = Serial.parseInt();  // Read D1 initial level
  while (Serial.available() > 0) {
    Serial.read();
  }
  Serial.print("D1 initial level is: ");
  Serial.println(d1_initial_level);
  
  Serial.println("Enter D2 inital level (0 or 1):");
  while (Serial.available() == 0) { }
  d2_initial_level = Serial.parseInt();  // Read D2 initial level
  while (Serial.available() > 0) {
    Serial.read();
  }
  Serial.print("D2 initial level is: ");
  Serial.println(d2_initial_level);
  
  Serial.println("Enter delay1 in microseconds:");
  while (Serial.available() == 0) { }
  delay1_Micros = Serial.parseInt();  // Read delay1
  while (Serial.available() > 0) {
    Serial.read();
  }
  Serial.print("delay1 is: ");
  Serial.println(delay1_Micros);
  
  if (num_pins > 2) {
    Serial.println("Enter D3 inital level (0 or 1):");
    while (Serial.available() == 0) { }
    d3_initial_level = Serial.parseInt();  // Read D3 initial level
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.print("D3 initial level is: ");
    Serial.println(d3_initial_level);
  
    Serial.println("Enter delay2 in microseconds:");
    while (Serial.available() == 0) { }
    delay2_Micros = Serial.parseInt();  // Read delay2
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.print("delay2 is: ");
    Serial.println(delay2_Micros);
  }
  if (num_pins > 3) {
    Serial.println("Enter D4 inital level (0 or 1):");
    while (Serial.available() == 0) { }
    d4_initial_level = Serial.parseInt();  // Read D4 initial level
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.print("D4 initial level is: ");
    Serial.println(d4_initial_level);
    Serial.println("Enter delay3 in microseconds:");
    while (Serial.available() == 0) { }
    delay3_Micros = Serial.parseInt();  // Read delay3
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.print("delay3 is: ");
    Serial.println(delay3_Micros);
  }
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  if (d1_initial_level == 1) {
    digitalWrite(d1, HIGH);
  } else {
    digitalWrite(d1, LOW);
  }
  if (d2_initial_level == 1) {
    digitalWrite(d2, HIGH);
  } else {
    digitalWrite(d2, LOW);
  }
  if (d3_initial_level == 1) {
    digitalWrite(d3, HIGH);
  } else {
    digitalWrite(d3, LOW);
  }
  if (d4_initial_level == 1) {
    digitalWrite(d4, HIGH);
  } else {
    digitalWrite(d4, LOW);
  }
}

void loop() {
  
  Serial.println("Hit Enter to Trigger:");
  while (Serial.available() == 0) { }
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Toggle first pin
  if (d1_initial_level == 1) {
    digitalWrite(d1, LOW);
  } else {
    digitalWrite(d1, HIGH);
  }

  // Wait for the specified delay
  delayMicroseconds(delay1_Micros);

  // Toggle second pin
  if (d2_initial_level == 1) {
    digitalWrite(d2, LOW);
  } else {
    digitalWrite(d2, HIGH);
  }

  if (num_pins > 2) {
    // Wait for the specified delay
    delayMicroseconds(delay2_Micros);
      
    // Toggle third pin
    if (d3_initial_level == 1) {
      digitalWrite(d3, LOW);
    } else {
      digitalWrite(d3, HIGH);
    }
  }

  if (num_pins > 3) {
    // Wait for the specified delay
    delayMicroseconds(delay3_Micros);
      
    // Toggle third pin
    if (d4_initial_level == 1) {
      digitalWrite(d4, LOW);
    } else {
      digitalWrite(d4, HIGH);
    }
  }
    
  Serial.println("Hit Enter to Re-initialize:");
  while (Serial.available() == 0) { }
  while (Serial.available() > 0) {
    Serial.read();
  }
  if (d1_initial_level == 1) {
    digitalWrite(d1, HIGH);
  } else {
    digitalWrite(d1, LOW);
  }
  if (d2_initial_level == 1) {
    digitalWrite(d2, HIGH);
  } else {
    digitalWrite(d2, LOW);
  }
  if (d3_initial_level == 1) {
    digitalWrite(d3, HIGH);
  } else {
    digitalWrite(d3, LOW);
  }
  if (d4_initial_level == 1) {
    digitalWrite(d4, HIGH);
  } else {
    digitalWrite(d4, LOW);
  }
}
