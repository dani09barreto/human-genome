#include <iostream>
#include "Sequence.h"

Sequence::Sequence(int numDifBases,bool complete, std::string name){
    this->numDifBases=numDifBases;
    this->name = name;
    this->complete = complete;
}
Sequence::Sequence(){
}
void Sequence::setComplete(bool n_complete){
    this->complete = complete;
}
void Sequence::setName(std::string n_name){
    this->name = n_name;
}
std::list<std::string> Sequence::getBases(){
    return(bases);
}
std::string Sequence::getName(){
    return(name);
}

void Sequence::addBase(std::string base){
    bases.push_back(base);
    //std::cout<<bases.back();
}
void Sequence::emptyListBases(){
    
}
void Sequence::countDifBases(){
}
