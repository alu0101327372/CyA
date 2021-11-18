#ifndef ALPHABET_H
#define ALPHABET_H

#include "Symbol.h"

#include <iostream>
#include <set>

class Alphabet {
 public:
  Alphabet() = default;
  Alphabet(std::set<Symbol>);

  std::set<Symbol> get_alphabet(void);
  friend std::ostream&operator<<(std::ostream&, const Alphabet& );
  int size(void);
 private:
  std::set<Symbol> alphabet_;
};

#endif