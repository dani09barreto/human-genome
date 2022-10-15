/* @file Manager.h
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "Shell.h"

class Manager {
 private:
  std::vector<Shell> commands;

 public:
  /*----Constructor----*/
  Manager(std::vector<Shell> = std::vector<Shell>());
  /*----Metodos----*/
  void init();
  void commandHelp();
};

#endif
