// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Dfa.h:
//      Contiene la definición de la clase Dfa.
// Revisión histórica
//      02/11/2021 - Creación (primera versión) del código
//      23/11/2021 - Continuación de la programación
//      24/11/2021 - Corrección de errores
//      05/11/2021 - Última revisión.
#ifndef DFA_H_
#define DFA_H_

#include <fstream>

#include "Alphabet.h"
#include "State.h"

class Dfa {
  public:
    Dfa(void) = default;
    Dfa(std::string name_make_dfa, std::string name_file_input, std::string name_file_output);
    ~Dfa(void);    

    void insert_file(std::string name_make_dfa, std::string name_file_input, std::string name_file_output);
    void read_file(void);
    void write_file(void);

    unsigned get_size(void);
    std::set<State> get_states(void);
    std::vector<std::string> get_accepted_states(void);
    uint get_start_states(void);
    void add_states(State new_state); 
    void update_state(std::set<State>::iterator& it, const State& new_state);
    void analize(std::set<State>::iterator& it, std::string& word, uint index, bool& acept_state);
    bool search_string(std::string word);
  private:
    // Alphabet of the DFA
    Alphabet alphabet_;
    // Set of states
    std::set<State> dfa_states_;
    // Input DFA file
    std::ifstream file_dfa_;
    // Input file
    std::ifstream file_input_;
    // Output file
    std::ofstream file_output_;
    // Check if the dfa is correct
    bool check_dfa_make_ = false;
};

#endif // DFA_H_