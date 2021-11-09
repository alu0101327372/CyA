// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Dfa.h:
//      Contiene la implementación de la clase Dfa.
// Revisión histórica
//      02/11/2021 - Creación (primera versión) del código
//      23/11/2021 - Continuación de la programación
//      24/11/2021 - Corrección de errores
//      05/11/2021 - Última revisión.
#include "Dfa.h"

Dfa::Dfa(std::string name_make_dfa, std::string name_file_input, std::string name_file_output) {
  file_dfa_.open(name_make_dfa);
  file_input_.open(name_file_input);
  file_output_.open(name_file_output);
  read_file();
  write_file();
}



// Close the files if the are open
Dfa::~Dfa(void) {
  if (file_input_.is_open()) {
    file_input_.close();
  }
  if (file_output_.is_open()) {
    file_output_.close();
  }
  if (file_dfa_.is_open()) {
    file_dfa_.close();
  }
}



// Inicialize the DFA
void Dfa::insert_file(std::string name_make_dfa, std::string name_file_input, std::string name_file_output) {
  file_dfa_.open(name_make_dfa);
  file_input_.open(name_file_input);
  file_output_.open(name_file_output);
  read_file();
  write_file();
}



// Read the file to make DFA
void Dfa::read_file(void) {
  std::string aux;
  bool acept_state = false;
  bool start_s = false;
  uint id_state, total_states, start_state, number_transitions;
  if (file_dfa_.is_open() && file_dfa_) {
    while (!file_dfa_.eof()) {
      file_dfa_ >> total_states;
      file_dfa_ >> start_state;        
      for (uint i = 0; i < total_states; i++) {
        file_dfa_ >> id_state >> acept_state >> number_transitions;
        if (id_state == start_state)
          start_s = true;
        else
          start_s = false; 
        State estado_temporal(id_state, acept_state, start_s);
        for (uint i = 0; i < number_transitions; i++) {
          char symbol;
          uint next_id;
          file_dfa_ >> symbol >> next_id;
          alphabet_.add((int)symbol);
          estado_temporal.add_transition(std::make_pair(symbol, next_id));
        }
        dfa_states_.insert(estado_temporal); 
      }
    }
    check_dfa_make_ = true;
  } 
  else {
    std::cerr << "Nombre de fichero para crear DFA erroneo. " << std::endl;
  }
}



// Used to read and write in output file the results
void Dfa::write_file(void) {
  std::string aux;
  
  if (!check_dfa_make_) {
    std::cerr << "DFA no construido." << std::endl;
    return;
  }

  if (file_input_.is_open() && file_input_ ) {
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



unsigned Dfa::get_size(void) {
  return dfa_states_.size();
}



std::set<State> Dfa::get_states(void) {
 return dfa_states_;

}



std::vector<std::string> Dfa::get_accepted_states(void) {
  std::vector<std::string> aux;
  for (auto it = dfa_states_.begin(); it != dfa_states_.end(); ++it) {
    if (it->is_accepted_state())
      aux.push_back("\"" + it->get_name() + "\"");
  }
  return aux;   
}



uint Dfa::get_start_states(void) {
  std::set<State>::iterator it;
  for ( it = dfa_states_.begin(); it != dfa_states_.end(); it++){
    if(it->is_start_state())
     return it->get_id();
  }
  return -1;
}



void Dfa::add_states(State new_state) {
  dfa_states_.insert(new_state);
}



void Dfa::update_state(std::set<State>::iterator& it, const State& new_state) {
  std::cout << it->get_name() << '\n';
  if (it != dfa_states_.end()) {
    dfa_states_.erase(it);
    dfa_states_.insert(new_state);
  }
}



// Recursive funtion to analize possibles solutions
void Dfa::analize(std::set<State>::iterator& it, std::string& word, uint index, bool& acept_state) {
  if (index >= word.size()) {
    if (it->is_accepted_state())
      acept_state = true;
    return;
  }
  auto transitions = it->transition_to(word[index]);
  for (auto trans : transitions) {
    it = dfa_states_.find(State(trans.second, ""));
    analize(it, word, index + 1, acept_state);
  }   
}



// Search in the string if it has accepted states
bool Dfa::search_string(std::string word) {
  bool get_acept_state = false;
  std::set<State>::iterator it = dfa_states_.begin();
  analize(it, word, 0, get_acept_state);
  return get_acept_state;
}