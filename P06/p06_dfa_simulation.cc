// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo Dfa.h:
//      Implementa un autómata determinista finito (AFD o DFA), y comprueba si las cadenas
//      son aceptadas o no por el automata
// Revisión histórica
//      02/11/2021 - Creación (primera versión) del código
//      23/11/2021 - Continuación de la programación
//      24/11/2021 - Corrección de errores
//      05/11/2021 - Última revisión.
#include "Dfa.h"

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
    std::string dfa_file = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];
    // Automata Finito Determista
    Dfa dfa;
    dfa.insert_file(dfa_file, input_file, output_file);
  }
  else {
    throw std::system_error(errno, std::system_category(), "Se ha introducido un numero invalido o erroneo de argumentos\n. Por favor vuelva a intentarlo o ejecute ./prueba --help para más información.");
  }
  return 0;
} 