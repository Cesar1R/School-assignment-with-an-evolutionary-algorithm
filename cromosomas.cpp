#include<vector>
#include<map>
#include<random>
#include<set> 
#include<map>

#include"cromosomas.h"

struct estudiante{
    int envidia, //Variable que almacenara la cantidad de estudiantes hacia los que siente envidia
        asignacion_actual; //Variable que almacena la escuela a la que esta asignado actualmente

    // std::vector<std::pair<int, double>> vec_preferencias; //Lista de preferencias
    std::map<int, double> map_preferencias; //Mapa que utiliza como clave el id de la escuela para devover el valor de apresiacion

    estudiante(int env_, int cur_as): envidia(env_), asignacion_actual(cur_as) {}

    void init (int env = 0, int cur_as = -1){ 
        envidia = env; asignacion_actual = cur_as; 
        gen_preferencias(this);
    }

};

struct poblador {
    int n; //Cantidad de estudiantes
    int m; //Cantidad de escuelas
    double fitness; 

    /*
    key: id de la escuela 
    val: cantidad de asientos disponibles en la escuela
    */
    std::map<int, int> escuela_asientos; 
    std::set<int> escuelas_disp; //Conjunto de escuelas disponibles

    std::vector<int> chromosomas; //Vector con una combinacion considerando los especificadores de las escuelas

    poblador(int n_, 
             int m_, 
             std::map<int, int> c_escuelas){
        n = n_; m = m_; 
        fitness = 0.0;
        chromosomas = std::vector<int> (n);

        for(const std::pair<int, int> & escuela_i: c_escuelas){
            escuela_asientos[escuela_i.first] = escuela_i.second;
            if(escuela_i.second){
                set.insert(escuela_i.first);
            }
        }
    }

    bool asignar (int escuela_asignada, int id){
        if(escuela_asientos[escuela_asignada] > 0){
            chromosomas[id] = escuela_asignada;
            escuela_asientos[escuela_asignada]--;
            if(escuela_asientos[escuela_asignada]==0){
                escuelas_disp.erase(escuela_asignada);
            }
            return true; // La asignacion se realizo con exito
        }
        else{ //No fue posible hacer la asignacion
            return false;
        }

    }
};

double gen_random_number(double max_val){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, max_val);

    return static_cast<double>(dis(gen));
}

void gen_preferencias(estudiante* e){
    double max_val = 100.0, 
        gen_val;

    //Parte que se encarga de limpiar los contenedores de las preferencias
    e->vec_preferencias.clear(); e->map_preferencias.clear(); 

    //Generaremos las preferencias desde 1 hasta m-1
    for(int i=1; i< e->m; i++){
        gen_val = gen_random_number(max_val); 
        // e->vec_preferencias.emplace_back(i, gen_val);
        e->map_preferencias[i] = gen_val; 

        //Actualizaremos el valor maximo que puede tomar el nuevo valor generado
        max_val = std::max(0.0, max_val - gen_val);
    }

    //Para asegurarnos que el vector sume el max_val, agregaremos el valor restante a la ultima escuela en ambos contenedores
    // e->vec_preferencias.emplace_back(e->m, max_val);
    e->map_preferencias[e->m] = max_val;
    
}



// int main(void){

//     return 0;
// }