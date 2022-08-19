#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <list>

class Secuencia {
  public:
   Secuencia();
   std::string ObtenerNombre();
   void FijarNombre(std::string n_nombre);
   void AgregarBase(char base);
  
  protected:
   std::list<char> bases;
   int cantiBases;
   std::char*100 nombre;
   bool completa;
};

#endif //__SECUENCIA__H__
