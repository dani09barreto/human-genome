#include <iostream>
#include "Sequence.h"

Sequence::Sequence(int numDifBases, bool complete, std::string name)
{
    this->numDifBases = numDifBases;
    this->name = name;
    this->complete = complete;
}
Sequence::Sequence()
{
    this->basesConcat = "";
}
void Sequence::setComplete(bool n_complete)
{
    this->complete = n_complete;
}
bool Sequence::getComplete()
{
    return complete;
}
void Sequence::setName(std::string n_name)
{
    this->name = n_name;
}
std::list<Line> Sequence::getBases()
{
    return (bases);
}
std::string Sequence::getName()
{
    return (name);
}

void Sequence::setBasesConcat(std::string n_basesConcat){
    this->basesConcat = n_basesConcat;
}

void Sequence::addLine(std::string n_line)
{   
    if (n_line.find('-') != std::string::npos){
        setComplete(false);
    }
    basesConcat = basesConcat + n_line; // Agregarlo al string largo
    Line newLine;
    newLine.setLenght(n_line.size());
    newLine.setLine(n_line);
    bases.push_back(newLine); // Agregarlo a la lista
}
void Sequence::emptyListBases()
{
}
std::string Sequence::getBasesConcat()
{
    return this->basesConcat;
}
void Sequence::updateStruct()
{
    std::list<Line>::iterator itL = bases.begin();
    int auxLenght = 0;
    std::string auxS = "";
    int j = 0;
    for (; itL != bases.end(); itL++)
    {    
        auxS="";                      // Recorrer lista de lineas
        auxLenght = (*itL).getLenght(); // Traer el tamaño
        for (int i = 0; i < auxLenght; i++)
        { // Dependiendo el tamaño itera
            auxS = auxS + this->basesConcat.at(j);
            j++; // Guardar la posición en la que va el string largo
        }
        (*itL).setLine(auxS);
    }
    
    //updatecountBases();
}
void Sequence::updatecountBases()
{   int aux=0;
    countBases.clear();
    for (int i =0; i<nitrogens.size();i++)
    {   aux = 0;
        for (int j = 0; j < basesConcat.size(); j++)
        {
            if(nitrogens.at(i)==basesConcat.at(j)){
               aux++;
            }
        }
        countBases.push_back(aux);
    }
    
   //countDifBases();
}
void Sequence::printCountBases(){
for (int i = 0; i < countBases.size(); i++)
    {
        std::cout << nitrogens.at(i) <<" : "<< countBases.at(i) << "\n";
    }
}
int Sequence::countDifBases()
{   int countDif = 0;
    for(int i=0;i<countBases.size();i++){
        if(countBases.at(i)!=0 && nitrogens.at(i) != 'X' && nitrogens.at(i) != '-'){
            countDif++;
        }
    }
    return countDif;
}
//--------------------------------------------------------------------------------
//--------------------------SEGUNDA ENTREGA---------------------------------------
//--------------------------------------------------------------------------------
  std::vector<int>Sequence::getVecFrequencies(){
    return countBases;
  }
  std::vector<char> Sequence::getNitrogens(){
    return nitrogens;
  }