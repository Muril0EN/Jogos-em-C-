#include <iostream>
#include <string> //biblioteca para uso de strings
#include <map>//
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chute.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

string palavra_secreta;
map<char, bool> chutou; //dicionário em C++ map<chave, valor> nome;
vector<char> chutes_errados;//vetor dinâmico em C++

int main() {

    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){

        imprime_erros();

        imprime_palavra();

        chuta();
    }
        
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Você perdeu! Tente novamente!!" << endl;
    } else {
        cout << "Parabéns! Vocẽ acertou a palavra secreta!!" << endl;

        cout << "Deseja adicionar nova palavra ao banco? (s/n): ";
        char resposta;
        cin >> resposta;
        if(resposta == 's'){
            adiciona_palavra();
        }
    }
    cin.get();
}

