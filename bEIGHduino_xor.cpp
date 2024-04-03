#include "bEIGHduino_xor.h"
#include "HardwareSerial.h"
#include "bEIGHduino_function.h"
#include "bEIGHduino_connection.h"

XOR::XOR(int input_count):Function(input_count, 1){}

void XOR::simulating(){
  Serial.println("XOR-Simulate");
  bool out_state = false;
  for(int i = 0; i<_input_count; i++){
    out_state = out_state^static_cast<Connection*>(inputs.get(i))->getState();
  }
  static_cast<Connection*>(outputs.get(0))->setState(out_state);
}