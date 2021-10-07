////////////////////////////////////////////
//      Criado por: Francin Barcelos      //
//      Data: 26/08/19                    //
//      Disciplina: Programação II        //
////////////////////////////////////////////

#include <iostream>
#include "Mapa.h"
#include <prglib.h>

using namespace std;
using prglib::pilha;
using prglib::fila;

struct estrutura{
    string ator;
    string caminho;
    int distancia;
};

int main() {
    Mapa mapa("../data/dados.txt");
    estrutura dados;

    int opcao;
    for(;;){
        cout << "Escolha a opção de busca: " << endl;
        cout << "1 - Largura" << endl;
        cout << "2 - Profundidade" << endl;
        cout << "0 - Sair" << endl << endl;


        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao){

            case 1: {
                fila<estrutura> atores(1024);
                string recebe_ator;
                bool achou_bacon = false;
                cout << "Digite o nome do ator: ";
                getline(cin, recebe_ator);

                dados.ator = ""; // declara uma string vazia
                dados.caminho = ""; // declara uma string vazia
                dados.distancia = 0;
                atores.enfileira(dados); // enfileirando a struct

                while(!achou_bacon) {
                    fila<string> filmes_do_ator = mapa.obtem_filmes(dados.ator);
                    dados = atores.desenfileira();
                    dados.distancia = +1;

                    while (!filmes_do_ator.vazia()) {
                        string proximo_filme = filmes_do_ator.desenfileira();
                        fila<string> atores_filme = mapa.obtem_atores(proximo_filme);

                        while (!atores_filme.vazia()) {
                            dados.caminho = dados.caminho + dados.ator + " esteve em " + proximo_filme + " com ";
                            dados.ator = atores_filme.desenfileira();


                            if (dados.ator == "Kevin Bacon") {
                                cout << "A distância de Bacon é: " << dados.distancia << endl;
                                dados.caminho += "Kevin Bacon.";
                                cout << dados.caminho << endl;
                                achou_bacon = true;
                                filmes_do_ator.esvazia();
                            }
                            else {
                                atores.desenfileira();
                            }
                        }
                    }
                }
            }
                break;
            case 2:{

            }
            case 0:
                return 0;
            default:
                cout << "Opção inválida!" << endl << endl;
                break;
        }
    }
}
