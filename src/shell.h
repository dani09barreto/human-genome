#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include <exception>
#include <string>
#include <functional>

class Shell{
    
    public:
        using argv_t = std::vector<std::string>;  //lista de argumentos
        using callFunction_t = std::function<void(argv_t)>; // llamado de una funcion por un comando

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

    void call (argv_t argvs) const;


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