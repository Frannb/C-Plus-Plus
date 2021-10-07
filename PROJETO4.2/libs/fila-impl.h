//
// Created by msobral on 31/10/2019.
//

// adicione aqui seu arquivo fila-impl.h ...

/*
 * File:   fila-imp.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:59
 */

#ifndef FILA_IMP_H
#define	FILA_IMP_H

namespace prglib {

    template <typename T> fila<T>::fila(unsigned int max_itens) {
        if (max_itens == 0) throw -1;
        // inicializa os atributos da fila
        cap = max_itens;
        N = 0; // inicialmente vazia
        inicio = 0;
        fim = 0;

        // aloca memória para a fila, com capacidade para "cap" dados do tipo T
        buffer = new T[cap];
    }

    template <typename T> fila<T>::fila(const fila& orig) {
        // cria uma fila que é cópia da fila "orig"
        cap = 0;
        *this = orig;
    }

    template <typename T> fila<T>::~fila() {
        // antes de destruir cmoipletamente esta fila,
        // libera sua área de memória
        if (cap) delete[] buffer;
    }

    template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {
        // torna esta fila uma cópia de "outra" fila

        // realoca memória desta fila, caso a memória da "outra" fila seja maior
        if (cap < outra.cap) {
            if (cap) delete[] buffer;
            cap = outra.cap;
            buffer = new T[cap];
        }

        // copia os atributos e dados da "outra" fila
        N = outra.N;
        inicio = fim = 0;
        for (int j=outra.inicio; fim < N; fim++,j++) {
            if (j == outra.cap) j = 0;
            buffer[fim] = buffer[j];
        }

        // o operador= deve retornar uma referência a esta fila
        return *this;
    }

    template <typename T> void fila<T>::enfileira(const T& algo) {
        if (cheia()) throw -1;

        // guarda "algo" no fim da fila
        buffer[fim] = algo;

        // faz o incremento circular
        fim++;
        if (fim == cap) fim = 0;

        // versão alternativa do incremento
        // funciona bem se cap for potência de 2
        // fim = (fim + 1) % cap;


        // faz o incremento da qutde de dados armazenados
        N++;
    }

    template <typename T> T fila<T>::desenfileira() {
        if (vazia()) throw -1;

        // obtém uma referência ao dado que está no início da fila
        T & dado = buffer[inicio];

        // avança o início da fila
        inicio++;
        if (inicio == cap) inicio = 0;

        // decrementa a quantidade de dados armazenados
        N--;

        // retorna o dado que estava no início da fila
        return dado;
    }

    template <typename T> T & fila<T>::frente() {
        if (vazia()) throw -1;
        return buffer[inicio];
    }

    template <typename T> bool fila<T>::vazia() const {
        return N == 0;
    }

    template <typename T> bool fila<T>::cheia() const {
        return N == cap;
    }

    template <typename T> unsigned int fila<T>::capacidade() const {
        return cap;
    }

    template <typename T> unsigned int fila<T>::comprimento() const {
        return N;
    }

    template <typename T> void fila<T>::esvazia() {
        N = 0;
        inicio = fim = 0;
    }

} // fim namespace

#endif	/* FILA_IMP_H */



