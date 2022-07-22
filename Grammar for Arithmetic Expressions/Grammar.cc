#include "Grammar.h"

/**
 * @brief Initialize Grammar Object
 * 
 * @param alphabet alphabet of the grammar
 * @param non_terminals non-terminal symbols of the grammar
 * @param start start symbol of the grammar
 * @param prod set of rules for the grammar
 */
Grammar::Grammar(const std::set<char>& alphabet, const std::set<char>& non_terminals, const char& start, 
  const std::multimap<char, std::pair<size_t, std::string>>& prod) : alphabet_(), non_terminals_(), 
  start_(), prod_(), creation_failed_(false) {
  alphabet_.set_alphabet(alphabet);
  non_terminals_.set_alphabet(non_terminals);
  start_ = start;
  prod_.set_production(prod);
}



/**
 * @brief Initialize Grammar Object
 * 
 * @param alphabet alphabet of the grammar
 * @param non_terminals non-terminal symbols of the grammar
 * @param start start symbol of the grammar
 * @param prod set of rules for the grammar
 */
Grammar::Grammar(const Alphabet& alphabet, const Alphabet& non_terminals, const char& start, 
  const Productions& prod) : alphabet_(), non_terminals_(), start_(), prod_(), creation_failed_(false) {
  alphabet_ = alphabet;
  non_terminals_ = non_terminals;
  start_ = start;
  prod_ = prod;
}



/**
 * @brief Build a new Grammar object from an existing one.
 * 
 * @param grammar Grammar object
 */
Grammar::Grammar(const Grammar& grammar) : alphabet_(grammar.alphabet_), 
  non_terminals_(grammar.non_terminals_), start_(grammar.start_), prod_(grammar.prod_), 
  creation_failed_(grammar.creation_failed_) {}



/**
 * @fn Grammar::Grammar(std::ifstream& cfg_file)
 * @brief Construye un nuevo objeto Grammar a partir de un archivo donde se
 * especifican los elementos de este.
 * 
 * @param cfg_file file where the elements of each are described
 * internal object of grammar.
 */
Grammar::Grammar(std::ifstream& cfg_file) : alphabet_(), non_terminals_(), start_(), prod_(), 
  creation_failed_(false) {
  std::string aux_str = "";
  size_t count = 0;
  std::regex line_only_spaces("^\\s*$");
  std::regex set_symbols_pattern("^\\s*?(([^\\s])\\s)*?\\s*?$");
  std::regex prods_pattern("^\\s*?([^\\s]) -> \\s*(.*?)\\s*?$");
  std::smatch prods_match;

  while (!cfg_file.eof()) {
    getline(cfg_file, aux_str);
    if (aux_str.empty() || regex_match(aux_str, line_only_spaces)) 
      continue;
    ++count;

    // analyze the lines that contain descriptions of productions.
    if (count > 2) {
      /// if the line is misspelled, the program is terminated
      if (regex_match(aux_str, prods_match, prods_pattern)) {
        /// if the non-terminal symbol of the line is incorrect, the program ends.
        if (non_terminals_.is_symbol(prods_match[1].str())) {
          // if the production contains a single symbol other than the alphabet or 
          // the set of non-terminal symbols, the program is terminated
          if (this->is_accpeted_production(prods_match[2].str())) {
            // if it is the first time that a production associated with the non-terminal symbol 
            // of the line is added, it is added with a number 1 as a reference, otherwise, 
            // it is added with the value of the largest number associated with the symbol plus 1 .
            if (!prod_.is_production(prods_match[1].str().front(), 1)) {
              prod_.set_production(prods_match[1].str().front(), 1, prods_match[2].str());
            } else {
              prod_.set_production(prods_match[1].str().front(), 
                            prod_.get_greates_non_terminal(prods_match[1].str().front()),
                            prods_match[2].str());
            }
          } else {
            creation_failed_ = true;
            break;
          }
        } else {
          creation_failed_ = true;
          break;
        }
      } else {
        creation_failed_ = true;
        break;
      }
    }

    if (count <= 2) {
      if (regex_match(aux_str, set_symbols_pattern)) {
        for (auto i : aux_str) {
          if (i != ' ') {
            if (count == 1) {
              alphabet_.add_symbol(i);
            }
            if ((count == 2) && (non_terminals_.get_size() == 0)) {
                start_ = i;
              }
            if (count == 2) {
              non_terminals_.add_symbol(i);
            }
          }
        }
      } else {
        creation_failed_ = true;
        break;
      }
    }
  }
}



Alphabet Grammar::get_alphabet(void) const {
  return alphabet_;
}



Alphabet Grammar::get_non_terminal(void) const {
  return non_terminals_;
}



char Grammar::get_start(void) const {
  return start_;
}



Productions Grammar::get_productions(void) const {
  return prod_;
}



std::string Grammar::get_productions(const char& non_terminal, const size_t& num) const {
  return prod_.get_production(non_terminal, num);
}



/**
 * @brief Used to check if the symbol exists in the alphabet
 * 
 * @param symbol the symbol to check
 * @return true if exist 
 * @return false it don't exist
 */
bool Grammar::is_symbol(const char& symbol) const {
  return alphabet_.is_symbol(symbol);
}



/**
 * @brief Used to check if the symbol exists in the non-terminal alphabet
 * 
 * @param symbol the symbol to check
 * @return true if exist 
 * @return false it don't exist
 */
bool Grammar::is_non_terminal(const char& symbol) const {
  return non_terminals_.is_symbol(symbol);
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
bool Grammar::is_production(const char& symbol, const size_t& num) const {
  return prod_.is_production(symbol, num);
}



/**
 * @brief Function that checks if there is a production associated with a non-symbol
 * terminal and a reference number in the set of productions.
 * 
 * @param symbol non terminal
 * @param num specific production
 * @return true if it is a valid production
 * @return false if it is not a valid production
 */
bool Grammar::is_accpeted_production(const std::string& prod) const {
  bool result = true;
  for (auto i : prod) {
    if (i == ' ') {
      continue;
    }
    if (!(alphabet_.is_symbol(i) || non_terminals_.is_symbol(i))) {
      result = false;
      break;
    }      
  }
  return result;
}

/**
 * @brief evaluate the content of the input file and based on it, it writes to the output file,
 * 
 * @param cfg_prods_file input text file.
 * @param cfg_out_file output text file.
 * @return true if it exists an error
 * @return false if it was succeded
 */
bool Grammar::analize(std::ifstream& cfg_prods_file, std::ofstream& cfg_out_file) {
  bool result = false;
  bool non_terminal_in_line_replaced = false;
  std::string aux_str = "";
  std::string final_chain{start_};
  std::regex line_only_spaces("^\\s*$");
  std::regex prods_pattern("^\\s*?([^\\s]): ([\\d]+)\\s*?$");
  std::smatch prods_match;

  cfg_out_file << final_chain << '\n';

  while (!cfg_prods_file.eof()) {
    getline(cfg_prods_file, aux_str);
    if (aux_str.empty() || regex_match(aux_str, line_only_spaces)) {
      continue;
    }
    if (regex_match(aux_str, prods_match, prods_pattern)) {
      // if the non-terminal symbol it produces is misspelled, the program is terminated.
      if (non_terminals_.is_symbol(prods_match[1].str())) {
        // if only one symbol is not contained in either alphabet_ or 
        // non_terminals_, then the program is terminated.
        if (prod_.is_production(prods_match[1].str().front(), size_t(std::stoi(prods_match[2].str())))) {
          for (auto i: final_chain) {
            /// if the first non-terminal symbol does not match the position in the line 
            // of the input.drv file that we are reading at the moment, the program is terminated.
            if (non_terminals_.is_symbol(i) && i != prods_match[1].str().front()) {
              result = true;
              break;
            }
            /// if we find the first non-terminal symbol and it matches 
            // the position in the file line, then this is replaced by its production and 
            // iterated again to read the next production or terminate the program successfully.
            if (i == prods_match[1].str().front()) {
              final_chain.replace(final_chain.find_first_of(i), 1, prod_.get_production(prods_match[1].str().front(), 
                                size_t(std::stoi(prods_match[2].str()))));
              non_terminal_in_line_replaced = true;
              cfg_out_file << "=> " << final_chain << '\n';
              break;
            }
          }

          if (non_terminal_in_line_replaced) {
            non_terminal_in_line_replaced = false;
            continue;
          } else {
            result = true;
            break;
          }
        } else {
          result = true;
          break;
        }
      } else {
        result = true;
        break;
      }
    } else {
      result = true;
      break;
    }
  }
  return result;
}