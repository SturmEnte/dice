const int BUTTON = 2;
const int START_PIN = 3;
const int END_PIN = 9;

// If this is enabled, will the dice never display the same value as the last one
const bool LESS_RANDOM = true;

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
}

void loop() {
    if(digitalRead(BUTTON) != LOW) {
        return;
    }

    int randomNumber;
    do {
        // Generate a number from 0 to 5
        randomNumber = random(0, 6);
    } while(LESS_RANDOM && randomNumber == lastNumber);
 
    // Display the number
    for(int i = 0; i < 7; i++) {
        digitalWrite(START_PIN + i, NUMBERS[randomNumber][i]);  
    }

    lastNumber = randomNumber;
    delay(250);
}
