// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
// Fecha: 04/10/2021
// Archivo cya-P02-Strings.cc: 
//          Contiene la función main del proyecto que usa la funcion
//          que realiza el trabajo de leer el fichero de entrada
//          identificando patrones en el texto que dan lugar
//          al fichero de salida.
// Historial de revisiones 
//          06/10/2021 - Creación (primera versión) del código
//          07/10/2021 - Continuación de programación
//          08/10/2021 - Continuación de programación
//          10/10/2021 - Revisión de errores
//          11/10/2021 - Última revisión.
#include "Alphabet.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {  // Comprobamos que el número de argumentos es correcto
    std::cout << "Usage: " << argv[0] << " Name of input file " << " Name of output file "
    << " Opcode " << std::endl;
    return 0;
  }
  
  std::ofstream fout;
  std::cout.rdbuf(fout.rdbuf()); //redirect std::cout to out.txt!
  fout.open(argv[2]);
  
  std::ifstream fin;
  fin.open(argv[1]);
  
  int opcode = std::atoi(argv[3]);
  std::string input_string;
  
  while (std::getline(fin, input_string, '\n')) {
    Alphabet alphabet(input_string);
    
    switch (opcode) {
      case 1:
        fout << alphabet.get_string_length() << std::endl;
        break;
      
      case 2:
        fout << alphabet.get_string_inverse() << std::endl;
        break;
      
      case 3:
        fout << alphabet.get_string_prefix() << std::endl;
        break;
        
      case 4:
        fout << alphabet.get_string_suffix() << std::endl;
        break;

      case 5:
        fout << alphabet.get_string_substring() << std::endl;
        break;
        
        default:
            break;
      }
  }
  return 0;
} 