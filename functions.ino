// functions and alarms
void checkTandH(){
  
  h = dht.readHumidity();
  f = dht.readTemperature(true);  //if using celsius f = dht.readTemperature();
  //int hif = dht.computeHeatIndex(f, h);  // heat index
    
  if (isnan(h) || isnan(f))
  {
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("SENSOR ERROR"));
  alarmFogOff();
  alarmHeatOff();
  }
  else
  { 
	  if(h < humOn)
	  {
		alarmFogOn();
	  }
	  else if(h > humOff)
	  {
		alarmFogOff();
	  }
	  else
	  {
		// to do
	  }

    if(f < heatOn)
    {
    alarmHeatOn();
    }
    else if(f > heatOff)
    {
    alarmHeatOff();
    }
    else
    {
    // to do
    }
  printHum();
  printTemp();  
  lcd.setCursor(1,3);
  lcd.print(freeRam());
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
  lcd.print(f,1);
  lcd.write(byte(4));
  //lcd.write(0b11011111); // deg character
  //lcd.print(F("F"));
  if(f > (heatOff + 4)){
	   lcd.setCursor(9,1);
       lcd.print(F("!"));
  }
  else{
	  lcd.setCursor(9,1);
      lcd.print(F(" "));
  }
	
}

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

void printLight(){
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
	
}

void printFog(){
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
	
}

void printHeat(){
  lcd.setCursor(14,1);
  lcd.write(byte(0));
  lcd.setCursor(16,1);
  if(powerFogger){
    lcd.print(F("On "));
  }
  else
  {
    lcd.print(F("Off"));
  }
  
}

void printFan(){
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


void logger(){
  if(f > maxT){
    maxT = f;
   }
   else 
   {
    if(f < minT) minT = f;
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
