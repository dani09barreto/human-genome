#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <list>

class Sequence {
  public:
   Sequence();
   char* getName();
   void setName(char* n_name);
   void addBase(char base);
   void countDifBases();
   void emptyListBases();
  protected:
   std::list<char> bases;
   int numDifBases;
   char* name;
   bool complete;
};

#endif //__SEQUENCE__H__
