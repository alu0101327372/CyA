// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 11: Algoritmos voraces
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 16/12/2021
// Archivo Mochila.h: 
//         Contiene la definición de la clase Mochila.
// Revisión histórica
//      16/12/2021 - Creación (primera versión) del código
//      17/11/2021 - Continuación de la programación
//      18/11/2021 - Corrección de errores
//      19/11/2021 - Última revisión.
#ifndef OBJETO_H_
#define OBJETO_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <list>

class Objeto {
  public:
    Objeto(const std::string& input);
    int tamaño(void) const;
    std::list<std::vector<float>>::iterator inicio(void);
    std::list<std::vector<float>>::iterator fin(void);
    void borrar(int);
  private:
    int cantidad_;
    std::list<std::vector<float>> objetos_;
};

#endif // OBJETO_H_