void menuActions(){
	
	// menuPosition=1;  keep track what is edited now
    // buttonAction=0; what button was presed
	// dispScreen=1; what menu we are editing
	buttonAction = checkJoystick();
	if(buttonAction != Neutral){
   switch (dispScreen)
  { 
    case 1:  //Home
        if(buttonAction == Press) screenSettings();
      break;
	  
    case 2:  // Settings
		if(menuPosition == 1 && buttonAction == Press)
		{
			screenSensor();
		} 
		else if(menuPosition == 1 && buttonAction == Down)
		{
			menuPosition = 2;
			updateCursor(1, 1, 1, 2, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Press)
		{
			screenSchedule();	
		}
		else if(menuPosition == 2 && buttonAction == Up)
		{
			menuPosition = 1;
			updateCursor(1, 1, 1, 1, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			updateCursor(1, 2, 1, 3, 1);
		}
		else if(menuPosition == 3 && buttonAction == Press)
		{
			screenClock();
		}
		else if(menuPosition == 3 && buttonAction == Up)
		{
			menuPosition = 2;
			updateCursor(1, 3, 1, 2, 1);	
		}
		else if(menuPosition == 3 && buttonAction == Down)
		{
			menuPosition = 4;
			updateCursor(1, 3, 12, 3, 1);	
		}
		else if(menuPosition == 4 && buttonAction == Press)
		{
			screenHome();	
		}
		else if(menuPosition == 4 && buttonAction == Up)
		{
			menuPosition = 3;
			updateCursor(12, 3, 1, 3, 1);	
		}
		
      break;
	  
    case 3:  //Sensor
         		
		if(menuPosition == 1 && buttonAction == Press)
		{
			screenTemp();
		} 
		else if(menuPosition == 1 && buttonAction == Down)
		{
			menuPosition = 2;
			updateCursor(1, 1, 1, 2, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Press)
		{
			screenHum();	
		}
		else if(menuPosition == 2 && buttonAction == Up)
		{
			menuPosition = 1;
			updateCursor(1, 2, 1, 1, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			updateCursor(1, 2, 6, 3, 1);	
		}
		else if(menuPosition == 3 && buttonAction == Up)
		{
			menuPosition = 2;
			updateCursor(6, 3, 1, 2, 1);	
		}
		else if(menuPosition == 3 && buttonAction == Press)
		{
			screenSettings();	
		}
		
      break;
	  
    case 4:  // Temperature
	
		if(menuPosition == 1 && buttonAction == Right)
		{
			heatOn += 1;
			lcd.print(heatOn);
			lcd.setCursor(9,1);
		} 
		else if(menuPosition == 1 && buttonAction == Left)
		{
			heatOn -= 1;
			lcd.print(heatOn);
			lcd.setCursor(9,1);	
		} 
		else if(menuPosition == 1 && buttonAction == Down)
		{
			menuPosition = 2;
			updateCursor(9, 1, 9, 2, 2);
		}
		else if(menuPosition == 2 && buttonAction == Right)
		{
			heatOff += 1;
			lcd.print(heatOff);
			lcd.setCursor(9,2);
		} 
		else if(menuPosition == 2 && buttonAction == Left)
		{
			heatOff -= 1;
			lcd.print(heatOff);
			lcd.setCursor(9,2);	
		}
		else if(menuPosition == 2 && buttonAction == Up)
		{
			menuPosition = 1;
			updateCursor(9, 2, 9, 1, 2);
		}
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			updateCursor(9, 2, 3, 3, 4);
		}
		else if(menuPosition == 3 && buttonAction == Press)
		{
			EEPROM.write(1,heatOn);
			EEPROM.write(2,heatOff);
		}
		else if(menuPosition == 3 && buttonAction == Up)
		{
			menuPosition = 2;
			updateCursor(3, 3, 9, 2, 3);
		}
		else if(menuPosition == 3 && buttonAction == Down)
		{
			menuPosition = 4;
			updateCursor(3, 3, 10, 3, 1);
		}
		else if(menuPosition == 4 && buttonAction == Press)
		{
			heatOn = EEPROM.read(1);
			heatOff = EEPROM.read(2);
			screenSensor();
		}
        else if(menuPosition == 4 && buttonAction == Up)
		{
			menuPosition = 3;
			updateCursor(10, 3, 3, 3, 1);
		}
      break;
	  
    case 5:  // Humidity
       
	    if(menuPosition == 1 && buttonAction == Right)
		{
			humOn += 1;
			lcd.print(humOn);
			lcd.setCursor(9,1);
		} 
		else if(menuPosition == 1 && buttonAction == Left)
		{
			humOn -= 1;
			lcd.print(humOn);
			lcd.setCursor(9,1);	
		} 
		else if(menuPosition == 1 && buttonAction == Down)
		{
			menuPosition = 2;
			updateCursor(9, 1, 9, 2, 2);
		}
		else if(menuPosition == 2 && buttonAction == Right)
		{
			humOff += 1;
			lcd.print(humOff);
			lcd.setCursor(9,2);
		} 
		else if(menuPosition == 2 && buttonAction == Left)
		{
			humOff -= 1;
			lcd.print(humOff);
			lcd.setCursor(9,2);	
		}
		else if(menuPosition == 2 && buttonAction == Up)
		{
			menuPosition = 1;
			updateCursor(9, 2, 9, 1, 2);
		}
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			updateCursor(9, 2, 3, 3, 4);
		}
		else if(menuPosition == 3 && buttonAction == Press)
		{
			EEPROM.write(3,humOn);
			EEPROM.write(4,humOff);
		}
		else if(menuPosition == 3 && buttonAction == Up)
		{
			menuPosition = 2;
			updateCursor(3, 3, 9, 2, 3);
		}
		else if(menuPosition == 3 && buttonAction == Down)
		{
			menuPosition = 4;
			updateCursor(3, 3, 10, 3, 1);
		}
		else if(menuPosition == 4 && buttonAction == Press)
		{
			humOn = EEPROM.read(3);
			humOff = EEPROM.read(4);
			screenSensor();
		}
        else if(menuPosition == 4 && buttonAction == Up)
		{
			menuPosition = 3;
			updateCursor(10, 3, 3, 3, 1);
		}	   
      break;
	  
	case 6:  // Schedule
	
		if(menuPosition == 1 && buttonAction == Press)
		{
			screenLight();
		} 
		else if(menuPosition == 1 && buttonAction == Down)
		{
			menuPosition = 2;
			updateCursor(1, 1, 1, 2, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Press)
		{
			screenFan();	
		}
		else if(menuPosition == 2 && buttonAction == Up)
		{
			menuPosition = 1;
			updateCursor(1, 2, 1, 1, 1);	
		}
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			updateCursor(1, 2, 6, 3, 1);	
		}
		else if(menuPosition == 3 && buttonAction == Up)
		{
			menuPosition = 2;
			updateCursor(6, 3, 1, 2, 1);	
		}
		else if(menuPosition == 3 && buttonAction == Press)
		{
			screenSettings();	
		}
      
      break;
	  
    case 7:  // Light
	
		if(menuPosition == 1 && buttonAction == Right) // 1
		{
			//  + h
			onLightsH += 1;
			if(onLightsH > 23) onLightsH = 0;
			print2digits(onLightsH);
			lcd.setCursor(7,1);
	
		}
		else if(menuPosition == 1 && buttonAction == Left)
		{
			// - h
			onLightsH -= 1;
			if(onLightsH < 0) onLightsH = 23;
			print2digits(onLightsH);
			lcd.setCursor(7,1);
	
		}	
		else if(menuPosition == 1 && buttonAction == Down) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 2 && buttonAction == Right) // 2
		{
			// + m
			onLightsM += 1;
			if(onLightsM > 59) onLightsM = 0;
			print2digits(onLightsM);
			lcd.setCursor(10,1);
	
		}
		else if(menuPosition == 2 && buttonAction == Left)
		{
			//- m
			onLightsM -= 1;
			if(onLightsM < 0) onLightsM = 59;
			print2digits(onLightsM);
			lcd.setCursor(10,1);
	
		}	
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			lcd.setCursor(7,2);
		}
		else if(menuPosition == 2 && buttonAction == Up) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 3 && buttonAction == Right) // 3
		{
			// + h
			offLightsH += 1;
			if(offLightsH > 23) offLightsH = 0;
			print2digits(offLightsH);
			lcd.setCursor(7,2);
	
		}
		else if(menuPosition == 3 && buttonAction == Left)
		{
			// - h
			offLightsH -= 1;
			if(offLightsH < 0) offLightsH = 23;
			print2digits(offLightsH);
			lcd.setCursor(7,2);
	
		}	
		else if(menuPosition == 3 && buttonAction == Down)
		{
			menuPosition = 4;
			lcd.setCursor(10,2);
		}
		else if(menuPosition == 3 && buttonAction == Up) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 4 && buttonAction == Right) // 4
		{
			// + m
			offLightsM += 1;
			if(offLightsM > 59) offLightsM = 0;
			print2digits(offLightsM);
			lcd.setCursor(10,2);
	
		}
		else if(menuPosition == 4 && buttonAction == Left)
		{
			// - m
			offLightsM -= 1;
			if(offLightsM < 0) offLightsM = 59;
			print2digits(offLightsM);
			lcd.setCursor(10,2);
	
		}	
		else if(menuPosition == 4 && buttonAction == Down)
		{
			menuPosition = 5;
			updateCursor(10,2,4,3,4);
		}
		else if(menuPosition == 4 && buttonAction == Up) 
		{
			menuPosition = 3;
			lcd.setCursor(7,2);
		}
		else if(menuPosition == 5 && buttonAction == Down) // 5
		{
			menuPosition = 6;
			updateCursor(4,3,10,3,1);			
		}
		else if(menuPosition == 5 && buttonAction == Up) 
		{
			menuPosition = 4;
			updateCursor(4,3,10,2,3);
		}
		else if(menuPosition == 5 && buttonAction == Press) 
		{
			// save
			EEPROM.write(5,onLightsH);
			EEPROM.write(6,onLightsM);
			EEPROM.write(7,offLightsH);
			EEPROM.write(8,offLightsM);
		}
		else if(menuPosition == 6 && buttonAction == Up) 
		{
			menuPosition = 5;
			updateCursor(10,3,4,3,1);			
		}
		else if(menuPosition == 6 && buttonAction == Press) 
		{
			onLightsH = EEPROM.read(5);
			onLightsM = EEPROM.read(6);
			offLightsH = EEPROM.read(7);
			offLightsM = EEPROM.read(8);
			screenSchedule();	
		}
      
      break;
	  
    case 8:  // Fan
	
		if(menuPosition == 1 && buttonAction == Right) // 1
		{
			//  + h
			onFanH += 1;
			if(onFanH > 23) onFanH = 0;
			print2digits(onFanH);
			lcd.setCursor(7,1);
	
		}
		else if(menuPosition == 1 && buttonAction == Left)
		{
			// - h
			onFanH -= 1;
			if(onFanH < 0) onFanH = 23;
			print2digits(onFanH);
			lcd.setCursor(7,1);
	
		}	
		else if(menuPosition == 1 && buttonAction == Down) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 2 && buttonAction == Right) // 2
		{
			// + m
			onFanM += 1;
			if(onFanM > 59) onFanM = 0;
			print2digits(onFanM);
			lcd.setCursor(10,1);
	
		}
		else if(menuPosition == 2 && buttonAction == Left)
		{
			//- m
			onFanM -= 1;
			if(onFanM < 0) onFanM = 59;
			print2digits(onFanM);
			lcd.setCursor(10,1);
	
		}	
		else if(menuPosition == 2 && buttonAction == Down)
		{
			menuPosition = 3;
			lcd.setCursor(7,2);
		}
		else if(menuPosition == 2 && buttonAction == Up) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 3 && buttonAction == Right) // 3
		{
			// + h
			offFanH += 1;
			if(offFanH > 23) offFanH = 0;
			print2digits(offFanH);
			lcd.setCursor(7,2);
	
		}
		else if(menuPosition == 3 && buttonAction == Left)
		{
			// - h
			offFanH -= 1;
			if(offFanH < 0) offFanH = 23;
			print2digits(offFanH);
			lcd.setCursor(7,2);
	
		}	
		else if(menuPosition == 3 && buttonAction == Down)
		{
			menuPosition = 4;
			lcd.setCursor(10,2);
		}
		else if(menuPosition == 3 && buttonAction == Up) 
		{
			menuPosition = 2;
			lcd.setCursor(10,1);
		}
		else if(menuPosition == 4 && buttonAction == Right) // 4
		{
			// + m
			offFanM += 1;
			if(offFanM > 59) offFanM = 0;
			print2digits(offFanM);
			lcd.setCursor(10,2);
	
		}
		else if(menuPosition == 4 && buttonAction == Left)
		{
			// - m
			offFanM -= 1;
			if(offFanM < 0) offFanM = 59;
			print2digits(offFanM);
			lcd.setCursor(10,2);
	
		}	
		else if(menuPosition == 4 && buttonAction == Down)
		{
			menuPosition = 5;
			updateCursor(10,2,4,3,4);
		}
		else if(menuPosition == 4 && buttonAction == Up) 
		{
			menuPosition = 3;
			lcd.setCursor(7,2);
		}
		else if(menuPosition == 5 && buttonAction == Down) // 5
		{
			menuPosition = 6;
			updateCursor(4,3,10,3,1);			
		}
		else if(menuPosition == 5 && buttonAction == Up) 
		{
			menuPosition = 4;
			updateCursor(4,3,10,2,3);
		}
		else if(menuPosition == 5 && buttonAction == Press) 
		{
			// save
			EEPROM.write(9,onFanH);
			EEPROM.write(10,onFanM);
			EEPROM.write(11,offFanH);
			EEPROM.write(12,offFanM);
		}
		else if(menuPosition == 6 && buttonAction == Up) 
		{
			menuPosition = 5;
			updateCursor(10,3,4,3,1);			
		}
		else if(menuPosition == 6 && buttonAction == Press) 
		{
			onFanH = EEPROM.read(9);
			onFanM = EEPROM.read(10);
			offFanH = EEPROM.read(11);
			offFanM = EEPROM.read(12);
			screenSchedule();	
		}
      
      break;
	  
    case 9: // Clock

      break;
  }
  }
}
