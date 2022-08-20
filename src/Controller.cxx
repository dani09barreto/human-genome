/* @file Controller.cxx
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#include "Controller.h"
#include "Sequence.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
std::list<Sequence> sequences;
int numSequences = 0; // Cantidad de secuencias
void Controller::Cargar(Shell::argv_t argvs, Shell command)
{
   
    Controller::verificationARGV(argvs, command);

    std::string line;
    std::ifstream inputFile;
    inputFile.open(argvs[1]);
    try
    {
        if (!inputFile.is_open()) // No existe el archivo o no se puede abrir
            throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_OPEN_FILE);
        if (inputFile.peek() == std::ifstream::traits_type::eof()) // Comprobar que el archivo no este vacio
            throw Shell::SyntaxError(Shell::SyntaxError::TypeError::EMPTY_FILE);
    }
    catch (Shell::SyntaxError &e)
    { // excepciones generadas en la compilacion
        std::cout << "[Error]: " << argvs[1] << " " << e.error();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    
    sequences.clear();
    std::list<Sequence>::iterator itSeq;
    itSeq = sequences.begin();
    char* aux;
    numSequences = 0;
    while (getline(inputFile, line))
    {
        std::size_t found = line.find(">");
        if (found != std::string::npos) // Si es una nueva secuencia
        { 
           //Esta parte la idea seria que si llega una nueva secuencia
           //Le sume al iterador para ir agregando en la nueva posición
           //Sin embargo no sé por que de cualquier forma sale un error
           //De memoria, ademas sale la lista vacia
        }
        
    }
    if(numSequences==1){
        std::cout<<" 1 secuencia cargada correctamente desde "<<argvs[1];
    } else{
        std::cout<<numSequences<<" secuencias cargadas correctamente desde "<<argvs[1];
    }
    inputFile.close();
}

void Controller::conteo(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
    if(numSequences==0){
        std::cout<<"No hay secuencias cargadas en memoria.";
    } else if(numSequences==1){
        std::cout<<"1 secuencia en memoria.";
    }else{
        std::cout<<numSequences<<" secuencias en memoria.";
    }
}
void Controller::salir(Shell::argv_t argvs, Shell command)
{
    std::cout << "Saliendo....\n";
    exit(3);
}
void Controller::listar_secuencias(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::histograma(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::es_subsecuencia(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::enmascarar(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::guardar(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::codificar(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::decodificar(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::ruta_mas_corta(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::base_remota(Shell::argv_t argvs, Shell command)
{
    Controller::verificationARGV(argvs, command);
}
void Controller::verificationARGV(Shell::argv_t argvs, Shell command)
{
    if (argvs[0].compare("ayuda") == 0)
    {
        std::cout << "\nComando:\n";
        std::cout << "- " << command.getCommand() << "\n\t"
                  << "Uso: " << command.getCommandUsage() << "\n\tDescripcion: " << command.getCommandDescription() << "\n";
    }
    else if (argvs.size() != command.getArgc())
        throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
}

void Controller::clear(Shell::argv_t argvs, Shell command)
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}