#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <set>

class Alphabet {
 public:
  Alphabet(void) = default;
  Alphabet(const std::string& name, const std::set<char>& alphabet);
  Alphabet(const Alphabet& alphabet);

  /// Setters.
  void add_symbol(const char& symbol);
  void add_symbol(const std::string& symbol);
  void set_alphabet(const std::string& name, 
                     const std::set<char>& alphabet);
  void set_alphabet(const Alphabet& alphabet);
  void set_name(const std::string& name);

  /// Getters.
  char get_symbol(const size_t& position) const;
  std::set<char> get_alphabet(void) const;
  std::string get_name(void) const;

  /// Funciones de la clase (Métodos).
  bool is_alphabet(const char& symbol) const;
  bool is_alphabet(const std::string& symbol) const;
  void clear_alphabet(void);

  /// Operadores sobrecargados.
  void operator=(const Alphabet& alphabet);
  bool operator==(const Alphabet& alphabet) const;
  char operator[](const size_t position) const;

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend std::istream& operator>>(std::istream& input, Alphabet& alphabet);
 private:
  std::string name_; ///< Nombre del conjunto, para diferenciarlos entre sí.
  std::set<char> alphabet_; ///< Variable donde guardamos el conjunto.
};

#endif