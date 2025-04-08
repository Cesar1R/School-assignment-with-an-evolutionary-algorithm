#include"aux_init.h"
#include"cromosomas.h"
#include<random>

int init_schools(int n, int m, std::map<int, int> &schools_seats){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<double> dist(4.0, 0.5);

    int escuelas_con_asientos = 0; 

    int contador = n;  
    for(int i=1; i<m; i++){
        int num = std::round(dist(gen));
        num = std::max(2, std::min(6, num));

        escuelas_con_asientos++;
        if(contador - num >= 0){
            schools_seats[i] = num; 
            contador -= num;
        } else{
            schools_seats[i] = contador;
            contador = 0; 
            break;
        }

    }

    schools_seats[m] = (contador >= 0)? contador:0;

    if(!contador){escuelas_con_asientos++;}

    return escuelas_con_asientos;
    
}

void init_pob (int n, int m, std::vector<poblador>& pob, const std::map<int, int>& schools_seats){
    
    for(const poblador& p: pob){
        p = poblador(n, m, schools_seats);

        for(int i = 1; i < n; i++){
            
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, m);
            
            int rd_school;
            bool flag = true; 
            do{
                rd_school = dis(gen); 
            }while(!p.asignar(rd_school, i))
            
        }
    }
}