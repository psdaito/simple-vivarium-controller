/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS "AS IS" AND ANY EXPRESS OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.  
 */
// Simple Vivarium Controller 
// Written by Peter Stalonczyk, aka Cairo @ dendroboard.com
// This controller is inspired by iAqua & Mr.Aqua  by Dan Cunningham, aka AnotherHobby @ plantedtank.net and Ryan Truss, aka MrMan @ plantedtank.net
// Much code was swiped, modified, and integrated or otherwise inspired from other public works
// All code is public domain, feel free to use, edit, and share
// Written for Arduino Uno
// VERSION:  1.0
// - initial version

#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <EEPROM.h> // Comes with Arduino IDE
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

// uncomment for debuging
#define DEBUG  

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
DHT dht(DHTPIN, DHTTYPE);

//global variables
int newMinute = 0;
float h, t ;
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
boolean powerFan = false;
byte heatOff = 78;
byte heatOn = 72;
byte humOff = 86;
byte humOn = 80;   //humiditi alarm humOn - 10
byte onLightsH = 10; //lights on 10 am
byte offLightsH = 22; // lights off 10 pm
byte onLightsM = 0; //lights on minute10 am
byte offLightsM = 0; // lights off 10 pm
byte onFanH = 1; //lights on 10 am
byte offFanH = 29; // lights off 10 pm
byte onFanM = 0; //lights on minute10 am
byte offFanM = 0; // lights off 10 pm
float minT = 100;
float maxT = 0;
float minH = 101;
float maxH = 0;

//time varaibles
time_t lastUpdateTime = 0; // track 5 seconds for refreshing clock and temp/hum
time_t lastCheckTime = 0;
time_t dimTime = 0; // used for brightness adjustment
time_t homeTime = 0; // used for returning home after configured time
//Screens And menu
const int Neutral = 0;
const int Press = 1;
const int Up = 2;
const int Down = 3;
const int Right = 4;
const int Left = 5;
byte dispScreen=1;
int menuPosition=1; // keep track what is edited now
int buttonAction=0; 
/* 1- home
	2- settings
		3- sensors mp1
			4- temperature mp1
			5- humidity mp2
		6- schedule mp2
			7- light sachedule mp1
			8- fan sachedule mp2	
	    9- clock mp1
*/
void setup() 
{ 
  // set default values for the first ever run
  firstRunSetup();
  
  #ifdef DEBUG
	Serial.begin(9600);
	delay(100);
  #endif
  
  #ifdef DEBUG
	Serial.println("Start debug");
  #endif
  
  
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
  lastUpdateTime = now();
  lastCheckTime = now();
  
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
  
  // read settings from eeprom
  readSettings();
  //load power schedule
  loadSchedule();
  //load home screen
  screenHome();
}


void loop()  
{
  unsigned long currentMillis = millis(); // get current millis
  time_t currentTime = now();
	
  if(now() - lastUpdateTime >= 3)  //runs every 3sec
  {
    lastUpdateTime=now();
    checkTandH();
    printStatus();
  }

  
  if(now() != lastCheckTime) // runs every sec
  {
    lastCheckTime=now();
	if(dispScreen == 1){
	  updateTimeDate(false);//passing false results in updating screen only if time or date has changed
	}
  }
  menuActions(); 
  Alarm.delay(10);
}

void updateTimeDate(boolean updateTime)
{
  // draw date and time
  if ((hour()!=prevRTC.Hour) || (minute()!=prevRTC.Minute) || updateTime) {
    prevRTC.Hour = hour();
    prevRTC.Minute = minute();
	 lcd.setCursor(0,0);
    lcd.print(hour());
    lcd.print(F(":"));
    newMinute = minute();
    if(newMinute < 10) lcd.print(0);
    lcd.print(newMinute);   
  }

  if ((day()!=prevRTC.Day) || (month()!=prevRTC.Month) || updateTime) {
    prevRTC.Day = day();
    prevRTC.Month = month();
    lcd.setCursor(13,0);
    lcd.print(month());
    lcd.print(F("."));
    lcd.print(day());
    lcd.print(F("."));
    lcd.print((year() - 2000));             
  }
}

void SaveTime()
{
  time_t saveTime = makeTime(saveRTC);
  setTime(saveTime);
  RTC.set(saveTime);
  if(dispScreen == 1){
	  updateTimeDate(true);
  }
}
time_t tmConvert_t(int YYYY, byte MM, byte DD, byte hh, byte mm, byte ss)
{
  tmElements_t tmSet;
  tmSet.Year = YYYY - 1970;
  tmSet.Month = MM;
  tmSet.Day = DD;
  tmSet.Hour = hh;
  tmSet.Minute = mm;
  tmSet.Second = ss;
  return makeTime(tmSet);         //convert to time_t
}


 

