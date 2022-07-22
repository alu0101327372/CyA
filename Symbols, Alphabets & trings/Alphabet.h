// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Alphabet.h: 
//         Contiene la definición de la clase Alphabet.
// Historial de revisiones 
//          06/10/2021 - Creación (primera versión) del código
//          07/10/2021 - Continuación de programación
//          08/10/2021 - Continuación de programación
//          10/10/2021 - Revisión de errores
//          11/10/2021 - Última revisión.
#ifndef ALPHABET_H_
#define ALPHABET_H_

#include "String.h"

#include <string.h>

#include <vector>
#include <fstream>

class Alphabet {
  public:
    // @brief inserts a line read from file as strings in a vector
    // and sets the last to string_ attribute
    Alphabet(std::string const &str, const char* kDelimiter = " ");

    // Checks if a string symbol belongs to the alphabet
    bool is_symbol(String symbol);
    
    // Returns the length's string of the class 
    std::size_t get_string_length(void);
    
    // Returns the inverse of the string of the  lass 
    std::string get_string_inverse(void);
   
    // Returns the preffix of the string of the class 
    std::string get_string_prefix();

    // Returns the suffix of the string of the class 
    std::string get_string_suffix(void);

    // Returns the substring of the string of the class 
    std::string get_string_substring(void);
  private:
    // Stores strings that had been read from a file
    std::vector<std::string> alphabet_;
    
    // Stores the string to evaluate
    String string_;
};

#endif  // ALPHABET_H_