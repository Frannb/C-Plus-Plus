/*
2.Escreva um programa que leia uma string do teclado e conte quantas palavras existem nessa string.
Ao final, a contagem de palavras deve ser mostrada na tela. As palavras são delimitadas por espaços.
*/

#include <iostream>
#include <string>

using namespace std;
int main () {
    string linha;
    int n=0;
    int pos;
    int ultimo_caractere=0; // 0 = espaço, e 1 = letra

    //cout << "Digite uma frase:" << endl;
    getline(cin, linha);

   // cout << "Você digitou esta linha: " << linha << endl;

    // lê caracteres a partir de cin, e guarda-os na string "linha",
    // até encontrar um caractere newline (quebra-de-linha, ou \n)

    for (pos=0; pos < linha.size(); pos++)
    {
        if (ultimo_caractere == 0) {
            if (! isspace(linha[pos])) {
                n++;
                ultimo_caractere = 1;
            }
        }
        else  { // (ultimo_caractere == 1)
            if (isspace(linha[pos])) {
                ultimo_caractere = 0;
            }
        }
    }

    cout << n << endl;

    return 0;
}