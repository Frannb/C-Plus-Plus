#ifndef PROJETO1_PROCESSADOR_H
#define PROJETO1_PROCESSADOR_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

//Diretório dos arquivos
const string arq_principal = "../Arquivo/Lista_telefonica.txt";
const string arq_grupo = "../Arquivo/Lista_de_Grupos.txt";

//Apresenta uma struct com as variáveis do contato
//Parâmetros:
//Contém nome, teledone e email dos contatos, em cont contém a popularidade onde é incrementado
//quando um contato é acessado.
struct contact : public error_code {
    string nome, telefone, email;
    int cont;
};

struct grupo: public error_code{
    string nome_grupo;
    unordered_map <string,contact*> tab_contatos_struct;
};

// Apresenta a popularidade do contato
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
void exibir_popularidade(unordered_map <string,contact*> & tab_contatos);

// Realiza a pesquisa do nome do contato na tabela hash
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// nome: Nome do contato a ser pesquisado
void pesquisa_nome(const string & nome, unordered_map <string,contact*> tab_contatos);

// Realiza a pesquisa do telefone do contato na tabela hash
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// telefone: Telefone do contato a ser pesquisado
void pesquisa_telefone(const string & telefone, unordered_map <string,contact*> tab_contatos);

// Realiza a pesquisa do email do contato na tabela hash
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// email: Email do contato a ser pesquisado
void pesquisa_email(const string & email, unordered_map <string,contact*> tab_contatos);

// Remove o contato da tabela
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// nome: Nome do contato a ser removido
void excluir_contato(const string & nome, unordered_map <string,contact*> & tab_contatos);

// Edita os dados do contato, podendo editar o nome, email ou telefone.
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// nome: Recebe o nome do contato, para exibir os dados do contato
// op: Selecional qual a opção de como será a edicação deste contato, por nome, email ou telefone.
void editar_dados(const string & nome, string & op, unordered_map <string,contact*> & tab_contatos);

void le_grupos_string(const string & arquivo, unordered_map <string, string> &tab_grupos_str);

// Faz a leitura do nosso backup, onde se encontra em um arquivo.txt e armazena em memória
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
// arquivo: recebe o diretório do arquivo
void le_contatos(const string & arquivo, unordered_map<string, contact*> & tab_contatos);

// Mostra em ordem alfabetica todos os contatos da tabela
// Parâmetros:
// tab_contatos: tabela hash que contém todos os contatos
void exibir_contato_ordem(unordered_map<string, contact*> & tab_contatos);

#endif //PROJETO1_PROCESSADOR_H
