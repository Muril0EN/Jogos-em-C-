#include<iostream> //biblioteca de entrada e saida de dados
using namespace std; // para não precisar usar essa sintaxe -> std::cout, como da primeira linha da função int main

int main () {

    //std::cout << "*************************************" << std::endl;
    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo de adivinhação *" << endl;
    cout << "*************************************" << endl;

    const int NUMERO_SECRETO = 42; //boa prática é colocar nomes de contantes em CAPsLk
    //cout << "o número secreto é " << NUMERO_SECRETO << ". Não conte para ninguém!" << endl;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    while(nao_acertou){
        tentativas++;
        int chute;
        cout << "Tentativa: " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0; //função abs retorno valor absoluto. Coverter uma das variáveis para real para garantir retorno em REAL
        pontos = pontos - pontos_perdidos;

        cout << "o valor do seu chute é " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO; //só em c++
        bool maior = chute > NUMERO_SECRETO;

        if( acertou ) {
            cout << "Parabéns você acertou o número secreto." << endl;
            nao_acertou = false;
        } else if( maior ) {
            cout << "Seu chute maior que o número secreto." << endl;
        } else {
            cout << "Seu chute menor que o número secreto." << endl;
        }
    } 
    cout << "Fim de jogo" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
    cout << "Sua pontuação foi de " << pontos << " pontos."<< endl;
}