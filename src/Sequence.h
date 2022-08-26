#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <list>
#include "Line.h"

class Sequence
{
  protected:
    std::list<Line> bases; 
    int numDifBases;
    std::string name;
    std::string basesConcat;
    bool complete;

  public:
    Sequence(int numDifBases, bool complete, std::string name);
    Sequence();
    std::string getName();
    void setName(std::string n_name);
    void setComplete(bool n_complete);
    void addLine(std::string n_line);
    std::list<Line> getBases();
    void countDifBases();
    void emptyListBases();
    std::string getBasesConcat();
    //std::string setBasesConcat(std::string n_bases);
};

#endif //__SEQUENCE__H__
