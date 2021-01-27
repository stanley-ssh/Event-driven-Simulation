#ifndef A2CONST_HPP
#define A2CONST_HPP

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
#include "Allitem.hpp"
#include "Queue.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "startAssessment.hpp"
#include  "Arrivals.hpp"
//#include "Simulation.hpp"
/*
 * A2Const.cpp
 * COMP 2150 Object Orientation
 * (C) Computer Science, University of Manitoba
 *
 * Static class for program constants
 */

// interface 
// move to A2Const.hpp if using separate compilation

class A2Const{
 
 public:


  static const  int numAssessmentNurses;

    static const int numBloodTech;
  
  static const  int numXRayTech;
 
   static const int numDoctors;
  
  static const int bloodWorkTime;
   
 static const int XRayTime;
   
 
};
#endif