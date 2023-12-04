/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Nov 1 2023
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief El programa toma como un fichero y devuelve el resultado de las operaciones en él en otro fichero de salida
  * @bug There are no known bugs
  * 
  */

#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Esta función leerá palabra por palabra de un fichero y calculará la operación y el resultado lo escribe en un fichero distinto
 * @param Toma como parámetros los pasados por terminal
 * @return Al ser una función void no devuelve nada
 */

void CalculoFichero(const int argc, char *argv[]) {
  const std::string kArchivo{argv[1]};  
  std::fstream input_file{kArchivo, std::ios_base::in};
  std::fstream output_file{"archivo_salida.txt", std::ios::app};
  if (!input_file.is_open() || !output_file.is_open()) {
    std::cout << "Ha habido un problema al abrir los archivos" << '\n';
    return;
  }
  char operacion;
  int numero1, numero2;
  while (input_file >> numero1 >> operacion >> numero2) {
    if (operacion == ':' && numero2 == 0) {
      output_file << "NaN" << " ";
    } else {
      switch (operacion) {
        case '+':
          output_file << numero1 + numero2 << " ";
          break;
        case '-':
          output_file << numero1 - numero2 << " ";
          break;
        case 'x':
          output_file << numero1 * numero2 << " ";
          break;
        case ':':
          output_file << numero1 / numero2 << " ";
          break;
        default:
          output_file << "NaN" << " ";
          break;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  CalculoFichero(argc,argv);  
  return 0;
}
