#include <iostream>
#include <stdexcept>


void fun_obj (poblador& individuo, 
    const std::vector<estudiante> &estudiantes, 
    int n){

    double fitness = 0.0; 
    int pref_tmp; 
    for(int i=0; i<n; i++){
        pref_tmp = individuo.chromosomas[i];
        fitness += estudiantes[i].map_preferencias[pref_tmp]; 
    }

    individuo.fitness = fitness; 
}

void calcular_Fitness(std::vector<poblador> & pob, 
          const std::vector<estudiante> &estudiantes){
    try{
        for(poblador & p: pob){
            fun_obj(pob, estudiantes);
        }
    } catch (...){
        cerr << "Error al calcular el fitness" << endl; 
    }
}
