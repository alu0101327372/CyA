#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <iostream>
#include <map>

class Production {
 public:
  Production(void) = default;
  Production(const char& non_terminal, std::pair<size_t, std::string> prod);
  Production(const char& non_terminal, const size_t& num, const std::string& prod);
  Production(const Production& prod);

  void set_produdction(const std::multimap<char, std::pair<size_t, std::string> >& prod);
  void set_produdction(const char& non_terminal, const size_t& num, const std::string& prod);
  void set_produdction(const char& non_terminal, std::pair<size_t, std::string>& prod);

  std::string get_production(const char& non_terminal, const size_t& num) const;
  size_t get_greatest_non_terminal(const char& symbol) const;

  bool is_production(const char& symbol, const size_t& num) const;

  void operator=(const Production& prod);

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Production& prod);
  
 private:
  /// multimap que contiene todas las producciones de la gramática.
  std::multimap<char, std::pair<size_t, std::string> > prod_;
};

#endif