#include <RTClib.h>
#include <Wire.h>
RTC_DS1307 rtc;
// Test code for DS1307 Data logger shield for Arduino
// 459 bytes (22%)

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()){
    Serial.println("Could not find RTC");
  }

  // Sets RTC with the connected compiled computer date and time
  if (!rtc.isrunning()){
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() {
  // Get the current date and time
  DateTime start = rtc.now();

  // Print out in format 2000-01-01 00:00:00.000
  // Note that we can not get milliseconds so will always be 000 ms
  Serial.print(start.year(), DEC);
  Serial.print("-");
  printTime(start.month());
  Serial.print("-");
  printTime(start.day());
  Serial.print(" ");
  printTime(start.hour());
  Serial.print(":");
  printTime(start.minute());
  Serial.print(":");
  printTime(start.second());
  Serial.println(".000");
  delay(1000);
}

void printTime(int digits){
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits, DEC);
}
