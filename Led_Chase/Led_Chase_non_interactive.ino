// LED Chase 
// Mahamed Ali
byte ledPin[] = {4, 7, 8, 10, 12};
int ledDelay(85);
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; 

void setup() {
 for (int x=0; x<10; x++) {
 pinMode(ledPin[x], OUTPUT); }
 changeTime = millis();
}

void loop() {
 // if it has been ledDelay ms since last change
 if ((millis() - changeTime) > ledDelay) {
 changeLED();
 changeTime = millis();
 }
}

void changeLED() {
 for (int x=0; x<10; x++) {
 digitalWrite(ledPin[x], LOW);
 }
 // turn on the current LED
 digitalWrite(ledPin[currentLED], HIGH);
 currentLED += direction;
 // change direction if we reach the end
 if (currentLED == 5) {direction = -1;}
 if (currentLED == 0) {direction = 1;}
}
