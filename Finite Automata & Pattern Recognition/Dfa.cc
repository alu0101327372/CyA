// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Materia: Computabilidad y Algoritmia // Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Marco Antonio Cabrera Hernández
// Correo electrónico: alu0101327372@ull.es
// Fecha: 10/04/2021
// Archivo Dfa.cc:
//      Contiene la implementación de la clase Dfa.
// Revisión histórica
//      26/10/2021 - Creación (primera versión) del código
//      28/10/2021 - Continuación de la programación
//      29/10/2021 - Corrección de errores
//      30/10/2021 - Última revisión. 
#include "Dfa.h"

Dfa::Dfa(void) {
  conjunto_de_estados_ = {
    // Estado q0
    Transicion(false, {{'A', 1}, {'C', 5}, {'G', 5}, {'T', 3}, }),
    // Estado q1
    Transicion(false, {{'A', 2}, {'C', 1}, {'G', 1}, {'T', 1}, }),
    // Estado q1'
    Transicion(true, {{'A', 2}, {'C', 1}, {'G', 1}, {'T', 1}, }),
    // Estado q2
    Transicion(false, {{'A', 3}, {'C', 3}, {'G', 3}, {'T', 4}, }),
    // Estado q2'
    Transicion(true, {{'A', 3}, {'C', 3}, {'G', 3}, {'T', 4}, }),
    // Estado q3
    Transicion(false, {{'A', 5}, {'C', 5}, {'G', 5}, {'T', 5}, }),
  };
  alfabeto_.add('A');
  alfabeto_.add('C');
  alfabeto_.add('G');
  alfabeto_.add('T');
}



// Comprueba si la cadena proporcionada coincide con la expresión regular
bool Dfa::es_aceptada(const std::string& secuencia_adn) {
  int estado_actual = 0;
  for (char caracter : secuencia_adn) {
    estado_actual = conjunto_de_estados_[estado_actual].obetener_transicion(caracter);
  }
  return conjunto_de_estados_[estado_actual].es_final_cadena();
}



// Devuelve verdadero si la cadena ya está en el conjunto de estados
bool Dfa::esta_en_conjunto(std::string caracter, std::vector<std::string> set_of_states) {
  for (int i = 0; i < set_of_states.size(); i++) {
    if (caracter == set_of_states[i]) {
      return true;
    }
  }
  return false;
}



// Devuelve un vector de todas las coincidencias encontradas en la cadena
std::vector<std::string> Dfa::obtener_ocurrencias(std::string secuencia_adn) {
  std::vector<std::string> resultado;
  for (char c : secuencia_adn) {
    if (!alfabeto_.es_caracter(c)) {
      throw std::system_error(errno, std::system_category(), "La secuencia contiene caracteres incorrectos");
    }
  }
  for (const std::string& subcadena : obtener_subcadena(secuencia_adn)) {
    if (es_aceptada(subcadena)) {
      resultado.push_back(subcadena);
    }
  }
  return resultado;
}



// Devuelve un vector con todas las subcadenas con una longitud especifica
std::vector<std::string> Dfa::obtener_subcadenas(const std::string& cadena, size_t longitud) {
  std::vector<std::string> resultado;
  int numero_subcadenas = cadena.length() - longitud + 1;
  for (int i = 0; i < numero_subcadenas; i++) {
    std::string subcadena = cadena.substr(i, longitud);
    if (!esta_en_conjunto(subcadena, resultado)) {
      resultado.push_back(subcadena);
    }
  }
  return resultado;
}



// Deveulve un vector con las subcadenas de la cadena dada
std::vector<std::string> Dfa::obtener_subcadena(const std::string& cadena) {
  std::vector<std::string> resultado;
  for (int i = 0; i <= cadena.length(); i++) {
    for (const std::string& subcadena : obtener_subcadenas(cadena, i)) {
      resultado.push_back(subcadena);
    }
  }
  return resultado;
}



std::string Dfa::write_file(std::string patron) {
  std::string aux = "";
  for (const std::string& ocurrencia : this->obtener_ocurrencias(patron)) {
    aux += ocurrencia + "\n";
  }
  return aux + "\n";
}