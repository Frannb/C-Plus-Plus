///////////////////////////////////////////////////////
//   Criado por: Francin Barcelos e Guilherme Jose   //
//   Data: 19/03/19                                  //
//   Disciplina: Programação II                      //
///////////////////////////////////////////////////////

#include "Interface.h"
#include "Processador.h"
#include "uteis.h"

using namespace std;

int main() {
    int opcao_case;
    list<string> l_armazena;
    list<string> l_armazena_grupo;
    list<contact> lista_de_contato;
    list<group> lista_de_grupo;
    list<string> l;
    contact dados;

    //Função para abrir a Lista_telefonica
        string line;
        ifstream myfile ("../Arquivo/Lista_telefonica.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                l_armazena.push_front(line);
            }
            myfile.close();
        } else cout << "Erro ao abrir arquivo!!";
    
    //Função para abrir a Lista_de_grupos
        string line2;
        ifstream myfile2 ("../Arquivo/Lista_de_Grupos.txt");
        if (myfile2.is_open()) {
            while (getline(myfile2, line2)) {
                l_armazena_grupo.push_front(line2);
            }
            myfile2.close();
        } else cout << "Erro ao abrir arquivo!!";

    //Percorre o arquivo e separa os dados
    for (auto it = l_armazena.rbegin(); it != l_armazena.rend(); it++) {
        separa_lista(*it, ';', l);
    }

    l.reverse();
    //Coloca os dados na lista de contatos
    while (! l.empty()) {
        if (l.empty()) {
            break;
        }
        dados.nome = l.front();
        l.pop_front();
        dados.telefone = l.front();
        l.pop_front();
        dados.email = l.front();
        l.pop_front();
        lista_de_contato.push_front(dados);
    }

    for (;;) {
        string sub_opcao, menu, submenu_pesquisa, submenu_alterar;

        menu_principal(menu);
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
                cria_grupo(l_armazena_grupo, lista_de_grupo);
                break;
            }
            case 3: {
                //Apaga grupo
                apaga_grupo(l_armazena_grupo, lista_de_grupo);
                break;
            }
            case 4: {
                //Pesquisar Contato
                submenu_pes(submenu_pesquisa, lista_de_contato);
                break;
            }
            case 5:{
                //Lista contato por ordem alfabética
                listar_contato_ordem(lista_de_contato);
                break;
            }
            case 6:{
                //Lista todos os contatos de todos os grupos
                listar_todos_grupos(l_armazena_grupo, lista_de_grupo);
                break;
            }
            case 7:{
                //Lista contato por grupo específico
                listar_grupo(l_armazena_grupo, lista_de_grupo);
                break;
            }
            case 8:{
                //Lista contato por popularidade
                listar_popularidade(lista_de_contato);

                break;
            }
            case 9:{
                //Alterar dados do contato
                submenu_alt(submenu_alterar, l_armazena, lista_de_contato);
                break;
            }
            case 0: return 0;

            default:
                cout << "Opção inválida!" << endl << endl;
                break;
        }
    }
}
