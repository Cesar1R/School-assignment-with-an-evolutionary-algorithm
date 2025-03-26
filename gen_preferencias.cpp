#include "cromosomas.h"
#include "gen_preferencias.h"
#include <random>
#include <vector>
#include <map>

float gen_random_number(float max_val){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, max_val);

    return static_cast<float>(dis(gen));
}

void gen_preferencias(estudiante* e){
    float max_val = 100.0, 
        gen_val;

    //Parte que se encarga de limpiar los contenedores de las preferencias
    e->vec_preferencias.clear(); e->map_preferencias.clear(); 

    //Generaremos las preferencias desde 1 hasta m-1
    for(int i=1; i< e->m; i++){
        gen_val = gen_random_number(max_val); 
        e->vec_preferencias.emplace_back({i, gen_val});
        e->map_preferencias[i] = gen_val; 

        //Actualizaremos el valor maximo que puede tomar el nuevo valor generado
        max_val = std::max(0.0, max_val - gen_val);
    }

    //Para asegurarnos que el vector sume el max_val, agregaremos el valor restante a la ultima escuela en ambos contenedores
    e->vec_preferencias.emplace_back({e->m, max_val});
    e->map_preferencias[e->m] = max_val;
    
}

int main(void){

    return 0;
}
