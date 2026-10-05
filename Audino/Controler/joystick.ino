#define ANALOG_X_PIN A2 
#define ANALOG_Y_PIN A3 
#define ANALOG_BUTTON_PIN A4 
	 
//Default values when axis not actioned 
#define ANALOG_X_CORRECTION 128 
#define ANALOG_Y_CORRECTION 128 

String  movment = ""; 	

struct button { 
	 byte pressed = 0; 
}; 
	 
struct analog { 
	 short x, y; 
	 
	 button button; 
}; 
	 
void setup() 
{ 
	 pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP); 
	 
	 Serial.begin(9600); 
} 
	 
void loop() 
{ 
	analog analog; 
	 
	analog.x = readAnalogAxisLevel(ANALOG_X_PIN) - ANALOG_X_CORRECTION; 
	analog.y = readAnalogAxisLevel(ANALOG_Y_PIN) - ANALOG_Y_CORRECTION; 
	analog.y -= 3;

	analog.button.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN); 

  movment = "";

  if(analog.y > 0){
    movment += "U";
  }

  else if(analog.y < 0){
    movment += "D";
  }

  if(analog.x > 0){
    movment += "L";
  }

  else if(analog.x < 0){
    movment += "R";
  }

  if (analog.button.pressed) { 
	  movment = " ";
	} 

  if(movment == ""){
    movment = "None";
  }

  Serial.println(movment);
	 
	
	 
	delay(200); 
} 
	 
byte readAnalogAxisLevel(int pin) 
{ 
	 return map(analogRead(pin), 0, 1023, 0, 255); 
} 
	 
bool isAnalogButtonPressed(int pin) 
{ 
	 return digitalRead(pin) == 0; 
} 
