// Escrito por: Francin Barcelos
// Data: 08/08/19

// 2.Escreva um programa que leia uma string do teclado e conte quantas palavras existem nessa string.
// Ao final, a contagem de palavras deve ser mostrada na tela. As palavras são delimitadas por espaços.


#include <iostream>
#include <string>

using namespace std;

int main() {
    string linha;
    int n = 0, i = 0;
    int pos;
    int ultimo_caractere = 0; // 0 = espaço, e 1 = letra

    cout << ("digite ");
    getline(cin, linha);

    //cin >> linha;
    string aux;
    cout << linha.size() << " esse e o tamanho da linha ";
    for (pos = 0; pos < linha.size(); pos++) {

            linha.find_first_of(' ');
        cout << n << " espaços " << i << endl;
        aux = linha.substr(0,linha.find_first_of(' '));
        linha.erase(0,linha.find_first_of(' '));
        cout << aux;
    }
    return 0;
}