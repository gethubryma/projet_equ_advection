#include "LaxWendroff.h"
#include "Equation.h"
#include <cmath>

template<typename T>
void LaxWendroff::update(Variable& u_n, Variable& u_np1, T advection, IMesh* mesh) {
    double CFL = 0.5;

    for (int i = 1; i < mesh->x_size() - 1; ++i) {
        u_np1[i] = u_n[i] - advection * CFL * (u_n[i + 1] - u_n[i - 1]) +
                    std::pow(advection * CFL, 2) * (u_n[i + 1] - 2 * u_n[i] + u_n[i - 1]);
    }

   
    for (int i = 1; i < mesh->x_size() - 1; ++i) {
        u_n[i] = u_np1[i];
    }
}

