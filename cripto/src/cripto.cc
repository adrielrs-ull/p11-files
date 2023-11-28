/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Nov 1 2023
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief El programa encripta un mensaje
  * @bug There are no known bugs
  * 
  */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief Esta función confirma que el número de parámetros pasados sean los correctos, si no salta un error
 * @param Los parámetros pasados son el tamaños de la línea de comando y el vector de estos
 * @return Devuelve erros si el número de parámetros no es correcto
 */

bool CheckCorrectParameters(const int argc, char *argv[], const int kLimite) {
  if (argc != kLimite) {
    return false;
  }
  return true;
}

/**
 * @brief Esta funcion muestra por pantalla el mensaje de ayuda cuando se ejecuta esta opción
 * @param No toma parámetros
 * @return No devuelve nada
 */

void printHelp() {
  std::cout << "./cripto -- Cifrado de ficheros\n";
  std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación\n\n";
  std::cout << "fichero_entrada: Fichero a codificar\n";
  std::cout << "fichero_salida:  Fichero codificado\n";
  std::cout << "método:          Indica el método de encriptado\n";
  std::cout << "                   1: Cifrado xor\n";
  std::cout << "                   2: Cifrado de César\n";
  std::cout << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2\n";
  std::cout << "operación:       Operación a realizar en el fichero\n";
  std::cout << "                   +: encriptar el fichero\n";
  std::cout << "                   -: desencriptar el fichero\n";
}

/**
 * @brief 
 * @param
 * @return 
 */

void Cripto(char *argv[]) {
  std::ifstream input_file{argv[1], std::ios_base::in};
  std::ofstream output_file{"archivo_salida.txt", std::ios::app};
  if (!input_file.is_open() || !output_file.is_open()) {
    std::cout << "No se han podido abrir los archivos" << '\n';
    return;
  }
  std::string line;
  while (input_file >> line) {
    for (char& caracter : line) {
      switch (caracter) {
        case 'x':
          caracter = 'a';
          break;
        case 'X':
          caracter = 'A';
          break;
        case 'y':
          caracter = 'b';
          break;
        case 'Y':
          caracter = 'B';
          break;
        case 'z':
          caracter = 'c';
          break;
        case 'Z':
          caracter = 'C';
          break;
        default:
          caracter += 3;
      }
    }
    output_file << line << '\n';
  }
  input_file.close();
  output_file.close();  
}

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 2)) {
    std::cout << "./cripto -- Cifrado de ficheros" << '\n';
    std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << '\n';
    std::cout << "./cripto -- Cifrado de ficherosPruebe ./cripto --help para más información" << '\n';
  } else if (argc == 2 && std::string(argv[1]) == "--help") {
    printHelp();
  } else {
    Cripto(argv);
  }
  return 0;  
}