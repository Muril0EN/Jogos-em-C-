#include <string>

#include "letra_existe.hpp"

extern std::string palavra_secreta; 

bool letra_existe(char chute){
    for(char letra : palavra_secreta){ // -> Avisar compilador, pois função foi implementada no C++11 = [...] _std=c++11 (padronizado no doc "Makefile")
            if(chute == letra){
                return true;
            }     
        } return false; //else não foi usado pq ele não permitiria a continuação da iteração
    } 