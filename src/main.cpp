 /* @file main.cpp
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma Humano (Estructuras de datos 2022-3)
 */
#include "Shell.h"
#include "Manager.h"
#include <vector>
#include "Controller.h"
//Lista de todos los comandos posibles que se pueden ejecutar en el programa.
std::vector <Shell> commands = {
    Shell("cargar", Controller::Cargar, "cargar <nombre_archivo>", "carga el archivo especifico", 2),
    Shell("conteo",Controller::conteo,"conteo","Imprime la cantidad de secuencias",1), 
    Shell("listar_secuencias",Controller::listar_secuencias,"listar_secuencias","Imprime la informacion de cada secuencia",1), 
    Shell("histograma",Controller::histograma,"histograma <descripcion_secuencia>","Imprime el histograma de una secuencia",2), 
    Shell("es_subsecuencia",Controller::es_subsecuencia,"es_subsecuencia <secuencia>","Determina si una secuencia existe dentro de las secuencias cargadas",2), 
    Shell("enmascarar",Controller::enmascarar,"enmascarar <secuencia>","Enmascara una secuencia determinada con el codigo X",2), 
    Shell("guardar",Controller::guardar,"guardar <nombre_archivo>","Guarda en el <nombre_archivo> las secuencias",2), 
    Shell("codficar",Controller::codificar,"codificar nombre_archivo.fabin","El comando debe generar el archivo binario con la correspondiente codificacion de Huffman",2), 
    Shell("decodificar",Controller::decodificar,"decodificar nombre_archivo.fabin","El comando debe cargar en memoria las secuencias contenidas en el archivo binario \n\tnombre_archivo.fabin, que contiene una codificacion Huffman",2), 
    Shell("ruta_mas_corta",Controller::decodificar,"ruta_mas_corta descripcion_secuencia i j x y","imprime en pantalla la secuencia de vertices (bases) del grafo que describen la ruta mas corta \n\tentre la base ubicada en la posicion [i ,j ] de la matriz de la secuenciadescripcion_secuencia y la base ubicada \n\ten la posicion [x ,y ] de la misma matriz",6), 
    Shell("base_remota",Controller::Cargar,"base_remota descripcion_secuencia i j","busca la ubicacion de la misma base (misma letra) mas lejana dentro de la matriz",4),
    Shell("salir",Controller::salir,"salir","Se termina la ejecucion",1),
    Shell("clear",Controller::clear,"clear","Limpia consola",1),
};

int main(int argc, char const *argv[]){
	//Inicializar al manager, gestionador de comandos
    Manager Manager {commands};
    Manager.init();
    return 0;
}
