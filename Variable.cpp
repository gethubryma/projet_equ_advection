#include "Variable.h"
#include <fstream>
#include <iostream>

Variable::Variable(IMesh* mesh, const std::string& name) : mesh(mesh), name(name) {
    int size = mesh->x_size();
    values.resize(size);
}

Variable::~Variable() {}

double& Variable::operator[](int i) {
    return values[i];
}

void Variable::print(int iteration, double time) const {
    std::string filename = "Variable_" + name + "_" + std::to_string(iteration) + ".data";
    std::ofstream file(filename);

    std::cout << "Variable " << name << " ecrit dans " << filename << std::endl;

    if (file.is_open()) {
        for (int i = 0; i < mesh->x_size(); ++i) {
            file << i << " " << values[i] << "\n";
            std::cout << "iteration " << i << " valeur : " << values[i] << " at time " << time << "\n";
        }
        file.close();
        
    } else {
        std::cerr << "Erreur" << name << std::endl;
    }
}

