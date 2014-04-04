/*
  LED Blink
  
 */
 
// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

void setup() 
{                
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   
  delay(300);               
  digitalWrite(led, LOW);    
  delay(300);               
}
