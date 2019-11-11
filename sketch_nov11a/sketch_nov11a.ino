#include <EEPROM.h>
#include "Types.h"

void setup() 
{  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println("Configure state controller eeprom config.");
  
  // Format eeprom with state controller config
  SystemState::State state;

  state.LastRetractPosition = RetractTypes::UnDefined;
  state.Version = 1.0;
  
  for (int iter = 0; iter < 6; iter++)
  {
    state.servoAttributes[iter].MaxAngle = 180;
    state.servoAttributes[iter].MinAngle = 0;
    state.servoAttributes[iter].DegPerSecond = 1;
  }
  
  EEPROM.put(0, state);

  //check eeprom write
  SystemState::State readState;

  Serial.println("Read state controller eeprom config.");
  EEPROM.get(0, readState);
  Serial.println(readState.Version);
  Serial.println(readState.LastRetractPosition);
  
  Serial.println("Read state controller servo eeprom config.");
  for (int iter = 0; iter < 6; iter++)
  {
    Serial.println(readState.servoAttributes[iter].MaxAngle);
    Serial.println(readState.servoAttributes[iter].MinAngle);
    Serial.println(readState.servoAttributes[iter].DegPerSecond);
  }

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
