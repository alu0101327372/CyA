#include "Grammar.h"

int main(int argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};

  const std::string kCFGFile{argv[1]};
  const std::string kCFGProductions{argv[2]};
  const std::string kCFGOutFile{argv[3]};

  std::ifstream cfg_file(kCFGFile, std::fstream::in);
  std::ifstream cfg_productions(kCFGProductions, std::fstream::in);
  std::ofstream cfg_out_file(kCFGOutFile, std::fstream::out);
  
  Grammar grammar(cfg_file);
  cfg_file.close();

  std::cout << grammar << '\n';
  // grammar.EvalProdsInFile(cfg_productions, cfg_out_file);
  cfg_productions.close();
  cfg_out_file.close();

  return 0;
}