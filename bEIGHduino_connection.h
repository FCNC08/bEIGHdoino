#ifndef bEIGHduino_connection_H
#define bEIGHduino_connection_H

#define Connection_NORMAL false;
#define Connection_OUTPUT true;

#include "LinkedList.h"

class Connection{
  public:
    Connection(int function_count);
    virtual void setState(bool state);
    bool getState();
    void addFunction(void* func);
    bool _type;
  protected:
    int _function_count;
    LinkedList functions;
    bool _state;
};

#endif