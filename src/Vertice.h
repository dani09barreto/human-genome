#ifndef VERTICE_H
#define VERTICE_H
#include <map>
#include <vector>

#include "Coordenada.h"

template <class T>
class Vertice {
 protected:
  T vertice;
  float costo;

 public:
  Vertice();
  Vertice(T n_vertice, float n_costo);
  ~Vertice();
  T obtenerVertice() const;
  float obtenerCosto() const;
  //bool obtenerVisitado();
  void fijarVertice(T n_vertice);
  void fijarCosto(float costo);
  //void fijarVisitado(bool n_visitado);

  bool operator==(const Vertice &n) const { return (vertice == n.vertice); }
   bool operator!=(const Vertice &n) const { return (vertice != n.vertice); }
  friend std::ostream &operator<<(std::ostream &o, const Vertice &v) {
		o <<"[ "<< v.obtenerVertice()<<" , "<<v.obtenerCosto()<<" ]";
		return o;
	}
};
template <class T>
class CompareVertice {
 public:
  bool operator()(const Vertice<T> &v1, const Vertice<T> &v2) const {
    return (v1.obtenerCosto() > v2.obtenerCosto());
  }
};
#include "Vertice.hxx"

#endif  // VERTICE_H