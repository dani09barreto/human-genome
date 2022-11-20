#include <iostream>
#include <limits>
#include <map>
#include <vector>

#include "Grafo.h"
#include "Vertice.h"

template <class T>
Grafo<T>::Grafo() {}
template <class T>
Grafo<T>::~Grafo() {
  listaAdyacencia.clear();
}
template <class T>
int Grafo<T>::obtenerCantiVertices() {
  return this->listaAdyacencia.size();
}
template <class T>
int Grafo<T>::obtenerCantiAristas() {
  int canti = 0;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (; it != listaAdyacencia.end(); it++) {
    canti += (it->second).size();
  }
  return canti;
}
template <class T>
bool Grafo<T>::insertarVertice(T vertice) {
  // 1. Verifiar que el vertice no exista ya en el grafo.
  if (buscarVertice(vertice)) {
    return false;
  }
  // 2 y 3. Agregar un nuevo elemento a la lista de vertices,con una lista
  // vacia.
  std::vector<Vertice<T>> vec;
  listaAdyacencia.insert({vertice, vec});
  return true;
}
template <class T>
bool Grafo<T>::insertarArista(T origen, T destino, float costo) {
  bool origenExiste = false;
  bool destinoExiste = false;

  typename std::map<T, std::vector<Vertice<T>>>::iterator it;
  if (this->buscarVertice(origen)) {
    origenExiste = true;
    it = listaAdyacencia.find(origen);
  }
  if (buscarVertice(destino)) {
    destinoExiste = true;
  }

  //  1. Verificar que el vertice origen y destino estan en el grafo.
  if (origenExiste && destinoExiste) {
    Vertice<T> auxVertice(destino, costo);

    // Iterador del vector parado en el inicio del origen.
    // 2.Con el indice del vertice origen, extraer la lista correspondiente.
    typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
    // 3. Verificar que el vertice destino no está en la lista
    for (; itV != it->second.end(); itV++) {
      if (*itV == auxVertice) {
        return false;
      }
    }
    // 4. Agregar un nuevo par a la lista (Vertice,costo)
    it->second.push_back(auxVertice);
    return true;
  } else {
    return false;
  }
}
template <class T>
bool Grafo<T>::buscarVertice(T v_buscar) {
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (; it != listaAdyacencia.end(); it++) {
    if (it->first == v_buscar) {
      return true;
    }
  }
  return false;
}
template <class T>
int Grafo<T>::buscarVerticeIndice(T v_buscar) {
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  int i = 0;
  for (; it != listaAdyacencia.end(); it++, i++) {
    if (it->first == v_buscar) {
      return i;
    }
  }
  return -1;
}
template <class T>
bool Grafo<T>::buscarArista(T origen, T destino) {
  bool origenExiste = false;
  bool destinoExiste = false;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      this->listaAdyacencia.find(origen);
  if (it != listaAdyacencia.end()) {
    origenExiste = true;
  }
  if (buscarVertice(destino)) {
    destinoExiste = true;
  }
  // 1.Verificar que el vértice origen y el vértice destino están en el grafo
  if (origenExiste && destinoExiste) {
    // 2. Utilizar el indice del vertice para extraer el vector.
    typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
    for (; itV != it->second.end(); itV++) {
      // 3. Buscar en cada par en donde tenga el destino
      if ((*itV).obtenerVertice() == destino) {
        // 4a. Retornar si está o no la conexión.
        return true;
      }
    }
  }
  return false;
}
template <class T>
float Grafo<T>::buscarAristaCosto(T origen, T destino) {
  bool origenExiste = false;
  bool destinoExiste = false;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it;

  if (this->buscarVertice(origen)) {
    origenExiste = true;
    it = listaAdyacencia.find(origen);
  }
  if (buscarVertice(destino)) {
    destinoExiste = true;
  }
  // 1.Verificar que el vértice origen y el vértice destino están en el grafo
  if (origenExiste && destinoExiste) {
    // 2. Utilizar el indice del vertice para extraer el vector.
    typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
    for (; itV != it->second.end(); itV++) {
      // 3. Buscar en cada par en donde tenga el destino
      if ((*itV).obtenerVertice() == destino) {
        // 4b. Retornar el costo de la relación.
        return (*itV).obtenerCosto();
      }
    }
  }
  return -1;
}
template <class T>
bool Grafo<T>::eliminarVertice(T vertice) {
  // 1. Verificar que el vértice esté en el grafo.
  if (buscarVertice(vertice)) {
    // 2 y 3. Utilizar el indice del vertice para eliminar la lista.
    listaAdyacencia.erase(vertice);
    typename std::map<T, std::vector<Vertice<T>>>::iterator it =
        listaAdyacencia.begin();
    for (; it != listaAdyacencia.end(); it++) {
      typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
      // 4. Eliminar el vertice del vector.
      for (; itV != it->second.end();) {
        if ((*itV).obtenerVertice() == vertice) {
          itV = (it->second).erase(itV);
        } else {
          ++itV;
        }
      }
    }
    return true;
  }
  return false;
}
template <class T>
bool Grafo<T>::eliminarArista(T origen, T v_borrar) {
  bool aristaEliminada = false;
  bool origenExiste = false;
  bool destinoExiste = false;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it;
  // 2. Obtener la lista correspondiente.
  if (this->buscarVertice(origen)) {
    origenExiste = true;
    it = listaAdyacencia.find(origen);
  }
  if (buscarVertice(v_borrar)) {
    destinoExiste = true;
  }  // 1. Verificar que el vertice origen y destino, estan en el grafo.
  if (origenExiste && destinoExiste) {
    typename std::vector<Vertice<T>>::iterator itV = (it->second).begin();
    for (; itV != (it->second).end();) {
      if ((*itV).obtenerVertice() == v_borrar) {
        // 3. Buscar en esa lista con ese vertice destino y eliminarlo.
        itV = (it->second).erase(itV);
        aristaEliminada = true;
      } else {
        ++itV;
      }
    }
  }
  return aristaEliminada;
}
template <class T>
void Grafo<T>::recorridoPlano() {
  std::vector<T> vec = this->obtenerListaVertices();
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec.at(i) << "\n";
  }
}
template <class T>
void Grafo<T>::recorridoEnProfundidad(T vertice, std::vector<T> &recorrido) {
  if (!this->buscarVertice(vertice)) {
    return;
  }
  recorrido.push_back(vertice);
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.find(vertice);
  std::vector<Vertice<T>> aristas = it->second;
  typename std::priority_queue<Vertice<T>, std::vector<Vertice<T>>,
                               CompareVertice<T>>
      pq;
  for (int i = 0; i < aristas.size(); i++) {
    pq.push(aristas[i]);
  }

  while (!pq.empty()) {
    Vertice<T> auxVer = pq.top();
    pq.pop();
    if (!estaVisitado(recorrido, auxVer.obtenerVertice())) {
      recorridoEnProfundidad(auxVer.obtenerVertice(), recorrido);
    }
  }
}
template <class T>
void Grafo<T>::recorridoEnAnchura(T vertice, std::vector<T> &recorrido) {
  if (!this->buscarVertice(vertice)) {
    return;
  }
  std::deque<T> cola;
  cola.push_back(vertice);

  while (!cola.empty()) {
    T v = cola.front();
    cola.pop_front();
    if (!estaVisitado(recorrido, v)) {
      recorrido.push_back(v);
      typename std::map<T, std::vector<Vertice<T>>>::iterator it =
          this->listaAdyacencia.find(vertice);

      std::vector<Vertice<T>> aristas = it->second;
      typename std::priority_queue<Vertice<T>, std::vector<Vertice<T>>,
                                   CompareVertice<T>>
          pq;
      for (int i = 0; i < aristas.size(); i++) {
        pq.push(aristas[i]);
      }
      while (!pq.empty()) {
        Vertice<T> auxVer = pq.top();
        pq.pop();
        if (!estaVisitado(recorrido, auxVer.obtenerVertice())) {
          cola.push_back(auxVer.obtenerVertice());
        }
      }
    }
  }
}
template <class T>
bool Grafo<T>::estaVisitado(std::vector<T> recorrido, T vertice) {
  for (int i = 0; i < recorrido.size(); i++) {
    if (recorrido[i] == vertice) {
      return true;
    }
  }
  return false;
}
template <class T>
std::vector<T> Grafo<T>::obtenerListaVertices() {
  std::vector<T> vec;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (; it != listaAdyacencia.end(); it++) {
    vec.push_back(it->first);
  }
  return vec;
}
template <class T>
std::vector<T> Grafo<T>::algoritmoPrim(T inicio) {
  // Vector paralelo al map, que relaciona cada nodo con su conexión
  typename std::vector<T> conexiones(this->obtenerCantiVertices());
  if (this->buscarVertice(inicio)) {
    int inf = 999999;
    // Vector paralelo al map para verificar que un nodo ya fue visitado
    std::vector<bool> visitados(this->obtenerCantiVertices(), false);

    // vector paralelo al map, que muestra el
    // Costo de transporte desde el nodo inicio
    std::vector<int> valor(this->obtenerCantiVertices(), inf);
    typename std::priority_queue<Vertice<T>, std::vector<Vertice<T>>,
                                 CompareVertice<T>>
        pq;

    Vertice<T> ver(inicio, 0);
    pq.push(ver);
    int index = this->buscarVerticeIndice(inicio);
    valor.at(index) = 0;
    while (!pq.empty()) {
      Vertice<T> auxVer = pq.top();
      index = this->buscarVerticeIndice(auxVer.obtenerVertice());
      visitados.at(index) = true;
      pq.pop();
      typename std::map<T, std::vector<Vertice<T>>>::iterator itB =
          listaAdyacencia.find(auxVer.obtenerVertice());
      typename std::vector<Vertice<T>>::iterator itV = itB->second.begin();
      for (; itV != itB->second.end(); itV++) {
        int costo = itV->obtenerCosto();
        T vertice = itV->obtenerVertice();
        int indexV = this->buscarVerticeIndice(vertice);
        if (!visitados.at(indexV) && valor.at(indexV) > costo) {
          valor.at(indexV) = costo;
          conexiones.at(indexV) = auxVer.obtenerVertice();
          Vertice<T> auxVer2(vertice, costo);
          pq.push(auxVer2);
        }
      }
    }
  }
  return conexiones;
}
template <class T>
std::map<T, T> Grafo<T>::algoritmoDijkstra(T inicio,std::map<T, float> &costo) {
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.find(inicio);
      std::map<T, T> Predecesores;
  if (it != this->listaAdyacencia.end()) {
        
    std::vector<T> Cola = this->obtenerListaVertices();
    int menor, pos;
    T vertice;
    for (int i = 0; i < Cola.size(); i++) {
      if (Cola[i] != inicio) {
        costo.insert({Cola[i], std::numeric_limits<int>::max()});
      } else {
        costo.insert({Cola[i], 0});
        Predecesores[Cola[i]] = Cola[i];
      }
    }
    while (!Cola.empty()) {
      menor = std::numeric_limits<int>::max();
      for (int i = 0; i < Cola.size(); i++) {
        if (menor > costo[Cola[i]]) {
          pos = i;
          menor = costo[Cola[i]];
          vertice = Cola[i];
        }
      }
      typename std::map<T, std::vector<Vertice<T>>>::iterator it =
          listaAdyacencia.find(vertice);
      typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
      for (; itV != it->second.end(); itV++) {
        if (costo[itV->obtenerVertice()] >
            (costo[vertice] + itV->obtenerCosto())) {
          Predecesores[itV->obtenerVertice()] = vertice;
          costo[itV->obtenerVertice()] = (costo[vertice] + itV->obtenerCosto());
        }
      }
      Cola.erase(Cola.begin() + pos);
    }
    return Predecesores;
  } /*else {
    std::cout << "Vertice de inicio no existe!\n";
  }*/
  return Predecesores;
}
template <class T>
void Grafo<T>::recorridoPresentacion() {
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (; it != listaAdyacencia.end(); it++) {
    std::cout << it->first << "\n";
    typename std::vector<Vertice<T>>::iterator itV = it->second.begin();
    for (; itV != it->second.end(); itV++) {
      std::cout << "    " << (*itV) << "\n";
    }
  }
}
template <class T>
bool Grafo<T>::esVacio() {
  return this->listaAdyacencia.empty();
}
template <class T>
T Grafo<T>::obtenerCoordXIndice(long index) {
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (long i = 0; i < index; i++, it++)
    ;
  return it->first;
}
template <class T>
long Grafo<T>::obtenerIndiceXCoord(Coordenada c) {
  int i = 0;
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for (; it != listaAdyacencia.end(); it++, i++) {
    if ((*it).first == c) {
      return i;
    }
  }
  return -1;
}
template <class T>
Coordenada Grafo<T>::obtenerCoordenada(int i, int j){
  typename std::map<T, std::vector<Vertice<T>>>::iterator it =
      listaAdyacencia.begin();
  for(;it != listaAdyacencia.end();it++){
    if(it->first.x == i && it->first.y == j){
      return it->first;
    }
  }
  return it->first;
}