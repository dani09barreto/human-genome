#ifndef MANAGER_H
#define MANAGER_H

#include "shell.h"
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