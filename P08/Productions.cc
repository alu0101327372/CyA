#include "Productions.h"

/**
 * @brief Initialize the production object
 * 
 * @param non_terminal symbol 
 * @param prod production
 */
Productions::Productions(const char& non_terminal, std::pair<size_t, std::string> prod) 
  : production_() {
  production_.insert(std::make_pair(non_terminal, prod));
}



/**
 * @brief Initialize the production object
 * 
 * @param non_terminal symbol
 * @param num specific production
 * @param prod production
 */
Productions::Productions(const char& non_terminal, const size_t& num, 
  const std::string& prod) : production_() {
  production_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}



/**
 * @brief Constructor of copy
 * 
 * @param prod Production object
 */
Productions::Productions(const Productions& prod) : production_(prod.production_) {}



void Productions::set_production(const std::multimap<char, std::pair<size_t, std::string>>& prod) {
  production_ = prod;
}



/**
 * @brief Introduce a new element in the multimap
 * 
 * @param non_terminal symbol
 * @param num specific production
 * @param prod production
 */
void Productions::set_production(const char& non_terminal, const size_t& num, const std::string& prod) {
  production_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}



/**
 * @brief Introduce a new element in the multimap
 * 
 * @param non_terminal symbol
 * @param prod production
 */
void Productions::set_production(const char& non_terminal, std::pair<size_t, std::string>& prod) {
  production_.insert(std::make_pair(non_terminal, prod));
}



/**
 * @fn std::string Productions::GetProd(const char& non_terminal, 
 *                                const size_t& num) const
 * @brief Getter, devuelve una producción concreta con ayuda de los parámetros
 * que se le pasan a la función.
 * 
 * @param non_terminal symbol
 * @param num specific production
 * @return production
 */
std::string Productions::get_production(const char& non_terminal, const size_t& num) const {
  std::string aux = " ";
  for (auto i : production_) {
    if ((i.first == non_terminal) && (i.second.first == num)) {
      aux = i.second.second;
    }
  }
  return aux;
}



/**
 * @brief returns the largest label plus 1, of a non-terminal symbol
 * 
 * @param symbol
 * @return size_t 
 */
size_t Productions::get_greates_non_terminal(const char& symbol) const {
  size_t result = 0;
  for (auto i : production_) {
    if ((i.first == symbol) && (i.second.first >= result))
      result = ++i.second.first;
  }
  return result;
}



/**
 * @brief Returns the number of elements that the multimap contains
 * 
 * @return size_t
 */
size_t Productions::production_size(void) const {
  return production_.size();
}



/**
 * @brief Function that checks if there is a production associated with a non-symbol
 * terminal and a reference number in the set of productions.
 * 
 * @param symbol non terminal
 * @param num specific production
 * @return true if exists
 * @return false if don't exists
 */
bool Productions::is_production(const char& symbol, const size_t& num) const {
  bool result = false;
  for (auto i : production_) {
    if ((i.first == symbol) && (i.second.first == num)) {
      result = true;
      break;
    }
  }
  return result;
}


/**
 * @brief Operator of copy
 * 
 * @param prod Production Object 
 * @return Production& 
 */
Productions& Productions::operator=(const Productions& prod) {
  production_ = prod.production_;
  return *this;
}

/**
 * @brief Operator << overload.
 * 
 * @param out ofstrea object
 * @param prod production
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Productions& prod) {
  out << '\n';
  for (auto i : prod.production_) {
    out << i.first << '(' << i.second.first << ')' << " -> ";
    out << i.second.second << '\n';
  }
  return out;
}