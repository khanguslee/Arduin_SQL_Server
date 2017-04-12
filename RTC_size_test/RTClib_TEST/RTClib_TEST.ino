#include <RTClib.h>
#include <Wire.h>
RTC_DS1307 rtc;
// Test code for DS1307 Data logger shield for Arduino
// 459 bytes (22%)

int time_month;
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
  DateTime now = rtc.now();

  // Print out in format 2000-01-01 00:00:00.000
  // Note that we can not get milliseconds so will always be 000 ms
  Serial.print(now.year(), DEC);
  Serial.print("-");
  printTime(now.month());
  Serial.print("-");
  printTime(now.day());
  Serial.print(" ");
  printTime(now.hour());
  Serial.print(":");
  printTime(now.minute());
  Serial.print(":");
  printTime(now.second());
  Serial.println(".000");
  delay(1000);
}

void printTime(int digits){
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits, DEC);
}
