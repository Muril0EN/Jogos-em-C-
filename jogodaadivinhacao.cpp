#include<iostream> //biblioteca de entrada e saida de dados
using namespace std; // para não precisar usar essa sintaxe -> std::cout, como da primeira linha da função int main

int main () {

    //std::cout << "*************************************" << std::endl;
    cout << "*************************************" << endl;
    cout << "* Bem vindos ao jogo de adivinhação *" << endl;
    cout << "*************************************" << endl;

    int chute;
    cout << "Qual seu chute? ";
    cin >> chute;
    cout << "o valor do seu chute é " << chute << endl;
    int numero_secreto = 42;
    //cout << "o número secreto é " << numero_secreto << ". Não conte para ninguém!" << endl;

    if(chute == numero_secreto) {
        cout << "Parabéns você acertou o número segreto." << endl;
    } else if(chute > numero_secreto) {
        cout << "Seu chute maior que o número secreto." << endl;
    } else {
        cout << "Seu chute menor que o número secreto." << endl;
    }

}