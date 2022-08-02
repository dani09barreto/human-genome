
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
        std::getline(std::cin, temp);

        std::stringstream str_stream(temp);
        std::string token;

        while (std::getline(str_stream, token, ' '))
            tokens.push_back(token);

        try{
            for (Shell shell : this->commands){
                if (shell.getCommand() == tokens[0]){
                    detected = true;
                    shell.call(tokens, shell);
                }
            }
            if (tokens[0].compare("help") == 0){
                    this->commandHelp();
                    detected = true;
            }
            if (!detected)
                throw Shell::SyntaxError(Shell::SyntaxError::TypeError::COMMAND_DONT_EXIST);
        }
        catch(Shell::SyntaxError &e){
            std::cout << "[Error]: " << e.error();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        
        detected = false;
    }
    // programa inicia
    // metodo de tokenisacion que se añade al vector de argumentos
}

void Manager::commandHelp(){
    std::cout << "Comandos:\n";
    for (Shell shell : this->commands){
        std::cout << shell.getCommandUsage() <<" "<< shell.getCommandDescription() << "\n";
    }
}   