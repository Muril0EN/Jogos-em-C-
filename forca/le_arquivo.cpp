#include <iostream>
#include <fstream>

#include "le_arquivo.hpp"

extern std::vector<std::string> le_arquivo(){
    //input + file + stream
    std::ifstream arquivo;//dados para usar ler valores de arquivo
    arquivo.open("palavras.txt");
    
    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        std::vector<std::string> palavras_do_arquivo;

        for(int i = 0; i < quantidade_palavras; i++){
            std::string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();//boa prática
        return palavras_do_arquivo;
    } else{ // boa prática 
        std::cout << "Não foi possível acessar o banco de palavras." << std::endl;
        exit(0); //parar execução
    }
}