#ifndef ARRIVALS_HPP
#define ARRIVALS_HPP


#include "customer.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "Departure.hpp"
class Arrivals: public Events{
    private:
    int start ;
    int end ;
    string type ;
    customer * thecustomer;
    public:
    string getType();

    customer * getCustomer ();
    Arrivals(customer * cust, string type,int currT ): type(type),start (currT ) , end(cust->getrequiredAss() ),
     Events(currT, cust->getrequiredAss() , "Arrival",cust->getArrivalTime()){thecustomer=cust;};
    void   process (PQueue & event, customer * cust , int currTime,PQueue &xray , PQueue & blood , int &tech , int &bloodTech );// the method should process the arrival  of a customer 

};
#endif