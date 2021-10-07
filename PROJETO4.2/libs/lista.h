#ifndef PRGLIB_LISTA_H
#define PRGLIB_LISTA_H

#include <string>

class lista {
    public:
    //construtor: não precisa de parâmetros para criar uma nova lista
    lista();

    // destrutor
    ~lista();

    // insere "algo" no inicio da lista
    void insere_inicio(const std::string &algo);

    // adiciona "algo" no final da lista
    void insere_fim(const std::string &algo);

    // adiciona "algo" em uma determinada posição
    void insere(const std::string &algo, int posicao);

    // remove o dado que está na "posicao" na lista, e retorna
    // uma cópia desse dado
    std::string remove(int posicao);

    // retorna uma referência ao dado que está na "posicao" na lista
    std::string &obtem(int posicao) const;

    // retorna a quantidade de dados armazenados na lista
    int comprimento() const;

    // retorna true se lista estiver vazia
    bool vazia() const;

    // Esvazia a lista
    void esvazia();


    private:

    struct Nodo {
        Nodo *proximo, *anterior; // não tem sentido ter um ponteiro "guarda" aqui
        std::string dado;

        // construtor do Nodo: prático para uso nos métodos
        // da lista
        Nodo(const std::string &algo) {
            dado = algo;

            // isto também não tem sentido ...
            // quando um nodo é criado, supõe-se que ele esteja sozinho, então esse dois
            // ponteiros devem apontar para ele próprio. Olhe a figura da lista vazia, que mostra
            // o nodo guarda com essa configuração
            // proximo = guarda;
            // anterior = guarda;
            //
            // o certo então é assim:
            proximo = this;
            anterior = this;
        }
    };

    // a lista possui sempre ao menos um nodo, que é chamado de guarda. Então basta
    // esse atributo para acessar os nodos !
    // Como ele sempre existe em uma lista, não precisa ser alocado dinamicamente
    Nodo  guarda;

    // comprimento da lista
    long comp;
};

#endif //PRGLIB_LISTA_H
