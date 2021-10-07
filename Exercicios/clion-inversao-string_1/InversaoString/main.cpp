
/* 1. Escreva um programa que leia uma string do teclado, e inverta a ordem de seus caracteres. Ao final, a string
invertida deve ser apresentada na tela. Apenas uma variável string pode ser usada pelo seu programa. */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string inv;

    getline (cin , inv);

    for (int i=inv.size()-1; i>= 0; i--)
    {
        cout << inv[i];

    }

    cout << endl;

    /*
    string inv;
    getline (cin , inv);

    int i=0, j = inv.size()-1;
    while (i<j){
        char c = inv[i];

        inv[i] = inv[j];
        inv[j] = c;
        i++;
        j--;

    }
    cout << inv;
*/
    return 0;
}
