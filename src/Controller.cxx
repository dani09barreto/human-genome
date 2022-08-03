#include "Controller.h"
#include <iostream>

void Controller::Cargar (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::conteo(Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);    
}
void Controller::salir(Shell::argv_t argvs, Shell command){
    std::cout<<"Pa fuera";
    for(std::string s: argvs){
        std::cout<<s;
    }
    exit(3);
}
void Controller::listar_secuencias (Shell::argv_t argvs, Shell command) {
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
} 
void Controller::histograma (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::es_subsecuencia (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::enmascarar (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::guardar (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::codificar (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::decodificar (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::ruta_mas_corta (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}
void Controller::base_remota (Shell::argv_t argvs, Shell command){
    Controller::help(argvs, command);
    if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}

void Controller::help(Shell::argv_t argvs, Shell command){
    if (argvs[1].compare("help") == 0)
        std::cout << command.getCommandUsage() <<" "<< command.getCommandDescription() << "\n";
}