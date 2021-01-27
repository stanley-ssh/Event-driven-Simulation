
#include "Allitem.hpp"
#include "Events.hpp"
#include <string>
using namespace std ;

  string  Events::  getType() {
    return type;
}
int Events:: getProiority(){
    return priority;
}
int Events::value(){
    return priority;
}
bool Events:: compare(Allitem   * event ){
    bool ret = false;
    Events * newEvent = dynamic_cast<Events * >  (event);
     if (newEvent != NULL ){
          if ( this->getProiority() < newEvent->getProiority()){
            ret= true ;
          }
    

     }
  
    return ret ;
}
int Events:: getstartTime () {
    return startTime;
}

int Events:: getEndTime (){
    return EndTime;
}

