#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include<iostream> 
#include <sstream>
#include <assert.h>

#include <fstream>
#include <string>
#include "string.h"
using namespace std;
#include "customer.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "A2Const.hpp"
#include "LInes.hpp"
#include "Allitem.hpp"
#include "Queue.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "startAssessment.hpp"
#include  "Arrivals.hpp"

class Simulation {
    private:
    A2Const * A ;
    int numXRayTech;
    int numBloodTech;
    int nurses;
    int doctors ;
    int bloodWorkTime;
    int XrayTime ;
    string txtFile ;
    LInes * lines ;

    public:
    static istream * nextLine ;
    static int patientNumbers;
    static int xrayNum;
    static int BloodWorkNum;
    static int treatments;//  the number of treatment done
    static int currTime  ;
    static int totalBlood ;// the total blood work for the simualtio 
    static int totalXray ; /// total xray time for the simullation 
    static int totalAssess;// total time for assessment 
    static int totalTreatmentTime;// total time for treatment 

    int convertInt(string value );
    void file ();

    Simulation (string textFile ):txtFile(textFile){
    A=new A2Const();
    lines = new LInes();// a list to tsore lines of a file 
    numBloodTech= A->numBloodTech;
    numXRayTech = A->numXRayTech;
    nurses=A->numAssessmentNurses;
    XrayTime= A->XRayTime;
    bloodWorkTime= A->bloodWorkTime;
    doctors= A->numDoctors;
    file();
    }
    int getAverage(int firtst , int second) ;

  void readFile ( ) ;
  void process ( Events * event, Queue &Q , PQueue & Pq , PQueue &xray , PQueue &blood ,int &numB,int &numXray,int &nurse, Queue &docList,int &Docs );
  void simulation () ;
  void finalSummary();
 
  LInes * get();
  LInes *  getNextLine ( );
};
#endif

