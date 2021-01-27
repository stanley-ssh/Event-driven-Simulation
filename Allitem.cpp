

#include "Allitem.hpp"
#include <iostream>
using namespace std ;

Allitem::Allitem () {

    //do nothing 
}

bool Allitem:: compare(Allitem * item ){
    // method is to cpmare item together 

    // dummy method to allow for polymorphism 
    return false; 
}
void Allitem::print () {
    cout<<"Value is "<< endl;
}
int Allitem:: value() {
    values=2;
    return values  ;
}
bool Allitem:: equals(Allitem val) {
    return false ;
}
string Allitem:: toString(){
    return "belle";
}