#include "Vertice.h"

template <class T>
Vertice<T>::Vertice() {}
template <class T>
Vertice<T>::Vertice(T n_vertice, float n_costo) {
  this->vertice = n_vertice;
  this->costo = n_costo;
}
template <class T>
Vertice<T>::~Vertice() {}

template <class T>
T Vertice<T>::obtenerVertice()const {
  return this->vertice;
}
template <class T>
float Vertice<T>::obtenerCosto() const{
  return this->costo;
}
template <class T>
void Vertice<T>::fijarVertice(T n_vertice) {
  this->vertice = n_vertice;
}
template <class T>
void Vertice<T>::fijarCosto(float n_costo) {
  this->costo = n_costo;
}