#include <EEPROM.h>
#include "Types.h"

void setup() {
  // put your setup code here, to run once:
  SystemState::State state;

  state.LastRetractPosition = RetractTypes::UnDefined;
  state.Version = 1.0;
  
  for (int iter = 0; iter < 6; iter++)
  {
    state.servoAttributes[iter].MaxAngle = 180;
    state.servoAttributes[iter].MinAngle = 180;
    state.servoAttributes[iter].DegPerSecond = 1;
  }
  
  EEPROM.put(0, state);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
