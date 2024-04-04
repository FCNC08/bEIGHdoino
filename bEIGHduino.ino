#include "bEIGHduino_util.h"
const int input_size = 2;
Inputs** inputs = new Inputs*[input_size]; 
int pin0 = 2;
int pin1 = 3;

int testpin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(testpin, INPUT);
  inputs[0] = new Inputs(pin0);
  inputs[1] = new Inputs(pin1);

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
  for(int i = 0; i<input_size; i++){
    int state = digitalRead(inputs[i]->_pin);
    if(state == HIGH){
      inputs[i]->setState(true);
    }else{
      inputs[i]->setState(false);
    }
  }
  
  Serial.println(digitalRead(testpin));
  delay(1000);
}
