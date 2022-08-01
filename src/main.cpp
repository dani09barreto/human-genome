#include "Shell.h"
#include "Manager.h"
#include <vector>
#include "Controller.h"

std::vector <Shell> commands = {
    Shell("cargar", Controller::Cargar, "nombre_archivo", "carga el archivo especifico", 2)
};

int main(int argc, char const *argv[]){
    Manager Manager {commands};
    Manager.init();
    return 0;
}
