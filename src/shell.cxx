#include "Shell.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>

//Archivo de definicion de funciones shell

Shell::Shell(std::string command, callFunction_t myFunction, std::string commandUsage, std::string commandDescription, int argc){
    this->command = command;
    this->myFunction = std::move(myFunction);
    this->commandUsage = command + " " + commandUsage;
    this->commandDescription = commandDescription;
    this->argc = argc;
}

std::string Shell::getCommand(){ 
    return this->command;
}

void Shell::call(argv_t argvs) const{ 
    this->myFunction(argvs);
}
/*
.
. definicion resto de funciones
.
*/

Shell::SyntaxError::SyntaxError(TypeError typeError, std::string stringError){
    this->typeError = typeError;
    this->stringError = stringError;
}

const char* Shell::SyntaxError::error() const noexcept {
    switch (this->typeError) {
        case COMMAND_DONT_EXIST:
            return "El comando ingresado no existe\n";
            break;

        case ERROR_AGV:
            return "Error escritura en comando\n";
            break;

        default:
            return "Comando inválido\n";
            break;
    }
}
