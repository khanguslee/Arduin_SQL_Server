// Ethernet Interface Module TEST
#include <Ethernet.h>
#include <SPI.h>

// Duinotech Ethernet Module
// HanRun HR911105A 16/02
// S1: Master Out Slave in (D11)
// CS: Chip Select (D10)
// VCC: Power (3.3v)
// SO: Master In Slave Out (D12)
// SCK: Serial Clock (D13)
// GND: Ground Connection (GND)

// Grab data from motion sensor and push it into an SQL server

// Declare variables
const int pirPin = 8;       // Pin for pir motion sensor
int pirState = LOW, value = 0;

void setup() {
  pinMode(pirPin, INPUT);   // Declare pir motion sensor as input
  
  Serial.begin(9600);
}

void loop() {
  value = digitalRead(pirPin);  // Read pir motion sensor value
  if (value == HIGH && pirState == LOW){
    Serial.println("Motion Detected");
    pirState = HIGH;
  } else if (value == LOW && pirState == HIGH){
    Serial.println("Motion Ended");
    pirState = LOW;
  }

}
