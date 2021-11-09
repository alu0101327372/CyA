// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Materia: Computabilidad y Algoritmia // Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Marco Antonio Cabrera Hernández
// Correo electrónico: alu0101327372@ull.es
// Fecha: 10/04/2021
// Archivo p05_dna_sequencer.cc:
//      Implementa un autómata determinista finito (AFD o DFA) para extraer ciertos
//      patrones de una secuencia de ADN de entrada. Las secuencias de ADN estarán representadas por
//      secuencias de símbolos en el alfabeto {A, C, G, T}.
//      De estas secuencias de ADN, nos interesará extraer todas
//      las posibles subsecuencias de ADN que comienzan y terminan con una A o una T,
//      y que tengan una longitud mayor o igual a 2.
// Revisión histórica
//      26/10/2021 - Creación (primera versión) del código
//      28/10/2021 - Continuación de la programación
//      29/10/2021 - Corrección de errores
//      20/10/2021 - Última revisión.
//      30/10/2021 - Última revisión.
#include "Dfa.h"

#include <string.h>

#include <fstream>
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
  // Comprueba que el número de argumentos es correcto
  if (argc == 1) {
    std::cout << "Modo de empleo: grep [OPCIÓN]... PATRÓN [FICHERO]...\n";
    std::cout << "Pruebe ‘grep --help’ para más información." << std::endl;
  }
  else if (argc == 2 && !strcmp(argv[1], "--help")) {
    grep();
  }
  else if (argc == 3) {
    std::string patron = argv[1];
    const std::string kArchivoSalida = argv[2];
    // Crea el flujo de salida como variable de la biblioteca fstream
    std::ofstream archivo_salida(kArchivoSalida, std::fstream::out);
    // Si no se puede abrir, el programa finaliza
    if (archivo_salida.fail()) {
      throw std::system_error(errno, std::system_category(), "No se pudo abrir el archivo.");
    }
    // Automata Determista
    Dfa dfa;
    archivo_salida << dfa.write_file(patron);
    // Cierra el archivo para liberar memoria, ya no es necesario
    archivo_salida.close();
  }
  else {
    throw std::system_error(errno, std::system_category(), "Se ha introducido un numero invalido o erroneo de argumentos\n. Por favor vuelva a intentarlo o ejecute ./prueba --help para más información.");
  }
  return 0;
} 