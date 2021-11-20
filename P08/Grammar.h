#ifndef _GRAMMAR_
#define _GRAMMAR_

#include "Alphabet.h"
#include "Production.h"

#include <fstream>
#include <regex>
#include <vector>

class Grammar {
 public:
  Grammar(void);
  Grammar(const std::set<char>& alphabet, const std::set<char>& non_terminals,
          const char& start, 
          const std::multimap<char, std::pair<size_t, std::string> >& prod);
  Grammar(const Alphabet& alphabet, const Alphabet& non_terminals,
          const char& start, const Production& prod);
  Grammar(const Grammar& grammar);
  Grammar(std::ifstream& CFGFile);

  Alphabet get_alphabet(void) const;
  Alphabet get_non_terminal(void) const;
  char get_start(void) const;
  Production get_production(void) const;
  std::string get_production(const char& non_terminal, const size_t& num) const;
  bool Fail(void) const;

  bool is_alphabet(const char& symbol) const;
  bool is_nonterminal(const char& symbol) const;
  bool is_production(const char& symbol, const size_t& num) const;
  bool is_accepted(const std::string& prod) const;
  bool EvalProdsInFile(std::ifstream& cfg_prods_file, 
                       std::ofstream& cfg_out_file);
  
  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);
 private:
  Alphabet alphabet_; ///< Alfabeto de la gramatica.
  Alphabet non_terminals_; ///< Conjunto de simbolos no terminales.
  char start_; ///< Simbolo de arranque.
  Production prod_; ///< Conjunto de reglas de producción.
  bool creation_failed_; ///< nos dice si el objeto se ha creado correctamente.
};

#endif