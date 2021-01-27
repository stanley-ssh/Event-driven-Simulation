#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
using namespace std ;
#include <string>
#include "Allitem.hpp"
#include "Events.hpp"
class customer: public Allitem {
	private:
	bool Xray;// check if the customer has an xray diagnossis
	bool BloodWork ;//check if the customer hsas bloodwork diagnosis 
	int arrivaltime ;
	int requiredAss ;
	int maxXray;// maximum time for xray work per customer 
	int maxBloodT; // maximum time fir blood work per customer
	int customerNumber ;
	bool hasBloodWork ();
	bool hasXray();
	string diagnosis;
	int treatmentPri;
	int treatTime ;// the time required for assessment 
	public:

	int getArrivalTime();
	int getTreatTime ();
	string getDiagnosis();
	int getrequiredAss();
	int getTreatmentPri();// priority of the treatment 
	int getPri() ;
	string toString();
	void setBloodWork (bool blood);//chage the blood work 
	void setXray (bool xray);
	bool getBlood ();
	bool getXray ();
	int getBloodTime();// complete time for a blood work assesment 
  	int getXRayTime ();// complete time for an xray assessmnet 
	bool compare (customer  * item );
	 int value();
	customer(int arrival , int requiredTime , int priority, int tretPri, string diagn, int treatTime, int maxBloodT,int  maxXrayT ) : Allitem(),arrivaltime(arrival),customerNumber(priority),
	requiredAss(requiredTime),treatmentPri(tretPri),diagnosis(diagn),treatTime (treatTime),maxXray(maxXrayT),maxBloodT(maxBloodT){
		BloodWork= hasBloodWork();
		Xray=hasXray();
	}
};
#endif
