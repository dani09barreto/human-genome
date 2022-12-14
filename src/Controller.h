/* @file Controller.h
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Shell.h"

class Controller {
  /*----Metodos (comando que ejecuta el shell)----*/
 public:
  static void Cargar(Shell::argv_t argvs, Shell command);
  static void conteo(Shell::argv_t argvs, Shell command);
  static void listar_secuencias(Shell::argv_t argvs, Shell command);
  static void histograma(Shell::argv_t argvs, Shell command);
  static void es_subsecuencia(Shell::argv_t argvs, Shell command);
  static void enmascarar(Shell::argv_t argvs, Shell command);
  static void guardar(Shell::argv_t argvs, Shell command);
  static void codificar(Shell::argv_t argvs, Shell command);
  static void decodificar(Shell::argv_t argvs, Shell command);
  static void ruta_mas_corta(Shell::argv_t argvs, Shell command);
  static void base_remota(Shell::argv_t argvs, Shell command);
  static void salir(Shell::argv_t argvs, Shell command);
  static int verificationARGV(Shell::argv_t argvs, Shell command);
  static void clear(Shell::argv_t argvs, Shell command);
  // Funciones segunda entrega
  static void updateFreq();
  static void initFreq();
  static void fillFreq(char letter, long long cont);
};

#endif
