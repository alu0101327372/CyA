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
//      17/12/2021 - Continuación de la programación
//      18/12/2021 - Corrección de errores
//      19/12/2021 - Última revisión.
#ifndef MOCHILA_H_
#define MOCHILA_H_

#include "Objeto.h"

class Mochila {
 public:
    Mochila(float peso);

    void insertar_objeto(Objeto&);
    void insertar_no_acotado(Objeto&);
    void imprimir();
    float espacio(void);
 private:
    float peso_max_;
    float peso_actual_;
    float beneficio_;
    std::vector<std::pair<int, float> > orden_;
};

#endif // MOCHILA_H_