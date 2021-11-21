#include "Grammar.h"

#include <string.h>

#include <system_error>
#include <cstring>
#include <cerrno>

void grep() {
  std::cout << " Para la correcta ejecucion del programa debemos seguir los siguientes pasos:\n";
  std::cout << " 1. Se debe pasar como parametros al ejecutar el programa, la secuencia de adn del que leer y el fichero que se va a guardar.\n";
  std::cout << " 2. Se hara de la siguiente forma: \n\t\t./p05_dna_sequencer {PATRÓN} dna_subsequences.out\n";
  std::cout << " 3. El programa se encargara de analizar la cadena de entrada, y mientras, escribirá la solución en el fichero de salida." << std::endl;
}

int main(int argc, char* argv[]) {
  // Check the numer of arguments is correct
  if (argc == 1) {
    std::cout << "Modo de empleo: grep [OPCIÓN]... PATRÓN [FICHERO]...\n";
    std::cout << "Pruebe ‘grep --help’ para más información." << std::endl;
  }
  else if (argc == 2 && !strcmp(argv[1], "--help")) {
    grep();
  }
  else if (argc == 4) {
    const std::string kCFGFile{argv[1]};
    const std::string kCFGProductions{argv[2]};
    const std::string kCFGOutFile{argv[3]};

    std::ifstream cfg_file(kCFGFile, std::fstream::in);
    std::ifstream cfg_productions(kCFGProductions, std::fstream::in);
    std::ofstream cfg_out_file(kCFGOutFile, std::fstream::out);
  
    Grammar grammar(cfg_file);
    cfg_file.close();

    if (grammar.analize(cfg_productions, cfg_out_file))
      throw std::system_error(errno, std::system_category(), "Ha habido algún error con el archivo");

    cfg_productions.close();
    cfg_out_file.close();
  }
  else {
    throw std::system_error(errno, std::system_category(), "Se ha introducido un numero invalido o erroneo de argumentos\n. Por favor vuelva a intentarlo o ejecute ./prueba --help para más información.");
  }

  return 0;
}