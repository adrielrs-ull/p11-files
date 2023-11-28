/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Nov 1 2023
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief El programa cambia unas letras por otras
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

bool CheckCorrectParameters(int argc, char *argv[], const int kLimite) {
  if (argc != kLimite) {
    return false;
  }
  return true;
}

/**
 * @brief Esta función canbia las letras de la cadena pasada por otras
 * @param Toma como parámetros una cadena
 * @return Retorna la cadena transformada
 */

std::string Rotate(std::string line) {
  std::string rotated;
  for (char& caracter : line) {
    switch (caracter) {
      case 'a':
        rotated += 'e';
        break;
      case 'e':
        rotated += 'i';
        break;
      case 'i':
        rotated += 'o';
        break;
      case 'o':
        rotated += 'u';
        break;
      case 'u':
        rotated += 'a';
        break;
      default:
        rotated += caracter;
    }
  }
  return rotated;
}

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 3)) {
    std::cerr << "Wrong Input" << '\n';
  } else {
    const std::string kArchivo1{argv[1]};
    const std::string kArchivo2{argv[2]};
    std::ifstream input_file{kArchivo1, std::ios_base::in}; 
    std::ofstream output_file{kArchivo2, std::ios::app};
    std::string line;
    if (!input_file.is_open() || !output_file.is_open()) {
      std::cerr << "No se han podido abrir los archivos" << '\n';
      return 1;
    }
    while (std::getline(input_file, line)) {
      std::string cadena = Rotate(line);
      output_file << cadena << '\n';
    }
    input_file.close();
    output_file.close();
  }
  return 0;
}