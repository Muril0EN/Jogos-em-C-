#include <iostream>
#include <string> //biblioteca para uso de strings
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA"; //movendo para scopo global

bool letra_existe(char chute){
    //for (int i = 0; i < PALAVRA_SECRETA.size(); i++){
    //    if(chute == PALAVRA_SECRETA[i]){
    //        return true;    
    //    } 

     //modo otimizado de implementar iterador (mesmo funcionamento da função acima)
        for(char letra : PALAVRA_SECRETA){ // -> Avisar compilador, pois função foi implementada no C++11 = [...] _std=c++11 (padronizado no doc "Makefile")
            if(chute == letra){
                return true;
            }     
        } return false;
    } 


int main(){
    
    cout << PALAVRA_SECRETA << endl;

    bool nao_acertou = true;
    bool nao_ganhou = true;

    while(nao_acertou && nao_ganhou){
        char chute;
        cin >> chute;

        if (letra_existe(chute)){
            cout << "O seu chute está na palavra." << endl;
        } else {
            cout << "O seu chute não está na palavra." << endl;
        }    
    }
}

