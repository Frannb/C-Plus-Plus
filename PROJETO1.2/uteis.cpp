#include "Processador.h"
#include "Interface.h"
#include "uteis.h"

void escrever_arquivo(string arq, list<string> & l_armazena){
    //Função para escrever na Lista_telefonica
    string line;
    ofstream myfile (arq, ios::app);
    if (myfile.is_open()) {
        for (auto & x: l_armazena) myfile << x;
        myfile.close();
    } else cout << "Erro ao abrir arquivo!!";
}

void substitui_arquivo(string arq, list<string> & l_armazena){
    //Função para escrever na Lista_telefonica
    string line;
    ofstream myfile (arq);
    if (myfile.is_open()) {
        for (auto & x: l_armazena) myfile << x + "\n";
        myfile.close();
    } else cout << "Erro ao abrir arquivo!!";
}

void separa_lista(const string& algo, char sep, list<string> & l) {
    //Função para separar a Lista_telefonica
    int p1 = 0, p2 = 0; string aux;
    while(true){
        p1 = algo.find_first_not_of(sep,p2); if(p1 == string::npos) break;
        p2 = algo.find_first_of(sep, p1);
        aux = algo.substr(p1, p2-p1);
        l.push_front(aux); if(p2 == string::npos) break;
    }
}

void escrever_arquivo_grupo(list<string> & l_armazena_grupo){
    //Função para escrever na Lista_telefonica
    string line;
    ofstream myfile ("../Arquivo/Lista_de_Grupos.txt", ios::app);
    if (myfile.is_open()) {
        for (auto & x: l_armazena_grupo) myfile << x;
        myfile.close();
    } else cout << "Erro ao abrir arquivo!!";
}
