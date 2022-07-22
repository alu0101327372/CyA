// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo State.cc:
//      Contiene la implementación de la clase State.
// Revisión histórica
//      02/11/2021 - Creación (primera versión) del código
//      23/11/2021 - Continuación de la programación
//      24/11/2021 - Corrección de errores
//      05/11/2021 - Última revisión.
#include "State.h"

State::State(unsigned id, std::string name): id_(id), state_(name) {}



State::State(const State& state) {
  this->id_= state.id_;
  this->state_ = state.state_;
  this->accepted_state_ = state.accepted_state_;
  this->transition_ = state.transition_;
  this->start_state_ = state.start_state_;
}



State::State(uint id, std::string state, bool acept, bool start) : 
  id_(id),
  state_(state),
  accepted_state_(acept),
  start_state_(start) {}



State::State(uint id, bool acept, bool start) : id_(id), accepted_state_(acept),
  start_state_(start){}



State::~State(void) {
  id_ = 0;
  state_.clear();
  accepted_state_= false;
  start_state_ = false;
  transition_.clear();
}




std::string State::get_name(void) const {
  return state_;
}



int State::get_id(void) const {
  return id_;
}



// Return if it is a start state
int State::is_start_state(void) const {
  return start_state_;
} 



// Return if it is an accepted state
bool State::is_accepted_state(void) const {
  return accepted_state_;
} 



void State::set_id(unsigned id)  {
  id_ = id;
}



void State::set_name(std::string name) {
  state_ = name;
} 



void State::set_accepted_state(bool is_acept_state) {
  accepted_state_ = is_acept_state;
}



void State::set_start_state(bool is_start) {
  start_state_ = is_start;
}



// Insert a transition
void State::add_transition(std::pair<char,unsigned> new_transition) {
  transition_.push_back(new_transition);
}



// Return the state with transition
uint State::transition(char symbol) const{
  for (auto transition : transition_) {
    if (transition.first == symbol ){ 
      return transition.second;
    }
  }
  return -1;
}



// Return vector with all transitions of the symbol
std::vector<std::pair<char, unsigned> > State::transition_to(char symbol) const{
  std::vector<std::pair<char, unsigned> > temporal;
  for (auto transition : transition_) {
    if (transition.first == symbol ){ 
      temporal.push_back(transition);
    }
  }
  return temporal;
}



bool State::operator<(const State& state) const {
  return (this->get_id() < state.get_id());
}



bool State::operator==(const State& state) const {
  return (this->get_id() == state.get_id()); 
}



State& State::operator=(const State& state) {
  this->id_ = state.id_;
  this->state_ = state.state_;
  this->accepted_state_ = state.accepted_state_;
  this->transition_ = state.transition_;
  this->start_state_ = state.start_state_;
  return *this;
}
