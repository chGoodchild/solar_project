// This sollenoid valve will allow people in a public place to 
// water plants by pressing a button. The longer they press the
// button the longer the valve remains open.

int outputPin = 3;
int inputPin = 2;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
}

void loop() {
  static int counter;
  counter = 0;

  while(digitalRead(inputPin) == 0) {
    // The valve will stay open for maximum 10 seconds.
    if(counter <= 10) {
      // Toggle the valve to indicate that the counter is
      // being incremented.
      if(digitalRead(inputPin) == 1) break;
      digitalWrite(outputPin, !digitalRead(outputPin));
      delay(50);
      if(digitalRead(inputPin) == 1) break;
      digitalWrite(outputPin, !digitalRead(outputPin));
      delay(450);
      counter++;
    } else {
      // Break if the user decides it's enough water.
      break;
    }
  }

  // Open the valve and hold it.
  digitalWrite(outputPin, 1);
  delay(counter * 1000);

  // Let the valve cool down and prevent people 
  // from watering too much.
  digitalWrite(outputPin, 0);
  delay(counter * 10000);
}
