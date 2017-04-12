#include <Wire.h>
#include <RtcDS1307.h>
RtcDS1307<TwoWire> Rtc(Wire);
// 442 bytes (21%)
void setup() {
  Serial.begin(9600);
  Rtc.Begin();
  // Set the RTC time and date
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  Rtc.SetDateTime(compiled);
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  // Print out in format 2000-01-01 00:00:00.000
  // Note that we can not get milliseconds so will always be 000 ms
  Serial.print(now.Year(), DEC);
  Serial.print("-");
  printTime(now.Month());
  Serial.print("-");
  printTime(now.Day());
  Serial.print(" ");
  printTime(now.Hour());
  Serial.print(":");
  printTime(now.Minute());
  Serial.print(":");
  printTime(now.Second());
  Serial.println(".000");
  delay(1000);
}

void printTime(int digits){
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits, DEC);
}
