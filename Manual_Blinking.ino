#include <SoftwareSerial.h>

//THIS IS FOR BLINKING THE BUILT IN LED
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Write the Number");
  delay(5000);

  if (Serial.available() != 0) {
    int number = Serial.parseInt();
    Serial.println(number);

    for (int i = 0; i < number; i++) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("ON");
      delay(2000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(2000);                       // wait for a second
    }
  }
  else {
    Serial.println("No Input");
  }
  exit(0);
}
