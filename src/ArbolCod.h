#ifndef ARBOLCOD_H
#define ARBOLCOD_H
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "NodoCod.h"
class ArbolCod {
 protected:
  NodoCod *raiz;
  std::map<char, std::string> codigos;

 public:
  ArbolCod();
  ArbolCod(int freq, char letra);
  ~ArbolCod();
  NodoCod *obtenerRaiz();
  void fijarRaiz(NodoCod *n_raiz);
  bool esVacio();
  bool insertar(int freq, char letra);
  void preOrden();
  void inOrden();
  void posOrden();
  void nivelOrden();
  std::map<char, std::string> obtenerCodigos();
  NodoCod *generarArbol(
      std::priority_queue<NodoCod *, std::vector<NodoCod *>, Compare> pq);
  void generarPQParaArbol(std::vector<char> letras, std::vector<int> freq);
  void generarCodigos(NodoCod *root, std::string str);
  std::string decodificar(std::string cod, long long contBases);
};
#endif