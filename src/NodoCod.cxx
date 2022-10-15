#include "NodoCod.h"
#include <iostream>
NodoCod::NodoCod() {
	this->hijoDer = nullptr;
	this->hijoIzq = nullptr;
}
NodoCod::NodoCod(int n_freq, char n_letra) {
	this->hijoDer = nullptr;
	this->hijoIzq = nullptr;
	this->freq = n_freq;
	this->letra = n_letra;
}
NodoCod::~NodoCod() {
	if (this->hijoDer != nullptr) {
		delete this->hijoDer;
		this->hijoDer = nullptr;
	}
	if (this->hijoIzq != nullptr) {
		delete this->hijoIzq;
		this->hijoIzq = nullptr;
	}
}
void NodoCod::fijarFreqLetra(int n_freq, char n_letra) {
	this->freq = n_freq;
	this->letra = n_letra;
}
int NodoCod::obtenerFreq() {
	return this->freq;
}
char NodoCod::obtenerLetra() {
	return this->letra;
}
NodoCod *NodoCod::obtenerHijoIzq() {
	return this->hijoIzq;
}
NodoCod *NodoCod::obtenerHijoDer() {
	return this->hijoDer;
}
void NodoCod::fijarHijoIzq(NodoCod *izq) {
	this->hijoIzq = izq;
}
void NodoCod::fijarHijoDer(NodoCod *der) {
	this->hijoDer = der;
}
void NodoCod::inOrden() {
	if (this->hijoIzq != nullptr)
		(this->hijoIzq)->inOrden();
	std::cout << this->freq << this->letra << " ";
	if (this->hijoDer != nullptr)
		(this->hijoDer)->inOrden();
}
void NodoCod::preOrden() {
	std::cout << this->freq << this->letra << "\n";
	if (this->hijoIzq != nullptr)
		(this->hijoIzq)->preOrden();
	if (this->hijoDer != nullptr)
		(this->hijoDer)->preOrden();
}
bool NodoCod::esHoja() {
	return (this->hijoIzq == nullptr && this->hijoDer == nullptr);
}