const int analogPin=A0;
const int ledCount=10;
int ledPins[]={
  2,3,4,5,6,7,8,9,10,11
  };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int thisLed=0;thisLed<ledCount;thisLed++){
    pinMode(ledPins[thisLed],OUTPUT);
    }
}

void loop() {
int aRead=analogRead(A0);

Serial.println(aRead);

  int sensorReading = analogRead(analogPin);
  if(sensorReading<450){
    sensorReading=450;
  }else if(sensorReading>800){
    sensorReading=800;
    }
  int ledLevel = map(sensorReading, 450, 800, 0, ledCount);

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
   
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
delay(1);
  }
}
