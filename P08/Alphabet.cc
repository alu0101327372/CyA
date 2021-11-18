#include "Alphabet.h"

/**
 *
 *  @brief  Alphabet constructor -> initialize Alphabet objects-
 *  @param  std::set<std::strings> set of Symbol that make up the alphabet.
 *
 */
Alphabet::Alphabet(std::set<Symbol> alph) { 
  alphabet_ = alph; 
}



/**
 *
 *  @brief  Get the value of a called alphabet obj.
 *  @return alphabet value.
 *
 */
std::set<Symbol> Alphabet::get_alphabet() { 
  return alphabet_; 
}



/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_Alphabet& symbol
 *  @return Write the Symbol of the alphabet
 *
 */
std::ostream&operator<<(std::ostream& os, const Alphabet& Kalphabet_) {
  for (auto symbol : Kalphabet_.alphabet_ ) {
    os << symbol << ' ';
  }
  return os;
}



/**
 *
 *  @brief  Get the size of a set of Symbol inside an alphabet.
 *  @return alphabet size.
 *
 */
int Alphabet::size() { 
  return alphabet_.size(); 
}