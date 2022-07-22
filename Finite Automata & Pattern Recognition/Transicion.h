// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Materia: Computabilidad y Algoritmia // Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Marco Antonio Cabrera Hernández
// Correo electrónico: alu0101327372@ull.es
// Fecha: 10/04/2021
// Archivo Transicion.h:
//      Contiene la definición de la clase Transicion.
// Revisión histórica
//      26/10/2021 - Creación (primera versión) del código
//      28/10/2021 - Continuación de la programación
//      29/10/2021 - Corrección de errores
//      30/10/2021 - Última revisión.
#ifndef TRANSICION_H_
#define TRANSICION_H_

#include <iostream>
#include <unordered_map>
#include <string>

class Transicion {
  public:
    Transicion(bool final_cadena, std::unordered_map<char, int> transiciones);

    int obetener_transicion(char symbol);
    bool es_final_cadena(void) const;
  private:
    // Comprueba el final de la cadena
    bool end_strings_;
    // Conjunto de transc¡iciones de un estado
    std::unordered_map<char, int> transiciones_;
};

#endif // TRANSICION_H_