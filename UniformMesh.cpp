#include "UniformMesh.h"

UniformMesh::UniformMesh(double t_ini, double t_final, double dt, double x_min, double x_max, double dx)
    : t_ini(t_ini), t_final(t_final), dt(dt), x_min(x_min), x_max(x_max), dx(dx) {}

UniformMesh::~UniformMesh() {}

double UniformMesh::getInitialTime() const {
    return t_ini;
}

double UniformMesh::getFinalTime() const {
    return t_final;
}

double UniformMesh::getTimeStep() const {
    return dt;
}

double UniformMesh::getInitialPosition() const {
    return x_min;
}

double UniformMesh::getFinalPosition() const {
    return x_max;
}

double UniformMesh::getPositionStep() const {
    return dx;
}

int UniformMesh::x_size() const {
    return static_cast<int>((x_max - x_min) / dx) + 1;
}

double UniformMesh::x_i(int i) const {
    return x_min + i * dx;
}
