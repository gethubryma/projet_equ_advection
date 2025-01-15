#include "Problem.h"
#include <iostream>
#include <thread>
#include "Timer.h"
#include "Upwind.h"
#include "LaxWendroff.h"

Problem::Problem(const Equation& equation, IMesh* mesh) : equation(equation), mesh(mesh) {}

Problem::~Problem() {
    delete mesh;
}

void Problem::solve() {
    Variable u_n(mesh, "u_n");
    Variable u_np1(mesh, "u_np1");
    Variable u_ref(mesh, "u_ref");
    Variable u_n_2nd_order(mesh, "u_n_2nd_order");
    Variable u_np1_2nd_order(mesh, "u_np1_2nd_order");

    equation.compute_initial_condition(u_n, mesh);
    u_n.print(0,0);

    equation.compute_initial_condition(u_n_2nd_order, mesh);
    u_n_2nd_order.print(0, 0);

    Timer totalTimer;  
    totalTimer.start(); 

    int iteration = 0;

    for (double time = mesh->getInitialTime(); time <= mesh->getFinalTime(); time += mesh->getTimeStep()) {
        std::cout << "--- compute equation at time : " << time << " ---" << std::endl;

    
        equation.compute_exact_solution(u_ref, mesh, time);

        Timer iterationTimer; 
        iterationTimer.start();  

        equation.compute(u_n, u_np1, mesh);

        //pour compute_for_scheme de questio bonus : u_np1_2nd_order
        double a = 1.0;
        equation.compute_for_schm(time,mesh,u_n_2nd_order,u_np1_2nd_order,a);

        //equation.compute_for_scheme<LaxWendroff>(time, mesh, u_n_2nd_order, u_np1_2nd_order, advection_speed);
        
        u_np1_2nd_order.print(iteration, time);
        u_np1.print(iteration, time);
        u_ref.print(iteration, time);
        
        u_n = u_np1;

        iterationTimer.stop();  
        std::cout << "Iteration time: ";
        iterationTimer.printMilliseconds();  

        ++iteration;
    }

    totalTimer.stop(); 
    std::cout << "Total time: ";
    totalTimer.printMilliseconds(); 
}

void Problem::solve_parallel() {
    Variable u_n(mesh, "u_n");
    Variable u_np1(mesh, "u_np1");
    Variable u_ref(mesh, "u_ref");
    Variable u_n_2nd_order(mesh, "u_n_2nd_order");
    Variable u_np1_2nd_order(mesh, "u_np1_2nd_order");

    equation.compute_initial_condition(u_n, mesh);
    u_n.print(0,0);

    Timer totalTimer; 
    totalTimer.start();

    int iteration = 0;

    
    for (double time = mesh->getInitialTime(); time <= mesh->getFinalTime(); time += mesh->getTimeStep()) {
        std::cout << "--- compute equation at time : " << time << " ---" << std::endl;

        equation.compute_exact_solution(u_ref, mesh, time);

        Timer iterationTimer; 
        iterationTimer.start();

        
        std::thread thread_u_n([&]() {
            equation.compute(u_n, u_np1, mesh);
        });

        std::thread thread_u_ref([&]() {
            equation.compute_exact_solution(u_ref, mesh, time);
        });

        std::thread thread_u_np1_2nd_order([&]() {
            //equation.compute_for_scheme<LaxWendroff>(time, mesh, u_n_2nd_order, u_np1_2nd_order, advection_speed);
            double a = 1.0;
            equation.compute_for_schm(time,mesh,u_n_2nd_order,u_np1_2nd_order,a);
        });

        thread_u_n.join();
        thread_u_ref.join();
        thread_u_np1_2nd_order.join();

        u_np1_2nd_order.print(iteration, time); 
        u_np1.print(iteration, time);
        u_ref.print(iteration, time);
        

        u_n = u_np1;

        iterationTimer.stop();
        std::cout << "Iteration time: ";
        iterationTimer.printMilliseconds();

        ++iteration;
    }

    totalTimer.stop();
    std::cout << "Total time: ";
    totalTimer.printMilliseconds();
}
