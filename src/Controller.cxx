/* @file Controller.cxx
 *  @authors Daniel Barreto, Santiago Gutierrez, Juan Paez
 *  @brief Proyecto Genoma (Estructuras de datos 2022-3)
 */

#include "Controller.h"

#include <bitset>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stack>
#include <string>

std::list<Sequence> sequences;
std::vector<int> frequencies;
std::vector<char> letters = {'A', 'C', 'G', 'T', 'U', 'R', 'Y', 'K', 'M',
                             'S', 'W', 'B', 'D', 'H', 'V', 'N', 'X', '-'};

std::map<char, std::string> keyCodes;
typedef Grafo<Coordenada> Tgrafo;
Tgrafo grafo;
void Controller::Cargar(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  std::string line;
  std::ifstream inputFile;
  inputFile.open(argvs[1]);
  try {
    if (!inputFile.is_open())  // No existe el archivo o no se puede abrir
      throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_OPEN_FILE);
    if (inputFile.peek() ==
        std::ifstream::traits_type::eof())  // Comprobar que el archivo no este
                                            // vacio
      throw Shell::SyntaxError(Shell::SyntaxError::TypeError::EMPTY_FILE);
  } catch (Shell::SyntaxError &e) {  // excepciones generadas en la compilacion
    std::cout << "[Error]: " << argvs[1] << " " << e.error();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  // Reiniciar estructuras
  sequences.clear();

  std::list<Sequence>::iterator itSeq = sequences.begin();

  for (std::string line; std::getline(inputFile, line);) {
    if (std::string::npos != line.find(">")) {  // Si es una nueva secuencia
      Sequence auxSeq;
      auxSeq.setName(line);
      sequences.push_back(auxSeq);
    } else {
      std::list<Sequence>::reference ref = sequences.back();
      ref.addLine(line);
    }
  }
  updateFreqMatrix();

  if (sequences.size() == 1) {
    std::cout << "1 secuencia cargada correctamente desde " << argvs[1]
              << std::endl;
  } else if (sequences.size() > 1) {
    std::cout << sequences.size() << " secuencias cargadas correctamente desde "
              << argvs[1] << std::endl;
  }
  // inputFile.close();
}

void Controller::conteo(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  if (sequences.size() == 0) {
    std::cout << "No hay secuencias cargadas en memoria." << std::endl;
  } else if (sequences.size() == 1) {
    std::cout << "1 secuencia en memoria." << std::endl;
  } else {
    std::cout << sequences.size() << " secuencias en memoria." << std::endl;
  }
}

void Controller::salir(Shell::argv_t argvs, Shell command) {
  std::cout << "Saliendo....\n";
  exit(3);
}

void Controller::listar_secuencias(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  std::list<Sequence>::iterator itSeq = sequences.begin();
  std::string auxName = "";
  if (sequences.empty()) {
    std::cout << "No hay secuencias cargadas en memoria." << std::endl;
  } else {
    for (; itSeq != sequences.end(); itSeq++) {
      auxName = (*itSeq).getName().erase(0, 1);
      if ((*itSeq).getComplete()) {
        std::cout << "Secuencia " << auxName << " contiene "
                  << (*itSeq).countDifBases() << " bases.\n";
      } else {
        std::cout << "Secuencia " << auxName << " contiene al menos "
                  << (*itSeq).countDifBases() << " bases.\n";
      }
    }
  }
}

void Controller::histograma(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  if (sequences.empty()) {
    std::cout << "No hay secuencias cargadas en memoria.";
    return;
  }

  std::string auxNameSeq = ">" + argvs[1];
  std::list<Sequence>::iterator itS = sequences.begin();
  // std::cout<<auxNameSeq;
  bool find = false;
  for (; itS != sequences.end(); itS++) {
    if ((*itS).getName() == auxNameSeq) {
      find = true;
      break;
    }
  }
  if (find) {
    (*itS).printCountBases();
  } else {
    std::cout << "Secuencia invalida.";
  }
}

void Controller::es_subsecuencia(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  if (sequences.size() == 0) {
    std::cout << "No hay secuencias cargadas en memoria" << std::endl;
    return;
  }

  std::string subSequencie = argvs[1];
  int nSecuencias = 0;

  for (Sequence sec : sequences) {
    std::string sequence = sec.getBasesConcat();
    int found = -argvs[1].size();
    do {
      found = sequence.find(subSequencie, found + argvs[1].size());
      if (found != -1) nSecuencias++;

    } while (found != -1);
  }
  if (nSecuencias == 0)
    std::cout << "La secuencia dada no existe." << std::endl;
  else
    std::cout << "La secuencia dada se repite " << nSecuencias << " veces"
              << std::endl;
}

void Controller::enmascarar(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }

  if (sequences.size() == 0) {
    std::cout << "No hay secuencias cargadas en memoria" << std::endl;
    return;
  }
  int nSecuencias = 0;
  std::string subSequencie = argvs[1];
  std::list<Sequence>::iterator itSeq = sequences.begin();

  for (; itSeq != sequences.end(); itSeq++) {
    std::string sequence = (*itSeq).getBasesConcat();
    int found = -1;
    do {
      found = sequence.find(subSequencie, found + argvs[1].size());
      if (found != -1) nSecuencias++;

      for (int i = found; i < found + subSequencie.size(); i++) {
        sequence.at(i) = 'X';
      }
    } while (found != -1);
    (*itSeq).setBasesConcat(sequence);
    itSeq->updateStruct();
    // itSeq->generateMatrix();
  }

  if (nSecuencias == 0) {
    std::cout << "La secuencia dada no existe." << std::endl;
    return;
  }
  updateFreqMatrix();
  if (nSecuencias == 1) {
    std::cout << "1 secuencia ha sido enmascarada." << std::endl;
    return;
  }
  std::cout << nSecuencias << " secuencias han sido enmascaradas" << std::endl;
}

void Controller::guardar(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  if (argvs[1].substr(argvs[1].find_last_of(".") + 1) != "fa") {
    throw Shell::SyntaxError(
        Shell::SyntaxError::TypeError::EXTENSION_ERROR_FILE_FA);
  }

  if (sequences.size() == 0) {
    std::cout << " No hay secuencias cargadas en memoria" << std::endl;
    return;
  }
  try {
    std ::fstream outFile;
    outFile.open(argvs[1], std::ios::out);
    for (Sequence sec : sequences) {
      outFile << sec.getName() << "\n";
      for (Line line : sec.getBases()) {
        outFile << line.getLine() << "\n";
      }
    }
    std::cout << "Las secuencias han sido guardadas en " << argvs[1]
              << std::endl;
  } catch (std::exception e) {
    std::cout << "Error guardando en " << argvs[1] << std::endl;
  }
}

void Controller::codificar(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  if (argvs[1].substr(argvs[1].find_last_of(".") + 1) != "fabin") {
    throw Shell::SyntaxError(
        Shell::SyntaxError::TypeError::EXTENSION_ERROR_FILE_FABIN);
  }
  ArbolCod *arbolCod = new ArbolCod();
  arbolCod->generarPQParaArbol(letters, frequencies);

  // Copiar map de codigos con su respectiva letra
  keyCodes.clear();
  keyCodes = arbolCod->obtenerCodigos();

  std::map<char, std::string>::iterator itMap;
  /*   for (itMap = keyCodes.begin(); itMap != keyCodes.end(); itMap++) {
      std::cout << itMap->first          // char con la letra (key)
                << ':' << itMap->second  // string con el codigo
                << std::endl;
    }
    for (int i = 0; i < letters.size(); i++) {
      std::cout << letters[i] << " " << frequencies[i] << std::endl;
    } */
  std::ofstream wf(argvs[1], std::ios::out | std::ios::binary);
  if (!wf) {
    std::cout << "No se pueden guardar las secuencias cargadas en " << argvs[1]
              << std::endl;
    throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_OPEN_FILE);
  }
  short cantiDif = 0;
  int cantSequences = sequences.size();

  for (int i = 0; i < frequencies.size(); i++) {
    if (frequencies.at(i) != 0) {
      cantiDif++;
    }
  }
  wf.write((char *)&cantiDif, sizeof(short));

  for (int i = 0; i < letters.size(); i++) {
    if (frequencies[i] != 0) {
      wf.write((char *)&letters[i], sizeof(char));
      long long aux = frequencies[i];
      wf.write((char *)&aux, sizeof(long long));
    }
  }

  wf.write((char *)&cantSequences, sizeof(cantSequences));

  for (Sequence sec : sequences) {
    short tamaNombre = sec.getName().size();
    wf.write((char *)&tamaNombre, sizeof(short));

    for (char ch : sec.getName()) {
      wf.write((char *)&ch, sizeof(char));
    }
    long long cantBases = sec.getBasesConcat().size();
    wf.write((char *)&cantBases, sizeof(long long));
    std::list<Line>::iterator itL = sec.getBases().begin();
    short legthLine = (*itL).getLenght();
    wf.write((char *)&legthLine, sizeof(short));

    int lengthBytes = 1;

    std::string str = "";
    std::stringstream strBites;
    for (char ch : sec.getBasesConcat()) {
      itMap = keyCodes.find(ch);
      str += itMap->second;
    }
    int contBites = 0;
    for (char ch : str) {
      if (contBites == 7) {
        strBites << ch;
        strBites << " ";
        contBites = 0;
        lengthBytes++;
      } else {
        strBites << ch;
        contBites++;
      }
    }
    std::string bytes;
    wf.write((char *)&lengthBytes, sizeof(lengthBytes));

    while (!strBites.eof()) {
      strBites >> bytes;
      if (bytes.size() != 8) {
        int size = bytes.size();
        for (int k = 0; k < 8 - size; k++) {
          bytes += '0';
        }
      }
      std::bitset<8> bit{bytes};
      wf.write((char *)&bit, sizeof(bit));
    }
  }
  wf.close();
  std::cout << "Secuencias codificadas y almacenadas en " << argvs[1]
            << std::endl;
}

void Controller::decodificar(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  sequences.clear();
  std::ifstream rf(argvs[1], std::ios::out | std::ios::binary);
  if (!rf) {
    std::cout << "No se pueden guardar las secuencias cargadas en " << argvs[1]
              << std::endl;
    throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_OPEN_FILE);
  }
  initFreq();
  short lenghtBases;
  rf.read((char *)&lenghtBases, sizeof(short));
  for (int i = 0; i < lenghtBases; i++) {
    char base;
    long long count;
    rf.read((char *)&base, sizeof(char));
    rf.read((char *)&count, sizeof(long long));
    fillFreq(base, count);
  }
  ArbolCod *arbolcod = new ArbolCod();
  arbolcod->generarPQParaArbol(letters, frequencies);
  keyCodes.clear();
  keyCodes = arbolcod->obtenerCodigos();

  // Se recibe cantidad de secuencias en el archivo
  int cantSeq;
  rf.read((char *)&cantSeq, sizeof(cantSeq));
  short sizeName;
  std::string name;
  long long cantBases;
  short ident;
  int lengthBytes;

  // se recorre el archivo dependiendo de la cantidad de secuencia
  for (int i = 0; i < cantSeq; i++) {
    name = "";
    Sequence seqAux;
    // se recibe tamaño del nombre
    rf.read((char *)&sizeName, sizeof(sizeName));
    // nombre secuencia
    for (int j = 0; j < sizeName; ++j) {
      char c;
      // se recibe el nombre caracter por caracter
      rf.read((char *)&c, sizeof(char));
      name += c;
    }
    seqAux.setName(name);
    std::bitset<8> bit;
    std::string bitchar = "";
    // se lee la cantidad de bases en la secuencia
    rf.read((char *)&cantBases, sizeof(cantBases));
    // se lee la indentacion de cada linea
    rf.read((char *)&ident, sizeof(short));
    // se lee la cantidad de bytes en la secuenca (solo para decodificar no para
    // armar secuencia)
    rf.read((char *)&lengthBytes, sizeof(lengthBytes));
    int contBases = 0;
    std::string concatBases;
    for (int i = 0; i < lengthBytes; i++) {
      rf.read((char *)&bit, sizeof(bit));
      bitchar += bit.to_string();
    }
    // se retorna las bases concatenadas desencriptadas
    concatBases = arbolcod->decodificar(bitchar, cantBases);
    // std::cout << name << std::endl;
    // std::cout << concatBases << std::endl;
    seqAux.setBasesConcat(concatBases);
    seqAux.updateStruct(ident);
    seqAux.generateMatrix();
    // se debe crear una nueva secuencia con (nombre, basesConcat, indentacion)
    // crear cada linea dependiendo la indentacion
    // añadir linea a secuencia y luego añadir secuencia a la lista de
    // secuencias
    sequences.push_back(seqAux);
  }
  rf.close();
  std::cout << "Secuencias decodificadas desde " << argvs[1]
            << " y cargadas en memoria." << std::endl;
}

void Controller::ruta_mas_corta(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  std::string auxNameSeq = ">" + argvs[1];
  std::list<Sequence>::iterator itS = sequences.begin();
  // std::cout<<auxNameSeq;
  bool find = false;
  for (; itS != sequences.end(); itS++) {
    if ((*itS).getName() == auxNameSeq) {
      find = true;
      break;
    }
  }
  if (!find) {
    std::cout << "La secuencia " + argvs[1] + " no existe.";
    return;
  }
  std::cout << (*itS).getCantiFil() << "\n";
  std::cout << (*itS).getCantiCol() << "\n";
  int coord_i = std::stoi(argvs[2]);
  int coord_j = std::stoi(argvs[3]);

  if ((coord_i < 0 || coord_j < 0)) {
    std::cout << "La base origen en la posicion [" + std::to_string(coord_i) +
                     "," + std::to_string(coord_j) + "] no existe";
    return;
  }
  if (coord_i > (*itS).getCantiFil() - 1 ||
      coord_j > (*itS).getCantiCol() - 1) {
    std::cout << "La base origen en la posicion [" + std::to_string(coord_i) +
                     "," + std::to_string(coord_j) + "] no existe";
    return;
  }
  int coord_x = std::stoi(argvs[4]);
  int coord_y = std::stoi(argvs[5]);
  if ((coord_x < 0 || coord_y < 0)) {
    std::cout << "La base destino en la posicion [" + std::to_string(coord_x) +
                     "," + std::to_string(coord_y) + "] no existe";
    return;
  }
  if (coord_x > (*itS).getCantiFil() - 1 ||
      coord_y > (*itS).getCantiCol() - 1) {
    std::cout << "La base destino en la posicion [" + std::to_string(coord_x) +
                     "," + std::to_string(coord_y) + "] no existe";
    return;
  }
  generarGrafo((*itS));
  grafo.recorridoPresentacion();

  std::cout << grafo.obtenerCantiAristas();
}

void Controller::base_remota(Shell::argv_t argvs, Shell command) {
  if (Controller::verificationARGV(argvs, command) > 0) {
    return;
  }
  std::string auxNameSeq = ">" + argvs[1];
  std::list<Sequence>::iterator itS = sequences.begin();
  bool find = false;
  for (; itS != sequences.end(); itS++) {
    if ((*itS).getName() == auxNameSeq) {
      find = true;
      break;
    }
  }
  if (!find) {
    std::cout << "La secuencia " + argvs[1] + " no existe.";
    return;
  }
  int coord_i = std::stoi(argvs[2]);
  int coord_j = std::stoi(argvs[3]);

  if ((coord_i < 0 || coord_j < 0)) {
    std::cout << "La base origen en la posicion [" + std::to_string(coord_i) +
                     "," + std::to_string(coord_j) + "] no existe";
    return;
  }
  if (coord_i > (*itS).getCantiFil() - 1 ||
      coord_j > (*itS).getCantiCol() - 1) {
    std::cout << "La base origen en la posicion [" + std::to_string(coord_i) +
                     "," + std::to_string(coord_j) + "] no existe";
    return;
  }
  generarGrafo((*itS));
  Coordenada aux = grafo.obtenerCoordenada(coord_i, coord_j);
  std::cout << coord_i << " " << coord_j << "\n";
  std::vector<Coordenada> lista = grafo.obtenerListaVertices();
  float mayor = 0;
  float dist;
  float X, Y;
  Coordenada lejano;
  for (int i = 0; i < lista.size(); i++) {
    if (lista[i].letra == aux.letra) {
      X = lista[i].x - aux.x;
      Y = lista[i].y - aux.y;
      dist = sqrt((X * X) + (Y * Y));
      if (dist > mayor) {
        mayor = dist;
        lejano = lista[i];
      }
    }
  }
  std::cout << lejano << "\n";
  std::map<Coordenada, float> costo;
  std::map<Coordenada, Coordenada> Predecesores =
      grafo.algoritmoDijkstra(aux, costo);
  float costoR = costo[lejano];
  std::vector<Coordenada> ruta = rutaCostoMinimo(lejano, Predecesores);
  std::cout << "Para la secuencia " << (*itS).getName()
            << " , la base remota esta ubicada en [" << lejano.x << ","
            << lejano.y << "], y la ruta entre la base en [" << aux.x << ","
            << aux.y << "] y la base remota en [" << lejano.x << "," << lejano.y
            << "] es:\n";
  for (int i = 0; i < ruta.size(); i++) {
    std::cout << ruta[i] << "->";
  }
  std::cout << "\nEl costo total de la ruta es: " << costo[lejano] << "\n";
}

int Controller::verificationARGV(Shell::argv_t argvs, Shell command) {
  if (argvs[0].compare("ayuda") == 0 && argvs.size() == 2) {
    std::cout << "\nComando:\n";
    std::cout << "- " << command.getCommand() << "\n\t"
              << "Uso: " << command.getCommandUsage()
              << "\n\tDescripcion: " << command.getCommandDescription() << "\n";
    return 1;
  } else if (argvs.size() != command.getArgc()) {
    throw Shell::SyntaxError(Shell::SyntaxError::TypeError::ERROR_AGV);
    return 2;
  }
  return 0;
}

void Controller::clear(Shell::argv_t argvs, Shell command) {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}
// Funciones auxiliares segunda entrega
void Controller::updateFreqMatrix() {
  frequencies.clear();
  frequencies.assign(18, 0);
  std::vector<int> freq;
  std::list<Sequence>::iterator itSeq = sequences.begin();
  itSeq = sequences.begin();
  for (int i = 0; itSeq != sequences.end(); itSeq++, i++) {
    (*itSeq).updatecountBases();
    freq = (*itSeq).getVecFrequencies();

    for (int i = 0; i < frequencies.size(); i++) {
      // Frecuencias en su letra sumele la frecuencia de la secuencia
      frequencies.at(i) = frequencies.at(i) + freq.at(i);
    }
    // Generar matriz por cada secuencia
    (*itSeq).generateMatrix();
  }
}
void Controller::initFreq() { frequencies.assign(18, 0); }
void Controller::fillFreq(char letter, long long cont) {
  for (int i = 0; i < 18; i++) {
    if (letters[i] == letter) frequencies[i] = cont;
  }
}
// Funcione auxiliares tercera entrega
void Controller::generarGrafo(Sequence seq) {
  grafo.~Grafo();

  char auxMatrix[MAX][MAX];
  seq.getMatrix(auxMatrix);
  Coordenada auxCord;
  int k = 0;
  // Agregar todos los vertices, que seria agregar cada posición de la matriz
  for (int i = 0; i < seq.getCantiFil(); i++) {
    for (int j = 0; j < seq.getCantiCol(); j++, k++) {
      if (auxMatrix[i][j] != '#') {
        auxCord.index = k;
        auxCord.x = i;
        auxCord.y = j;
        auxCord.letra = auxMatrix[i][j];
        grafo.insertarVertice(auxCord);
      }
    }
  }
  //  Agregar las aristas teniendo en cuenta un posiblemente desfasamiento
  int vIzq, vDer, vSup, vInf;
  Coordenada vecino;
  for (int i = 0; i < seq.getCantiFil(); i++) {
    for (int j = 0; j < seq.getCantiCol(); j++) {
      auxCord = grafo.obtenerCoordenada(i, j);
      /*
      auxCord.x = i;
      auxCord.y = j;
      auxCord.letra = auxMatrix[i][j];*/

      vSup = i - 1;
      vInf = i + 1;
      vIzq = j + 1;
      vDer = j - 1;
      if (auxMatrix[i][j] != '#') {
        // Agregar vecino superior
        if (vSup != -1) {
          vecino = grafo.obtenerCoordenada(vSup, j);
          grafo.insertarArista(auxCord, vecino, auxCord.costTo(vecino));
        }
        // Agregar vecino inferior
        if (vInf < seq.getCantiFil() && auxMatrix[vInf][j] != '#') {
          vecino = grafo.obtenerCoordenada(vInf, j);
          grafo.insertarArista(auxCord, vecino, auxCord.costTo(vecino));
        }
        // Agregar vecino izquierdo
        if (vIzq < seq.getCantiCol() && auxMatrix[i][vIzq] != '#') {
          vecino = grafo.obtenerCoordenada(i, vIzq);
          grafo.insertarArista(auxCord, vecino, auxCord.costTo(vecino));
        }
        // Agregar vecino derecho
        if (vDer != -1 && auxMatrix[i][vDer] != '#') {
          vecino = grafo.obtenerCoordenada(i, vDer);
          grafo.insertarArista(auxCord, vecino, auxCord.costTo(vecino));
        }
      }
    }
  }
}

std::vector<Coordenada> Controller::rutaCostoMinimo(
    Coordenada end_id, std::map<Coordenada, Coordenada> predecesores) {
  std::stack<Coordenada> pila;
  std::vector<Coordenada> ruta;
  Coordenada it = predecesores[end_id];

  while (true) {
    if (it == predecesores[it]) {
      pila.push(it);
      break;
    }
    pila.push(it);
    it = predecesores[it];
  }

  while (!pila.empty()) {
    ruta.push_back(pila.top());
    pila.pop();
  }

  return ruta;
}