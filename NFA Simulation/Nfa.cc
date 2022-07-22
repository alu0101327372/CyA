// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Dfa.h:
//      Contiene la implementación de la clase Dfa.
// Revisión histórica
//      09/11/2021 - Creación (primera versión) del código
//      10/11/2021 - Continuación de la programación
//      11/11/2021 - Corrección de errores
//      12/11/2021 - Última revisión.
#include "Nfa.h"
/**
 * @brief Construct a new Nfa object
 * @param name_make_nfa to make NFA
 * @param name_file_input to read and find patterns
 * @param name_file_output to put results
 */
Nfa::Nfa(std::string name_make_nfa, std::string name_file_input, std::string name_file_output) {
  file_nfa_.open(name_make_nfa);
  file_input_.open(name_file_input);
  file_output_.open(name_file_output);
  read_file();
  write_file();
}



/**
 * @brief Close the open files
 * 
 */
Nfa::~Nfa(void) {
  if (file_input_.is_open()) {
    file_input_.close();
  }
  if (file_output_.is_open()) {
    file_output_.close();
  }
  if (file_nfa_.is_open()) {
    file_nfa_.close();
  }
}



/**
 * @brief Inicialize NFA
 * @param name_make_dfa to make NFA
 * @param name_file_input to read and find patterns
 * @param name_file_output to put results
 */
void Nfa::insert_file(std::string name_make_dfa, std::string name_file_input, std::string name_file_output) {
  alphabet_.add('&');
  file_nfa_.open(name_make_dfa);
  file_input_.open(name_file_input);
  file_output_.open(name_file_output);
  read_file();
  write_file();
}



/**
 * @brief Read the file to make NFA
 * 
 */
void Nfa::read_file(void) {
  std::string aux;
  bool acept_state = false;
  bool start_s = false;
  uint id_state, total_states, start_state, number_transitions;
  if (file_nfa_.is_open() && file_nfa_) {
    while (!file_nfa_.eof()) {
      file_nfa_ >> total_states;
      file_nfa_ >> start_state;        
      for (uint i = 0; i < total_states; i++) {
        file_nfa_ >> id_state >> acept_state >> number_transitions;
        if (id_state == start_state)
          start_s = true;
        else
          start_s = false; 
        State estado_temporal(id_state, acept_state, start_s);
        for (uint i = 0; i < number_transitions; i++) {
          char symbol;
          uint next_id;
          file_nfa_ >> symbol >> next_id;
          alphabet_.add(symbol);
          estado_temporal.add_transition(std::make_pair(symbol, next_id));
        }
        dfa_states_.insert(estado_temporal); 
      }
    }
    check_dfa_make_ = true;
  } 
  else {
    std::cerr << "Nombre de fichero para crear NFA erroneo. " << std::endl;
  }
}



/**
 * @brief Used to write in output file the results
 * 
 */
void Nfa::write_file(void) {
  std::string aux;
  
  if (!check_dfa_make_) {
    std::cerr << "NFA no construido." << std::endl;
    return;
  }

  if (file_input_.is_open() && file_input_) {
    while (!file_input_.eof()) {
      file_input_ >> aux;      
      if (alphabet_.is_symbol(aux) && search_string(aux)) {
        file_output_ << aux << " --> ACCEPTED" << std::endl;
      } else {
        file_output_ << aux << " --> REJECTED" << std::endl;
      }
    }
    std::cout << "Fichero generado con éxito." << std::endl;
  } 
  else {
    std::cerr << "Nombre de fichero de lectura erroneo. " << std::endl;
  }
}



unsigned Nfa::get_size(void) {
  return dfa_states_.size();
}



std::set<State> Nfa::get_states(void) {
 return dfa_states_;

}



std::vector<std::string> Nfa::get_accepted_states(void) {
  std::vector<std::string> aux;
  for (auto it = dfa_states_.begin(); it != dfa_states_.end(); ++it) {
    if (it->is_accepted_state())
      aux.push_back("\"" + it->get_name() + "\"");
  }
  return aux;   
}



uint Nfa::get_start_states(void) {
  std::set<State>::iterator it;
  for ( it = dfa_states_.begin(); it != dfa_states_.end(); it++){
    if(it->is_start_state())
     return it->get_id();
  }
  return -1;
}



void Nfa::add_states(State new_state) {
  dfa_states_.insert(new_state);
}



void Nfa::update_state(std::set<State>::iterator& it, const State& new_state) {
  std::cout << it->get_name() << '\n';
  if (it != dfa_states_.end()) {
    dfa_states_.erase(it);
    dfa_states_.insert(new_state);
  }
}



/**
 * @brief Recursive funtion to search possibles path
 * 
 * @param it Iterator to state evaluated
 * @param word Reference to string to analize
 * @param index Index 
 * @param acept_state Boolean param to get acept state 
 */
void Nfa::analize(std::set<State>::iterator& it, std::string& word, uint index, bool& acept_state) {
  if (index >= word.size()) {
    if (it->is_accepted_state())
      acept_state = true;
    return;
  }
  auto transitions = it->transition_to(word[index]);
  for (auto trans : transitions) {
    it = dfa_states_.find(State(trans.second, ""));
    if (trans.first == '&') {
      analize(it, word, index, acept_state);
    }
    else {
    analize(it, word, index + 1, acept_state);
    }
  }   
}



/**
 * @brief Search Pattern in String
 * @param word
 * @return true
 * @return false
 */
bool Nfa::search_string(std::string word) {
  bool get_acept_state = false;
  std::set<State>::iterator it = dfa_states_.begin();
  analize(it, word, 0, get_acept_state);
  return get_acept_state;
}