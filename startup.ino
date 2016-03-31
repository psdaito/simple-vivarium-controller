void firstRunSetup()
{
  // we need to track if this has EVER run, because we only want it to run once ever
  if(EEPROM.read(1024)!= 16)
  {
    EEPROM.write(1024,16); // write to EEPROM so this never runs again
    
	  // set default values on first launch
    EEPROM.write(1,72);   // 1 // heat on
    EEPROM.write(2,78);  // 2 // heat off
    EEPROM.write(3,80);   // 3 // humidity on
    EEPROM.write(4,86);   // 4 // humidity off
    EEPROM.write(5,10);   // 5 // lights on hour
    EEPROM.write(6,0);   // 6 // lights on minute
    EEPROM.write(7,22);   // 7 // lights off hour
    EEPROM.write(8,0);   // 8 // lights off minute
    EEPROM.write(9,1);   // 9 // fan on hour
    EEPROM.write(10,0);  // 10 // fan on minute
	  EEPROM.write(11,23);  // 11 // fan off hour
    EEPROM.write(12,0);  // 10 // fan off minute
	
  }
}

void readSettings()
{
	heatOn = EEPROM.read(1);
	heatOff = EEPROM.read(2);
	humOn = EEPROM.read(3);
	humOff = EEPROM.read(4);
	onLightsH = EEPROM.read(5);
	onLightsM = EEPROM.read(6);
	offLightsH = EEPROM.read(7);
	offLightsM = EEPROM.read(8);
	onFanH = EEPROM.read(9);
	onFanM = EEPROM.read(10);
	offFanH = EEPROM.read(11);
	offFanM = EEPROM.read(12);
}
