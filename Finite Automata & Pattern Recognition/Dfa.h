// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Materia: Computabilidad y Algoritmia // Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Marco Antonio Cabrera Hernández
// Correo electrónico: alu0101327372@ull.es
// Fecha: 10/04/2021
// Archivo Dfa.h:
//      Contiene la definición de la clase Dfa.
// Revisión histórica
//      26/10/2021 - Creación (primera versión) del código
//      28/10/2021 - Continuación de la programación
//      29/10/2021 - Corrección de errores
//      30/10/2021 - Última revisión.
#ifndef DFA_H_
#define DFA_H_

#include "Transicion.h"
#include "Alfabeto.h"

#include <string>
#include <vector>
#include <system_error>
#include <cerrno>

class Dfa {
  public:
    Dfa(void);

    bool es_aceptada(const std::string& secuencia_adn);
    bool esta_en_conjunto(std::string caracter, std::vector<std::string> set_of_states);
    std::vector<std::string> obtener_ocurrencias(std::string secuencia_adn);
    std::vector<std::string> obtener_subcadena(const std::string& cadena);
    std::vector<std::string> obtener_subcadenas(const std::string& cadena, size_t longitud);
    std::string write_file(std::string patron);
  private:
    std::vector<Transicion> conjunto_de_estados_;
    Alfabeto alfabeto_;
};

#endif // DFA_H_