// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Symbol.h: 
//         Contiene la definición de la clase Symbol.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>
#include <string>

class Symbol {
  public:
    Symbol(void) = default;
    Symbol(std::string symbol);

    // Setter for the attribute symbol_
    void set_symbol(std::string symbol);

    // @return symbol_
    std::string get_symbol(void) const;

    //Sobrecarga del operador == 
    friend bool operator==(const Symbol symbol_1, const Symbol symbol_2);

    // Sobrecarga del operador <
    friend bool operator<(const Symbol symbol_1, const Symbol symbol_2);

    //Sobrecarga del operador >
    friend bool operator>(const Symbol symbol_1, const Symbol symbol_2);
  private:
    // Stores a symbol
    std::string symbol_;    
};

#endif // SYMBOL_H_