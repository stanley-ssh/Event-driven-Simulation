

#include<iostream> 
#include <sstream>
#include <assert.h>
#include "lineNodes.hpp"

#include <fstream>
#include <string>
#include "string.h"
using namespace std;
#include "customer.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "LInes.hpp"
#include "Allitem.hpp"
#include "Queue.hpp"
#include "PQueue.hpp"
#include "Events.hpp"
#include "startAssessment.hpp"
#include  "Arrivals.hpp"
#include "Simulation.hpp"

// implementation

// leave this in A2Const.cpp and un-comment the next line


/*
 * A2main.cpp
 * COMP 2150 Object Orientation
 * (C) Computer Science, University of Manitoba
 *
 * Main function for Assignment 2
 */

#include <cstdlib>
#include "A2Const.hpp"
using namespace std;

int main(int argc, char *argv[]){
  // if(argc < 2){
  //   cout << "Usage: " << argv[0] << " <file name>\n";
  //   exit(1);
  // }
  cout << "Simulation begins...\n";
  Simulation * newSimulation = new Simulation("test10.txt");
  newSimulation->readFile();
  cout << "\n...Simulation complete.  Final Summary \n\n";
    newSimulation->finalSummary();

  cout << "\nEnd of processing.\n";
  return 0;
}// main
