void screenHome(){
	dispScreen=1;
	menuPosition = 1;
	lcd.clear();
	lcd.noBlink();
	lcd.noCursor();
	readSettings();
	updateAlarms();
}

void screenSettings(){
	dispScreen=2;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(5,0);
    lcd.print(F("SETTINGS"));
	lcd.setCursor(3,1);
	lcd.print(F("Sensor"));
	lcd.setCursor(3,2);
	lcd.print(F("Schedule"));
	lcd.setCursor(3,3);
	lcd.print(F("Clock"));
	lcd.setCursor(14,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
    lcd.cursor();
    lcd.blink();	
}

void screenSensor(){
	dispScreen=3;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(6,0);
    lcd.print(F("SENSOR"));
	lcd.setCursor(3,1);
	lcd.print(F("Temperature"));
	lcd.setCursor(3,2);
	lcd.print(F("Humidity"));
	lcd.setCursor(8,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenTemp(){
	dispScreen=4;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(4,0);
    lcd.print(F("TEMPERATURE"));
	lcd.setCursor(3,1);
    lcd.print(F("MIN : "));
	lcd.print(heatOn);
	lcd.setCursor(3,2);
    lcd.print(F("MAX : "));
	lcd.print(heatOff);
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(9,1);
	//lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenHum(){
	dispScreen=5;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(6,0);
    lcd.print(F("HUMIDITY"));
	lcd.setCursor(3,1);
    lcd.print(F("MIN : "));
	lcd.print(humOn);
	lcd.setCursor(3,2);
    lcd.print(F("MAX : "));
	lcd.print(humOff);
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(9,1);
	//lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenSchedule(){
	dispScreen=6;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(6,0);
    lcd.print(F("SCHEDULE"));
	lcd.setCursor(3,1);
	lcd.print(F("Light"));
	lcd.setCursor(3,2);
	lcd.print(F("Fan"));	
	lcd.setCursor(8,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenLight(){
	dispScreen=7;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(7,0);
    lcd.print(F("LIGHT"));
	lcd.setCursor(3,1);
	lcd.print(F("ON"));
	lcd.setCursor(7,1);
	print2digits(onLightsH);
	lcd.print(F(":"));
	print2digits(onLightsM);
	lcd.setCursor(3,2);
	lcd.print(F("OFF"));
	lcd.setCursor(7,2);
	print2digits(offLightsH);
	lcd.print(F(":"));
	print2digits(offLightsM);	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(7,1);
	lcd.cursor();
    lcd.blink();
}

void screenFan(){
	dispScreen=8;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(8,0);
    lcd.print(F("FAN"));
	lcd.setCursor(3,1);
	lcd.print(F("ON"));
	lcd.setCursor(7,1);
	print2digits(onFanH);
	lcd.print(F(":"));
	print2digits(onFanM);
	lcd.setCursor(3,2);
	lcd.print(F("OFF"));
	lcd.setCursor(7,2);
	print2digits(offFanH);
	lcd.print(F(":"));
	print2digits(offFanM);	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(7,1);
	lcd.cursor();
  lcd.blink();
}

void screenClock(){  // have add temporary variables to hold time
	dispScreen=9;
	saveRTC.Year = year() - 2000;
    saveRTC.Month = month();
    saveRTC.Day = day();
    saveRTC.Hour = hour();
    saveRTC.Minute = minute();
    saveRTC.Second = 0;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(4,0);
    lcd.print(F("TIME / DATE"));
	lcd.setCursor(3,1);
	lcd.print(F("H  M   M  D  Y"));
	lcd.setCursor(3,2);
	print2digits(hour());
	lcd.print(F(":"));
	print2digits(minute());
	lcd.setCursor(10,2);
	print2digits(month());
    lcd.print(F("-"));
    print2digits(day());
    lcd.print(F("-"));
    lcd.print((year() - 2000));	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(3,2);
	lcd.cursor();
    lcd.blink();
}
