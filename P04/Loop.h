// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File Loop.h:
//      Contains the definition of the Loop class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#ifndef LOOP_H_
#define LOOP_H_

#include <iostream>
#include <string>

class Loop {
  public:
    Loop(std::string type, size_t line);
    
    std::string write_file() const;
  private: 
    // Type of loop, it allows while and for 
    std::string type_;
    // Line of the input file
    size_t line_;
};

#endif // LOOP_H_