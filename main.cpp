#include"cromosomas.h"
#include"crossover.h"
#include"aux_init.h"

using namespace std;

int main(){

    try {
        //Caracteristicas de la poblacion
        int pob_size = 100;
        int generaciones = 100;
        int probabilidad_cruce = 0.9;

        
        int n = 160, //Estudiantes 
            m = 40; //Escuelas
            
        std::vector< estudiante > estudiantes(n);
        

        //Variables de contadores 
        int i, j;

        //Inicializacion de los estudiantes 

        for(i=0; i<n; i++){
            estudiante e; 
            e.init();
            estudiantes.push_back(e);
        }
        
    

        //Inicializacion/Generacion de la capacidad de las escuelas
        map<int, int> schools_seats; 
        m = init_schools(n, m, schools_seats);

        //Inicializar la poblacion 
        std::vector< poblador > poblacion (pob_size);
        init_pob(n, m, poblacion, schools_seats);

        
        calcular_Fitness(poblacion_inicial); 

        //Ciclo de evolucion

        for(int gen = 0; i < generaciones; gen++){
            vector< poblador > nueva_poblacion = poblacion_inicial; 

            size_t k; 

            //Seleccion 

            vector< poblador > mating(poblacion_inicial.size()); 
            for(k = 0; k < poblacion_inicial.size(); k++){
                //Continuar aqui
            }
        }

    }


}