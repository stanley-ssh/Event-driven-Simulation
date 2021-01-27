#include "customer.hpp"
#include "string.h"
bool customer::compare(customer  * event ){
	bool ret =false;
	customer * cust = dynamic_cast<customer * > (event );
	if (cust !=NULL ) {// compare two customer by customer number 
	
		ret = cust ->getPri() == this->getPri();
	}
	return  ret ;
}
int customer::getBloodTime(){
	
	return maxBloodT;
}
int customer:: getXRayTime(){
	
	return maxXray;
}
bool customer::hasXray(){
	char cst [diagnosis.size()+1];
	bool ret = false;
	diagnosis.copy(cst,diagnosis.size()+1);
	cst[diagnosis.size()]='\0';
	for (int i =0 ; i<strlen(cst);i++){
		if (cst[i]=='X'){
			ret= true ;
		}
	}
	return ret ;
}
void customer::setBloodWork(bool blood ){
	BloodWork = blood;
}
void customer::setXray(bool ray ){
	Xray= ray ;
}
bool customer::getBlood (){
	return BloodWork;
}
bool customer::getXray(){
	return Xray;
}
bool customer::hasBloodWork(){
	char cst [diagnosis.size()+1];
	bool ret = false;
	diagnosis.copy(cst,diagnosis.size()+1);
	cst[diagnosis.size()]='\0';
	for (int i =0 ; i<strlen(cst);i++){
		if (cst[i]=='B'){
			ret= true ;
		}
	}
	return ret ;
}
 int customer::getTreatmentPri(){
	 //should return the  priority if the diagnosis 
	 return treatmentPri;
 }
int customer:: getTreatTime(){
	return treatTime;
}
string customer :: getDiagnosis(){
	return diagnosis;
}
int customer:: getPri(){
	return customerNumber;
}
	int customer:: value(){
		return customerNumber;
	}
	int customer:: getArrivalTime(){
		return arrivaltime;
	}
	int customer:: getrequiredAss(){
		return requiredAss;
	}
string customer:: toString(){
	return "hj";//to_string(arrivaltime);
}

