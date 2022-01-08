// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 11: Algoritmos voraces
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 16/12/2021
// Archivo Mochila.h: 
//         Contiene la implementación de la clase Mochila.
// Revisión histórica
//      16/12/2021 - Creación (primera versión) del código
//      17/12/2021 - Continuación de la programación
//      18/12/2021 - Corrección de errores
//      19/12/2021 - Última revisión.
#include "Mochila.h"

/**
 * @brief Constructor de la clase
 * 
 * @param peso peso de la mochila
 */
Mochila::Mochila(float peso) {
  peso_max_ = peso;
  peso_actual_ = 0;
  beneficio_ = 0;
}



/**
 * @brief Funcion que introduce objetos en la mochila, 
 * los objetos son unicos y se pueden introducir fracciones de ellos mismos
 * 
 * @param objetos objetos de la mochila
 */
void Mochila::insertar_objeto(Objeto& objetos) {
  float utilidad_maxima = 0;
  float fraccion = 0;
  int object_number = 1;
  auto posicion = objetos.inicio();
  const int indice_peso = 0;
  const int indice_valor = 1;
  const int indice_utilidad = 2;
  const int indice_usado = 3;
  const float zero = 0;
  // Se repite mientras la mochila no este llena y queden objetos para seguir
  // metifino
  while (peso_actual_ < peso_max_ && orden_.size() < objetos.tamano()) {
    int counter = 1;
    utilidad_maxima = 0;
    const int size = objetos.tamano();
    // Se recorre lista para encontrar objeto con mayor utilidad sin repetir
    for (auto it = objetos.inicio(); it != objetos.fin(); ++it) {
      if ((it->at(indice_utilidad) > utilidad_maxima) && (it->at(indice_usado) == zero)) {
        utilidad_maxima = it->at(indice_utilidad);
        object_number = counter;
        posicion = it;
      }
      counter++;
    }
    fraccion = espacio() / posicion->at(indice_peso);
    if (fraccion > 1) {
      fraccion = 1;
    }
    peso_actual_ = peso_actual_ + posicion->at(indice_peso) * fraccion;
    beneficio_ = beneficio_ + posicion->at(indice_valor) * fraccion;
    orden_.emplace_back(std::make_pair(object_number, fraccion));
    posicion->at(indice_usado) = 1;
  }
}



/**
 * @brief Funcion que introduce objetos en la mochila, 
 * los objetos son ilimitados pero no se pueden fraccionar
 * 
 * @param objetos objetos de la mochila
 */
void Mochila::insertar_no_acotado(Objeto& objetos) {
  float utilidad_maxima = 0;
  int fraccion = 0;
  int object_number = 1;
  auto posicion = objetos.inicio();
  const int indice_peso = 0;
  const int indice_valor = 1;
  const int indice_utilidad = 2;
  const float zero = 0;
  bool disponible = true;
  // Se repite mientras la mochila no este llena y exista algun objeto que pueda
  // ser introducido en la mochila
  while (peso_actual_ < peso_max_ && disponible) {
    int counter = 1;
    utilidad_maxima = 0;
    const int size = objetos.tamano();
    disponible = false;
    // Se recorre lista para encontrar item con mayor utilidad que pueda entrar
    for (auto it = objetos.inicio(); it != objetos.fin(); ++it) {
      if (it->at(indice_utilidad) > utilidad_maxima && it->at(indice_peso) <= espacio()) {
        utilidad_maxima = it->at(indice_utilidad);
        object_number = counter;
        posicion = it;
        disponible = true;
      }
      counter++;
    }
    fraccion = espacio() / posicion->at(indice_peso);
    if (fraccion > 0) {
      peso_actual_ = peso_actual_ + posicion->at(indice_peso) * fraccion;
      beneficio_ = beneficio_ + posicion->at(indice_valor) * fraccion;
      orden_.emplace_back(std::make_pair(object_number, fraccion));
    }
  }
}



/**
 * @brief Devuelve cuanto queda por llenar en la mochila
 * 
 */
float Mochila::espacio() { 
  return peso_max_ - peso_actual_; 
}



/**
 * @brief Escribe en pantalla la solucion a la que se ha llegado
 * 
 */
void Mochila::imprimir() {
  const int size = orden_.size();
  std::cout << "Beneficio: " << beneficio_ << std::endl;
  std::cout << "Peso: " << peso_actual_ << std::endl;
  std::cout << "Solucion: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << orden_[i].first << ":" << orden_[i].second << " ";
  }
  std::cout << std::endl;
}