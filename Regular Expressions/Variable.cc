// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File Variable.h:
//      Contains the implementation of the Variable class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#include "Variable.h"

Variable::Variable(std::string type, size_t line) {
  line_ = line;
  type_ = type;
}



// Returns a string in the specified format for the output file
std::string Variable::write_file() const {
  return "[Line " + std::to_string(line_) + "] " + type_;
}