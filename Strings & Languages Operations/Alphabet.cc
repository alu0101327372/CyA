// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.cc: 
//         Contiene la implementación de la clase Alphabet.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#include "Alphabet.h"

/**
 * @brief Constructs a new Alphabet object using the symbols provided.
 * 
 * @param symbol Symbol from which it creates the alphabet.
 */
Alphabet::Alphabet(std::string symbol) {
  Symbol aux = symbol;
  alphabet_.emplace(aux);
  size_ = alphabet_.size();
}



/**
 * @brief Inserts symbols in the alphabet.
 * 
 * @param symbol Symbol insert in the alphabet.
 */
void Alphabet::push_back(Symbol symbol) {
  if (is_symbol(symbol) == false) {
    alphabet_.erase(symbol);
  }
}



/**
 * @brief Checks if a Symbol belongs to the alphabet.
 *
 * @param symbol Symbol to check.
 * @return true If the symbol belongs to the alphabet.
 * @return false If the symbol does not belong to the alphabet.
 */
bool Alphabet::is_symbol(Symbol symbol) {
  std::set<Symbol>::iterator it = alphabet_.find(symbol);
  if (it != alphabet_.end())
    return false;
  
  return true;
}



/**
 * @brief Get the size of the alphabet.
 * 
 * @return int Size of the alphabet.
 */
int Alphabet::get_size(void) const {
  return alphabet_.size();
}



/**
 * @brief Gets the alphabet.
 * 
 * @return std::vector<Symbol> The alphabet.
 */
std::set<Symbol> Alphabet::get_alphabet(void) {
  return alphabet_;
}



void Alphabet::set_alphabet(Alphabet& alphabet) {
  *this = alphabet;
}




void Alphabet::operator=(Alphabet& alphabet) {
  alphabet.set_alphabet(*this);
}