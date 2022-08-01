#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "shell.h"

class Controller{

    /*----Metodos (funciones que ejecuta el shell)----*/
    public:
    static void Cargar (Shell::argv_t argvs);
    static void conteo (Shell::argv_t argvs);
    static void listar_secuencias (Shell::argv_t argvs);
    static void histograma (Shell::argv_t argvs);
    static void es_subsecuencia (Shell::argv_t argvs);
    static void enmascarar (Shell::argv_t argvs);
    static void guardar (Shell::argv_t argvs);
    static void codificar (Shell::argv_t arvs);
    static void decodificar (Shell::argv_t arvs);
    static void ruta_mas_corta (Shell::argv_t arvs);
    static void base_remota (Shell::argv_t arvs);
    static void salir ();

};

#endif