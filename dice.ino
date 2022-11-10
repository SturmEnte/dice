const int BUTTON = 2;
const int START_PIN = 3;
const int END_PIN = 9;

const bool LESS_RANDOM = true;

const int NUMBERS[6][7] = {
    {LOW, LOW, LOW, HIGH, LOW, LOW, LOW},         // 1 
    {HIGH, LOW, LOW, LOW, HIGH, LOW, LOW},        // 2 
    {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH},       // 3  
    {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH},      // 4  
    {HIGH, LOW, HIGH, HIGH, HIGH, LOW, HIGH},     // 5 
    {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH}     // 6 
};

void setup() {
    pinMode(BUTTON, INPUT);
    for(int i = START_PIN; i <= END_PIN; i++) {
        pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
}

int lastNumber = -1;

void loop() {
    if(digitalRead(BUTTON) != LOW) {
        return;
    }

    int randomNumber;
    do {
      randomNumber = random(0, 6);
      Serial.println(randomNumber);
    } while(LESS_RANDOM && randomNumber == lastNumber);
 
    for(int i = 0; i < 7; i++) {
        digitalWrite(START_PIN + i, NUMBERS[randomNumber][i]);  
    }

    lastNumber = randomNumber;
    delay(250);
}
