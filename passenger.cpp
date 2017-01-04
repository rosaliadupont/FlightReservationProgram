// Author: Sean Davis
#include <cstring>
#include <fstream>
#include "passenger.h"
using namespace std;


Passenger::Passenger() 
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) : 
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

bool Passenger::operator==(int flightNumber)
{
  return (flightNum == flightNumber);
} // equality operator for passenger's flightNumber

bool Passenger::operator==(const char* nam)
{
  return (strcmp(name, nam) == 0);
} // equality operator for passenger's name

void Passenger::operator!()
{
  flightNum = CANCELLED;
  return;
} // remove operator for passenger

ostream& operator<<(ostream &os, Passenger &p)
{
  return os << p.name << endl;
} // insertion operator to print name of passenger
