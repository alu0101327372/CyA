// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File File.cc:
//      Contains the implementation of the File class.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#include "File.h"

File::File(const std::string& kFileName, std::ifstream& input_file) {
  file_name_ = kFileName;
  // This loop reads each line of the file and initializes the vectors
  while(!input_file.eof()) {
    // Line that represents each line of the file
    std::string aux_line = "";
    std::getline(input_file, aux_line);
    // Stores each match of the pattern search
    std::smatch matches;
    // Expression of the variabples search pattern
    std::regex expression_variable("\\S*(int|double)\\s[A-Za-z]*(\\s=\\s(\\d|[A-Za-z]);|;)$");
    // Look for the pattern and if it finds it add a Variable object to the vector
    if (std::regex_search(aux_line, matches, expression_variable)) {
      std::string type = matches[0];
      // Change the format of the variable to suit the specification
      std::string aux = replace_variable(type);
      vars_.push_back(Variable(aux, counter));
    }
    // Expression of the loops search pattern
    std::regex expression_loop("\\s*(for|while)\\s*[(]\\s*");
    // Look for the pattern and if it finds it add a Loop object to the vector
    if (std::regex_search(aux_line, matches, expression_loop)) {
      std::string type = matches[1];
      loops_.push_back(Loop(type, counter));
    }
    // Expression of the main function search pattern
    std::regex is_main_expression("^int main");
    // Look for the pattern and if it finds it is_main = true
    if (std::regex_search(aux_line, matches, is_main_expression)) {
      std::string type = matches[0];
      is_main = true;
    }
    // Comments search pattern expression
    std::regex expresion_comment("(((^|\\s)/\\*)|((^|\\s)\\*\\s.*)|(\\*/$))|((^|\\s)//.*)");
    // Look for the pattern and if it finds it add a Comment object to the vector
    if (std::regex_search(aux_line, matches, expresion_comment)) {
      if (counter == 1) {
        is_description = true;
      }
      std::string type = matches[0];
      comments_.push_back(Comment(type, counter));
    }
    counter++;
  }
}



// Replace the format of the variable to the specification of the output file
// int -> INT: or double -> DOUBLE:
std::string File::replace_variable(std::string str) {
  std::regex expression1("^int*");
  std::regex expression2("^double*");
  std::regex expression3(";");
  std::smatch matches;
  std::string aux;
  if (std::regex_search(str, matches, expression1))
    aux = std::regex_replace(str, expression1, "INT:");
  else 
    aux = std::regex_replace(str, expression2, "DOUBLE:");
  return std::regex_replace(aux, expression3, "$2");
}



// Returns a string in the specified format for the output file
std::string File::write_file() const {
  // Strings that are going to store the output format
  std::string program_str, description_str, vars_str, stmts_str, main_str, comments_str, comments_str2;
  program_str = "PROGRAM:\n" + file_name_ + "\n";

  description_str = "DESCRIPTION:\n";
  // Stores the line where description ends
  int end_description = 0;
  if (is_description == true) {
    for (const Comment& d : comments_) {
      description_str += d.get_comment() + "\n";
      if (d.get_comment() == "*/") {
        end_description = d.get_line();
        break;
      }
    }
  }
  vars_str = "VARIABLES: \n";
  for (const Variable& v : vars_)
    vars_str += v.write_file() + "\n";

  stmts_str = "STATEMENTS: \n";
  for (const Loop& l : loops_)
    stmts_str += l.write_file() + "\n";

  main_str = "MAIN: \n";
  if (is_main == true)
    main_str += "True\n";
  else 
    main_str += "False\n";

  comments_str = "COMMENTS: \n";
  if (is_description == true) {
    comments_str += "[Line 1 - " + std::to_string(end_description) + "] DESCRIPTION\n";
    for (const Comment& c : comments_) {
      if(c.get_line() > end_description) {
        comments_str += c.write_file() + "\n";
      }
    }
  }
  else {
    for (const Comment& c : comments_) {
      comments_str2 += c.write_file() + "\n";
    }
  }
  return program_str + "\n" + description_str + "\n" + vars_str + "\n" + stmts_str + "\n" 
        + main_str + "\n" + comments_str + "\n" + comments_str2;
}



std::ostream& operator<<(std::ostream& os, const File& f) {
  return os << f.write_file();
}