// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File Variable.h:
//      Contains the definition of the Variable class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>

class Variable {
  public:
    Variable(std::string type, size_t line);

    std::string write_file() const;
  private:
    // Type of variable, it allows integers and doubles 
    std::string type_;
    // Line of the input file
    size_t line_;
};

#endif // VARIABLE_H