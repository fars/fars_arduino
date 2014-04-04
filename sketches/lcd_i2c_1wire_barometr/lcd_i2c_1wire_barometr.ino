  
/*
** DH11 test
 SDA SCL a4 a5 1 wire -2 
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>


#define DHT11PIN 2

#define I2C_ADDR    0x27  
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

dht11 DHT11;

int n = 1;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.begin (16,2);
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                   // go home

  lcd.print(" Hello, FARS");  
}

void loop()
{
  
  int chk = DHT11.read(DHT11PIN);
  lcd.clear();
  lcd.setCursor (0,0);        
  lcd.print("Read sensor: ");
  lcd.setCursor (0,1);
 
  switch (chk)
  {
    case DHTLIB_OK: 
		lcd.print("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		lcd.print("Checksum error"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		lcd.print("Time out error"); 
		break;
    default: 
		lcd.print("Unknown error"); 
		break;
  }
  delay(1000);
 
  lcd.clear(); 
  lcd.setCursor (0,0);        
  lcd.print("Humidity(%):   ");
  lcd.setCursor (0,1);
  lcd.print(DHT11.humidity);
  delay(2000);

  lcd.clear();
  lcd.setCursor (0,0);        
  lcd.print("Temperature(C):");
  lcd.setCursor (0,1);
  //lcd.println((float)DHT11.temperature, 2);
  lcd.print(DHT11.temperature);
  delay(2000);

  
}

