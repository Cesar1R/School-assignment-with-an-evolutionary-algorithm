#include<vector>
#include<map>
#include<random>

#include"cromosomas.h"

struct estudiante{
    int m, //Cantidad de escuelas
        envidia, //Variable que almacenara la cantidad de estudiantes hacia los que siente envidia
        asignacion_actual; //Variable que almacena la escuela a la que esta asignado actualmente

    std::vector<std::pair<int, double>> vec_preferencias; //Lista de preferencias
    std::map<int, double> map_preferencias; //Mapa que utiliza como clave el id de la escuela para devover el valor de apresiacion

    estudiante(int m_, int env_, int cur_as): m(m_), envidia(env_), asignacion_actual(cur_as) {}

    void init (int m_){
        m = m_; 
        envidia = 0; 
        asignacion_actual = -1; 
        gen_preferencias(this);
    }

};

struct poblador {
    int n; //Cantidad de estudiantes
    int m; //Cantidad de escuelas
    std::vector<std::pair<int, double>> chromosomas; 
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
        e->vec_preferencias.emplace_back(i, gen_val);
        e->map_preferencias[i] = gen_val; 

        //Actualizaremos el valor maximo que puede tomar el nuevo valor generado
        max_val = std::max(0.0, max_val - gen_val);
    }

    //Para asegurarnos que el vector sume el max_val, agregaremos el valor restante a la ultima escuela en ambos contenedores
    e->vec_preferencias.emplace_back(e->m, max_val);
    e->map_preferencias[e->m] = max_val;
    
}



// int main(void){

//     return 0;
// }