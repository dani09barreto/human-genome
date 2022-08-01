
#include "Manager.h"
#include <iostream>
#include "shell.h"

Manager::Manager(std::vector<Shell> commands){
    this->commands = commands;
}

void Manager::init (){
    std::cout << "$";
    std::vector <std::string> a;
    std::string temp;
    std::cin >> temp;
    a.push_back(temp);


    for (Shell shell: this->commands){
        shell.call(a);
    }
    //programa inicia
    //metodo de tokenisacion que se añade al vector de argumentos
}

void Manager::commandHelp (){
    // funcion que muestra todos los comandos
}