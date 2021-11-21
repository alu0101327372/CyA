#ifndef _SET_SYMBOLS_
#define _SET_SYMBOLS_

#include <iostream>
#include <set>

/**
 * @class SetSymbols.
 * @brief Dos de los 4 elementos de una gramática es el alfabeto y su conjunto
 * de símbolos no terminales, esta clase se encarga de definirlos y usarlos
 * según sea conveniente. 
 */
class SetSymbols {
 public:
  /// Constructores. Tenemos 4, el por defecto, al que solo le pasamos el
  /// nombre (el que más usamos), y los dos de copia.
  SetSymbols(void);
  SetSymbols(const std::string& name);
  SetSymbols(const std::string& name, const std::set<char>& set_symbols);
  SetSymbols(const SetSymbols& set_symbols);

  /// Setters.
  void Insert(const char& symbol);
  void Insert(const std::string& symbol);
  void SetSetSymbols(const std::string& name, 
                     const std::set<char>& set_symbols);
  void SetSetSymbols(const SetSymbols& set_symbols);
  void SetName(const std::string& name);

  /// Getters.
  char At(const size_t& position) const;
  std::set<char> GetSetSymbols(void) const;
  std::string GetName(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInSetSymbols(const char& symbol) const;
  bool IsItInSetSymbols(const std::string& symbol) const;
  size_t Size(void) const;
  void Clear(void);

  /// Operadores sobrecargados.
  SetSymbols& operator=(const SetSymbols& set_symbols);
  bool operator==(const SetSymbols& set_symbols) const;
  char operator[](const size_t position) const;

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const SetSymbols& set_symbols);
  friend std::istream& operator>>(std::istream& input, SetSymbols& set_symbols);

 private:
  std::string name_; ///< Nombre del conjunto, para diferenciarlos entre sí.
  std::set<char> set_symbols_; ///< Variable donde guardamos el conjunto.
};
#endif