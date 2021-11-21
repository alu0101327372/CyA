#ifndef _PRODUCTIONS_
#define _PRODUCTIONS_

#include <iostream>
#include <map>

/**
 * @class Productions.
 * @brief Una gramática debe tener producciones, que un conjunto de símbolos
 * no terminales que pueden generar otros símbolos no terminales y terminales,
 * esta clase se encarga de definir esas producciones y usarlas según convenga. 
 */
class Productions {
 public:
  /// Constructores. Tenemos el por defecto, y los dos predeterminados, y el
  /// de copia.
  Productions(void);
  Productions(const char& non_terminal, 
              std::pair<size_t, std::string> prod);
  Productions(const char& non_terminal, const size_t& num, 
              const std::string& prod);
  Productions(const Productions& prod);

  /// Setters.
  void SetProd(const std::multimap<char, std::pair<size_t, std::string>>& 
               prod);
  void SetProd(const char& non_terminal, const size_t& num, 
               const std::string& prod);
  void SetProd(const char& non_terminal, 
               std::pair<size_t, std::string>& prod);
  
  /// Getters.
  std::pair<std::multimap<char, std::pair<size_t, std::string>>::iterator,
  std::multimap<char, std::pair<size_t, std::string>>::iterator> 
  GetEqRang(const char& non_terminal);
  std::string GetProd(const char& non_terminal, const size_t& num) const;
  size_t GetUpperNumP1(const char& symbol) const;

  /// Funciones de la clase (Métodos).
  size_t Size(void) const;
  bool IsItAProduction(const char& symbol, const size_t& num) const;

  /// Operadores sobrecargados.
  Productions& operator=(const Productions& prod);

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Productions& prod);
  
 private:
  /// multimap que contiene todas las producciones de la gramática.
  std::multimap<char, std::pair<size_t, std::string>> prod_;
};
#endif