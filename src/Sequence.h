#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <list>
#include "Line.h"

class Sequence
{
  protected:
    std::list<std::string> bases;
    std::list<Line> bases2; //lista de lineas
    int numDifBases;
    std::string name;
    bool complete;

  public:
    Sequence(int numDifBases, bool complete, std::string name);
    Sequence();
    std::string getName();
    void setName(std::string n_name);
    void setComplete(bool n_complete);
    void addBase(std::string base);
    std::list<std::string> getBases();
    void countDifBases();
    void emptyListBases();
};

#endif //__SEQUENCE__H__
