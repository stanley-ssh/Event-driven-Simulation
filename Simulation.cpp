#include <iostream>
#include <sstream>
#include <assert.h>

#include <fstream>
#include <string>
#include "string.h"
using namespace std;
#include "Simulation.hpp"
#include "LInes.hpp"
#include "customer.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "Allitem.hpp"
#include "Queue.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "startAssessment.hpp"
#include "Arrivals.hpp"
#include "A2Const.hpp"
  //-----------------------------------------
     // NAME		: Stanley Anmelcehi 
     // STUDENT NUMBER	: 7819079
     // COURSE		: COMP 2150
     // INSTRUCTOR	: MIke dormatzik
     // ASSIGNMENT	: assignment 2
     // QUESTION	: question 1    
     // 
     // REMARKS: The program is to perform an event driven simulation
     //
     //
     //-------
istream *Simulation::nextLine;
int Simulation::BloodWorkNum =0;
int Simulation::xrayNum= 0;
int Simulation :: treatments= 0 ;
int Simulation::patientNumbers = 0;
int Simulation::totalAssess=0;
int Simulation::totalBlood=0;
int Simulation::totalXray=0;
int Simulation::totalTreatmentTime=0;
int currTime = 0;

void Simulation ::process(Events *event, Queue &Q, PQueue &Pq, PQueue &xray, PQueue &blood, int &bloodTEch, int &XrayTech, int &nurse, Queue &docList, int &docs)
{
  if (event->getType().compare("Arrival") == 0)
  { // if the ebent os an arrival
    // treat the event like an arrival

    Arrivals *arrive = dynamic_cast<Arrivals *>(event);
    // check if it is a customer arrival
    if (arrive->getType().compare("customerArr") == 0)
    {
      assert(arrive != NULL);
      Q.enQueue(arrive->getCustomer());
      // add it to the queue of customers
      // check if there are available nurses
      if (nurse > 0)
      {
        //Q.pop();//remove the customer from the queue
        customer *firstCust = arrive->getCustomer();
        // create a time for gthe customer to depart assessment
        totalAssess+= firstCust->getrequiredAss();
        Departure *endAss = new Departure(firstCust, event->getProiority(), firstCust->getrequiredAss() + firstCust->getArrivalTime(), "Nurse-Dep");
        // add this to the evnt list
        Pq.push(endAss);
      }
      // else{
      // this should read in the next lne
      LInes *currentLine = getNextLine();
      if (currentLine != NULL)
      {
        customer *cust = new customer(convertInt(currentLine->deleteFirst()),
                                      convertInt(currentLine->deleteFirst()), patientNumbers++, convertInt(currentLine->deleteFirst()), currentLine->deleteFirst(), convertInt(currentLine->deleteFirst()), bloodWorkTime, XrayTime);

        Arrivals *newArrival = new Arrivals(cust, "customerArr", cust->getArrivalTime());
        Pq.push(newArrival);
        // increment for the next patient
        // patientNumbers ++;
      }
    }
    // if the arrival is into an xray
    else if (arrive->getType().compare("X-ray") == 0)
    {

      (arrive->process(Pq, arrive->getCustomer(), event->getstartTime(), xray, blood, XrayTech, bloodTEch));
    }
    else if (arrive->getType().compare("bloodArrival") == 0)
    {
      // if the arrivalis for a bloodwork

      (arrive->process(Pq, arrive->getCustomer(), event->getstartTime(), xray, blood, XrayTech, bloodTEch));
    }
    else if (arrive->getType().compare("Diagnosis") == 0) // if ots a diagnosis arrival
    {
      totalAssess+= arrive->getCustomer()->getrequiredAss();
      arrive->process(Pq, arrive->getCustomer(), arrive->getCustomer()->getArrivalTime() + arrive->getCustomer()->getrequiredAss(), xray, blood, XrayTech, bloodTEch);
    }
  }

  //else if the event is a departure then
  else if (event->getType().compare("Departure") == 0)
  {
    // departure [pusedocode ]

    Departure *lastDepart = dynamic_cast<Departure *>(event);
    if (lastDepart->getType().compare("X-rayDep") == 0)
    {
      xrayNum++;
      totalXray+=lastDepart->getCustom()->getXRayTime();
      lastDepart->getCustom()->setXray(false);
      XrayTech++; // the number of technicians would increase
      //check if that was not the last customer on the xray queue process the next one
      if (!xray.isEmpty())
      {
        // start to process the next xray customer
        Arrivals *nextXrayCust = dynamic_cast<Arrivals *>(xray.pop());
        Pq.push(nextXrayCust);
      }

      // if the customer is departing from an xray
      //if (LastXray!= nullptr){
      cout << "Time: " << event->getProiority() << " customer " << lastDepart->getCustom()->getPri() << " completes  xray" << endl;

      // }
      //check if the customer has another treatment
      if (!lastDepart->getCustom()->getBlood())
      {
        cout << "depart customer" << endl;
        // if the customer des not have a blood work
        //create a departure event for the customer
        if (docs > 0)
        {
          // if there are avialble doctors for treat ment
          //docs--;
          treatments++;
          cout << "Time: " << event->getProiority() << "customer" << lastDepart->getCustom()->getPri() << "starts Treatment" << endl;
          Departure *custDep = new Departure(lastDepart->getCustom(), event->getstartTime(), event->getProiority() + lastDepart->getCustom()->getTreatTime(), "customerDep");
          //zero because the customer is departing immediately after works
          //Q.enQueue(custDep->getCustom());
          Pq.push(custDep);
        }
        else
        {
          docList.enQueue(lastDepart->getCustom());
        }
      }
      else
      {
        // if thecustomer still has another treeatment
        //schedule a startassesment for a blod work

        Arrivals *bloodArrival = new Arrivals(lastDepart->getCustom(), "bloodArrival", event->getProiority());
        Pq.push(bloodArrival);
      }
    }
    else if (lastDepart->getType().compare("Blood-Dep") == 0)
    {
      totalBlood+=lastDepart->getCustom()->getBloodTime();
      BloodWorkNum++;
      lastDepart->getCustom()->setBloodWork(false);
      bloodTEch++;
      // check if there are people waiting for a blood work
      if (!blood.isEmpty())
      {
        // start processing
        Arrivals *bloodA = dynamic_cast<Arrivals *>(blood.pop());
        Pq.push(bloodA);
      }
      // if the customer is leaving froma blood work
      //Arrivals *lastBlod =
      //if (lastBlod!=nullptr){
      cout << "Time: " << event->getProiority() << " customer " << lastDepart->getCustom()->getPri() << "completes bloodwork" << endl;
      //         }
      //check if it still has anotyher treatment

      if (!lastDepart->getCustom()->getXray())
      {
        // create a departure for te\he customer
        if (docs > 0)
        {
          //docs--;
          totalTreatmentTime+=lastDepart->getCustom()->getTreatTime();
          cout << "Time: " << event->getProiority() << " customer" << lastDepart->getCustom()->getPri() << "starts Treatment" << endl;
          treatments++;
          Departure *custDep = new Departure(lastDepart->getCustom(), event->getstartTime(), event->getProiority() + lastDepart->getCustom()->getTreatTime(), "customerDep");
          Pq.push(custDep);
        }
        else
        {
          docList.enQueue(lastDepart->getCustom());
        }
      }
      else
      {
        // if thecustomer still has another treeatment
        //schedule a startassesment for an xray
        Arrivals *XrayArrive = new Arrivals(lastDepart->getCustom(), "X-ray", event->getProiority());
        Pq.push(XrayArrive);
      }
    }

    //else if the customer to depart is a for a cutomer o leave
    else if (lastDepart->getType().compare("customerDep") == 0)
    {
      assert(!Q.isEmpty());
      docs++;
      Allitem *finshed = Q.pop(); // remove the custo,er from the list
                                  // cast the event as a departure to be able to treat it like one
                                  // print the statistics of the customer  departting  of the departing customer
                                  //if ((finshed!=nullptr)){
      Departure *dept = dynamic_cast<Departure *>(event);
      if (dept != NULL)
      {

        cout << "customer " << finshed->value() << "Departed at time " << event->getProiority() << endl;
      }
      // get next person waiting for the doctor and process departure time
      if (!docList.isEmpty())
      {
        customer *newCustomer = dynamic_cast<customer *>(docList.pop());
        if (newCustomer != NULL)
        {
          Departure *newTreat = new Departure(newCustomer, event->getProiority(), event->getProiority() + newCustomer->getTreatTime(), "customerDep");
        }
      }
    }
    else if (lastDepart->getType().compare("Nurse-Dep") == 0)
    {
      // if the departure is from a nurse
      // create an arrival for a diagnosis
      nurse++;
      Arrivals *diag = new Arrivals(lastDepart->getCustom(), "Diagnosis", lastDepart->getProiority());
      // add it to the event list
      Pq.push(diag);
    }
  }
}
LInes *Simulation::get()
{
  return lines;
}

//the method would return a list of all thw owrds on aline
LInes *Simulation ::getNextLine()
{
  string curr = lines->deleteFirst();
  if (curr != "")
  {
    string word = "";
    int i = 0;
    LInes *aword = new LInes();
    for (char  x : curr)
    {
      if (x == ' ')
      {
        aword->insertEnd(word);
        word = "";
      }
      else
      {

        word = word + x;
      }
      i++;
    }
    aword->insertEnd(word);
    return aword;
  }
  else
  {
    return NULL;
  }
}

///this method is to convet a string to an int
int Simulation::convertInt(string value)
{
  stringstream geek(value);
  int x = 0;
  geek >> x;
  return x;
}

// the methos reads in a file and stores it into a list-> lines 
void Simulation::file()
{
  string str;
  ifstream *inFile = new ifstream;
  inFile->open(txtFile);

  string line;

  while (getline(*inFile, line))
  {
    lines->insertEnd(line);
  }
}

void Simulation::readFile()
{
  int sum = 0;
  int localCopy = numXRayTech;
  //std::ifstream inFile (fileName);//= new ifstream;
  //inFile->open(fileName);
  Queue *customerQ = new Queue(); // a queue of a ll the customers or waiting room
  PQueue *Xray = new PQueue();    // a quue of people waiting for n xray
  PQueue *bloodWork = new PQueue();
  Queue *TreatList = new Queue(); // queue of peole waiting to get treatmenet

  PQueue *EventList = new PQueue();
  LInes *currentLine = getNextLine();
  customer *cust = new customer(convertInt(currentLine->deleteFirst()),
                                convertInt(currentLine->deleteFirst()), patientNumbers++, convertInt(currentLine->deleteFirst()), currentLine->deleteFirst(), convertInt(currentLine->deleteFirst()), XrayTime, bloodWorkTime);

  Arrivals *aEvent = new Arrivals(cust, "customerArr", cust->getArrivalTime());

  // creating a new arrival wiith the customer
  // add the event to the event list
  EventList->push(aEvent);
  //EventList->push(dep1);

  while (!EventList->isEmpty())
  {
    //currTime
    Events *currentEvent = EventList->pop();
    process(currentEvent, *customerQ, *EventList, *Xray, *bloodWork, numBloodTech, numXRayTech, nurses, *TreatList, doctors);
  }


}
int Simulation::getAverage(int first, int second ){
  int ret =0 ;
  if (second!=0){
    ret = first/second;
  }
  return ret ;
}
  void Simulation:: finalSummary(){
    cout<<"Wait time station average "<< "  total patients "<<  "     service time       total average "<< endl; 
    cout<<"--------------------------------------------------------------------------------\n"<<endl;
    cout<<"------------"<<endl;

    cout<<"Assessment                  "<<patientNumbers<<"                       "<<totalAssess<<"         "<<getAverage(totalAssess,patientNumbers)<<endl;
    cout<<"BloodWork                    "<<BloodWorkNum<<"                        "<<totalBlood<<"          "<<getAverage(totalBlood,BloodWorkNum)<<endl;
    cout<<"Xray                        "<< xrayNum<<"                           "<<totalXray<<"           "<<getAverage(totalXray,xrayNum)<<endl;
  cout<<"Treatment                   "<<treatments<<"                          "<<totalTreatmentTime<<"       "<<getAverage(totalTreatmentTime,treatments)<<endl;      
  }

