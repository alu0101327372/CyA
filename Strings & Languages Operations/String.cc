// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo String.cc: 
//         Contiene la implementación de la clase String.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#include "String.h"

/**
 * @brief Constructs a new String object from a string representation of the string and an alphabet.
 *
 * @param str std::string representation of the string and the alphabet.
 */
String::String(std::string str) {
  int count = 0;
  for (unsigned i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      count++;
    }
  }
  if (0 < count) {
    include_alphabet(str);
  }
  else {
    not_include_alphabet(str);
  }
  // Checks if the string belongs to the alphabet
  if (is_string() == false)
    string_ = "";
}



/**
 * @brief Constructs a new String object from a string representation of the string and an alphabet.
 *
 * @param str std::string representation of the string and the alphabet.
 */
void String::include_alphabet(std::string str) {
  for (unsigned i = str.find_last_of(' ') + 1; i < str.length(); i++) {
    string_ += str[i];
  }

  for (unsigned i = 0; i < str.find_last_of(' '); i++) {
    if (str[i] != ' ') {
      Symbol aux;
      std::string aux_string {str[i]};
      aux.set_symbol(aux_string);
      alphabet_.push_back(aux);
    }
  } 
}



/**
 * @brief Constructs a new String object from a string representation of the string.
 *
 * @param str std::string representation of the string.
 */
void String::not_include_alphabet(std::string str) {
  for (unsigned i = 0; i < str.length(); i++) {
    Symbol aux;
    std::string aux_string {str[i]};
    aux.set_symbol(aux_string);
    if (alphabet_.is_symbol(aux) == false) {
      alphabet_.push_back(aux);
    }
    string_+= str[i];
  }
}



/**
 * @brief  Set a string of corresponding atribute.
 * 
 * @param str The string representation of the String.
 */
void String::set_string(std::string str) {
   string_ = str;
}



/**
 * @brief Checks if a String belongs to the alphabet.
 *
 * @return true If the string belongs to the alphabet.
 * @return false If the string does not belong to the alphabet.
 */
bool String::is_string(void) {
  for (unsigned i = 0; i < string_.length(); i++){
    Symbol aux;
    std::string aux_string {string_[i]};
    aux.set_symbol(aux_string);
    if (alphabet_.is_symbol(aux) == false){
      return false;
    } 
  }
  return true;
}



/**
 * @brief Checks if a String is equal to the another.
 *
 * @param str std::string The string to compare
 * @return true If the string is equeal to the other.
 * @return false If the string is not equal to the other.
 */
bool String::is_equal(std::string str) {
  if (string_ == str) {
    return true;
  }
  return false;
}



/**
 * @brief Checks if a String is equal to the another.
 *
 * @param str std::string The string to compare
 * @param str_2 std::string The string to compare
 * @return true If the string is substring to the other.
 * @return false If the string is not substring to the other.
 */
int String::is_substring(std::string str, std::string str_2) {
  for (int i = 0; (i + str.length() - 1) < str_2.length(); i++) {
    bool ok =  true;
    for (unsigned j = 0; j < str.length(); j++) {
      if (str_2[i + j] != str[j]) {
        ok = false;
        break;
      }
    }
    if (ok) return i;
  }
  return (str.length() == 0) ? 0 : -1;
}



/**
 * @brief Returns the length of the String.
 *
 * @return std::size_t The length of the String.
 */
std::size_t String::get_length(void) {
  if (string_ == "") {
    return 0;
  }
  else {
    return string_.length();
  }
}



/**
 * @brief Returns the atribute string_.
 *
 * @return std::size_t The string_
 */
std::string String::get_string(void) {
  return string_;
}


/**
 * @brief Returns the inverse string of this. This is the equivalent of reading the current String, backwards.
 *
 * @return std::string The inverse string.
 */
std::string String::get_inverse(void) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    std::reverse(string_.begin(), string_.end());
    return string_.data();
  }
}



/**
 * @brief Generates a list of all possible prefixes for this string.
 *
 * @return std::string All possible prefixes for this string.
*/
std::string String::get_prefix(void) {
  if (string_ == ""){
    return "La cadena no pertenence al alfabeto";
  }
  else {
    unsigned iterator = 1;
    std::string fout = "{&, ";
    while (iterator < get_length()) {
      for (unsigned i = 0; i < iterator; i++) {
        fout += string_[i];
      }
      iterator++;
      fout +=  ", ";
    }
    fout  += string_ + "}";
    return fout;
  }
}



/**
 * @brief Generates a list of all possible suffixes for this string.
 *
 * @return std::string All possible suffixes for this string.
*/
std::string String::get_suffix(void) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    unsigned length = get_length();
    std::string fout = "{&, ";
    while (length - 1 > 0) {
      length--;
      for (unsigned x = length; x < get_length(); x++) {
        fout += string_[x];
      }
      fout += ", ";
    }
    fout += string_ + "}";
    return fout;
  }
}



/**
 * @brief Generates a list of all possible substrings for this string.
 *
 * @return std::string All possible substrings for this string.
*/
std::string String::get_substring(void) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    int i = 0, x = 0, y = 0;
    int delimiter = 1, limit = 1; 
    int length = get_length();
    std::string fout = "{&, ";
    while (y < length - 1) {
      while (x < length && i <= 5) {
        if (i == (length - (delimiter - 1))) {
          break;
        }
        for (; i < limit; i++) {
          fout += string_[i];
        }
        fout += ", ";
        i -= delimiter - 1;
        limit++;
        x++;
      }
      limit = ++delimiter;
      x = i = 0;
      y++;
    }
    fout += string_ + "}";
    return fout;
  }
}



/**
 * @brief Compares strings
 *
 * @param str std::string The string to compare
 * @return std::string The result of the comparation.
 */
std::string String::comparation(std::string str) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    std::string aux;
    if (is_equal(str) == true) {
      aux = string_ + " == " + str;
    }
    else if (is_substring(string_, str) == 0) {
      aux = string_ + " < " + str;
    }
    else if (is_substring(str, string_) == 0) {
      aux = string_ + " > " + str;
    }
    else {
      aux = string_ + " != " + str;
    }
    return aux;
  }
}



/**
 * @brief Concatenates strings
 *
 * @param str std::string The string to concatenate
 * @return std::string The result of the concatenation.
 */
std::string String::concatenation(std::string str) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    return string_ + str;
  }
}



/**
 * @brief Add strings n times.
 *
 * @param n int The times the string is going to be add
 * @return std::string The result of the addition
 */
std::string String::addition(int n) {
  if (string_ == "") {
    return "La cadena no pertenence al alfabeto";
  }
  else {
    std::string aux;
    for (int i = 1; i <= n; i++) {
      aux += string_;
    }
    return aux;
  }
}



/**
 * @brief Operator overload=.
 *
 * @param string The element to overload
 * @return The overload
 */
bool String::operator==(String& string) {
  return string.get_string() == string_;
}



/**
 * @brief Operator overload=.
 *
 * @param string The element to overload
 * @param os The standard output
 * @return The overload
 */
std::ostream& operator<<(std::ostream& os, String& string) {
  os << string.get_string();
  return os;
}