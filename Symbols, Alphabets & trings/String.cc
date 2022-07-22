// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo String.cc: 
//         Contiene la implementación de la clase String.
// Historial de revisiones 
//          06/10/2021 - Creación (primera versión) del código
//          07/10/2021 - Continuación de programación
//          08/10/2021 - Continuación de programación
//          10/10/2021 - Revisión de errores
//          11/10/2021 - Última revisión.
#include "String.h"

// @return the data of the string of the class 
std::string String::get_data() {
  return string_.data();
}



// @return  the length's string of the class 
std::size_t String::get_length(void) {
  return string_.length();
}



// @return the inverse of the string of the class 
std::string String::get_inverse() {
  std::reverse(string_.begin(), string_.end());

  return string_.data();
}



// @return  the preffix of the string of the class 
std::string String::get_prefix() {
  int iterator = 0;

  std::cout << EMPTY_STRING << " ";

  while(iterator < get_length() - 1) {
    for (int i = 0; i <= iterator; i++)
      std::cout << string_.data()[i];
        
    iterator++;
	 std::cout << " ";
  }
  return string_.data();
}



// @return the suffix of the string of the class 
std::string String::get_suffix() {
  int length = get_length();

  std::cout << EMPTY_STRING << " ";

  while(length - 1 > 0) {
    length--;
    
    for (int x = length; x < get_length(); x++)
      std::cout << string_.data()[x];

    std::cout << " ";
  }
  return string_.data();
}



// @return the substring of the string of the class 
std::string String::get_substring() {
  int i = 0, x = 0, y = 0;
  int delimiter = 1, limit = 1; 
  int length = get_length();
  
  std::cout << EMPTY_STRING << " ";
  
  while(y < length - 1) {
    while(x < length && i <= 5) {
      if (i == (length - (delimiter - 1)))
		  break;

		for (; i < limit; i++)
		  std::cout << string_.data()[i];

		std::cout << " ";

		i -= delimiter - 1;
		limit++;
		x++;
    }

    limit = ++delimiter;
    x = i = 0;
    y++;
    
    std::cout << " ";
  }
  return string_.data();
}



// Setter for string_ attribute
void String::set_string(std::string string) {
   string_ = string;
}