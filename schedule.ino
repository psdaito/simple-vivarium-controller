void loadSchedule(){
 // lights On Off timer	
  Alarm.alarmRepeat(onLights,0,0,alarmLightOn);  // 10:00am light on
  Alarm.alarmRepeat(offLights,0,0,alarmLightOff);  // 10:00pm light off
  if((hour() > onLights) && (hour() < offLights)) alarmLightOn(); // at boot turn lights on if needed. 
}

/*
 Alarm.alarmRepeat(hours, minutes, seconds, function);
Create an alarm that will call a function every day at a particular time.

Alarm.alarmRepeat(dayofweek, hours, minutes, seconds, function);
Create an alarm that will call a function every week on a specific day at a particular time.
"dayofweek" can be dowSunday, dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, or dowSaturday.

Alarm.alarmOnce(hours, minutes, seconds, function);
Create an alarm that will call a function tomorrow at a particular time.

Alarm.alarmOnce(dayofweek, hours, minutes, seconds, function);
Create an alarm that will call a function once, at specific day and time. 

Alarm.timerRepeat(seconds, function);
Create a timer that will call a function every at an interval of "seconds".

Alarm.timerOnce(seconds, function);
Create a timer that will call a function once in "seconds".

 
 */
