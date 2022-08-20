#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <list>

class Sequence {
  public:
   Sequence(int numDifBases,bool complete, std::string name);
   Sequence();
   std::string getName();
   void setName(std::string n_name);
   void setComplete(bool n_complete);
   void addBase(char base);
   std::list<char> getBases();
   void countDifBases();
   void emptyListBases();
  protected:
   std::list<char> bases;
   int numDifBases;
   std::string name;
   bool complete;
};

#endif //__SEQUENCE__H__
