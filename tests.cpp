#include <gtest/gtest.h>
#include "UniformMesh.h"
#include "Variable.h"
#include "Equation.h"
#include "Problem.h"

// Test de la classe UniformMesh
TEST(UnitaryTest, MeshTest) {
    UniformMesh mesh(0.0, 1.0, 0.1, 0.0, 1.0, 0.1);
    EXPECT_EQ(mesh.getInitialTime(), 0.0);
    EXPECT_EQ(mesh.getFinalTime(), 1.0);
    EXPECT_EQ(mesh.getTimeStep(), 0.1);
    EXPECT_EQ(mesh.getInitialPosition(), 0.0);
    EXPECT_EQ(mesh.getFinalPosition(), 1.0);
    EXPECT_EQ(mesh.getPositionStep(), 0.1);
    EXPECT_EQ(mesh.x_size(), 11);
    EXPECT_EQ(mesh.x_i(5), 0.5);
}

// Test de la classe Variable
TEST(UnitaryTest, VariableTest) {
    UniformMesh mesh(0.0, 1.0, 0.1, 0.0, 1.0, 0.1);
    Variable variable(&mesh, "test_variable");
    variable[0] = 42.0;
    EXPECT_EQ(variable[0], 42.0);
}

// Test de la classe Equation
TEST(UnitaryTest, EquationTest) {
    Equation equation(1.0);
    UniformMesh mesh(0.0, 1.0, 0.1, 0.0, 1.0, 0.1);
    Variable u_n(&mesh, "u_n");
    Variable u_np1(&mesh, "u_np1");
    equation.compute(u_n, u_np1, &mesh);
    
}

// print ne plante pas
TEST(UnitaryTest, VariablePrintTest) {
    UniformMesh mesh(0.0, 1.0, 0.1, 0.0, 1.0, 0.1);
    Variable variable(&mesh, "test_variable");
    variable[0] = 42.0;
    EXPECT_NO_THROW(variable.print(0, 0.0));
}

TEST(UnitaryTest, ProblemSimpleTest) {
    
    Equation equation(1.0);
    
    UniformMesh* mesh = new UniformMesh(0.0, 1.0, 0.1, 0.0, 10.0, 1.0);

    Problem problem(equation, mesh);

    ASSERT_NO_THROW(problem.solve()); 
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}