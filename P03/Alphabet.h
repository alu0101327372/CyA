// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.h: 
//         Contiene la definición de la clase Alphabet.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#ifndef ALPHABET_H_
#define ALPHABET_H_

#include "Symbol.h"

#include <set>

class Alphabet {
  public:
    Alphabet(void) = default;
    Alphabet(std::string symbol);

    // @return the alphabet
    std::set<Symbol> get_alphabet(void);


    void set_alphabet(Alphabet& alphabet);

    // @return size of the alphabet
    int get_size(void) const;

    // Inserts symbols in the alphabet
    void push_back(Symbol symbol);

    // Checks if a string symbol belongs to the alphabet
    bool is_symbol(Symbol symbol);

    void operator=(Alphabet& alphabet);
  private:
    // Stores strings that had been read from a file
    std::set<Symbol> alphabet_;

    // Stores the size of the alphabet_
    int size_;
};

#endif  // ALPHABET_H_