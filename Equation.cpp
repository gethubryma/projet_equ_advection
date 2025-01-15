#include "Equation.h"
#include "LaxWendroff.h"
#include "Upwind.h"
#include <cmath>

void Equation::compute(double time, double position) {
    
}
Equation::Equation(double advection) : advection(advection) {}

template <typename T>
void Equation::compute_for_scheme(double t, IMesh* mesh, Variable& u_n, Variable& u_np1, double advection) {
    T::update(u_n, u_np1, advection, mesh);
}

Equation::~Equation() {}
void Equation::compute(Variable& u_n, Variable& u_np1, IMesh* mesh) {
    double dx = mesh->getPositionStep();
    double dt = mesh->getTimeStep();
    double CFL = 0.5;
    u_np1[0] = u_n[0] - CFL * (u_n[0] - u_n[mesh->x_size() - 1]);

    for (int i = 1; i < mesh->x_size(); ++i) {
        u_np1[i] = u_n[i] - CFL * (u_n[i] - u_n[i - 1]);
    }

    for (int i = 1; i < mesh->x_size(); ++i) {
        u_n[i] = u_np1[i];
    }
}

void Equation::compute_initial_condition(Variable& u_n, IMesh* mesh) {
    double pos_min = mesh->getInitialPosition();
    double pos_max = mesh->getFinalPosition();
    double sigma = 10.0 * mesh->getPositionStep();
    double mu = (pos_max + pos_min) / 2.0;
    double dx = mesh->getPositionStep();
    double pi = 4.0 * std::atan(1.0);

    for (int i = 0; i < mesh->x_size(); ++i) {
        double x = pos_min + i * dx;
        u_n[i] = (1.0 / (sigma * std::sqrt(2.0 * pi))) * std::exp(-std::pow((x - mu), 2) / (2.0 * std::pow(sigma, 2)));
    }
}

void Equation::compute_exact_solution(Variable& u_ref, IMesh* mesh, double cur_time) {
    double pos_min = mesh->getInitialPosition();
    double pos_max = mesh->getFinalPosition();
    double sigma = 10.0 * mesh->getPositionStep();
    double mu = (pos_max + pos_min) / 2.0;
    double dx = mesh->getPositionStep();
    double pi = 4.0 * std::atan(1.0);

    for (int i = 0; i < mesh->x_size(); ++i) {
        double x = pos_min + i * dx;
        double u_exact = (1.0 / (sigma * std::sqrt(2.0 * pi))) * std::exp(-std::pow((x - advection * cur_time - mu), 2) / (2.0 * std::pow(sigma, 2)));
        u_ref[i] = u_exact;
    }
}


void Equation::compute_for_schm(double t, IMesh * mesh, Variable & u_n, Variable & u_np1, double advection){
        double CFL = 0.5;

    for (int i = 1; i < mesh->x_size() - 1; ++i) {
        u_np1[i] = u_n[i] - advection * CFL * (u_n[i + 1] - u_n[i - 1]) +
                    std::pow(advection * CFL, 2) * (u_n[i + 1] - 2 * u_n[i] + u_n[i - 1]);
    }
    
    for (int i = 1; i < mesh->x_size() - 1; ++i) {
        u_n[i] = u_np1[i];
    }
}
