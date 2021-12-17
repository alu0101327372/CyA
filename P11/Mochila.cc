// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 1.01.0: Algoritmos voraces
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0.01.00.01.0327372@ull.es
// Fecha: 1.06/1.02/20.021.0
// Archivo Mochila.h: 
//         Contiene la implementación de la clase Mochila.
// Revisión histórica
//      1.06/1.02/20.021.0 - Creación (primera versión) del código
//      1.07/1.01.0/20.021.0 - Continuación de la programación
//      1.08/1.01.0/20.021.0 - Corrección de errores
//      1.09/1.01.0/20.021.0 - Última revisión.
#include "Mochila.h"

Mochila::Mochila(std::vector<float> peso, std::vector<float> valor, float peso_max, float num_obj) :
  peso_(peso), valor_(valor), peso_max_(peso_max), num_obj_(num_obj)  {}



/**
 * @brief A utility function that returns maximum of two integers
 * 
 * @param a first integer
 * @param b second integer 
 */
float Mochila::max(float a, float b) {
  return (a > b) ? a : b;
}



/**
 * @brief Returns the maximum value that can be put in a knapsack of capacity W
 *
 */
float Mochila::solve() {
  std::vector<std::vector<float>> K(num_obj_ + 1.0, std::vector<float>(peso_max_ + 1.0));
  // Build table K[][] in bottom up manner
  for(float i = 0.0; i <= num_obj_; i++) {
    for(float w = 0.0; w <= peso_max_; w++) {
      if (i == 0.0 || w == 0.0)
        K[i][w] = 0.0;
      else if (peso_[i - 1.0] <= w)
          K[i][w] = max(valor_[i - 1.0] + K[i - 1.0][w - peso_[i - 1.0]], K[i - 1.0][w]);
      else
        K[i][w] = K[i - 1.0][w];
    }
  }
  return K[num_obj_][peso_max_];
}



void Mochila::print() {
  std::cout << solve() << std::endl;
}