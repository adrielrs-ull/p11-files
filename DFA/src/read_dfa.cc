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
#include <set>
#include <unordered_map>

struct Transition {
    char symbol;
    unsigned int destination;
};

struct State {
    bool isAccepting;
    std::vector<Transition> transitions;
};

void printDFA(const std::vector<State>& states, unsigned int startState, const std::set<unsigned int>& acceptingStates) {
    std::cout << "|Q| = " << states.size() << '\n';
    std::cout << "q0 = " << startState << '\n';

    std::cout << "F = {";
    for (auto state : acceptingStates) {
        std::cout << state << " ";
    }
    std::cout << "}\n";

    for (unsigned int i = 0; i < states.size(); ++i) {
        for (auto transition : states[i].transitions) {
            std::cout << "delta(" << i << ", " << transition.symbol << ") = " << transition.destination << '\n';
        }
    }
}

int main() {
    // Nombre del archivo que deseas abrir para lectura
    const std::string filename = "input.dfa";

    // Crear un objeto ifstream y abrir el archivo
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return 1;
    }

    // Leer el número total de estados del DFA
    unsigned int totalStates;
    inputFile >> totalStates;

    // Leer el estado de arranque del DFA
    unsigned int startState;
    inputFile >> startState;

    // Leer la información de cada estado
    std::vector<State> states(totalStates);
    std::set<unsigned int> acceptingStates;

    for (unsigned int i = 0; i < totalStates; ++i) {
        // Leer información del estado
        inputFile >> i >> states[i].isAccepting;

        // Leer número de transiciones del estado
        unsigned int numTransitions;
        inputFile >> numTransitions;

        // Leer información de cada transición
        for (unsigned int j = 0; j < numTransitions; ++j) {
            Transition transition;
            inputFile >> transition.symbol >> transition.destination;
            states[i].transitions.push_back(transition);
        }

        // Si el estado es de aceptación, agregarlo al conjunto de estados de aceptación
        if (states[i].isAccepting) {
            acceptingStates.insert(i);
        }
    }

    // Cerrar el archivo
    inputFile.close();

    // Imprimir información del DFA
    printDFA(states, startState, acceptingStates);

    return 0;
}