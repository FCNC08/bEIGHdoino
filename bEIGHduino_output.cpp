#include "bEIGHduino_output.h"
#include "Arduino.h"
#include "bEIGHduino_connection.h"
#include "bEIGHduino_function.h"

Output::Output(int function_count, int pin):Connection(function_count){
  _type = Connection_OUTPUT;
  _pin = pin;
  pinMode(pin, OUTPUT);
}

void Output::setState(bool state){
  Serial.println("test in output");
  if(_state != state){
    _state = state;
    if(state){
      digitalWrite(_pin, HIGH);
    }else{
      digitalWrite(_pin, LOW);
    }
    for(int i = 0; i<_function_count; i++){
      Function* comp = static_cast<Function*>(functions.get(i));
      comp->simulate();
    }
  }

}