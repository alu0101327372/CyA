// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.h: 
//         Contiene la definición de la clase Alphabet.
// Revisión histórica
//      09/11/2021 - Creación (primera versión) del código
//      10/11/2021 - Continuación de la programación
//      11/11/2021 - Corrección de errores
//      12/11/2021 - Última revisión.
#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <string>
#include <set>

class Alphabet {
 public:
  Alphabet(void) = default;
  Alphabet(const Alphabet& alphabet);

  void add(char symbol);
  bool is_symbol(char symbol);
  bool is_symbol(std::string aux);
  void set_alphabet(const Alphabet alphabet);  

  Alphabet& operator=(const Alphabet& alphabet);
 private:
  std::set<char> alphabet_;
};

#endif // ALPHABET_H_