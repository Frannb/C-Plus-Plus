//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./ContaPalavras"


class Contador : public ::testing::Test {

protected:
    virtual void SetUp() {
        srand(clock());
    }

    static const vector<string> palavras;
    static const int MaxPalavras = 11;

    string gera_frase(int len) {
        string r;
        int n = palavras.size();

        while (len-- > 1) {
            int nespacos = 1 + (rand() % 4);
            string espacos(nespacos, ' ');
            r += palavras[rand() % n] + espacos;
        }
        r += palavras[rand() % n];

        return r;
    }
};

const vector<string> Contador::palavras = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};

string roda(const string & dado) {
    Terminal term(PROG);

    term.escreva(dado+'\n');
    auto res = term.leLinha();
    strip(res);
    return res;
}

::testing::AssertionResult AssertConta(const char* frase_expr,
                                           const char* len_expr,
                                           const string & frase,
                                           int len) {
    string res = roda(frase);
    int nres;
    try {
        nres = stoi(res);
    } catch(...) {
        return ::testing::AssertionFailure() << "frase: " << frase << " tem " << len << " palavras, mas seu programa retornou um valor não numérico: "
                                             << res << endl;
    }
    if (nres == len) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "frase: " << frase << " tem " << len << " palavras, mas seu programa retornou "
                                         << nres << endl;
}

// Testa com uma frase composta por 2 ou mais palavras
TEST_F(Contador, Normal) {
    for (int n=0; n < 10; n++) {
        int len = 2 + (rand() % this->MaxPalavras);
        string frase = this->gera_frase(len);

        ASSERT_PRED_FORMAT2(AssertConta, frase, len);
    }
}

// Testa com uma frase composta por uma única palavra
TEST_F(Contador, Simples) {
    for (int n=0; n < 10; n++) {
        int len = 1;
        string frase = this->gera_frase(len);

        ASSERT_PRED_FORMAT2(AssertConta, frase, len);
    }
}

// Testa com uma frase composta por 2 ou mais palavras e espaços nas bordas
TEST_F(Contador, Bordas) {
    for (int n=0; n < 10; n++) {
        int len = 2 + (rand() % this->MaxPalavras);
        string frase = this->gera_frase(len);
        string espacos_inicio(1+(rand() % 4), ' ');
        string espacos_fim(1+(rand() % 4), ' ');
        frase.insert(0, espacos_inicio);
        frase.append(espacos_fim);

        ASSERT_PRED_FORMAT2(AssertConta, frase, len);
    }
}

// Testa com uma frase vazia
TEST_F(Contador, Nenhuma) {
    for (int n=0; n < 10; n++) {
        int len = 0;
        string frase;

        ASSERT_PRED_FORMAT2(AssertConta, frase, len);
    }
}

