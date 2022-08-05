#include "Controller.h"
#include <iostream>

void Controller::Cargar (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::conteo(Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command); 
}
void Controller::salir(Shell::argv_t argvs, Shell command){
    std::cout << "Saliendo....\n";
    exit(3);
}
void Controller::listar_secuencias (Shell::argv_t argvs, Shell command) {
    Controller::verificationARGV(argvs, command);
} 
void Controller::histograma (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::es_subsecuencia (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::enmascarar (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::guardar (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::codificar (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::decodificar (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::ruta_mas_corta (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}
void Controller::base_remota (Shell::argv_t argvs, Shell command){
    Controller::verificationARGV(argvs, command);
}

void Controller::verificationARGV(Shell::argv_t argvs, Shell command){
    if (argvs.size() == 1)
         throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);

    if (argvs[1].compare("help") == 0){
        std::cout << "\nComando:\n";
        std::cout << "- " << command.getCommand() <<"\n\t"<< "Uso: "<< command.getCommandUsage() <<"\n\tDescripcion: "<< command.getCommandDescription() << "\n";
    }
    else if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}

void Controller::clear (Shell::argv_t argvs, Shell command){
    #ifdef WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}