#ifndef PROJETO1_INTERFACE_H
#define PROJETO1_INTERFACE_H

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include "Processador.h"

using namespace std;

// Apresenta o menu principal na tela
void menu_principal();

// Apresenta submenu da pesquisa, usando ao procurar um contato
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
void submenu_pesquisa(unordered_map <string,contact*>& tab_contatos);

// Apresenta submenu do alterar contato, usando ao editar um contato
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
int submenu_alterar_contato(unordered_map <string,contact*>& tab_contatos);

// Apresenta submenu do alterar contato, usando ao editar um contato
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
void menu_pesquisar_contato(int sub_opcao, unordered_map <string,contact*> & tab_contatos);

// Apresenta as opções de como irá ser editado o contato, se por nome, email ou telefone
// Parâmetros:
// opcao: Irá receber a opção selecionada, nome, telefone ou email
// N: Recebe o novo nome
// T: Recebe o novo telefone
// E: Recebe o novo email
void opcoes_editar_dados(const string & opcao, string & N, string & T, string & E);

//Adiciona os contatos
void cadastrar_contato();

void listar_todos_grupos(const string & arquivo, unordered_map <string, string> &tab_grupos_str);

void listar_grupo_especifico(const string & arquivo, unordered_map <string, string> &tab_grupos_str);

void cria_grupo(const string & arquivo, unordered_map <string, grupo*> &tab_grupos, unordered_map <string,contact*> &tab_contatos, unordered_map <string, string> &tab_grupos_str);

void apaga_grupo(const string & arquivo, unordered_map <string, string> &tab_grupos_str, unordered_map <string, grupo*> &tab_grupos);

void le_grupos(const string & arquivo,unordered_map <string, grupo*> &tab_grupos);

// Parte da interface do exibir_contato_ordem
// Parâmetros:
// lista_contato: Lista de contato que contém todos os contatos, extraida de uma tabela hash
void ordena_contato(list<contact*> lista_contatos);

#endif
