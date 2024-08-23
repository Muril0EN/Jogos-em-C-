#include <iostream>
#include <string> //biblioteca para uso de strings
#include <map>//
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA"; //movendo para scopo global
map<char, bool> chutou; //dicionário em C++ map<chave, valor> nome;
vector<char> chutes_errados;//vetor dinâmico em C++

bool letra_existe(char chute){
    //for (int i = 0; i < palavra_secreta.size(); i++){
    //    if(chute == palavra_secreta[i]){
    //        return true;    
    //    } 

     //modo otimizado de implementar iterador (mesmo funcionamento da função acima)
        for(char letra : palavra_secreta){ // -> Avisar compilador, pois função foi implementada no C++11 = [...] _std=c++11 (padronizado no doc "Makefile")
            if(chute == letra){
                return true;
            }     
        } return false; //else não foi usado pq ele não permitiria a continuação da iteração
    } 

bool nao_acertou() {
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    } 
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){

    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo da forca *" << endl;
    cout << "*************************************" << endl;
    cout << endl;

}

void imprime_erros(){

    cout << "Chutes errados: ";
    for(char letra: chutes_errados){
        cout << letra << " ";
    }
    cout << endl;

}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        } else {
            cout << "_ ";
        }

    }
        cout << endl;
}

void chuta(){
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

vector<string> le_arquivo(){
    //input + file + stream
    ifstream arquivo;//dados para usar ler valores de arquivo
    arquivo.open("palavras.txt");
    
    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for(int i = 0; i < quantidade_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();//boa prática
        return palavras_do_arquivo;
    } else{ // boa prática 
        cout << "Não foi possível acessar o banco de palavras." <<endl;
        exit(0); //parar execução
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo; //output file ...
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;

        for(string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    } else{
        cout << "Não foi possível acessar o banco de palavras." <<endl;
        exit(0); //parar execução
    }
}

void adiciona_palavra(){
    cout << "Digite a nova palavra: " << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
    
    }

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
}

