#ifndef PASSENGER_H
#define	PASSENGER_H

#include "plane.h"
#include <fstream>
#include <iostream>

class Passenger 
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  friend istream& operator>>(istream &inf, Plane &rhs);
  short flightNum;
  short row; 
  char seat;
  char name[NAME_LENGTH];
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers();
  bool operator==(int flightNumber);
  bool operator==(const char* nam);
  void operator!();
  friend ostream&  operator<<(ostream &os, Passenger &p);
}; // class passengers 

#endif	// PASSENGERS_H

