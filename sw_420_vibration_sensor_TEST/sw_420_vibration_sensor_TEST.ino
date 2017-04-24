const int vibrationPin = 8;
int value = 0, previous_value = 0;

int prev_count, current_count;
const int threshold = 500;
boolean value_flag = false;
void setup() {
  pinMode(vibrationPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = digitalRead(vibrationPin);
  
  if (previous_value != value){
    current_count += 1;
  } else {
    prev_count += 1;
  }
  
  // Change value
  if (current_count == threshold ){
    previous_value = value;
    current_count = 0;
    prev_count = 0;
  } else if (prev_count == threshold){
    current_count = 0;
    prev_count = 0;
  }
  Serial.print(previous_value);
  Serial.print(",");
}
