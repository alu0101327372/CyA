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
  void Insert(const char& symbol);
  void Insert(const std::string& symbol);
  void SetAlphabet(const std::string& name, 
                     const std::set<char>& alphabet);
  void SetAlphabet(const Alphabet& alphabet);
  void SetName(const std::string& name);

  /// Getters.
  char At(const size_t& position) const;
  std::set<char> GetAlphabet(void) const;
  std::string GetName(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInAlphabet(const char& symbol) const;
  bool IsItInAlphabet(const std::string& symbol) const;
  void Clear(void);

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