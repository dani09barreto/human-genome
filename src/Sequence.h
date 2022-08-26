#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <list>
#include <vector>
#include "Line.h"

class Sequence
{
protected:
  std::list<Line> bases;
  const std::vector<char> nitrogens = {'A', 'C', 'G', 'T', 'U', 'R',
                                       'Y', 'K', 'M', 'S', 'W', 'B',
                                       'D', 'H', 'V', 'N', 'X'};
  int numDifBases;
  std::vector<int> countBases; // Lista paralela a las posibles bases
  std::string name;
  std::string basesConcat;
  bool complete = true;

public:
  Sequence(int numDifBases, bool complete, std::string name);
  Sequence();
  std::string getName();
  void setName(std::string n_name);
  void setComplete(bool n_complete);
  void addLine(std::string n_line);
  std::string getBasesConcat();
  std::list<Line> getBases();
  bool getComplete();
  void updatecountBases();
  void printCountBases();
  void emptyListBases();
  int countDifBases();
  void updateStruct();
  
  
  // std::string setBasesConcat(std::string n_bases);
};

#endif //__SEQUENCE__H__
