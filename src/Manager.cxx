/* @file Manager.cxx
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#include "Manager.h"

#include <string.h>

#include <iostream>
#include <sstream>

#include "Shell.h"

Manager::Manager(std::vector<Shell> commands) { this->commands = commands; }

void Manager::init() {
  bool detected = false;
  while (true) {
    std::cout << "\n$";
    std::vector<std::string> tokens;
    std::string temp;
    std::getline(std::cin, temp);  // Recibir cada comando

    std::stringstream str_stream(temp);
    std::string token;
    // Separarlo para luego tokenizarlo en un vector
    while (std::getline(str_stream, token, ' ')) tokens.push_back(token);

    try {
      for (Shell shell : this->commands) {
        // Evaluar si el comando existe
        if (shell.getCommand() == tokens[0]) {
          detected = true;
          shell.call(tokens, shell);
        } else if (shell.getCommand() == tokens[1]) {
          detected = true;
          shell.call(tokens, shell);
        }

        if (tokens[0].compare("ayuda") == 0 && tokens.size() == 1) {
          this->commandHelp();
          detected = true;
          break;
        }
      }
      if (!detected)
        throw Shell::SyntaxError(
            Shell::SyntaxError::TypeError::COMMAND_DONT_EXIST);
    } catch (Shell::SyntaxError& e) {  // excepciones generadas en la
                                       // compilacion
      std::cout << "[Error]: " << e.error();
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }

    detected = false;
  }
}

void Manager::commandHelp() {
  std::cout << "Comandos:\n\n";
  for (Shell shell : this->commands) {  // Traer uso y descripción del comando.
    std::cout << "- " << shell.getCommand() << "\n\t"
              << "Uso: " << shell.getCommandUsage() << "\n\n";
  }
}
