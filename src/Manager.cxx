
#include "Manager.h"
#include <iostream>
#include "shell.h"
#include <sstream>
#include <string.h>

Manager::Manager(std::vector<Shell> commands){
    this->commands = commands;
}

void Manager::init(){
    bool detected = false;
    while (true){
    std::cout << "\n$";
        std::vector<std::string> tokens;
        std::string temp;
        std::getline(std::cin, temp); //Recibir cada comando

        std::stringstream str_stream(temp);
        std::string token;
		//Separarlo para luego tokenizarlo en un vector
        while (std::getline(str_stream, token, ' '))
            tokens.push_back(token);

        try{
            for (Shell shell : this->commands){
            //Evaluar si el comando existe
                if (shell.getCommand() == tokens[0]){
                    detected = true;
                    shell.call(tokens, shell);
                }
            }
            if (tokens[0].compare("help") == 0){//Si es el comando ayuda
                    this->commandHelp();
                    detected = true;
            }
            if (!detected)
                throw Shell::SyntaxError(Shell::SyntaxError::TypeError::COMMAND_DONT_EXIST);
        }
        catch(Shell::SyntaxError &e){//excepciones generadas en la compilacion
            std::cout << "[Error]: " << e.error();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        
        detected = false;
    }
    
}

void Manager::commandHelp(){
    std::cout << "Comandos:\n\n";
    for (Shell shell : this->commands){//Traer uso y descripción del comando.
        std::cout << "- " << shell.getCommand() <<"\n\t"<< "Uso: "<< shell.getCommandUsage() <<"\n\tDescripcion: "<< shell.getCommandDescription() << "\n\n";
    }
}   
