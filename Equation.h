#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include "Upwind.h" 


class Equation {
private:
    double advection;

public:
    Equation(double advection);
    ~Equation();
    //autre methode sans utiliser les template 
    void compute_for_schm(double t, IMesh* mesh, Variable& u_n, Variable& u_np1,double advection);
   
    void compute(double time, double position);
    void compute(Variable& u_n, Variable& u_np1, IMesh* mesh);
    void compute_initial_condition(Variable& u_n, IMesh* mesh);
    void compute_exact_solution(Variable& u_ref, IMesh* mesh, double cur_time);
    //ici utilisation des template
    template <typename T>
    void compute_for_scheme(double t, IMesh* mesh, Variable& u_n, Variable& u_np1,double advection);
    

};

#endif 
