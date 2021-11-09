// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo String.h: 
//         Contiene la definición de la clase String.
// Historial de revisiones 
//          06/10/2021 - Creación (primera versión) del código
//          07/10/2021 - Continuación de programación
//          08/10/2021 - Continuación de programación
//          10/10/2021 - Revisión de errores
//          11/10/2021 - Última revisión.
#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <algorithm>
#include <string>

#define EMPTY_STRING "&"

class String {
  public:
    // @return the data of the string of the class 
    std::string get_data();

    // @return the length's string of the class 
    std::size_t get_length(void);
    
    // @return the inverse of the string of the  lass 
    std::string get_inverse(void);
   
    // @return the preffix of the string of the class 
    std::string get_prefix();

    // @return the suffix of the string of the class 
    std::string get_suffix(void);

    // @return the substring of the string of the class 
    std::string get_substring(void);

    // setter for string_ attribute
    void set_string(std::string string);
 private:
    // Stores the string to evaluate
    std::string string_;
};

#endif  // STRING_H_