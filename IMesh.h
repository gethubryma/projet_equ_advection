#ifndef IMESH_H
#define IMESH_H

class IMesh {
public:
    virtual ~IMesh() {}

    virtual double getInitialTime() const = 0;
    virtual double getFinalTime() const = 0;
    virtual double getTimeStep() const = 0;
    virtual double getInitialPosition() const = 0;
    virtual double getFinalPosition() const = 0;
    virtual double getPositionStep() const = 0;
    virtual int x_size() const = 0;
    virtual double x_i(int i) const = 0;
};

#endif