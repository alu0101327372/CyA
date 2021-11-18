#ifndef CHAIN_H
#define CHAIN_H

#include "Symbol.h"

#include <iostream>
#include <string>
#include <vector>

class Chain {
 public:
  Chain(void) = default;
  Chain(const std::vector<Symbol>& chain);
  Chain(const Chain& chain);

  void EmplaceBack(const char& symbol);
  void EmplaceBack(const std::string& symbol);
  void EmplaceBack(const Symbol& symbol);

  std::vector<Symbol> GetChain(void) const;
  Symbol At(const size_t& position) const;

  size_t Size(void) const;

  void operator=(const Chain& chain);
  bool operator==(const Chain& chain) const;
  Symbol operator[](const size_t& position) const;
  Chain operator+(const Chain& chain);

  friend std::ostream& operator<<(std::ostream& out, const Chain& chain);
  friend std::istream& operator>>(std::istream& input, Chain& chain);
 private:
  std::vector<Symbol> chain_;
};

#endif