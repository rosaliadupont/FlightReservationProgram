#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"
using namespace std;

class Plane
{
  static const int EMPTY = -1;
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  int flightNumber;
  LinkedList* passengers;
  int getRow() const;
  void showGrid() const;
  //void showPassengers() const;
public:
  Plane(const int flightNum);
  Plane(ifstream &inf);
  ~Plane();
  void addFlight();
  //int addPassenger();
  Plane& operator++();
  Plane& operator--(int);
  Plane& operator!();
  void writePlane(ofstream &outf) const;
  friend ostream& operator<<(ostream& outf, const Plane &rhs);
  friend istream& operator>>(istream &inf, Plane &rhs);
  int findPassenger(const char* name) const;
}; // class Plane

#endif	// PLANE_H


