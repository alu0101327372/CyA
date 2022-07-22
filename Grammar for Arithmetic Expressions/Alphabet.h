#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>

class Alphabet {
 public:
  Alphabet(void) = default;
  Alphabet(const std::set<char>& set_symbols);
  Alphabet(const Alphabet& set_symbols);

  void add_symbol(const char& symbol);
  void add_symbol(const std::string& symbol);
  void set_alphabet(const std::set<char>& set_symbols);
  void set_alphabet(const Alphabet& set_symbols);

  char get_symbol(const size_t& position) const;
  std::set<char> get_alphabet(void) const;
  size_t get_size(void) const;

  bool is_symbol(const char& symbol) const;
  bool is_symbol(const std::string& symbol) const;
  void clear_alphabet(void);

  Alphabet& operator=(const Alphabet& set_symbols);
  bool operator==(const Alphabet& set_symbols) const;
  char operator[](const size_t position) const;
 private:
  std::set<char> alphabet_;
};
#endif // ALPHABET_H