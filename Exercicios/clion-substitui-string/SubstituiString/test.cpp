//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "substitui.h"
#include "gtest/gtest.h"

using std::string;

class TestSubstitui : public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }
};

string randstr(int len) {
    string r;

    while (len-- > 0) {
        char c = 'a' + (rand() % 26);
        r += c;
    }
    return r;
}

::testing::AssertionResult AssertSubstitui(const char* texto_expr,
                                               const char* sub_expr,
                                               const char* outra_expr,
                                               const char* correto_expr,
                                               const string & texto,
                                               const string & sub,
                                               const string & outra,
                                               const string & correto) {
    string res = substitui(texto, sub, outra);
    if (res == correto) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "texto=" << texto << ", " << sub_expr << "=" << sub << ", " << outra_expr << "=" << outra << ": "
                                         << " resultado deveria ser: " << correto
                                         << ", mas sua função retornou: " << res;
}

TEST_F(TestSubstitui, MesmoComprimento) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};

    for (auto & dado: palavras) {
        int len;
        do { len= rand() % (dado.size() - 2);} while (len == 0);
        int pos = rand() % (dado.size() - len);
        string sub = dado.substr(pos, len);
        string outra;
        do {
            outra = randstr(len);
        } while (dado.find(outra) != string::npos);

        string corr = dado;
        corr.replace(pos, len, outra);
        //string res = substitui(dado, sub, outra);

        ASSERT_PRED_FORMAT4(AssertSubstitui, dado, sub, outra, corr);
    }
}

TEST_F(TestSubstitui, ComprimentoDiferente) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};

    for (auto & dado: palavras) {
        int len;
        do { len= rand() % (dado.size() - 2);} while (len == 0);
        int pos = rand() % (dado.size() - len);
        int slen = len;

        while (slen == len or slen == 0) slen = rand() % (2*dado.size());

        string outra = randstr(slen);
        string sub = dado.substr(pos, len);

        string corr = dado;
        corr.replace(pos, len, outra);
        //string res = substitui(dado, sub, outra);

        ASSERT_PRED_FORMAT4(AssertSubstitui, dado, sub, outra, corr);
    }
}

TEST_F(TestSubstitui, SomenteUmCaractere) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};

    for (auto & dado: palavras) {
        int len = 1;
        int pos = rand() % (dado.size() - len);
        string sub = dado.substr(pos, len);
        string outra = sub;
        while (outra == sub) outra = randstr(1);

        string corr = dado;
        corr.replace(pos, len, outra);
        //string res = substitui(dado, sub, outra);

        ASSERT_PRED_FORMAT4(AssertSubstitui, dado, sub, outra, corr);
    }
}

TEST_F(TestSubstitui, Invalida) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia"};

    for (auto & dado: palavras) {
        int len;
        do { len= rand() % (dado.size() - 2);} while (len == 0);
        int pos = rand() % (dado.size() - len);
        int slen = len;

        while (slen == len or slen == 0) slen = rand() % (2*dado.size());
        string sub;
        do {
            sub = randstr(len);
        } while (dado.find(sub) != string::npos);

        string outra = randstr(slen);

        //string res = substitui(dado, sub, outra);

        ASSERT_PRED_FORMAT4(AssertSubstitui, dado, sub, outra, dado);
    }
}
