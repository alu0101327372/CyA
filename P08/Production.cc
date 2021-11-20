#include "Production.h"

/**
 * @fn Production::Production(const char& non_terminal, 
 *                       std::pair<size_t, std::string> prod)
 * @brief Constructor predeterminado, coge los valores que se le pasan a la
 * función y inicializa el primer elemento del multimap con ellos.
 * 
 * @param non_terminal clave del multimap.
 * @param prod valor del multimap.
 */
Production::Production(const char& non_terminal, 
                         std::pair<size_t, std::string> prod) {
  prod_.insert(std::make_pair(non_terminal, prod));
}

/**
 * @fn Production::Production(const char& non_terminal, const size_t& num, 
 *                        const std::string& prod)
 * @brief Segundo constructor predeterminado, hace lo mismo que el anterior
 * pero de otra forma
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para encontrar la producción concreta
 * @param prod cadena por la que se sustituye a "non_terminal"
 */
Production::Production(const char& non_terminal, const size_t& num, 
                         const std::string& prod) {
  prod_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}

/**
 * @fn Production::Production(const Production& prod)
 * @brief Constructor de copia
 * 
 * @param prod objeto del que copiaremos sus atributos para crear uno nuevo
 */
Production::Production(const Production& prod) : prod_(prod.prod_) {}



void Production::set_production(const std::multimap<char, std::pair<size_t, std::string> >& prod) {
  prod_ = prod;
}

/**
 * @fn void Production::set_production(const char& non_terminal, const size_t& num, 
 *                               const std::string& prod)
 * @brief Setter, introduce un nuevo elemento en el multimap
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para hallar la producción concreta
 * @param prod cadena por la que se sustituye a "non_terminal"
 */
void Production::set_production(const char& non_terminal, const size_t& num,
                          const std::string& prod) {
  prod_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}

/**
 * @fn void Production::set_production(const char& non_terminal, 
 *                               std::pair<size_t, std::string>& prod)
 * @brief Setter, introduce un nuevo elemento en el multimap.
 * 
 * @param non_terminal clave del elemento del multimap
 * @param prod objeto que contiene, una etiqueta para identificar la producción
 * y la producción en sí.
 */
void Production::set_production(const char& non_terminal, 
                          std::pair<size_t, std::string>& prod) {
  prod_.insert(std::make_pair(non_terminal, prod));
}


/**
 * @fn std::string Production::get_production(const char& non_terminal, 
 *                                const size_t& num) const
 * @brief Getter, devuelve una producción concreta con ayuda de los parámetros
 * que se le pasan a la función.
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para encontrar la producción concreta
 * @return std::string, es la producción hallada, si los argumentos de la
 * función están mal, este valor será vacío.
 */
std::string Production::get_production(const char& non_terminal, 
                                 const size_t& num) const {
  std::string aux{""};
  for (auto i : prod_) {
    if ((i.first == non_terminal) && (i.second.first == num)) {
      aux = i.second.second;
    }
  }
  return aux;
}

/**
 * @fn size_t Production::get_greatest_non_terminal(const char& symbol) const
 * @brief devuelve la etiqueta más grande más 1, de un símbolo no terminal
 * asociado a una o varias producciones, si el símbolo no está en el conjunto
 * de símbolos no terminales, el valor retornado es cero.
 * 
 * @param symbol simbolo a evaluar.
 * @return size_t 
 */
size_t Production::get_greatest_non_terminal(const char& symbol) const {
  size_t result{0};
  for (auto i : prod_) {
    if ((i.first == symbol) && (i.second.first >= result))
      result = ++i.second.first;
  }
  return result;
}


/**
 * @fn bool Production::is_production(const char& symbol, 
 *                                       const size_t& num) const
 * @brief Función que nos dice si hay una producción asociada a un símbolo no
 * terminal y un número de referencia en el conjunto de producciones.
 * 
 * @param symbol símbolo no terminal.
 * @param num número que clasifica todas las producciones que tiene un símbolo
 * no terminal.
 * @return true hay una producción para el símbolo no terminal dado, y con la
 * etiqueta num.
 * @return false no hay una producción para el símbolo no terminal dado, y con 
 * la etiqueta num.
 */
bool Production::is_production(const char& symbol, const size_t& num) const {
  bool result{false};
  for (auto i : prod_) {
    if ((i.first == symbol) && (i.second.first == num)) {
      result = true;
      break;
    }
  }
  return result;
}

/**
 * @fn void Production::operator=(const Production& prod)
 * @brief Sobrecarga del operator "=", iguala los objetos std::multimap de cada
 * objeto de la clase.
 * 
 * @param prod objeto del cual se van a coger sus atribujos internos para 
 * pasarselos al objeto que está a la izquierda del operador.
 */
void Production::operator=(const Production& prod) {
  prod_ = prod.prod_;
}

/**
 * @fn std::ostream& operator<<(std::ostream& out, const Production& prod)
 * @brief Sobrecarga del operador de extracción.
 * 
 * @param out objeto de flujo de salida
 * @param prod objeto que queremos mostrar por la salida estándar
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Production& prod) {
  out << '\n';
  for (auto i : prod.prod_) {
    out << i.first << '(' << i.second.first << ')' << " -> ";
    out << i.second.second << '\n';
  }
  return out;
}