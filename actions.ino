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
		else if(menuPosition == 4 && buttonAction == Down)
		{
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
		else if(menuPosition == 4 && buttonAction == Down)
		{
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
      
      break;
	  
    case 8:  // Fan
      
      break;
	  
    case 9: // Clock

      break;
  }
  }
}
