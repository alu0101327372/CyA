// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File Comment.h:
//      Contains the implementation of the Comment class.
// Revision history
//      10/14/2021 - Creation (first version) of the code
//      10/15/2021 - Continuation of programming
//      10/16/2021 - Bug fixes
//      10/17/2021 - Last revision.
#include "Comment.h"

Comment::Comment(std::string comment, size_t line) {
  line_ = line;
  comment_ = comment;
  if (line_ == 1)
    is_description = true;
}



size_t Comment::get_line() const {
  return line_;
}



std::string Comment::get_comment() const {
  return comment_;
}



// Returns a string in the specified format for the output file
std::string Comment::write_file() const {
  return "[Line " + std::to_string(line_) 
  + (length_ ? "-" + std::to_string(line_ + length_) : "")
  + "] " + comment_;
}