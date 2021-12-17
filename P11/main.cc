// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 11: Algoritmos voraces
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 16/12/2021
// Archivo main.cc: 
//         Implementa el problema de la mochila.
// Revisión histórica
//      16/12/2021 - Creación (primera versión) del código
//      17/11/2021 - Continuación de la programación
//      18/11/2021 - Corrección de errores
//      19/11/2021 - Última revisión.
#include "Mochila.h"

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
  else if (argc == 3) {
    std::vector<float> peso = {10.0, 20.0, 30.0, 4.0, 40.0, 50.0};
    std::vector<float> value = {20.0, 30.0, 66.0, 40.0, 60.0};
    float pesoM = 100.0;
    float num = 5.0;
    Mochila m(peso, value, pesoM, num);
    m.print();
  }
  else {
    throw std::system_error(errno, std::system_category(), "Se ha introducido un numero invalido o erroneo de argumentos\n. Por favor vuelva a intentarlo o ejecute ./prueba --help para más información.");
  }
  return 0;
} 