#include <iostream>
#include <string> //biblioteca para uso de strings
#include <map>//
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA"; //movendo para scopo global
map<char, bool> chutou; //dicionário em C++ map<chave, valor> nome;
vector<char> chutes_errados;//vetor dinâmico em C++

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
        } return false; //else não foi usado pq ele não permitiria a continuação da iteração
    } 

bool nao_acertou() {
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    } 
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}


int main() {

    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo da forca *" << endl;
    cout << "*************************************" << endl;
    cout << endl;

    while(nao_acertou() && nao_enforcou()){

        cout << "Chutes errados: ";
        for(char letra: chutes_errados){
            cout << letra << " ";
        }
        cout << endl;

        for(char letra : PALAVRA_SECRETA){
            if(chutou[letra]){
                cout << letra << " ";
            } else {
                cout << "_ ";
            }

        }
        cout << endl;

        cout << "Seu chute: ";
        char chute;
        cin >> chute;
        chutou[chute] = true;

        if (letra_existe(chute)){
            cout << "O seu chute está na palavra." << endl;
            cout <<  endl;
        } else {
            cout << "O seu chute não está na palavra." << endl;
            chutes_errados.push_back(chute); //fazer um append no vetor dinâmico
            cout <<  endl;
        } 
        cout << endl;
    }
    
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
    if(nao_acertou()){
        cout << "Você perdeu! Tente novamente!!" << endl;
    } else {
        cout << "Parabéns! Vocẽ acertou a palavra secreta!!" << endl;
    }
}

