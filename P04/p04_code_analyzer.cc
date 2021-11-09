// University of La Laguna
// Higher School of Engineering and Technology
// Degree in Computer Engineering
// Subject: Computability and Algorithmy // Course: 2nd
// Practice 4: Regular expressions
// Author: Marco Antonio Cabrera Hernández
// Email: alu0101327372@ull.es
// Date: 04/10/2021
// File File.h:
//      Contains the main function of the project that the class uses
//      File to be able to perform operations with files
//      input, these operations are:
//      Create a new file in the current directory where the program is running,
//      and fill that file with data extracted from the input file.
// Revision history
//      10/20/2021 - Creation (first version) of the code
//      10/21/2021 - Continuation of programming
//      10/22/2021 - Bug fixes
//      10/23/2021 - Last revision.
#include "File.h"

#include <string.h>

#include <fstream>
#include <system_error>
#include <cerrno>

int main(int argc, char* argv[]) {
  // Checks the number of arguments is correct
  if (argc != 3 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
    std::cout << "Usage: " << argv[0] << " <input_file> <output_file>\n";
    return 0;
  }
  const std::string kFileName = argv[0];
  const std::string kFileInput = argv[1];
  const std::string kFileOutput = argv[2];
  // Creates the input and output streams as variables from the fstream library
  std::ifstream fin(kFileInput, std::fstream::in);
  std::ofstream fout(kFileOutput, std::fstream::out);
  // if it cannot be opened, the program ends
  if (fin.fail() || fout.fail()) {
    throw std::system_error(errno, std::system_category(), "Cannot open the file");
  }
  File file(kFileInput, fin);
  fout << file;
  // close the file to free memory, no longer its needed
  fin.close();
  fout.close();

  return 0;
} 