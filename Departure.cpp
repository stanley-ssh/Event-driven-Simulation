#include "Departure.hpp"
int Departure:: calcTimeSpent(){
    return currenTime+ requiredTime;
}
int Departure::getTimeSpent(){
    return timeSpent;
}
int Departure:: waitTime(){
    return  currenTime- custStart;

}
// int Departure::value(){
//     return custom->getPri();
// }
string Departure::getType(){
    return type;
}

customer * Departure::getCustom(){
    return custom;
}
int Departure::getRequiredT(){
    return requiredTime;
}