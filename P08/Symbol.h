#ifndef _SYMBOL_
#define _SYMBOL_

#include <iostream>
#include <string>

/**
 * @class Symbol. 
 * @brief Para poder tratar con alfabetos con símbolos de longitud mayor a 1
 * (con un alfabeto que contenga el símbolo "hola" por ejemplo), necesitamos
 * definir que es un símbolo exactamente, lo que hace esta clase.
 */
class Symbol {
 public:
  /// Constructores. Tenemos 4, el por defecto, los dos predeterminados (los
  /// usamos más), y el de copia.
  Symbol(void);
  Symbol(const char& character);
  Symbol(const std::string& chain);
  Symbol(const Symbol& symbol);

  /// Setters.
  void SetSymbol(const char& character);
  void SetSymbol(const std::string& chain);
  void SetSymbol(const Symbol& symbol);
  void EmplaceBack(const char& character);
  void EmplaceBack(const std::string& chain);
  void EmplaceBack(const Symbol& symbol);

  /// Getters.
  std::string GetSymbol(void) const;

  /// Funciones de la clase (Métodos).
  size_t Size(void) const;

  /// Operadores sobrecargados.
  bool operator==(const Symbol& symbol) const;
  Symbol operator=(const Symbol& symbol);
  Symbol operator+(const Symbol& symbol);
  bool operator<(const Symbol& symbol) const;

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend std::istream& operator>>(std::istream& input, Symbol& symbol);
  
 private:
  std::string symbol_; ///< std::string que actua como un símbolo.
};
#endif 