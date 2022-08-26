#include <iostream>
#include "Sequence.h"

Sequence::Sequence(int numDifBases,bool complete, std::string name){
    this->numDifBases=numDifBases;
    this->name = name;
    this->complete = complete;
}
Sequence::Sequence(){
    this->basesConcat="";
}
void Sequence::setComplete(bool n_complete){
    this->complete = complete;
}
void Sequence::setName(std::string n_name){
    this->name = n_name;
}
std::list<Line> Sequence::getBases(){
    return(bases);
}
std::string Sequence::getName(){
    return(name);
}

void Sequence::addLine(std::string n_line){
    basesConcat = basesConcat + n_line; // Agregarlo al string largo
    Line newLine;
    newLine.setLenght(n_line.size());
    newLine.setLine(n_line);
    bases.push_back(newLine); // Agregarlo a la lista
    
}
void Sequence::emptyListBases(){
    
}
std::string Sequence::getBasesConcat(){
    return basesConcat;
}
void Sequence::countDifBases(){
}
