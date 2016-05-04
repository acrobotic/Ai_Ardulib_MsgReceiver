#include "Ai_MsgReceiver.h"

MsgReceiver receiver = MsgReceiver();

void setup() 
{
  // Initiate Serial Communication
  Serial.begin(9600); 
}

void loop() 
{
  int myInt;
  float myFloat;
  char *outStr;
  while (Serial.available() > 0) 
  {
    receiver.process(Serial.read());
    if (receiver.messageReady()) 
    {
      Serial.println( "Message Ready" );
      myInt = receiver.readInt(0);
      //sprintf(outStr)

      myFloat = receiver.readFloat(1);
      receiver.reset();
    }
  }
}
