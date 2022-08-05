 /* @file main.cpp
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "Shell.h"
#include <vector>

class Manager{
    private:
        std::vector<Shell> commands;

    public:
        /*----Constructor----*/    
        Manager(std::vector<Shell> = std::vector<Shell> ());
        /*----Metodos----*/    
        void init ();
        void commandHelp ();
};


#endif
