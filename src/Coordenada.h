#include <cmath>
#include <iostream>
struct Coordenada {
  long index;
  int x, y;
  char letra;
  
  float costTo(const Coordenada &b) const {
    float resta = (float)(1 + abs(letra - b.letra));
    float resultado = (float)(1 / resta);
    return resultado;
  }
  friend std::ostream &operator<<(std::ostream &o, const Coordenada &p) {
    o <<p.letra<< " [" << p.x << "," << p.y <<"]";
    return o;
  }
  bool operator==(const Coordenada &p) const { return (x == p.x && y == p.y); }
  bool operator()(const Coordenada &p) const { return (index < p.index); }
  bool operator<(const Coordenada &p) const { return index < p.index; }
  bool operator!=(const Coordenada &p) const { return (x != p.x || y != p.y); }
};