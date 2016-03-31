void screenHome(){
	dispScreen=1;
	menuPosition = 1;
	lcd.clear();
	lcd.noBlink();
	lcd.noCursor();
	heatOn = EEPROM.read(1);
	heatOff = EEPROM.read(2);
	humOn = EEPROM.read(3);
	humOff = EEPROM.read(4);
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
	lcd.setCursor(8,0);
    lcd.print(F("LIGHT"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenFan(){
	dispScreen=8;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(8,0);
    lcd.print(F("FAN"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}

void screenClock(){
	dispScreen=9;
	menuPosition = 1;
	lcd.clear();
	lcd.setCursor(4,0);
    lcd.print(F("TIME / DATE"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
	lcd.cursor();
    lcd.blink();
}
