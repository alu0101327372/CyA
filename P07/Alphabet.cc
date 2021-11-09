// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.h: 
//         Contiene la implementación de la clase Alphabet.
// Revisión histórica
//      09/11/2021 - Creación (primera versión) del código
//      10/11/2021 - Continuación de la programación
//      11/11/2021 - Corrección de errores
//      12/11/2021 - Última revisión.
#include "Alphabet.h"
/**
 * @brief Construct of copy of Alphabet object
 * 
 * @param rhs 
 */
Alphabet::Alphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
}



/**
 * @brief Insert symbol in alphabet
 * 
 * @param symbol because we use char in set
 */
void Alphabet::add(char symbol) {
  alphabet_.insert(symbol);
}



/**
 * @brief Used to check if the symbol exists in the alphabet
 * 
 * @param symbol the symbol to check
 * @return true if exist 
 * @return false it don't exist
 */
bool Alphabet::is_symbol(char symbol) {
  return alphabet_.find(symbol) != alphabet_.end();
}



/**
 * @brief used to check if the string had all its symbol in the alphabet
 * 
 * @return true if exist
 * @return false 
 */
bool Alphabet::is_symbol(std::string string_to_analize) {
  for (char c : string_to_analize) {
    if (is_symbol(c))
      return true;
  }
  return false;
}



/**
 * @brief Operator of copy
 * 
 * @param rhs 
 * @return Alphabet& 
 */
Alphabet& Alphabet::operator=(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
  return *this;
}