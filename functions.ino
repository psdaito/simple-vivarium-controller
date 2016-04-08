// functions and alarms
void checkTandH(){
  
  h = dht.readHumidity();
  t = dht.readTemperature(true);  //if using celsius t = dht.readTemperature();
  //int hif = dht.computeHeatIndex(t, h);  // heat index
    
  if (isnan(h) || isnan(t))
  {
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("SENSOR ERROR"));
  alarmFogOff();
  alarmHeatOff();
  }
  else
  {

  int intt = t;
  int inth = h;
     
	  if(inth < humOn)
	  {
		alarmFogOn();
	  }
	  else if(inth > humOff)
	  {
		alarmFogOff();
	  }

    if(intt < heatOn)
    {
    alarmHeatOn();
    }
    else if(intt > heatOff)
    {
    alarmHeatOff();
    }

	if(dispScreen == 1){ //display temp and hum only if home screen is active
		printHum();
		printTemp(); 
	}    
  //lcd.setCursor(1,3);
  //lcd.print(freeRam());
  }
}

int checkJoystick()
{
  int joystickState = analogRead(3);
  // need to calibrate before use !!!!
  if (joystickState < 50) return Left;
  if (joystickState < 150) return Down;
  if (joystickState < 250) return Press;
  if (joystickState < 500) return Right;
  if (joystickState < 650) return Up;
  return Neutral;
}

void updateCursor(int x, int y, int x1, int y1, int arrow){
	if(arrow == 1) // remove arrow  move cursor add arrow
	{
	lcd.setCursor(x, y);
	lcd.print(" ");
	lcd.setCursor(x1, y1);
	lcd.print(">");
	}
	else if(arrow == 2) // move cursor only
    {
    lcd.setCursor(x1, y1);	
    }
	else if(arrow == 3) // remove arrow move cursor
	{
	lcd.setCursor(x, y);
	lcd.print(" ");
	lcd.setCursor(x1, y1);	
	}
	else if(arrow == 4)
	{
	lcd.setCursor(x1, y1); //move cursor add arrow
	lcd.print(">");	
	}
}

void print2digitsXY(int number, int posX, int posY) {
	 lcd.setCursor(posX,posY);
  if (number <= 0 && number < 10) {
	lcd.print(0);
	lcd.print(number);
  }
  else{
	lcd.print(number);
  } 
}


void print2digits(int number) {
  if (number <= 0 && number < 10) {
	lcd.print(0);
	lcd.print(number);
  }
  else{
	lcd.print(number);
  } 
}


// LCD print functions
void printHum(){
  lcd.setCursor(1,2);
  lcd.write(byte(3));
  lcd.setCursor(3,2);
  lcd.print(h,1);
  lcd.print(F("%"));
    if(h < 65){
	   lcd.setCursor(9,2);
       lcd.print(F("!"));
  }
  else{
	  lcd.setCursor(9,2);
      lcd.print(F(" "));
  }
}

void printTemp(){
  lcd.setCursor(1,1);
  lcd.write(byte(2));
  lcd.setCursor(3,1);
  lcd.print(t,1);
  lcd.write(byte(4));
  //lcd.write(0b11011111); // deg character
  //lcd.print(F("F"));
  if(t > (heatOff + 4)){
	   lcd.setCursor(9,1);
       lcd.print(F("!"));
  }
  else{
	  lcd.setCursor(9,1);
      lcd.print(F(" "));
  }
	
}

/*
void printTime(){
  lcd.setCursor(0,0);
  lcd.print(hour());
  lcd.print(F(":"));
  newMinute = minute();
  if(newMinute < 10) lcd.print(0);
  lcd.print(newMinute);
  // date
  lcd.setCursor(13,0);
  lcd.print(month());
  lcd.print(F("."));
  lcd.print(day());
  lcd.print(F("."));
  lcd.print((year() - 2000));
  
}
*/

void printStatus(){
	if(dispScreen == 1){ // show only if home screen
		
	// light status
	lcd.setCursor(8,3);
	lcd.write(byte(5));
	lcd.setCursor(10,3);
	if(powerLight){
		lcd.print(F("On "));
	}
	else
	{
		lcd.print(F("Off"));
	}

	// fogger status
	lcd.setCursor(14,2);
	lcd.write(byte(6));
	lcd.setCursor(16,2);
	if(powerFogger){
		lcd.print(F("On "));
	}
	else
	{
		lcd.print(F("Off"));
	}
	
	// heater status
	lcd.setCursor(14,1);
	lcd.write(byte(0));
	lcd.setCursor(16,1);
	if(powerHeat){
    lcd.print(F("On "));
	}
	else
	{
		lcd.print(F("Off"));
	}

	// fan status
	lcd.setCursor(14,3);
	lcd.write(byte(1));
	lcd.setCursor(16,3);
	if(powerFan){
		lcd.print(F("On "));
	}
	else
	{
		lcd.print(F("Off"));
	}
				
  }
	
}



void logger(){
  if(t > maxT){
    maxT = t;
   }
   else 
   {
    if(t < minT) minT = t;
   }

   if(h > maxH){
    maxH = h;
   }
   else 
   {
    if(h < minH) minH = h;
   }
}

// Alarms On - Off
void alarmFogOn(){
  digitalWrite(relayFog, LOW);
  powerFogger = true;
}

void alarmFogOff(){
  digitalWrite(relayFog, HIGH);
  powerFogger = false;  
}

void alarmHeatOn(){
  digitalWrite(relayHeat, LOW);
  powerHeat = true;
}

void alarmHeatOff(){
  digitalWrite(relayHeat, HIGH);
  powerHeat = false;  
}

void alarmLightOn(){
  digitalWrite(relayLight, LOW);
  powerLight = true;
} 
   
void alarmLightOff(){
  digitalWrite(relayFog, HIGH);
  powerLight = false;
}

void alarmFanOn(){
  digitalWrite(relayFan, LOW);
  powerFan = true;
} 
   
void alarmFanOff(){
  digitalWrite(relayFan, HIGH);
  powerFan = false;
}


int freeRam()
{
  // Returns available SRAM
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
