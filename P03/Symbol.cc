// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Symbol.cc: 
//         Contiene la implementación de la clase Symbol.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#include "Symbol.h"

/**
 * @brief Constructs a new Symbol object with the string representation provided.
 * 
 * @param symbol The string representation of the Symbol.
 */
Symbol::Symbol(std::string symbol) {
  set_symbol(symbol);
}



/**
 * @brief FromUtf8Chain generates a sequence of Symbols corresponding to the UTF-8 characters of a string.
 * 
 * @return std::vector<Symbol> Atribute symbol_.
 */
std::string Symbol::get_symbol(void) const {
  return symbol_;
}



/**
 * @brief  Set a symbol of corresponding atribute.
 * 
 * @param symbol The string representation of the Symbol.
 */
void Symbol::set_symbol(std::string symbol) {
  symbol_ = symbol;
}



/**
 * @brief  Overload operator ==.
 * 
 * @param symbol_1 The symbol to compare
 * @param symbol_2 The symbol to compare
 * @return The overolad
 */
bool operator==(const Symbol symbol_1, const Symbol symbol_2) {
  return symbol_1.symbol_ == symbol_2.symbol_;
}



/**
 * @brief  Overload operator <
 * 
 * @param symbol_1 The symbol to compare
 * @param symbol_2 The symbol to compare
 * @return The overolad
 */
bool operator<(const Symbol symbol_1, const Symbol symbol_2) {
  return symbol_1.symbol_ < symbol_2.symbol_;
}



/**
 * @brief  Overload operator >
 * 
 * @param symbol_1 The symbol to compare
 * @param symbol_2 The symbol to compare
 * @return The overolad
 */
bool operator>(const Symbol symbol_1, const Symbol symbol_2) {
  return symbol_1.symbol_ > symbol_2.symbol_;
}