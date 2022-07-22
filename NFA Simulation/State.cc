// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo State.cc:
//      Contiene la implementación de la clase State.
// Revisión histórica
//      09/11/2021 - Creación (primera versión) del código
//      10/11/2021 - Continuación de la programación
//      11/11/2021 - Corrección de errores
//      12/11/2021 - Última revisión.
#include "State.h"
/**
* @brief Construct a new State object
* 
*/
State::State(unsigned id, std::string name): id_(id), state_(name) {}



/**
 * @brief Construct copy of new State object
 * 
 */
State::State(const State& state) {
  this->id_= state.id_;
  this->state_ = state.state_;
  this->accepted_state_ = state.accepted_state_;
  this->transition_ = state.transition_;
  this->start_state_ = state.start_state_;
}



/**
 * @brief Construct a new State complete
 * 
 * @param id Id of state
 * @param state Name of state
 * @param acept If it is acept state it will be true
 * @param start If it is start state it will be true
 */
State::State(uint id, std::string state, bool acept, bool start) : 
  id_(id),
  state_(state),
  accepted_state_(acept),
  start_state_(start) {}



/**
 * @brief Construct a new State object
 * 
 * @param id 
 * @param acept If it is acept state it will be true
 * @param start If it is start state it will be true
 */
State::State(uint id, bool acept, bool start) : id_(id), accepted_state_(acept),
  start_state_(start){}



/**
 * @brief Clean data of the state
 * 
 */
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



int State::is_start_state(void) const {
  return start_state_;
} 



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



/**
 * @brief Insert transition in vector of pair<char, unsigned>
 * 
 * @param new_transition pair<char, unsigned>
 */
void State::add_transition(std::pair<char,unsigned> new_transition) {
  transition_.push_back(new_transition);
}



/**
 * @brief Return the state with transition
 * 
 * @param symbol 
 * @return uint 
 */
uint State::transition(char symbol) const{
  for (auto transition : transition_) {
    if (transition.first == symbol ){ 
      return transition.second;
    }
  }
  return -1;
}



/**
 * @brief Return vector with all transitions of the symbol
 * 
 * @param symbol 
 * @return pair<char, unsigned>
 */
std::vector<std::pair<char, unsigned> > State::transition_to(char symbol) const{
  std::vector<std::pair<char, unsigned> > temporal;
  for (auto transition : transition_) {
    if (transition.first == symbol ){ 
      temporal.push_back(transition);
    }
  }
  return temporal;
}



/**
 * @brief Overload of operator <
 * 
 * @param state 
 * @return true 
 * @return false 
 */
bool State::operator<(const State& state) const {
  return (this->get_id() < state.get_id());
}



/**
 * @brief Overload of operator <
 * 
 * @param state 
 * @return true 
 * @return false 
 */
bool State::operator==(const State& state) const {
  return (this->get_id() == state.get_id()); 
}



/**
 * @brief Overload of operator =
 * 
 * @param rhs 
 * @return State& 
 */
State& State::operator=(const State& state) {
  this->id_ = state.id_;
  this->state_ = state.state_;
  this->accepted_state_ = state.accepted_state_;
  this->transition_ = state.transition_;
  this->start_state_ = state.start_state_;
  return *this;
}
