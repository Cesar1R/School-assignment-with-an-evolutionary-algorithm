#ifndef AUX_INIT_H
#define AUX_INIT_H
#include"cromosomas.h"
#include<map>
#include<vector>
int init_schools(int n, int m, 
                 std::map<int, int>& schools_seats);

void init_pob (int n, int m, 
               std::vector<poblador>& pob, 
               const std::map<int, int> &schools_seats);

#endif