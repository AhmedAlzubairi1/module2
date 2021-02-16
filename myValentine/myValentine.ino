int potPin=2;
int switchPin=53;
int rightButtonPin=49;
int leftButtonPin=51;
int leds [8] = { 2, 3, 4, 5, 6, 7, 8, 9}; 
int ledsLimits[8] = {30, 60, 90, 120, 150, 180, 210, 240};

void setup() {
  Serial.begin(9600);
   pinMode(switchPin,INPUT);
      pinMode(rightButtonPin,INPUT_PULLUP);
      //Push Buttons are 0 at press, 1 at not pressed

      pinMode(leftButtonPin,INPUT_PULLUP);
      // Left side
      pinMode(2,OUTPUT);
      pinMode(3,OUTPUT);
      pinMode(4,OUTPUT);
      pinMode(5,OUTPUT);


      //Right side
      
      pinMode(6,OUTPUT);
      pinMode(7,OUTPUT);
      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);

      // green LEDs

      pinMode(47,OUTPUT);
      pinMode(45,OUTPUT);

      // Blue led
      pinMode(43,OUTPUT);
      

}
void turnOffLeds(int dir, int value){
// turn off all values greater than it.
  if (dir ==0){
    Serial.println("Clockwise");
    for (int i=0; i<=7;i++){
      //check if I didn't pass that location.
      if ( ledsLimits[i]>value){
        
        Serial.print(ledsLimits[i]);
        Serial.print(" is > ");
        Serial.print(value);
        Serial.print(" turning OFF led:");
        Serial.println(leds[i]);
        digitalWrite(leds[i],LOW);
      }
    }
    // clock wise direction
  }
  else{
    Serial.println("Counter Clockwise");
    // Counter clockwise direction
    // here I need to go backwrods
    int start=0;
    for (int i=7; i>=0;i--){
      //check if I passed that location.
      if (ledsLimits[start]>value){
        digitalWrite(leds[i],LOW);
        
      }
      start++;
      
    }
  }


}
void turnOnLeds(int dir, int value){

  if (dir ==0){
    Serial.println("Clockwise");
    for (int i=0; i<=7;i++){
      //check if I passed that location.
      if ( ledsLimits[i]<=value){
        
        Serial.print(ledsLimits[i]);
        Serial.print(" is <= ");
        Serial.print(value);
        Serial.print(" turning on led:");
        Serial.println(leds[i]);
        digitalWrite(leds[i],HIGH);
      }
    }
    // clock wise direction
  }
  else{
    Serial.println("Counter Clockwise");
    // Counter clockwise direction
    // here I need to go backwrods
    int start=0;
    for (int i=7; i>=0;i--){
      //check if I passed that location.
      if (ledsLimits[start]<=value){
        digitalWrite(leds[i],HIGH);
        
      }
      start++;
      
    }
  }
  
}

void blinkLights(int left, int right){
  if (left == 1){
    // Do Sideways Green led when blue button is clicked
    digitalWrite(47,HIGH);
    delay(100);
    digitalWrite(47,LOW);
    delay(100);
    // If right one is also clicked, I should also turn it on
    if (right==1){
      digitalWrite(43,HIGH);
      delay(100);
      digitalWrite(43,LOW);
      delay(100);

    }
    digitalWrite(45,HIGH);
    delay(100);
    digitalWrite(45,LOW);
    delay(100);
    

  }
  else{
    if (right ==1){
      // Blink blue led
    
    digitalWrite(43,HIGH);
    delay(100);
    digitalWrite(43,LOW);
    delay(100);


    
    }
  }
}
void loop() {
  
  int val = analogRead(potPin);
  int potValue = map(val, 0, 1024, 0, 255);
  int switchValue=digitalRead(switchPin);
  int rightButtonVal= ! digitalRead(rightButtonPin);
  int leftButtonVal= ! digitalRead(leftButtonPin);

  Serial.print(potValue);
  Serial.print(",");
  Serial.print(switchValue);
  Serial.print(",");
  Serial.print(leftButtonVal);
  Serial.print(",");
  Serial.print(rightButtonVal);
  Serial.print("\n");
  // First I reset the leds
  turnOffLeds(switchValue,potValue);
  // THen turn on the ones I want
  turnOnLeds(switchValue,potValue);
  // Now see if the person clicked the buttons
  blinkLights(leftButtonVal,rightButtonVal);
 // delay(4000);
 
 
}
