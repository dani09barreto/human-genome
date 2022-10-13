#ifndef __LINE__H__
#define __LINE__H__

#include <iostream>

class Line {
 private:
  std::string line;
  int lenght;

 public:
  Line();
  void setLine(std::string line);
  void setLenght(int lenght);
  int getLenght();
  std::string getLine();
};

#endif