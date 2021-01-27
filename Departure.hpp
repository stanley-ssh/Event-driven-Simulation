
#ifndef DEPARTURE_HPP
#define DEPARTURE_HPP
#include "customer.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "Departure.hpp"

class Departure : public Events{
    private:
    int currenTime ;
    int requiredTime ;
    int timeSpent ;
    int custStart;// the customer starting time 
    string type;/// the type of departure 
    customer * custom;
    int calcTimeSpent() ;


    public:
    int waitTime();
    int getTimeSpent () ;
    int getRequiredT();
    string   getType ();
    //int value();
    customer* getCustom();
    
    Departure(customer * cust , int currenT, int requi, string dep  ):custom(cust), currenTime(currenT), type(dep),
    requiredTime(requi), timeSpent(calcTimeSpent()),
    Events(cust->getArrivalTime(),cust->getTreatTime()+currenT,"Departure",requi),custStart(cust->getArrivalTime()){custom=cust;}
};
#endif