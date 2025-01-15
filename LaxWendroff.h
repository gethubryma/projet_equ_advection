#ifndef LAXWENDROFF_H
#define LAXWENDROFF_H

#include "IMesh.h"
#include "Variable.h"

class LaxWendroff {
public:
    template<typename T>
    static void update(Variable& u_n, Variable& u_np1, T advection, IMesh* mesh);
};

#endif 
