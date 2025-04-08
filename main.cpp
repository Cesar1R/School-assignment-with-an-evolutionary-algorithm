#include"cromosomas.h"
#include"crossover.h"

using namespace std;

int main(){

    try {
        //Caracteristicas de la poblacion
        int pob_size = 100;
        int generaciones = 100;
        int probabilidad_cruce = 0.9;

        
        int n = 100, //Estudiantes 
            m = 40; //Escuelas
            
        std::vector<poblador> poblacion (pob_size);
        std::vector<estudiante> estudiante(n);
        

        //Variables de contadores 
        int i, j;

        //Inicializacion de los estudiantes 

        for(i=0; i<n; i++){
            estudiante e; 
        }

        //Iniciailiazacion de la funcion objetivo
        Funcion funcion_objetivo();

        //Inicializacion de la poblacion objetivo
        for(i=0; i<pob_size; i++){
            estudiante e; 
            for(j=0; j<n; j++){

            }
        }
    }


}