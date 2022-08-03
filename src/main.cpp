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
    Shell("guardar",Controller::Cargar,"guardar <nombre_archivo>","Guarda en el <nombre_archivo> las secuencias",2), 
    Shell("salir",Controller::salir,"salir","Se termina la ejecucion",1), 
    Shell("codficar",Controller::Cargar,"","",3), 
    Shell("decodificar,",Controller::Cargar,"","",3), 
    Shell("decodificar",Controller::Cargar,"","",3), 
    Shell("decodificar",Controller::Cargar,"","",3) 
};

int main(int argc, char const *argv[]){
	//Inicializar al manager, gestionador de comandos
    Manager Manager {commands};
    Manager.init();
    return 0;
}
