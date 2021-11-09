// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo String.h: 
//         Contiene la definición de la clase String.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#ifndef STRING_H_
#define STRING_H_

#include "Alphabet.h"

#include <algorithm>

class String {
  public:
    String(std::string str);

    // Proccess a given line that include an alphabet
    void include_alphabet(std::string str);

    // Proccess a given line that not includes an alphabet
    void not_include_alphabet(std::string str);

    // setter for string_ attribute
    void set_string(std::string string);

    // Checks if a string belongs to its alphahet
    bool is_string(void);

    // Check if a string is equal than another
    bool is_equal(std::string input_string);

    // Checks if a string is substring of another
    int is_substring(std::string input_string, std::string input_string2);

    // @return the length's string of the class 
    std::size_t get_length(void);

    // @return the attribute string_
    std::string get_string(void);
    
    // @return the inverse of the string of the  lass 
    std::string get_inverse(void);
   
    // @return the preffix of the string of the class 
    std::string get_prefix(void);

    // @return the suffix of the string of the class 
    std::string get_suffix(void);

    // @return the substring of the string of the class 
    std::string get_substring(void);

    // Compare strings
    std::string comparation(std::string input_string);

    // Concatenates strings with antoher
    std::string concatenation(std::string input_string);

    // Raise a string n times
    std::string addition(int n);

    //Operadores
    void operator=(String& word);

    bool operator==(String& word);

    friend std::ostream& operator<<(std::ostream& output, String& word);
 private:
    // Stores the string to evaluate
    std::string string_;

    // Stores the alphabet object
    Alphabet alphabet_;
};

#endif  // STRING_H_