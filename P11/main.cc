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

#include <stdlib.h>

// Funcion contiene informacion sobre el programa
void grep(int argc, char* argv[]) {
  std::string help = "--help";
  int max_size;
  const std::string kconfig_file = ".cfg";
  std::string file;
  if (argc == 2 && (argv[1] == help)) {
    std::cout << "Los objetos son unicos y solo puede haber uno de cada en la "
                 "mochila, pero se pueden fraccionar, el objetivo es maximizar "
                 "el beneficio de los objetos que se introducen en la mochila"
              << std::endl;
    std::cout << "./ejecutable [-u] [peso_max] [archivo.cfg]"
              << std::endl;
    std::cout << "La opcion -u resuelve el problema de forma no acotada"
              << std::endl;
    std::cout << "Con la opcion -u los objetos no se pueden fraccionar"
              << std::endl;
    exit(1);
  }
  if (argc < 3 || argc > 4) {
    std::cout << "No se han introducido correctamente los argumentos" << std::endl;
    std::cout << "La estructura es la siguiente: ./ejecutable [-u] [peso_max] [archivo.cfg]" << std::endl;
    std::cout << "Para mas informacion ejecutar con parametro --help" << std::endl;
    exit(1);
  }
  if (argc == 3) {
    max_size = atoi(argv[1]);
    if (max_size <= 0) {
      std::cout << max_size << std::endl;
      std::cout << "El segundo parametro debe ser un numero que indicara el peso maximo de la mochila" << std::endl;
      exit(1);
    }
    file = argv[2];
    std::size_t found = file.find(kconfig_file);
    if (found == std::string::npos) {
      std::cout << "El segundo parametro debe ser un archivo .cfg que contenga "
                   "la lista de objetos a trabajar"
                << std::endl;
      exit(1);
    }
  } else {
    max_size = atoi(argv[2]);
    if (max_size <= 0) {
      std::cout << max_size << std::endl;
      std::cout
          << "El segundo parametro debe ser un numero que indicara el peso "
             "maximo de la mochila"
          << std::endl;
      exit(1);
    }
    file = argv[3];
    std::size_t found = file.find(kconfig_file);
    if (found == std::string::npos) {
      std::cout << "El segundo parametro debe ser un archivo .cfg que contenga "
                   "la lista de objetos a trabajar"
                << std::endl;
      exit(1);
    }
  }
}

int main(int argc, char* argv[]) {
  grep(argc, argv);
  std::string input;
  float size;
  // Asigna los valores correctamente de peso de mochila y nombre de lista de
  // items cuando se añade opcion -u
  if (argc == 3) {
    input = argv[2];
    size = atof(argv[1]);
  } else {
    input = argv[3];
    size = atof(argv[2]);
  }

  Mochila mochila(size);
  Objeto objetos(input);
  // Se meten los elementos en la mochila de la forma correspondiente que viene
  // dictado por opcion -u
  if (argc == 3) {
    mochila.insertar_objeto(objetos);
  } else {
    mochila.insertar_no_acotado(objetos);
  }

  mochila.imprimir();
  return 0;
} 