// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.h: 
//         Contiene la implementación de la clase Alphabet.
// Revisión histórica
//      02/11/2021 - Creación (primera versión) del código
//      23/11/2021 - Continuación de la programación
//      24/11/2021 - Corrección de errores
//      05/11/2021 - Última revisión.
#include "Alphabet.h"

Alphabet::Alphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
}



void Alphabet::add(int symbol) {
  alphabet_.insert(symbol);
}



bool Alphabet::is_symbol(char symbol) {
  return alphabet_.find(symbol) != alphabet_.end();
}


bool Alphabet::is_symbol(std::string string_to_analize) {
  for (char c : string_to_analize) {
    if (is_symbol(c))
      return true;
  }
  return false;
}



Alphabet& Alphabet::operator=(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
  return *this;
}