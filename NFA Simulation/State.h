// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo State.h:
//      Contiene la definición de la clase State.
// Revisión histórica
//      09/11/2021 - Creación (primera versión) del código
//      10/11/2021 - Continuación de la programación
//      11/11/2021 - Corrección de errores
//      12/11/2021 - Última revisión.
#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <vector>

class State {
 public:
    State(void) = default;
    State(unsigned id, std::string name);
    State(const State& state);
    State(uint id, std::string name_state, bool acept, bool start);
    State(uint id, bool acept, bool start);
    ~State(void); 

    std::string get_name(void) const;
    int get_id(void) const;
    int is_start_state(void) const;
    bool is_accepted_state(void) const;

    void set_accepted_state(bool is_acept_state);
    void set_start_state(bool is_start);
    void set_id(unsigned id);
    void set_name(std::string name);

    void add_transition(std::pair<char,unsigned> aux);
    uint transition(char symbol) const;
    std::vector<std::pair<char, unsigned> > transition_to(char symbol) const;

    bool operator<(const State& state) const;
    bool operator==(const State& state) const;
    State& operator=(const State& state);
  private:
    // State identifier
    uint id_;
    // State
    std::string state_;
    // Check if it is an accepted state
    bool accepted_state_ = false;
    // Check if it is the start state
    bool start_state_ = false;
    // Transition to a state (symbol, state)
    std::vector<std::pair<char, unsigned> > transition_;
};

#endif // STATE_H_
