// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alfabeto.cc: 
//         Contiene la implementación de la clase Alfabeto.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#include "Alfabeto.h"

void Alfabeto::add(char caracter) {
  alfabeto_.push_back(caracter);
}

// Comprueba si un caracter pertenece al alfabeto
bool Alfabeto::es_caracter(char& caracter) {
  for (int i = 0; i < alfabeto_.size(); i++) {
    if (caracter == alfabeto_[i]) {
      return true;
    }
  }
  return false;
}