///////////////////////////////////////////////////////
//   Criado por: Francin Barcelos e Guilherme Jose   //
//   Data: 15/06/2020                                //
//   Disciplina: Programação II                      //
///////////////////////////////////////////////////////

#include "Interface.h"
#include "Processador.h"
#include "uteis.h"

using namespace std;

int main() {
    int opcao_case;
    unordered_map <string,contact*> tab_contatos;
    list<contact*> l_contatos;
    le_contatos(arq_principal, tab_contatos);
    /*
    for (auto & par: tab_contatos) {
        // mostra a chave (par.first) seguido do valor (par.second)
        cout << par.first << ": " << par.second->nome << par.second->telefone << endl;
    }*/

    for (;;) {
        menu_principal();
        cout << "Digite a opção desejada: ";
        cin >> opcao_case;
        cin.ignore();

        switch (opcao_case) {
            case 1: {
                //Novo Contato
                cadastrar_contato();
                break;
            }
            case 2: {
                //Cria grupo

                break;
            }
            case 3: {
                //Apaga grupo

                  break;
            }
            case 4: {
                //Pesquisar Contato
                submenu_pes(tab_contatos);
                break;
            }
            case 5:{
                //Lista contato por ordem alfabética
                exibir_contato_ordem(tab_contatos);
                break;
            }
            case 6:{
                //Lista todos os contatos de todos os grupos

                break;
            }
            case 7:{
                //Lista contato por grupo específico

                break;
            }
            case 8:{
                //Lista contato por popularidade
                exibir_popularidade(tab_contatos);

                break;
            }
            case 9:{
                //Alterar dados do contato
                submenu_alt(tab_contatos);
                break;
            }
            case 0: return 0;

            default:
                cout << "Opção inválida!" << endl << endl;
                break;
        }
    }
}
