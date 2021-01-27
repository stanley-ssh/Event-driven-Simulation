
#include <iostream>
#include "Events.hpp"
#include "Departure.hpp"
#include "customer.hpp"
#include "PQueue.hpp"
#include "startAssessment.hpp"
#include "Arrivals.hpp"

void startAssessment::craeteCompleteAssesment(PQueue &xray, PQueue &blood, int &tech, PQueue &eventlist, int &bloodTech)
{
    if (custom->getXray())
    {
        // treat it lie an xray
        Arrivals *newXray = new Arrivals(custom, "X-ray", startTime);
        //eventlist.push(newXray);
        if (tech > 0)
        {   // if there is an available ytechnician
            //create a departur for the cray
            // xray.push ( newXray);
            cout << "Time: " << startTime << "customer " << newXray->getCustomer()->getPri() << "begins xray" << endl;
            tech--;
            Departure *Xraydep = new Departure(custom, startTime, custom->getXRayTime() + startTime, "X-rayDep");
            // insert the departure into the eventlist
            eventlist.push(Xraydep);
        }
        else
        {
            // if there are no available technician
            xray.push(newXray);
        }
        // insert it into< the xray queue
    }
    // check if the diagnosis is a blood work
    else if (custom->getBlood())
    {
        // teat it like a blood work
        Arrivals *newBlood = new Arrivals(custom, "bloodArrival", startTime);
        if (bloodTech > 0)
        { // if there is anavailble tecincial
            //blood.push(newBlood);
            cout << "Time: " << startTime << "customer " << newBlood->getCustomer()->getPri() << "begins bloodwork" << endl;
            bloodTech--;
            // create a departure for the customer
            Departure *bloodDepart = new Departure(custom, startTime, custom->getBloodTime() + startTime, "Blood-Dep");
            // insert the departue into the eventlist

            eventlist.push(bloodDepart);
        }
        else
        {
            // ninsert into the bloodwork queue
            blood.push(newBlood);
            cout << "customer " << newBlood->getCustomer()->getPri() << " is waiting for a blood work " << endl;
        }

        // insert it into the bloodwork queue
    }
}
int startAssessment ::getstartTime()
{
    return startTime;
}
string startAssessment::getDiagnosis()
{
    return diagnos;
}