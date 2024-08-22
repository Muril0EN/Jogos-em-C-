#include <iostream>
#include <string> //biblioteca para uso de strings
using namespace std;

int main(){
    string palavra_secreta = "MELANCIA";
    cout << palavra_secreta << endl;

    bool nao_acertou = true;
    bool nao_ganhou = true;

    while(nao_acertou && nao_ganhou){
        char chute;
        cin >> chute;

        cout << "O seu chute foi " << chute << endl;
    }

}

