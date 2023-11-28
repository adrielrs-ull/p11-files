/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  * @author Adriel Reyes Suárez alu0101640136@ull.edu.es
  * @date Nov 1 2023
  * @software license https://www.gnu.org/licenses/gpl-3.0.html
  * @brief El programa imprime por pantalla la palabra con el mayor número de vocalesd y consonantes
  * @bug There are no known bugs
  * 
  */

#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief Esta función confirma que el número de parámetros pasados sean los correctos, si no salta un error
 * @param Los parámetros pasados son el tamaños de la línea de comando y el vector de estos
 * @return Devuelve erros si el número de parámetros no es correcto
 */

bool CheckCorrectParameters(int argc, char *argv[], const int kLimite) {
  if (argc != kLimite) {
    std::cerr << "Wrong Input" << '\n';
    return false;
  }
  return true;
}

/**
 * @brief Esta función se encarga de contar las vocales de las palabras de los archivos
 * @param Toma como parámetros la palabra del archivo que se irá leyendo
 * @return Retorna el número de vocales
 */

int CountVowels(const std::string& word) {
  int count{0};
  for (char caracter : word) {
    char lower_case = std::tolower(caracter);
    switch (caracter) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        count++;
        break;
    }
  }
  return count;
}

/**
 * @brief Esta función se encarga de contar las consontantes de las palabras de los archivos
 * @param Toma como parámetros la palabra del archivo que se irá leyendo
 * @return Retorna el número de consonantes
 */

int CountConsonants(const std::string& word) {
  int count{0};
  for (char caracter : word) {
    char lower_case = std::tolower(caracter);
    if (std::isalpha(caracter) && lower_case != 'a' && lower_case != 'e' && lower_case != 'i' && lower_case != 'o' && lower_case != 'u') {
      count++;
    }
  }
  return count;
}



int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv, 2)) {
    std::cout << '\n';
  } else {
    const std::string kArchivo{argv[1]};
    std::ifstream input_file{kArchivo, std::ios_base::in};
    if (!input_file.is_open()) {
      std::cerr << "El archivo no se ha podido abrir" << '\n';
      return 1;
    } 
  
   std::string word, maxVowelsWord, maxConsonantsWord;
   int maxVowels{0}, maxConsonants{0};
   while (input_file >> word) {
      int vowels = CountVowels(word);
      int consonants = CountConsonants(word);
      if (vowels > maxVowels) {
        maxVowels = vowels;
        maxVowelsWord = word;
      } else if (consonants > maxConsonants) {
        maxConsonants = consonants;
       maxConsonantsWord = word;
     }
    }
    input_file.close(); 
    std::cout << "La palabra con mayor número de vocales es: " << maxVowelsWord << " con " << maxVowels << " vocales." << '\n';
    std::cout << "La palabra con mayor número de consonantes es: " << maxConsonantsWord << " con " << maxConsonants << " consonantes." << '\n';
  }
  return 0;
}