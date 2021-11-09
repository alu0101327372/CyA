// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo cya-P03-Strings.cc: 
//          Contiene la función main del proyecto que usa la funcion
//          que realiza el trabajo de leer el fichero de entrada
//          identificando patrones en el texto que dan lugar
//          al fichero de salida.
// Historial de revisiones 
//          14/10/2021 - Creación (primera versión) del código
//          15/10/2021 - Continuación de programación
//          16/10/2021 - Revisión de errores
//          17/10/2021 - Última revisión.
#include "String.h"

#include <string.h>

#include <fstream>
#include <system_error>
#include <cerrno>

int main(int argc, char* argv[]) {
  // Check that the number of arguments is correct
  if (argc != 4 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
    std::cout << "Usage: " << argv[0] << " <input_file> <output_file> <opcode>\n"
    << "Opcodes:\n"
    << "  1 (Length): Get the length of each sentence\n"
    << "  2 (Inverse): Get the inverse of each sentence\n"
    << "  3 (Prefixes): Get all the prefix of each sentence\n"
    << "  4 (Suffixes): Get all the suffixes of each sentence\n"
    << "  5 (SubStrings): Get all the sub-chains of each sentence\n"
    << "  6 (Compare): Get the comparation of two strings\n"
    << "  7 (Concatenation): Get the concatenation of two strings\n"
    << "  8 (Addition): Get the addition of a string n times\n"
    << "\n";
    return 0;
  }
  std::ofstream fout;
  fout.open(argv[2]);

  std::ifstream fin;
  fin.open(argv[1]);
  
  int opcode = std::atoi(argv[3]);
  std::string input_string;
  std::string input;
  int n;
  if (opcode == 6 || opcode == 7) {
    std::cout << "Introduce una cadena de entrada\n";
    std::cin >> input;
  }
  else if (opcode == 8) {
    std::cout << "Introduce un numero de entrada\n";
    std::cin >> n;
  }
  while (std::getline(fin, input_string, '\n')) {
    String string(input_string);
    switch (opcode) {
      case 1:
        fout << string.get_length() << std::endl;
        break;
      
      case 2:
        fout << string.get_inverse() << std::endl;
        break;
      
      case 3:
        fout << string.get_prefix() << std::endl;
        break;
        
      case 4:
        fout << string.get_suffix() << std::endl;
        break;

      case 5:
        fout << string.get_substring() << std::endl;
        break;

      case 6:
        fout << string.comparation(input) << std::endl;
        break;

      case 7:
        fout << string.concatenation(input) << std::endl;
        break;

      case 8:
        fout << string.addition(n) << std::endl;
        break;

        default:
          throw std::system_error(errno, std::system_category(), "Invalid opcode");
          break;
      }
  }
  fin.close();
  fout.close();
  return 0;
} 
