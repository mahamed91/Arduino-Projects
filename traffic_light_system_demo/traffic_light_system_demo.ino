// Traffic Lights Practice
// Mahamed Ali

// Declare the variables

int ledDelay = 5000;
int carRedLED = 12;
int carYellowLED = 10;
int carGreenLED = 8;
int pedRedLED = 4;
int pedGreenLED = 7;
int button = 2;
int crossTime = 5000;
unsigned long changeTime;

//Initialise the pins
void setup() { 
 pinMode(carRedLED, OUTPUT);
 pinMode(carYellowLED, OUTPUT);
 pinMode(carGreenLED, OUTPUT);
 pinMode(pedRedLED, OUTPUT);
 pinMode(pedGreenLED, OUTPUT);
 pinMode(button, INPUT);
 digitalWrite(carGreenLED,HIGH);
 digitalWrite(pedRedLED,HIGH);
}

void loop() {
 int state = digitalRead(button);
 if (state == HIGH && (millis() - changeTime) > 5000) {
 changeLights();
 }
}

void changeLights() {
 digitalWrite(carGreenLED, LOW); 
 digitalWrite(carYellowLED, HIGH);
 delay(2000); 
 digitalWrite(carYellowLED, LOW); 
 digitalWrite(carRedLED, HIGH);
 delay(1000); 
 digitalWrite(pedRedLED, LOW); 
 digitalWrite(pedGreenLED, HIGH); /
 delay(crossTime); // wait for preset time period

 // flash the ped green
 for (int x=0; x<10; x++) {
   digitalWrite(pedGreenLED, HIGH);
   delay(250);
   digitalWrite(pedGreenLED, LOW);
   delay(250);
 }
 digitalWrite(pedRedLED, HIGH);
 delay(500);
 digitalWrite(carYellowLED, HIGH);
 digitalWrite(carRedLED, LOW); 
 delay(1000);
 digitalWrite(carGreenLED, HIGH);
 digitalWrite(carYellowLED, LOW); 
 // record the time since last change of lights
 changeTime = millis();
}
