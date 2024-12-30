void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); // Ensure the LED starts OFF
  Serial.println("Setup Complete");
}

void loop() {
   String Q = "";
   String readString = "";
   String readString2 = "";
   
  //------------------------------Check Serial Port--------------------------------------
  while (Serial.available()) {
    delay(1);  //delay to allow buffer to fill
    if (Serial.available() > 0) {
      char c = Serial.read();  //gets one byte from serial buffer
      if (isControl(c)) {
        //'Serial.println("it's a control character");
        break;
      }
      readString += c; //makes the string readString
    }
    Q = readString;
  }

  
 // Serial.println(Q);
  
   String Q1 = "";
  //------------------------------Check Serial Port--------------------------------------
  while (Serial2.available()) {
    delay(1);  //delay to allow buffer to fill
    if (Serial2.available() > 0) {
      char c = Serial2.read();  //gets one byte from serial buffer
      if (isControl(c)) {
        //'Serial.println("it's a control character");
        break;
      }
      readString2 += c; //makes the string readString
    }
    //Serial.println(readString2);
  }

  Q1 = readString2;
 // Serial.println(Q1);
  
   if (Q == "1") {
    Serial2.println(1);  
     digitalWrite(13, HIGH);   
  }
     if (Q == "0") {
    Serial2.println(0); 
    digitalWrite(13, LOW); 
  }

     if (Q1 == "1") {
    //Serial2.println(1);
    digitalWrite(13, HIGH);   
  }
     if (Q1 == "0") {
   // Serial2.println(0); 
    digitalWrite(13, LOW); 
  }
}

