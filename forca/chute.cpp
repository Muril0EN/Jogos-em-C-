#include <iostream>
#include <vector>
#include <map>

#include "letra_existe.hpp"
#include "chute.hpp"

extern std::vector<char> chutes_errados;
extern std::map<char, bool> chutou;

void chuta(){
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;
    
    chutou[chute] = true;

    if (letra_existe(chute)){
        std::cout << "O seu chute está na palavra." << std::endl;
        std::cout <<  std::endl;
    } else {
        std::cout << "O seu chute não está na palavra." << std::endl;
        chutes_errados.push_back(chute); //fazer um append no vetor dinâmico
        std::cout <<  std::endl;
    } 
    std::cout << std::endl;
}