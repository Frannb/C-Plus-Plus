#ifndef PRGLIB_LISTA_CPP
#define PRGLIB_LISTA_CPP

#include <string>
#include "lista.h"

//construtor: não precisa de parâmetros para criar uma nova lista
//é preciso inicializar o guarda com uma string vazia
lista::lista(): guarda("") {
    comp = 0;
}

// destrutor
lista::~lista(){
    //Enquando o comprimento for maior que zero, deleta o nodo
    while(comp > 0){
        //cria um novo nodo com o proximo do guarda
        Nodo * novo_nodo = guarda.proximo;
        //pega o proximo do novo nodo
        guarda.proximo = novo_nodo->proximo;
        //e deleta o novo nodo
        delete novo_nodo;
        comp--;
    }
}

// insere "algo" no inicio da lista
void lista::insere_inicio(const std::string &algo){
    Nodo * novo_nodo = new Nodo(algo);
    // conecta nodo ao nodo que era sucessor do guarda
    novo_nodo->proximo = guarda.proximo;
    guarda.proximo->anterior = novo_nodo;

    // conecta nodo ao guarda
    guarda.proximo = novo_nodo;
    novo_nodo->anterior = &guarda ;

    comp++;
}

// adiciona "algo" no final da lista
void lista::insere_fim(const std::string &algo){
    Nodo * novo_nodo = new Nodo(algo);
    // conecta nodo ao nodo que era sucessor do guarda
    novo_nodo->anterior = guarda.anterior;
    guarda.anterior->proximo = novo_nodo;

    // conecta nodo ao guarda
    guarda.anterior = novo_nodo;
    novo_nodo->proximo = &guarda ;

    comp++;
}

// adiciona "algo" em uma determinada posição
void lista::insere(const std::string &algo, int posicao) {
    //Testa para ver se a possição não é maior que o comprimento
    if (posicao > comp) throw -1;
    else {
        Nodo *novo_nodo = new Nodo(algo);
        //cria um novo nodo com o proximo do guarda
        Nodo *nodo_atual = guarda.proximo;
        //percorrer o proximo de cada nodo
        //a cada laço vai decrementando, quando posição for 1, add a frente desse dado
        // se posicao > 0, iria adicionar depois da posição
        while (posicao > 0) {
            //Aponta para o proximo do novo nodo
            nodo_atual = nodo_atual->proximo;
            posicao--;
        }
        novo_nodo->proximo = nodo_atual->proximo;
        nodo_atual->proximo = novo_nodo;
        novo_nodo->anterior = nodo_atual->anterior;
        nodo_atual->anterior = novo_nodo;

        //novo_nodo->proximo = nodo_atual->proximo;
        //novo_nodo->anterior = nodo_atual->anterior;
        //nodo_atual->anterior = novo_nodo;
        //nodo_atual->proximo = nodo_atual->proximo;
        comp++;
    }
}

// remove o dado que está na "posicao" na lista, e retorna
// uma cópia desse dado
std::string lista::remove(int posicao){

    int nova_posicao = posicao - 1; // posição auxiliar

    //posição da variável que deseja remover da lista nao pode ser maior que o comprimento da lista
    if(posicao >= comp) throw -1;

    //Se a lista estiver vazia, não será possível remover da lista
    if(comp == 0) throw -1;


    if(posicao == 0){
        //cria um novo nodo contendo a guarda
        Nodo * novo_nodo = &guarda;

        //o proximo do novo_nodo é substituído pelo próximo do próximo da guarda
        novo_nodo->proximo = guarda.proximo->proximo;
        comp --;

        //retorna o guarda proximo do proximo
        //mesmo no codigo entando escrito novo_nodo->dado, está retornando o dado do novo_nodo->proximo
        return novo_nodo->dado;
    } else{
        //Cria um novo nodo com o proximo do guarda
        Nodo * novo_nodo = guarda.proximo;
        //Verifica se a posição é maior que zero, enquanto for
        //Busca o nodo
        //a criacao do nova_posicao sendo o decrescimo da posicao foi devido ao fato de que quando estivesse deletando
        //ou retornando novo_nodo, estava sempre retornando ou deletando o proximo do novo_nodo
        while (nova_posicao > 0){
            //Aponta para o proximo do novo nodo e decrementa a posicao
            novo_nodo = novo_nodo->proximo;
            nova_posicao --;
        }
        comp --;

        //ja que quando deleta novo_nodo deleta apenas o proximo do novo_nodo, foi criado um nodo auxiliar que contem
        //o proximo do novo nodo
        Nodo * nodo_aux = novo_nodo->proximo;

        //Depois de deletado o proximo do novo_nodo, o novo_nodo próximo é substituido pelo proximo do nodo auxiliar
        delete novo_nodo;
        novo_nodo->proximo = nodo_aux->proximo;
        return novo_nodo->dado;

    }
}

// retorna uma referência ao dado que está na "posicao" na lista
std::string & lista::obtem(int posicao) const {
    //Testa para ver se a possição não é maior que o comprimento
    if(posicao > comp) throw -1;
    else{
        //cria um novo nodo com o proximo do guarda
        Nodo * novo_nodo = guarda.proximo;
        //percorrer o proximo de cada nodo
        //a cada laço vai decrementando, quando posição for 0, acha o dado e retorna este dado
        while (posicao > 0){
            //Aponta para o proximo do novo nodo
            novo_nodo = novo_nodo->proximo;
            posicao --;
        }
        return novo_nodo->dado;
    }

}

// retorna a quantidade de dados armazenados na lista
int lista::comprimento() const{
    return comp;
}

// retorna true se lista estiver vazia
bool lista::vazia() const{
    //se comp(comprimento da lista) for 0, a lista está vazia
    return comp==0;
}

// Esvazia a lista
void lista::esvazia(){
    while(! vazia()){
        remove(0);
    }
}

#endif //PRGLIB_LISTA_CPP