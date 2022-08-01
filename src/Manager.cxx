
#include "Manager.h"
#include <iostream>
#include "shell.h"
#include <sstream>

Manager::Manager(std::vector<Shell> commands){
    this->commands = commands;
}

void Manager::init (){
    bool detected = false;
    std::cout << "$";
    std::vector <std::string> tokens;
    std::string temp;
    std::getline(std::cin,temp);

    std::stringstream str_stream(temp);
    std:: string token;

    while(std::getline(str_stream,token,' '))
    tokens.push_back(token);

    for (Shell shell: this->commands){   
        if(shell.getCommand() == tokens[0]){
            detected = true;
            shell.call(tokens);            
        }
            
    }       
    //programa inicia
    //metodo de tokenisacion que se añade al vector de argumentos
}

void Manager::commandHelp (){
    for (Shell shell: this->commands){
        std::cout<<"Comandos:\n";
        std::cout<<shell.getCommand();
    }
}