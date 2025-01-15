#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include "IMesh.h"
#include <thread>
#include "Timer.h"

class Problem {
private:
    Equation equation;
    IMesh* mesh;

public:
    Problem(const Equation& equation, IMesh* mesh);
    ~Problem();
    
    void solve();
    void solve_parallel();
};

#endif
