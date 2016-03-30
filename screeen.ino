void screenHome(){
	dispScreen=1;
	lcd.clear();
}

void screenSettings(){
	dispScreen=2;
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
}

void screenSensor(){
	dispScreen=3;
	lcd.clear();
	lcd.setCursor(6,0);
    lcd.print(F("SENSOR"));
	lcd.setCursor(3,1);
	lcd.print(F("Temperature"));
	lcd.setCursor(3,2);
	lcd.print(F("Humidity"));
	lcd.setCursor(1,1);
	lcd.print(F(">"));
}

void screenTemp(){
	dispScreen=4;
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
}

void screenHum(){
	dispScreen=5;
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
}

void screenSchedule(){
	dispScreen=6;
	lcd.clear();
	lcd.setCursor(6,0);
    lcd.print(F("SCHEDULE"));
	lcd.setCursor(3,1);
	lcd.print(F("Light"));
	lcd.setCursor(3,2);
	lcd.print(F("Fan"));
	lcd.setCursor(1,1);	
	lcd.setCursor(8,3);
	lcd.print(F("EXIT"));
	lcd.print(F(">"));
}

void screenLight(){
	dispScreen=7;
	lcd.clear();
	lcd.setCursor(8,0);
    lcd.print(F("LIGHT"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
}

void screenFan(){
	dispScreen=8;
	lcd.clear();
	lcd.setCursor(8,0);
    lcd.print(F("LIGHT"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
}

void screenClock(){
	dispScreen=9;
	lcd.clear();
	lcd.setCursor(4,0);
    lcd.print(F("TIME / DATE"));
	
	lcd.setCursor(5,3);
	lcd.print(F("SAVE"));
	lcd.setCursor(12,3);
	lcd.print(F("EXIT"));
}