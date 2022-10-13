/* @file Shell.cxx
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#include "Shell.h"

#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>

// Archivo de implementación de funciones shell

Shell::Shell(std::string command, callFunction_t myFunction,
             std::string commandUsage, std::string commandDescription,
             int argc) {
  this->command = command;
  this->myFunction = std::move(myFunction);
  this->commandUsage = commandUsage;
  this->commandDescription = commandDescription;
  this->argc = argc;
}

std::string Shell::getCommand() { return this->command; }
std::string Shell::getCommandDescription() { return this->commandDescription; }
std::string Shell::getCommandUsage() { return this->commandUsage; }

int Shell::getArgc() { return this->argc; }

void Shell::call(argv_t argvs, Shell command) const {
  this->myFunction(argvs, command);
}
/*
.
. Definicion resto de funciones
.
*/

Shell::SyntaxError::SyntaxError(TypeError typeError, std::string stringError) {
  this->typeError = typeError;
  this->stringError = stringError;
}

const char* Shell::SyntaxError::error() const noexcept {
  switch (this->typeError) {
    case COMMAND_DONT_EXIST:
      return "El comando ingresado no existe";
      break;

    case ERROR_AGV:
      return "Error escritura en comando";
      break;
    case ERROR_OPEN_FILE:
      return "no se encuentra o no puede leerse.";
      break;
    case EMPTY_FILE:
      return "no contiene ninguna secuencia.";
      break;

    default:
      return "Comando inválido";
      break;
  }
}
