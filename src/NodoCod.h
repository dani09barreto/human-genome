#ifndef NodoCod_H
#define NodoCod_H
#include <vector>
class NodoCod {
protected:
	int freq;
	char letra;
	NodoCod *hijoIzq;
	NodoCod *hijoDer;

public:
	NodoCod();
	NodoCod(int n_freq, char n_letra);
	~NodoCod();
	void fijarFreqLetra(int n_freq, char n_letra);
	int obtenerFreq();
	char obtenerLetra();
	void inOrden();
	void preOrden();
	NodoCod *obtenerHijoIzq();
	NodoCod *obtenerHijoDer();
	bool esHoja();
	void fijarHijoIzq(NodoCod *izq);
	void fijarHijoDer(NodoCod *der);
};
/*Clase auxiliar que sirve para facilitar
la comparación de frecuencias a la hora
de armar la cola de prioridad de menor a mayor.
Teniendo en cuenta que en la STL de por sí
se ordenar de mayor a menor.*/
class Compare {
public:
	bool operator()(NodoCod *a, NodoCod *b) {
		return a->obtenerFreq() > b->obtenerFreq();
	}
};
#endif