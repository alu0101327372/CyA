// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File File.h:
//      Contains the definition of the File class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#ifndef FILE_H_
#define FILE_H_

#include "Comment.h"
#include "Variable.h"
#include "Loop.h"

#include <algorithm>
#include <fstream>
#include <vector>
#include <regex>

class File {
  public:
    File(const std::string& kFileName, std::ifstream& input_file);

    // Replace the format of the variable to the specification of the output file
    // int -> INT: or double -> DOUBLE:
    std::string replace_variable(std::string str);
    std::string write_file() const;
    friend std::ostream& operator<<(std::ostream& os, const File& f);
  private:
    // Checks if the function main exits
    bool is_main = false;
    // Check if exists a description
    bool is_description = false;
    // Line counter of the file
    int counter = 1;
    std::string file_name_;
    std::vector<Comment> comments_;
    std::vector<Comment> description_;
    std::vector<Loop> loops_;
    std::vector<Variable> vars_;
};

#endif // FILE_H_