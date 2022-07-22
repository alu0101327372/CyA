#ifndef PRODUCTIONS_H
#define PRODUCTIONS_H

#include <iostream>
#include <map>

class Productions {
 public:
  Productions(void) = default;
  Productions(const char& non_terminal, std::pair<size_t, std::string> prod);
  Productions(const char& non_terminal, const size_t& num, const std::string& prod);
  Productions(const Productions& prod);

  void set_production(const std::multimap<char, std::pair<size_t, std::string>>& prod);
  void set_production(const char& non_terminal, const size_t& num, const std::string& prod);
  void set_production(const char& non_terminal, std::pair<size_t, std::string>& prod);
  
  std::string get_production(const char& non_terminal, const size_t& num) const;
  size_t get_greates_non_terminal(const char& symbol) const;

  /// Funciones de la clase (Métodos).
  size_t production_size(void) const;
  bool is_production(const char& symbol, const size_t& num) const;

  Productions& operator=(const Productions& prod);
  friend std::ostream& operator<<(std::ostream& out, const Productions& prod);
 private:
  std::multimap<char, std::pair<size_t, std::string>> production_;
};

#endif // PRODUCTIONS_H