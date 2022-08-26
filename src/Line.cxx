#include <iostream>
#include "Line.h"

Line::Line (){

}

void Line::setLine (std::string n_line){
    this->line = n_line;
}
void Line::setLenght (int n_lenght){
    this->lenght = n_lenght;
}
int Line::getLenght (){
    return this->lenght;
}
std::string Line::getLine (){
    return this->line;
}