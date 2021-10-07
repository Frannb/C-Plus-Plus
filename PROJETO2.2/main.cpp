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
    unordered_map <string, grupo*> tab_grupos;
    unordered_map <string, string> tab_grupos_str;
    list<contact*> l_contatos;
    le_contatos(arq_principal, tab_contatos);
    le_grupos(arq_grupo, tab_grupos);
    le_grupos_string(arq_grupo, tab_grupos_str);


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
                cria_grupo(arq_grupo, tab_grupos, tab_contatos, tab_grupos_str);
                break;
            }
            case 3: {
                //Apaga grupo
                apaga_grupo(arq_grupo, tab_grupos_str, tab_grupos);
                  break;
            }
            case 4: {
                //Pesquisar Contato
                submenu_pesquisa(tab_contatos);
                break;
            }
            case 5:{
                //Lista contato por ordem alfabética
                exibir_contato_ordem(tab_contatos);
                break;
            }
            case 6:{
                //Lista todos os contatos de todos os grupos
                listar_todos_grupos(arq_grupo, tab_grupos_str);
                break;
            }
            case 7:{
                //Lista contato por grupo específico
                listar_grupo_especifico(arq_grupo, tab_grupos_str);
                break;
            }
            case 8:{
                //Lista contato por popularidade
                exibir_popularidade(tab_contatos);

                break;
            }
            case 9:{
                //Alterar dados do contato
                submenu_alterar_contato(tab_contatos);
                break;
            }
            case 0: return 0;

            default:
                cout << "Opção inválida!" << endl << endl;
                break;
        }
    }
}
