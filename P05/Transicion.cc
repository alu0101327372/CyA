// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Materia: Computabilidad y Algoritmia // Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Marco Antonio Cabrera Hernández
// Correo electrónico: alu0101327372@ull.es
// Fecha: 10/04/2021
// Archivo Transicion.h:
//      Contiene la implementacoón de la clase Transicion.
// Revisión histórica
//      26/10/2021 - Creación (primera versión) del código
//      28/10/2021 - Continuación de la programación
//      29/10/2021 - Corrección de errores
//      30/10/2021 - Última revisión.
#include "Transicion.h"

Transicion::Transicion(bool final_cadena, std::unordered_map<char, int> transiciones) : 
  end_strings_(final_cadena), transiciones_(transiciones) {}



// Devuelve el índice de la transición al nuevo estado
int Transicion::obetener_transicion(char symbol) {
  return transiciones_[symbol];
}



// Devuelve verdadero si es el final de la cadena 
bool Transicion::es_final_cadena(void) const {
  return end_strings_;
}