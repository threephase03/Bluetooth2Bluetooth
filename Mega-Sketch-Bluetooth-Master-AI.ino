

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  String command;

  // Check Serial Port
  if (Serial.available()) {
    command = readSerialCommand(Serial);
    if (command == "On" || command == "Off") {
      Serial2.println(command); // Forward to Serial2
    }
  }

  // Check Serial2 Port
  if (Serial2.available()) {
    command = readSerialCommand(Serial2);
    if (command == "On") {
      digitalWrite(13, HIGH); // Turn LED on
    } else if (command == "Off") {
      digitalWrite(13, LOW);  // Turn LED off
    }
  }
}

String readSerialCommand(HardwareSerial &serial) {
  String result = "";
  while (serial.available()) {
    char c = serial.read();
    if (isControl(c)) {
      break;
    }
    result += c;
  }
  return result;
}

bool isControl(char c) {
  return c < 32 || c == 127; // Checks for control characters
}
