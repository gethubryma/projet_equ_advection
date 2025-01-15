#include "Upwind.h"
#include "IMesh.h"
#include "Variable.h"

template<typename T>
void Upwind::update(Variable& u_n, Variable& u_np1, T advection, IMesh* mesh) {
    double CFL = 0.5;

    u_np1[0] = u_n[0] - CFL * (u_n[0] - u_n[mesh->x_size() - 1]);

    for (int i = 1; i < mesh->x_size(); ++i) {
        u_np1[i] = u_n[i] - CFL * (u_n[i] - u_n[i - 1]);
    }

    for (int i = 1; i < mesh->x_size(); ++i) {
        u_n[i] = u_np1[i];
    }
}


