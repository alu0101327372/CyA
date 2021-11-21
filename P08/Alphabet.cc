#include "Alphabet.h"

/**
 * @brief Construct of copy of Alphabet object
 * 
 * @param name Name of the alphabet
 * @param alphabet Alphabet set 
 */
Alphabet::Alphabet(const std::set<char>& alphabet) : alphabet_(alphabet) {}



/**
 * @brief Construct of copy of Alphabet object
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(const Alphabet& alphabet) : alphabet_(alphabet.alphabet_) {}




/**
 * @brief Insert symbol in alphabet
 * 
 * @param symbol because we use char in set
 */
void Alphabet::add_symbol(const char& symbol) {
  char aux = symbol;
  alphabet_.insert(aux);
}



/**
 * @brief Insert symbol in alphabet
 * 
 * @param symbol because we use a set
 */
void Alphabet::add_symbol(const std::string& symbol) {
  if (symbol.size() == 1) {
    char aux = symbol.front();
    alphabet_.insert(aux);
  }
}



void Alphabet::set_alphabet(const std::set<char>& alphabet) {
  alphabet_ = alphabet;
}



void Alphabet::set_alphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
}



char Alphabet::get_symbol(const size_t& position) const {
  char result;
  if (position < alphabet_.size()) {
    size_t count = 0;
    for (std::set<char>::iterator i = alphabet_.begin(); i != alphabet_.end(); i++) {
      if (count == position) {
        result = *i;
        break;
      }
      ++count;
    }
  }
  return result;
}



std::set<char> Alphabet::get_alphabet(void) const {
  return alphabet_;
}



size_t Alphabet::get_size(void) const {
  return alphabet_.size();
}



/**
 * @brief Used to check if the symbol exists in the alphabet
 * 
 * @param symbol the symbol to check
 * @return true if exist 
 * @return false it don't exist
 */
bool Alphabet::is_symbol(const char& symbol) const {
  bool result = false;
  for (std::set<char>::iterator i = alphabet_.begin(); i != alphabet_.end(); i++) {
    if (symbol == *i) {
      result = true;
      break;
    }
  }
  return result;
}



/**
 * @brief Used to check if the symbol exists in the alphabet
 * 
 * @param symbol the symbol to check
 * @return true if exist 
 * @return false it don't exist
 */
bool Alphabet::is_symbol(const std::string& symbol) const {
  bool result = false;
  if (symbol.size() == 1) {
    char aux = symbol.front();
    for (std::set<char>::iterator i = alphabet_.begin(); i != alphabet_.end(); i++) {
      if (aux == *i) {
        result = true;
        break;
      }
    }
  }
  return result;
}



void Alphabet::clear_alphabet(void) {
  alphabet_.clear();
}



/**
 * @brief Operator of copy
 * 
 * @param alphabet 
 * @return Alphabet& 
 */
Alphabet& Alphabet::operator=(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
  return *this;
}



/**
 * @brief Operator ==
 * 
 * @param alphabet 
 * @return true if is equal 
 * @return false if is not equal
 */
bool Alphabet::operator==(const Alphabet& alphabet) const {
  bool result = true;
  if (alphabet_.size() == alphabet.alphabet_.size()) {
    size_t count = 0;
    for (std::set<char>::iterator i = alphabet_.begin(); i != alphabet_.end(); i++) {
      if (!(alphabet.get_symbol(count) == *i)) {
        result = false;
        break;
      }
      ++count;
    }
  } else {
    result = false;
  }
  return result;
}



/**
 * @brief Operator []
 * 
 * @param alphabet 
 * @return specific symbol
 */
char Alphabet::operator[](const size_t position) const {
  return this->get_symbol(position);
}