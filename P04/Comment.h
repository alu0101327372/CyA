// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File Comment.h:
//      Contains the definition of the Comment class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#ifndef COMMENT_H_
#define COMMENT_H_

#include <iostream>
#include <string>

class Comment {
  public:
    Comment(std::string comment, size_t line);

    size_t get_line() const;
    std::string get_comment() const;
    std::string write_file() const;
  private:
    // Checks if exists a description, it happens when line_ == 1
    bool is_description = false;
    // Data of the comment 
    std::string comment_;
    // Line of the input file
    size_t line_;
    // Lenght of the comment
    size_t length_;
};

#endif // COMMENT_H_