#include "Objeto.h"

// Constructor de clase Item, guarda en una lista varios vectores que contienen
// distintos datos de cada objeto
Objeto::Objeto(const std::string& input) {
  std::string linea;
  std::ifstream input_list(input);
  int counter = 0;
  float utilidad = 0;
  float peso = 0;
  float valor = 0;
  float usado = 0;
  std::smatch matches;
  std::regex expresion("([0-9]+) ([0-9]+)");

  while (std::getline(input_list, linea)) {
    switch (counter) {
      case 0:
        cantidad_ = stoi(linea);
        break;
      default:
        if (regex_search(linea, matches, expresion)) {
          int iteracion = 0;
          for (auto match : matches) {
            switch (iteracion) {
              case 1:
                peso = stoi(match);
                break;
              case 2:
                valor = stoi(match);

                break;
            }
            iteracion++;
          }
        }
        break;
    }
    // Elementos del vector representan atributos de cada objeto, en orden
    // siendo peso, valor, utilidad y un valor auxiliar
    if (counter > 0) {
      std::vector<float> aux;
      aux.emplace_back(peso);
      aux.emplace_back(valor);
      utilidad = valor / peso;
      aux.emplace_back(utilidad);
      aux.emplace_back(usado);
      objetos_.emplace_back(aux);
    }
    counter++;
  }
  input_list.close();
  if (cantidad_ != objetos_.size()) {
    std::cerr << "Ha habido un error, la cantidad de items indicada no coincide con los declarados" << std::endl;
    exit(1);
  }
}



// Devuelve tamaño de lista
int Objeto::tamaño(void) const { 
  return cantidad_; 
}



// Devuelve iterador al comienzo de la lista
std::list<std::vector<float>>::iterator Objeto::inicio(void) {
  return objetos_.begin();
}



// Devuelve iterador al final de la lista
std::list<std::vector<float>>::iterator Objeto::fin(void) { 
  return objetos_.end(); 
}