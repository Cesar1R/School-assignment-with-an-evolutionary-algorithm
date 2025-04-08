#ifndef FITNESS_H
#define FITNESS_H

#include"cromosomas.h"
#include<vector>


void fun_obj (poblador& individuo, 
                const std::vector<estudiante> &estudiantes, 
                int n);

void calcular_Fitness(std::vector<poblador> & pob, 
                      const std::vector<estudiante> &estudiantes);


#endif