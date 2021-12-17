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
#ifndef MOCHILA_H_
#define MOCHILA_H_

#include <iostream>
#include <fstream>
#include <vector>

class Mochila {
  public:
    Mochila(std::vector<float> peso, std::vector<float> valor, float peso_max, float num_obj);

    float max(float a, float b);
    float solve();
    void print();
  private:
    std::vector<float> peso_;
    std::vector<float> valor_;
    float peso_max_;
    float num_obj_;
};

#endif