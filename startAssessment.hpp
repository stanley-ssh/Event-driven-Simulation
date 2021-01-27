#ifndef STARTASSESSMENT_HPP
#define STARTASSESSMENT_HPP
#include <iostream>
#include "Events.hpp"
#include "Departure.hpp"
#include "customer.hpp"
#include "PQueue.hpp"
class startAssessment :public Events{
    private:
    int startTime ;// should be the curr time 
    string diagnos;
    int requiredAss;// required time for assesment 
    customer * custom;
    public:

    string getDiagnosis();
    int getstartTime();
    startAssessment(customer *cust , int currTime ): 
    startTime(currTime), diagnos(cust->getDiagnosis()),requiredAss(cust->getTreatTime())
    , Events(startTime, currTime + cust ->getTreatTime(),
    "StartAssessment", currTime + cust->getTreatTime()){custom=cust; }
    void craeteCompleteAssesment(PQueue & xray, PQueue &blood, int &tech,PQueue & eventlist, int &bloodTech );// 
};
#endif