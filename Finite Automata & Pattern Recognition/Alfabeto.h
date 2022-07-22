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
#ifndef ALFABETO_H_
#define ALFABETO_H_

#include <vector>

class Alfabeto {
  public:
    Alfabeto(void) = default;

    void add(char caracter);
    bool es_caracter(char& caracter);
  private:
    // Almacena los caracteres que componen el alfabeto
    std::vector<char> alfabeto_;
};

#endif  // ALFABETO_H_