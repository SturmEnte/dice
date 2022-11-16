const int BUTTON = 2;
const int START_PIN = 3;
const int END_PIN = 9;

// If this is enabled, will the dice never display the same value as the last one
const bool LESS_RANDOM = true;

const int ANIM_NUMS = 15;
const int ANIM_START_DELAY = 100;
const int ANIM_END_DELAY = 1000;
const int ANIM_BLINKS = 3;

// An array of all numbers and which leds should be turned on in ordner to display the numbers right
const int NUMBERS[6][7] = {
    {LOW, LOW, LOW, HIGH, LOW, LOW, LOW},         // 1 
    {HIGH, LOW, LOW, LOW, HIGH, LOW, LOW},        // 2 
    {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH},       // 3  
    {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH},      // 4  
    {HIGH, LOW, HIGH, HIGH, HIGH, LOW, HIGH},     // 5 
    {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH}     // 6 
};

int lastNumber = -1;

void setup() {
    pinMode(BUTTON, INPUT);
    for(int i = START_PIN; i <= END_PIN; i++) {
        pinMode(i, OUTPUT);
    }

    startAnimation(200);
}

void loop() {
    if(digitalRead(BUTTON) != LOW) {
        return;
    }

    int delaySteps = (ANIM_START_DELAY - ANIM_END_DELAY) / ANIM_NUMS;
    int d = ANIM_START_DELAY;

    for(int i = 0; i <= ANIM_NUMS; i++) {
      randomNumber();
      delay(d);
      d -= delaySteps;
    }
    
    lastNumber = randomNumber();
    for(int i = 0; i <= ANIM_BLINKS; i++) {
      for(int j = START_PIN; j <= END_PIN; j++) {
        digitalWrite(j, LOW);
      }
      delay(200);
      displayNumber(lastNumber);
      delay(200);
    }
}

int randomNumber() {
  int randomNumber;
  do {
    // Generate a number from 0 to 5
      randomNumber = random(0, 6);
  } while(LESS_RANDOM && randomNumber == lastNumber);
  
  // Display the number
  displayNumber(randomNumber);
  
  return randomNumber;
}

void displayNumber(int number) {
  for(int i = 0; i < 7; i++) {
      digitalWrite(START_PIN + i, NUMBERS[number][i]);  
  }
}

void startAnimation(int d) {
  digitalWrite(3, HIGH);
  delay(d);
  digitalWrite(3, LOW);
  delay(d);
  digitalWrite(9, HIGH);
  delay(d);
  digitalWrite(9, LOW);
  delay(d);
  digitalWrite(4, HIGH);
  delay(d);
  digitalWrite(4, LOW);
  delay(d);
  digitalWrite(8, HIGH);
  delay(d);
  digitalWrite(8, LOW);
  delay(d);
  digitalWrite(5, HIGH);
  delay(d);
  digitalWrite(5, LOW);
  delay(d);
  digitalWrite(7, HIGH);
  delay(d);
  digitalWrite(7, LOW);
  delay(d);
  digitalWrite(6, HIGH);
  delay(d);
  digitalWrite(6, LOW);
}
