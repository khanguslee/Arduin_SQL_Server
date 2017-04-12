#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
// 518 bytes (25%)
void setup() {
  Serial.begin(9600);
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");
}

void loop() {
  Serial.print(year());
  Serial.print("-");
  printTime(month());
  Serial.print("-");
  printTime(day());
  Serial.print(" ");
  printTime(hour());
  Serial.print(":");
  printTime(minute());
  Serial.print(":");
  printTime(second());
  Serial.println(".000"); 
  delay(1000);
}

void printTime(int digits){
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits,DEC);
}
