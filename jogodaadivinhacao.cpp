#include<iostream> //biblioteca de entrada e saida de dados
using namespace std; // para não precisar usar essa sintaxe -> std::cout, como da primeira linha da função int main

int main () {

    //std::cout << "*************************************" << std::endl;
    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo de adivinhação *" << endl;
    cout << "*************************************" << endl;

    cout << "* Escolha seu nível de dificuldade * *" << endl;
    cout << "Fácil (f), Médio (m) ou Díficil (d)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'f'){
        numero_de_tentativas = 15;
    } else if (dificuldade = 'm'){
        numero_de_tentativas = 10;
    } else {
        numero_de_tentativas = 5;
    }

    const int NUMERO_SECRETO = 42; //boa prática é colocar nomes de contantes em CAPsLk
    //cout << "o número secreto é " << NUMERO_SECRETO << ". Não conte para ninguém!" << endl;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {
        //tentativas++; somento usando while
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
            break;
        } else if( maior ) {
            cout << "Seu chute maior que o número secreto." << endl;
        } else {
            cout << "Seu chute menor que o número secreto." << endl;
        }
    } 
    cout << "Fim de jogo" << endl;
    if(nao_acertou){
        cout << "Você perdeu, tente novamente!" << endl;
    } else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
        cout.precision(2); //setar precisão
        cout << fixed; //marcador para decimal
        cout << "Sua pontuação foi de " << pontos << " pontos."<< endl;
    }
    
}