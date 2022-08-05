 /* @file Shell.h
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include <exception>
#include <string>
#include <functional>
/*TAD Shell

Conjunto minimo de datos:
	- command, cadena de caracteres, nombre del comando
	- myFunction, call function, usado para el manejo de llamado de funciones
	- commandUsage, cadena de caracteres, muestra como debe usarse el comando
	- commandDescription, cadena de caracteres, explica que hace el comando
	- SyntaxError, tipo SyntaxError, tipo de dato usado para manejar las excepciones
	
Comportamiento (operaciones) del objeto:
	- getCommand(), obtiene el nombre del comando
	- getCommandUsage(), obtener el como usar el comando
	- getCommandDescription(), obtener la descripción del comando


*/
class Shell{
    
    public:
        using argv_t = std::vector<std::string>;  //lista de argumentos
        using callFunction_t = std::function<void(argv_t, Shell)>; // llamado de una funcion por un comando

    private:
        std::string command;
        callFunction_t myFunction;
        std::string commandUsage;
        std::string commandDescription;
        int argc;
    
    /*----Constructor----*/
    public:
        Shell(
            std::string command, 
            callFunction_t myFunction, 
            std::string commandUsage,
            std::string commandDescription,
            int argc
        );

    /*----Metodos----*/
    std::string getCommand ();

    std::string getCommandUsage ();

    std::string getCommandDescription ();

    int getArgc();

    void call (argv_t argvs, Shell command) const;
/*

TAD SyntaxError

Conjunto minimo de datos:
	- TypeError, enumeración, es un conjunto de tipos de errores que pueden salir en ejecución
	- stringError, cadena de caracteres, presentacion del error cuando se llame
Comportamiento (Operaciones) del objeto:
	- error(), función para obtener el tipo de error en ejecución
*/

    class SyntaxError : public std::exception {
        public:
            enum TypeError{
                COMMAND_DONT_EXIST,
                ERROR_AGV
            };

        private:
            TypeError typeError;
            std::string stringError;

        /*----Constructor----*/
        public:
            SyntaxError(
                TypeError typeError,
                std::string stringError = "Exception Error"
        );

        /*----Metodos----*/
        const char *error() const noexcept;
        const TypeError getType() const;  
    };
    
};


#endif
