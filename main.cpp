#include "Problem.h"
#include "UniformMesh.h"
#include "Equation.h"
#include <chrono>

int main() {
    //j'ai utilisé ./main.exe pour les resultat et ./unit_tests (tests passed)
    Equation equation(1.0);
    
    auto start = std::chrono::high_resolution_clock::now();

    IMesh* mesh = new UniformMesh(0, 2, 0.1, 0, 10, 0.1);
    Problem problem(equation, mesh);
    problem.solve();
    //problem.solve_parallel();

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Temps total d'exécution : " << dur.count() << " millisecondes" << std::endl;


    return 0;
}
