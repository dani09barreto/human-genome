#include "ArbolCod.h"

#include <queue>
/*
Todo el código de la generación del arbol de Huffman
y la generación de los códigos está basado en la
implementación del usuario namang133 de la pagina
GeeksForGeeks.

https://www.geeksforgeeks.org/huffman-coding-using-priority-queue/

*/
ArbolCod::ArbolCod() { this->raiz = nullptr; }
ArbolCod::~ArbolCod() {
  if (this->raiz != nullptr) {
    delete this->raiz;
    this->raiz = nullptr;
  }
}
ArbolCod::ArbolCod(int freq, char letra) {
  this->raiz->fijarFreqLetra(freq, letra);
}
NodoCod *ArbolCod::obtenerRaiz() { return this->raiz; }
void ArbolCod::fijarRaiz(NodoCod *n_raiz) { this->raiz = n_raiz; }
bool ArbolCod::esVacio() { return this->raiz == nullptr; }
void ArbolCod::inOrden() {
  if (!this->esVacio()) {
    (this->raiz)->inOrden();
  }
}
void ArbolCod::preOrden() {
  if (!this->esVacio()) {
    (this->raiz)->preOrden();
  }
}
NodoCod *ArbolCod::generarArbol(
    std::priority_queue<NodoCod *, std::vector<NodoCod *>, Compare> pq) {
  // Hasta que quede un solo valor en la cola

  while (pq.size() != 1) {
    NodoCod *izq = pq.top();  // Obtener el primer menor de la lista
    pq.pop();                 // Sacarlo de la cola

    NodoCod *der = pq.top();  // Obtener el segundo menor de la lista
    pq.pop();                 // Sacarlo de la cola
    // Generar el nuevo nodo con la suma de las
    // frecuencias, poniendole como caracter el
    // $, teniendo en cuenta que es un nodo
    // intermedio

    NodoCod *nodo = new NodoCod(izq->obtenerFreq() + der->obtenerFreq(), '$');

    // Se agregan estos nodos hijos al padre,
    // el cual es la suma de la frecuencia de
    // sus hijos
    nodo->fijarHijoIzq(izq);
    nodo->fijarHijoDer(der);
    pq.push(nodo);
  }
  return pq.top();  // Retorna la raíz del arbol ya armado
}
void ArbolCod::generarPQParaArbol(std::vector<char> letras,
                                  std::vector<int> freq) {
  // Generar el monticulo minimo a apartir del adapatador priority queue
  std::priority_queue<NodoCod *, std::vector<NodoCod *>, Compare> pq;
  for (int i = 0; i < letras.size(); i++) {
    if (freq.at(i) != 0) {
      // Si la frecuencia es diferente a cero, se agregar en el arbol
      NodoCod *n_nodo = new NodoCod(freq.at(i), letras.at(i));
      pq.push(n_nodo);
    }
  }
  raiz = generarArbol(pq);
  Busq = raiz;
  generarCodigos(raiz, "");
}
void ArbolCod::generarCodigos(NodoCod *root, std::string str) {
  if (root == nullptr) {
    return;
  }

  if (root->obtenerLetra() != '$') {
    codigos.insert({root->obtenerLetra(), str});
  }
  this->generarCodigos(root->obtenerHijoIzq(), str + "0");
  this->generarCodigos(root->obtenerHijoDer(), str + "1");
}
std::map<char, std::string> ArbolCod::obtenerCodigos() { return this->codigos; }

char ArbolCod::decodificar(char code) {
  char letter = '#';
  Busq = code == '1' ? Busq->obtenerHijoDer() : Busq->obtenerHijoIzq();
  if (Busq->esHoja()) {
    letter = Busq->obtenerLetra();
    Busq = raiz;
  }
  return letter;
}

void ArbolCod::MoveBusq() { Busq = raiz; }