#include "Controller.h"
#include <iostream>

void Controller::Cargar (Shell::argv_t argvs){
    std::cout << "funcion cargar";
}
void Controller::conteo(Shell::argv_t argvs){
    std::cout << "funcion conteo";
}
void Controller::salir(Shell::argv_t argvs){
    std::cout<<"Pa fuera";
    for(std::string s: argvs){
        std::cout<<s;
    }
    exit(3);
}
void Controller::listar_secuencias (Shell::argv_t argvs) {
    std::cout << "funcion listar";
} 
void Controller::histograma (Shell::argv_t argvs){
    std::cout << "funcion histograma";
}
void Controller::es_subsecuencia (Shell::argv_t argvs){

}
void Controller::enmascarar (Shell::argv_t argvs){

}
void Controller::guardar (Shell::argv_t argvs){

}
void Controller::codificar (Shell::argv_t arvs){

}
void Controller::decodificar (Shell::argv_t arvs){

}
void Controller::ruta_mas_corta (Shell::argv_t arvs){

}
void Controller::base_remota (Shell::argv_t arvs){

}