#include "bEIGHduino_util.h"

void setup() {
  Serial.begin(9600);
  Connection** inputs = new Connection*[2];
  inputs[0] = new Connection(1);
  inputs[1] = new Connection(1);

  Output* output = new Output(0, 4);
  XOR* ands = new XOR(2);

  ands->addInput(inputs[0]);
  ands->addInput(inputs[1]);
  ands->addOutput(output);

  inputs[0]->addFunction(ands);
  inputs[1]->addFunction(ands);
  inputs[0]->setState(false);
  inputs[1]->setState(true);
}

void loop() {
  
}
