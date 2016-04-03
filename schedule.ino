void loadSchedule(){
 // lights On Off timer	
  Alarm.alarmRepeat(onLightsH,onLightsM,0,alarmLightOn);  // 10:00am light on
  Alarm.alarmRepeat(offLightsH,offLightsM,0,alarmLightOff);  // 10:00pm light off
  Alarm.alarmRepeat(onFanH,onFanM,0,alarmFanOn);  // 10:00am light on
  Alarm.alarmRepeat(offFanH,offFanM,0,alarmFanOff);  // 10:00pm light off
  if((hour() > onLightsH) && (hour() < offLightsH)) alarmLightOn(); // at boot turn lights on if needed.
  if((hour() > onFanH) && (hour() < offFanH)) alarmFanOn(); // at boot turn fan on if needed.  
}
void updateAlarms()
{
  // clear, free, delete all possible alarms
  for (byte i=0; i<=4; i++) Alarm.free(i);
  Alarm.alarmRepeat(onLightsH,onLightsM,0,alarmLightOn);  // 10:00am light on
  Alarm.alarmRepeat(offLightsH,offLightsM,0,alarmLightOff);  // 10:00pm light off
  Alarm.alarmRepeat(onFanH,onFanM,0,alarmFanOn);  // fan on
  Alarm.alarmRepeat(offFanH,offFanM,0,alarmFanOff);	// fan off
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
