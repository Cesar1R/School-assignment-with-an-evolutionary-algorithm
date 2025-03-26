#include<vector>
#include<map>

#include"cromosomas.h"
#include"gen_preferencias.h"

struct estudiante{
    int m, //Cantidad de escuelas
        envidia, //Variable que almacenara la cantidad de estudiantes hacia los que siente envidia
        asignacion_actual; //Variable que almacena la escuela a la que esta asignado actualmente

    std::vector<std::pair<int, float>> vec_preferencias; //Lista de preferencias
    std::map<int, float> map_preferencias; //Mapa que utiliza como clave el id de la escuela para devover el valor de apresiacion

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
    std::vector<std::pair<int, float>> chromosomas; 
};


// int main(void){

//     return 0;
// }