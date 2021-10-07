#include <iostream>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

int main() {
    string line;
    lista l;
    ifstream myfile("../Arquivo/arq.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            l.insere_inicio(line);
        }
        myfile.close();
    }else throw -1;

    l.insere_fim("Prog2");
    //Adicionando em uma posição qualquer
    l.insere("Engenharia Telecom", 8);
    //Adicionando no final
    l.insere("ADD FINAL", l.comprimento()-1);
    //Adicionando no inicio
    l.insere("ADD INICIO", 0);

    cout << "Foi removido: " + l.obtem(5) << endl;
    cout << "Foi removido: " + l.obtem(0) << endl;
    cout << endl;
    l.remove(5); //Remove o limão
    l.remove(0); //Remove o Kiwi

    for (int i = 0; i < l.comprimento(); i++){
        cout << l.obtem(i) << endl;
    }

    l.esvazia();
    cout << endl;
    //Testa se a lista está vazia
    if (l.vazia()){
        cout << "LISTA VAZIA" << endl;
    }else cout << "LISTA NÃO VAZIA";

}