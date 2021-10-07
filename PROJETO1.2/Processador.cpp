#include "Processador.h"
#include "Interface.h"
#include "uteis.h"

using namespace std;
//contact dados;

void listar_todos_grupos(list<string> & l_grupo, list<group> & lista_de_grupo){
    string l_leitura;
    transforma_lista_string_em_lista_grupo(l_grupo,lista_de_grupo);

    for (auto it = lista_de_grupo.begin(); it != lista_de_grupo.end(); it++){
        cout << endl;
        cout << it->nome_grupo << ":" << endl;
        for (auto &x: it->lcstruct_grupo){
            cout << (x.nome + ";" + x.telefone + ";" + x.email + ";") << endl;
        }
    }
}

void listar_grupo(list<string> & l_grupo, list<group> & lista_de_grupo){
    group grupo_aux;
    string nome_grupo;
    transforma_lista_string_em_lista_grupo(l_grupo,lista_de_grupo);
    cout << endl << "Digite o nome do grupo que deseja visualizar os contatos: ";
    getline(cin, nome_grupo);
    grupo_aux.nome_grupo = nome_grupo;

    for (auto it = lista_de_grupo.begin(); it != lista_de_grupo.end(); it++){
        if (it->nome_grupo == nome_grupo) {

            for (auto &x: it->lcstruct_grupo) {
                grupo_aux.lcstruct_grupo.push_back(x);
            }
        }
    }
    cout << endl;
    cout << grupo_aux.nome_grupo << ":" << endl;
    for (auto &x: grupo_aux.lcstruct_grupo){
        cout << (x.nome + ";" + x.telefone + ";" + x.email + ";") << endl;
    }
}

void listar_popularidade(list<contact> & lista_de_contato){
    cout << endl;
    lista_de_contato.sort();
    for (auto it = lista_de_contato.begin(); it != lista_de_contato.end(); it++) {
        cout << it->nome << ": " << it->cont << endl;
    }
}

void pesquisa_nome(const string & nome, list<contact> & lista_de_contato) {
    //Percorre a lista de contatos para achar o nome pesquisado
    for (auto it = lista_de_contato.begin(); it != lista_de_contato.end(); it++) {
        if(nome == (it->nome)){
            cout << endl;
            cout << "Nome: " << it->nome << endl;
            cout << "Telefone: " << it->telefone << endl;
            cout << "Email: " << it->email << endl;
            it->cont++;
        }
    }
}

void pesquisa_telefone(const string & telefone, list<contact> & lista_de_contato){
    //Percorre a lista de contatos para achar o telefone pesquisado
    for (auto it = lista_de_contato.begin(); it != lista_de_contato.end(); it++) {
        if(telefone == (it->telefone)){
            cout << endl;
            cout << "Nome: " << it->nome << endl;
            cout << "Telefone: " << it->telefone << endl;
            cout << "Email: " << it->email << endl;
            it->cont++;
        }
    }
}

void pesquisa_email(const string & email, list<contact> & lista_de_contato){
    //Percorre a lista de contatos para achar o email pesquisado
    for (auto it = lista_de_contato.begin(); it != lista_de_contato.end(); it++) {
        if(email == (it->email)){
            cout << endl;
            cout << "Nome: " << it->nome << endl;
            cout << "Telefone: " << it->telefone << endl;
            cout << "Email: " << it->email << endl;
            it->cont++;
        }
    }
}

void excluir_contato(const string & nome, list<string> & l_arquivo, list<contact> & lista_de_contato){
    cout << endl;
    //Recebe o nome do contato a ser excluido e exibe na tela
    pesquisa_nome(nome, lista_de_contato);
    list<string> l;

    //Procura a linha do contato e remove
    for (auto it = l_arquivo.rbegin(); it != l_arquivo.rend(); it++) {
        if (!it->find(nome)) {
            l_arquivo.remove(*it);
        }
        //Insere os demais contatos em uma nova lista
    }
    //Adicionas os contatos restantes da lista no arquivo, substituindo o arquivo atual
    substitui_arquivo(arq_principal,l_arquivo);
    cout << endl;
    cout << "Contato deletado!";
}

void editar_dados(const string & nome,string & op, list<string> & l_arquivo,list<contact> & lista_de_contato){
    string N, T, E;
    //Recebe o nome do contato a ser excluido e exibe na tela
    pesquisa_nome(nome, lista_de_contato);
    list<string> l;

    //Procura a linha do contato, adiciona em um vetor
    for (auto it = l_arquivo.rbegin(); it != l_arquivo.rend(); it++) {
        if(l_arquivo.empty()){
            break;
        }
        for (int i = 0; i < l_arquivo.size(); ++i) {
            if (!it->find(nome)) {
                separa_lista(*it, ';', l);
                l_arquivo.remove(*it);
            }
        }
    }
    l.reverse();
    while (! l.empty()) {
        N = l.front();
        l.pop_front();
        T = l.front();
        l.pop_front();
        E = l.front();
        l.pop_front();
        cout << endl;
    }

    op_editar_dados(op, N, T, E);

    //Anexa o contato altera a lista
    l_arquivo.push_back(N + ";" + T + ";" + E);
    //Adiciona os contatos na lista, substituindo o arquivo atual
    substitui_arquivo(arq_principal,l_arquivo);
    cout << endl;
    cout << "Contato editado!";
}

void cria_grupo(list<string> & l_cgrupo, list<group> & lista_de_grupo){ //por enquanto tem dado erro que impede de completar a funcao
    list<string> l_aux;
    list<string> l_escrita; //lista que servirá para escrever no arquivo
    list<contact> l_contatos;
    string cont_aux, nome_grupo_aux; //string auxiliar q representa o contato e o nome do grupo, respectivamente
    group grupo;
    contact contato;
    cout << endl;
    cout << "Na ausência de alguma opção digite 0" << endl << endl;

    for (auto &x: l_cgrupo){
        l_aux.push_back(x);
    }

    transforma_lista_string_em_lista_grupo(l_cgrupo, lista_de_grupo); //transforma lista_de_grupos.txt em uma lista de grupos
    cout << "Digite o nome para o novo grupo: ";
    getline(cin,nome_grupo_aux);
    cin.ignore();

    for( auto &x: lista_de_grupo){
        if(nome_grupo_aux == x.nome_grupo){
            cout << "Nome de grupo já utilizado, ";
            while (nome_grupo_aux == x.nome_grupo){
                cout << "Digite novamente: " << endl;
                getline(cin,nome_grupo_aux);
            }
        }
    }
    //Cria o nome do novo grupo e então já coloca na lista para escrever no arquivo
    grupo.nome_grupo = nome_grupo_aux;
    l_escrita.push_back("\n");
    l_escrita.push_back(grupo.nome_grupo + "\n");

    cout <<"Agora digite o nome do contato para adicioná-lo, se quiser parar digite /" << endl;
    while(cont_aux != "/") {
        getline(cin,cont_aux);
        buscar_contato(l_aux, cont_aux, contato, l_contatos, l_escrita);
    }

    //Adiciona os contatos do novo grupo
    for(auto &x: l_contatos){
        grupo.lcstruct_grupo.push_back(x);
    }

    lista_de_grupo.push_back(grupo);

    l_escrita.push_back("\n");
    l_escrita.push_back("-");
    l_escrita.push_back("\n");
    escrever_arquivo_grupo(l_escrita);

}

void apaga_grupo(list<string> & l_cgrupo, list<group> & lista_de_grupo){
    list<string> l_escrita; //lista que servirá para escrever no arquivo
    string cont_aux; //string auxiliar q representa o contato e o nome do grupo, respectivamente
    group grupo;
    string nome_grupo_aux; //nome do grupo que será deletado
    string str ("-");
    string arq("../Arquivo/Lista_de_Grupos.txt");

    transforma_lista_string_em_lista_grupo(l_cgrupo, lista_de_grupo); //transforma lista_de_grupos.txt em uma lista de grupos

    cout << "Digite o nome do grupo que deseja apagar" << endl;
    getline(cin, nome_grupo_aux);

    //Percorre a lista de grupos e deleta o nome do grupo selecionado
    for (auto it = lista_de_grupo.begin(); it != lista_de_grupo.end(); it++){
        if (it->nome_grupo == nome_grupo_aux){
            lista_de_grupo.erase(it);
            break;
        }
    }

    for (auto it = lista_de_grupo.begin(); it != lista_de_grupo.end(); it++){
        l_escrita.push_back(it->nome_grupo);
        for (auto &x: it->lcstruct_grupo){
            l_escrita.push_back(x.nome + "; " + x.telefone + "; " + x.email + ";");
        }
        l_escrita.push_back("-");
    }

    substitui_arquivo(arq, l_escrita);
}

void transforma_lista_string_em_lista_grupo(list<string> &l_a_transformar,
                                            list<group> & lista_de_grupo) {
    list<string> l_aux;
    contact contato;
    group grupo;
    string str ("-");
    int pos = 0;
    int i = 0;

    while (!l_a_transformar.empty()) {
        if (l_a_transformar.back() == str){
            l_a_transformar.pop_back();
        }

        if(l_a_transformar.empty()){
            break;
        }

        i = 0;
        //Encontra onde está o caracter delimitador dos grupos
        for(auto it = l_a_transformar.rbegin(); it != l_a_transformar.rend(); it++){
            if (*it != str){
                i++;
            }else{
                pos = i;
                break;
            }
        }

        //Separa a linha da Lista_telefonica em lista de palavras e depois retira as que já foram separadas
        for (i = 0; i < pos ; i++) {
            if (l_a_transformar.empty()) break;
            separa_lista(l_a_transformar.back(), ';', l_aux);
            l_a_transformar.pop_back();
        }

        //Se a iteraçao atual for o caracter delimitador "-" ele vai popar e então pegar o nome do grupo correto
        if (l_aux.back() == str){
            l_aux.pop_back();
            grupo.nome_grupo = l_aux.back();
            l_aux.pop_back();
        }
        else {
            grupo.nome_grupo = l_aux.back();
            l_aux.pop_back();
        }

        //foi invertida a lista para melhor observação das iterações
        l_aux.reverse();

        //Coloca as strings que foram separadas na struct contato
        for (auto it = l_aux.begin(); it != l_aux.end(); it++){
            if(l_aux.empty()){
                break;
            }
            contato.nome = l_aux.front();
            l_aux.pop_front();
            contato.telefone = l_aux.front();
            l_aux.pop_front();
            contato.email = l_aux.front();
            l_aux.pop_front();
            grupo.lcstruct_grupo.push_back(contato);//depois de obter todos os parâmetros do contato, envia contatos para a lista de contatos do grupo

        }
        //o grupo formado vai para a lista de grupos e dps a lista de contatos do grupo é apagada, para começar a pegar novos contatos, se houver
        lista_de_grupo.push_back(grupo);
        grupo.lcstruct_grupo.clear();
    }
}

void buscar_contato(list<string> & l_cgrupo, const string & nome, contact & contato, list<contact> & l_contatos, list<string> &l_escrita){
    list<string> l_separa;
    list<string> l_aux;


    //Percorre o arquivo e separa os dados
    for (auto it = l_cgrupo.rbegin(); it != l_cgrupo.rend(); it++) {
        separa_lista(*it, ';', l_separa);
    }

    //Inverte a lista para ficar na posição, nome, sobrenome, telefone e email
    //Após adiciona em contato
    l_separa.reverse();

    //Compara o nome pesquisado com o primeiro da pilha, caso for entra no laço exibindo os dados
    while (! l_separa.empty()) {
        if (l_separa.front() == nome){
            string NC;
            contato.nome = l_separa.front();
            l_escrita.push_back(l_separa.front() + ";");
            l_separa.pop_front();
            contato.telefone = l_separa.front();
            l_escrita.push_back(l_separa.front()+ ";");
            l_separa.pop_front();
            contato.email = l_separa.front();
            l_escrita.push_back(l_separa.front());
            l_separa.front();
            cout << endl;
            l_contatos.push_back(contato);
            l_escrita.push_back("\n");
            break;
        }else l_separa.pop_front();
    }
}