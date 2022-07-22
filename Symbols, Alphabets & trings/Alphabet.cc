// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.cc: 
//         Contiene la implementación de la clase Alphabet.
// Historial de revisiones 
//          06/10/2021 - Creación (primera versión) del código
//          07/10/2021 - Continuación de programación
//          08/10/2021 - Continuación de programación
//          10/10/2021 - Revisión de errores
//          11/10/2021 - Última revisión.
#include "Alphabet.h"

// @brief inserts a line read from file as strings in a vector
// and sets the last to string_ attribute
Alphabet::Alphabet(std::string const &str, const char* kDelimiter) {
  char *word = strtok(const_cast<char*>(str.c_str()), kDelimiter); 
    
  while (word != nullptr) { 
    alphabet_.push_back(std::string(word)); 
    word = strtok(nullptr, kDelimiter); 
  }
  string_.set_string(alphabet_.back().data());
}



// Checks if a string symbol belongs to the alphabet
bool Alphabet::is_symbol(String symbol) {
  for (int i = 0; i < alphabet_.size(); i++) {
    if (symbol.get_data() == alphabet_[i].data())
      return true;
  }
  return false;
}



// @return the length's string of the class 
std::size_t Alphabet::get_string_length(void) {
  return string_.get_length();
}



// @return  the inverse of the string of the class 
std::string Alphabet::get_string_inverse() {
  return string_.get_inverse();
}



// @return  the preffix of the string of the class 
std::string Alphabet::get_string_prefix() {
  return string_.get_prefix();
}



// @return the suffix of the string of the class 
std::string Alphabet::get_string_suffix() {
  return string_.get_suffix();
}



// @return the substring of the string of the class 
std::string Alphabet::get_string_substring() {
  return string_.get_substring();
}