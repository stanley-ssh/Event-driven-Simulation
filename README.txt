The simulation class has all the function to process a simulation.
When a simulation is created it wuld pass in a string which is the name of
the file to be used. Initialization of a simulation also creates a list called lines 
lines stores the lines in a file into a linkedlist.A getline function gets the first 
line of the linked list (the first line in the file ) and stores it into a linked list.
Then to process a patient i convert each nod of the line into a an int, and pass it into aa customer Object.
when a customer object is created a n arriavl Object is also created ,the arrival object woiuld take in 
the customer and  the currentTime. When a customer arrives iti checks if there are nurses available to start Assessment 
if there are nurses available to start assessment then the arrival of the customer is processed in the arrival class.
the proceess function creates a startAssessment object whicjh is mainly used to process a a diagnosis.When a diagnosis is
made, if there are technicials available then the departure of the diagnosis is created and put in an eventlist
 priority queue ( the queue inserts a departure based on passed in required time(time of departure)).When diagnosis
 is done then a departure is done for the diagnosis.And if there is still a diagnosis then a new arrival is created for that
 particular diagnosis.But there ar no more diagnosis then a startAssessment is created if there are doctors 
 availabe. if there are no docutors availabe then the customer is put in a list doclist, which is just a queue.
 But if there are doctors available then a departure for the customer is created an inserted into the event list.
If  there are no assessment nurses available then the customer is put in a queue.when a customer then departs a
new departure for the next customer starts. 

To run the program : g++ A2Const.cpp Allitem.cpp Arrivals.cpp customer.cpp Departure.cpp Events.cpp lineNodes.cpp lines.cpp
List.cpp Node.cpp PQueue.cpp Simulation.cpp main.cpp -o 

