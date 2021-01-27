

#include "Arrivals.hpp"

#include "PQueue.hpp"
#include "Departure.hpp"
#include "customer.hpp"
#include "startAssessment.hpp"
string Arrivals::getType()
{
    return type;
}
void Arrivals::process(PQueue &event, customer *cust, int currTime, PQueue &xray, PQueue &blood, int &tech, int &bloodTech)
{
    // create a departure
    // create a startAssesment model

    startAssessment *newAsses = new startAssessment(cust, currTime);
    newAsses->craeteCompleteAssesment(xray, blood, tech, event, bloodTech);

}
customer * Arrivals::getCustomer()
{
    return thecustomer;
}