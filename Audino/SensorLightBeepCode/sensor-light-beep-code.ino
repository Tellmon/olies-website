const  int red = 9; //red led
const  int yellow = 12; // yellow led
const  int green = 10; // green led
const  int blue = 11; // blue led
const  int echo = 6; // echo side
const  int trig = 7; // triggure side
const int buzz = 8;

float duration, distance;
int frequence;


void setup() {
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() {
  float distance = getDistance();
  //Serial.print(distance);
  //Serial.println("loop");

  if (distance < 10){
    Serial.println("red");
    activate(red);
    frequence = 1600;
  }

  else if (distance < 20){
    Serial.println("yellow");
    activate(yellow);
    frequence = 1400;
  }

  else if (distance < 30){
    activate(green);
    Serial.println("green");
    frequence = 1200;
  }

  else{
    activate(blue);

    Serial.println("blfue");
    frequence = 1000;
  }

  delay(100);

  for(int i = 8; i < 13; i ++ ){
    //Serial.print(i);
    digitalWrite(i, LOW);
  }
  delay(100);

  tone(buzz, frequence, 1000);
  
  // check if delay works aswell
  
}

void activate(int colour){
  digitalWrite(colour, true);
  //Serial.println("activate");
}

float getDistance(){
  //Serial.println("distance");
  digitalWrite(trig, HIGH); // makes sure its off
  delayMicroseconds(10);
  digitalWrite(trig, LOW); // sends pulse
  //delayMicroseconds(10);// sends pulse for 10 ms
  //digitalWrite(trig, LOW); // turns pulse off

  //  time it takes for sound to leave and come back and stored at durataion 
  duration = pulseIn(echo, HIGH); 

  // uses S * T = D where S is speed of sound in air and /2 as double distance
  distance = (duration*.0343)/2;

  return distance;
}

