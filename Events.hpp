#ifndef EVENTS_HPP
#define EVENTS_HPP


#include "Allitem.hpp"
#include <string>
using namespace std ;
class  Events : public Allitem{
    private:
    int priority ;
    int startTime ;
    int EndTime ;
    std::string type ;
    public:
    string getType () ;
    int getProiority () ;
    int getstartTime();
    int getEndTime();
    virtual int value() ;
    bool compare (Allitem   *event );
    Events(int start , int end , string type, int pri ) : startTime(start ), EndTime(end ) , type(type ) , priority(pri){};
};

#endif
