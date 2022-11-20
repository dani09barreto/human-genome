#ifndef GRAFO_H
#define GRAFO_H
#include <map>
#include <queue>
#include <vector>

#include "Vertice.h"

template <class T>

class Grafo {
 protected:
  std::map<T, std::vector<Vertice<T> >> listaAdyacencia;

 public:
  Grafo();
  ~Grafo();
  int obtenerCantiVertices();
  int obtenerCantiAristas();

  bool insertarVertice(T vertice);
  bool insertarArista(T origen, T destino, float costo);

  bool buscarVertice(T v_buscar);
  int buscarVerticeIndice(T v_buscar);
  // Vertice<T> buscarVerticeInstancia(T v_buscar);

  bool buscarArista(T origen, T destino);
  float buscarAristaCosto(T origen, T destino);

  bool eliminarVertice(T vertice);
  bool eliminarArista(T origen, T v_borrar);

  // Recorridos
  void recorridoPlano();
  void recorridoEnProfundidad(T vertice, std::vector<T> &recorrido);
  void recorridoEnAnchura(T vertice, std::vector<T> &recorrido);
  bool estaVisitado(std::vector<T> recorrido, T vertice);

  // Algoritmos
  std::vector<T> algoritmoPrim(T inicio);
  std::map<T, T> algoritmoDijkstra(T inicio);

  void recorridoPresentacion();
  std::vector<T> obtenerListaVertices();
  bool esVacio();
  T obtenerCoordXIndice(long index);
  long obtenerIndiceXCoord(Coordenada c);
};
#include "Grafo.hxx"

#endif