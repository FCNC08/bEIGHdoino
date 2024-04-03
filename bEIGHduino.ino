#include "bEIGHduino_util.h"
Connection** inputs = new Connection*[2];

void setup() {
  inputs[0] = new Connection();
  inputs[1] = new Connection();

  Output* output = new Output(4);
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
