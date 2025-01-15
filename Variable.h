#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>
#include "IMesh.h"
#include <string>

class Variable {
private:
    std::vector<double> values;
    IMesh* mesh;
    std::string name;

public:
    Variable(IMesh* mesh, const std::string& name);
    ~Variable();

    double& operator[](int i);
    void print(int iteration, double time) const;
};

#endif 
