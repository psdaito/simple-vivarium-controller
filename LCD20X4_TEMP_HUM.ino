#include <EEPROM.h>


#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <TimeAlarms.h>

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
DHT dht(DHTPIN, DHTTYPE);

//global variables
int newMinute = 0;
float h, f ;
float h1 = 0;
float f1 = 0;
tmElements_t prevRTC, saveRTC;
 //a custom HEX character
uint8_t heat[8] = {0x09,0x12,0x12,0x09,0x09,0x12,0x12,0x00};
uint8_t fan[8] = {0x00,0x0E,0x15,0x1F,0x15,0x0E,0x00,0x00};
uint8_t custom_T[8] = {0x04,0x0A,0x0A,0x0E,0x0E,0x1F,0x1F,0x0E};
uint8_t custom_H[8] = {0x04,0x04,0x0A,0x0A,0x11,0x11,0x11,0x0E};
uint8_t degF[8] = {0x18,0x18,0x00,0x07,0x04,0x06,0x04,0x04};  // deg celsius {0x18,0x18,0x00,0x03,0x04,0x04,0x04,0x03}
uint8_t light[8] = {0x0E,0x11,0x11,0x11,0x0E,0x0E,0x0E,0x04};
uint8_t fog[8] = {0x00,0x0D,0x12,0x00,0x0D,0x12,0x00,0x00};
//pins
const int relayLight = 4;
const int relayFog = 5;
const int relayHeat = 6;
const int relayFan = 7;

// light and fogger status
boolean powerLight = false;
boolean powerHeat = false;
boolean powerFogger = false;
boolean powerFan = true;
byte heatOff = 78;
byte heatOn = 72;
byte humOff = 86;
byte humOn = 80;   //humiditi alarm humOn - 10
byte onLights = 10; //lights on 10 am
byte offLights = 22; // lights off 10 pm
float minT = 100;
float maxT = 0;
float minH = 101;
float maxH = 0;

void setup() 
{ 
  setSyncProvider(RTC.get);
  delay(100);
  //Serial.begin(9600); // needed only for debug
  //delay(100); 
  if(timeStatus()!= timeSet)
  {
    saveRTC.Year = 45;
    saveRTC.Month = 1;
    saveRTC.Day = 1;
    saveRTC.Hour = 6;
    saveRTC.Minute = 0;
    saveRTC.Second = 0;
    RTC.set(makeTime(saveRTC));
    setTime(makeTime(saveRTC));
    delay(500);
  }
  lcd.begin(20,4);         // initialize the lcd for 20 chars 4 lines
  lcd.createChar(0, heat);  // load custom icons
  lcd.createChar(1, fan);
  lcd.createChar(2, custom_T);
  lcd.createChar(3, custom_H);
  lcd.createChar(4, degF);
  lcd.createChar(5, light);
  lcd.createChar(6, fog);
  dht.begin();
  
  //set hihg to avoid relay clicking before checking status
  digitalWrite(relayLight, HIGH);
  digitalWrite(relayHeat, HIGH); 
  digitalWrite(relayFog, HIGH); 
  //set pins
  pinMode(relayLight, OUTPUT);
  pinMode(relayHeat, OUTPUT);
  pinMode(relayFog, OUTPUT);
  pinMode(relayFan, OUTPUT);
  
  // start fan
  digitalWrite(relayFan, LOW); 
  //alarms
  //Alarm.timerRepeat(10, ledOn); // test alarm
  loadSchedule();
 
}


void loop()  
{
  Alarm.delay(2500);
  checkTandH();
  printTime();
  printLight();
  printFog();
  printHeat();
  printFan();
}




 

