#include <iostream>
#include "Sequence.h"

Sequence::Sequence(){
}
char* Sequence::getName(){
    return(name);
}
void Sequence::setName(char* n_name){
    this->name = n_name;
}
void Sequence::addBase(char base){
    bases.push_back(base);
    //std::cout<<bases.back();
}
void Sequence::emptyListBases(){
    
}
void Sequence::countDifBases(){
}
