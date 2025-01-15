#include "IMesh.h"

class UniformMesh : public IMesh {
private:
    double t_ini;
    double t_final;
    double dt;
    double x_min;
    double x_max;
    double dx;

public:
    UniformMesh(double t_ini, double t_final, double dt, double x_min, double x_max, double dx);
    ~UniformMesh();

    double getInitialTime() const override;
    double getFinalTime() const override;
    double getTimeStep() const override;
    double getInitialPosition() const override;
    double getFinalPosition() const override;
    double getPositionStep() const override;
    int x_size() const override;
    double x_i(int i) const override;
};
