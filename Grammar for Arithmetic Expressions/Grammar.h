#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "Alphabet.h"
#include "Productions.h"

#include <fstream>
#include <regex>
#include <vector>

class Grammar {
 public:
  Grammar(void) = default;
  Grammar(const std::set<char>& alphabet, const std::set<char>& non_terminals, const char& start, 
    const std::multimap<char, std::pair<size_t, std::string>>& prod);
  Grammar(const Alphabet& alphabet, const Alphabet& non_terminals, const char& start, 
    const Productions& prod);
  Grammar(const Grammar& grammar);
  Grammar(std::ifstream& CFGFile);

  Alphabet get_alphabet(void) const;
  Alphabet get_non_terminal(void) const;
  char get_start(void) const;
  Productions get_productions(void) const;
  std::string get_productions(const char& non_terminal, const size_t& num) const;

  bool is_symbol(const char& symbol) const;
  bool is_non_terminal(const char& symbol) const;
  bool is_production(const char& symbol, const size_t& num) const;
  bool is_accpeted_production(const std::string& prod) const;
  bool analize(std::ifstream& cfg_prods_file, std::ofstream& cfg_out_file);
 private:
  Alphabet alphabet_;
  Alphabet non_terminals_;
  char start_;
  Productions prod_;
  bool creation_failed_;
};

#endif // GRAMMAR_H