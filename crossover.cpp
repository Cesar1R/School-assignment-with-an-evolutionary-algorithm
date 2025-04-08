#include"crossover.h"
#include<random>

poblador crossover(poblador* u, poblador* v){
    int n = u -> n; 

    poblador res(n, u->m); 

    int escuela_asignada; 

    for(int i = 0; i < n; i++){
        int u_cros = u->cromosomas[i], 
            v_cros = v->chromosomas[i]; 

        bool u_disponible = true; 
             v_disponible = true; 

        //Validacion de que haya asientos disponibles en la escuela
        if(!u -> escuela_asientos[i]){
            u_i_asignado = false; 
        }
        if(v -> escuela_asientos[i]){

            v_i_asignado = false; 
        }

        //Si ninguna escuela tiene asientos disponibles, se hace una asignacion aleatoria
        if(!u_disponible && !v_disponible){
            std::set<int>::iterator s_Iter;
            
            s_Iter = u -> escuelas_disp.begin();
            escuela_asignada = *s_Iter;
            u->escuelas_disp.erase(s_Iter);
        }

        //Si solo una tiene asientos disponibles, se asigna a esa
        else if (v_i_asignado || u_i_asignado){
            escuela_asignada = (v_i_asignado) ? u_cros:v_cros; 

        } else { //Si ambas escuelas tienen asientos dispobles 
            if(u_cros == v_cros){ //Si las escuelas son iguales, se asigna la escuela de los padres
                escuela_asignada = u->cromosomas[i];
            } else { //En caso contrario, se asigna la de mayor probabilidad, en funcion del fitnes
                double sum_fit = u -> fitness + v -> fitness,
                       prob_v = (v -> fitness) / sum_fit, 
                       prob_u = (u -> fitness) / sum_fit; 

                static std::random_device rd;
                static std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis(0.0, 1.0);
                
                escuela_asignada = (dis(gen) <= prob_u) ? u->cromosomas[i] : v->cromosomas[i];

            }
        }
        //Validacion de que la escuela se asigno con esito
        res.asignar(escuela_asignada, i); 
    }
}
