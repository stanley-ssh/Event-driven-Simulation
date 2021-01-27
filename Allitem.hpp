#ifndef ALLITEM_HPP
#define ALLITEM_HPP
using namespace std;
#include <string>
#include <iostream> 
class Allitem  {
	private:
    int values;
	// void  virtual  print();
	 //string toString ();
	public:
	void print();
	 virtual int  value();
	 virtual bool compare (Allitem * item );
	 std::string virtual  toString () ;
	bool virtual  equals (Allitem item );
	//typedef enum {customer} item ;
	Allitem();
   // ~Allitem();
};
# endif