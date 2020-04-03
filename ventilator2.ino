//Spark Vent relay operation using Arduino
//Cycles relay(s) off for double the time they are on
//On time is adjustable with potentiometer
//
// Jeremy Funke March 2020

//time in milliseconds
#define INHALE_MIN 400
#define INHALE_MAX 4000

//The relay connections
#define VALVE_PIN 7
#define VALVE_PIN2 2

//The potentiometer wiper
#define POT_PIN A0

#define LED_PIN 13

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize pins
  pinMode(VALVE_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  float sensor = analogRead(POT_PIN); //read voltage of potentiometer

  //scale reading to minmax
  int inhale = ((INHALE_MAX - INHALE_MIN) * (sensor / 1024.0)) + INHALE_MIN;
  
  Serial.print(sensor);
  Serial.print(" knob = inhale for "); 
  Serial.print(inhale);
  Serial.println(" ms"); //print findings to serial console to check potentiometer is working as expected
  
  digitalWrite(LED_PIN, HIGH); // turn the relay on
  digitalWrite(VALVE_PIN, HIGH);
  digitalWrite(VALVE_PIN2, LOW);    
  delay(inhale);            // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the  relay off
  digitalWrite(VALVE_PIN, LOW);
  digitalWrite(VALVE_PIN2, HIGH);
  delay(inhale*2);                       // wait for a 2 seconds
}
