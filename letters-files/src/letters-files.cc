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

bool CheckCorrectParameters(const int argc, char *argv[], const int kLimite) {
  if (argc != kLimite) {
    return false;
  }
  return true;
}
/**
 * @brief La función generará archivos almacenando todas las palabras que empiecen por esa letra 
 * @param Toma como parámetros el número de parámetros y estos mismos pasados por la terminal
 * @return No retorna nada por ser una función void
 */

void GenerateFiles(const int argc, char *argv[]) {
      const std::string kArchivo{argv[1]};
    std::ifstream input_file{kArchivo, std::ios_base::in};
    if (!input_file.is_open()) {
      std::cerr << "Hubo un error al abrir el archivo de entrada" << '\n';
      return;
    }
    std::string word;
    std::vector<std::ofstream> outputFiles;
    for (char letra = 'A'; letra <= 'Z'; letra++) {
      std::string output_file_name = std::string(1, letra) + ".txt";
      outputFiles.emplace_back(output_file_name);
    }
    while(input_file >> word) {
      char first_letter = std::tolower(word[0]);
      if (std::isalpha(first_letter)) {
        first_letter = std::toupper(first_letter);
        outputFiles[first_letter - 'A'] << word << '\n';
      }
    }
  for (auto& output_file : outputFiles) {
    output_file.close();
  }
  input_file.close();
}

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 2)) {
    std::cout << "Wrong input" << '\n';
  } else {
    GenerateFiles(argc, argv);
  }
  return 0;
}