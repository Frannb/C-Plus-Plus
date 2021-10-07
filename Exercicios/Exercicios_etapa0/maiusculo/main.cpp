#include <iostream>
#include <string>

using namespace std;

int main() {
    string palavra, maiusculo;
    int i;

    cout << "Digite sua frase: ";
    cin >> palavra;
   for (int i = 0; i < palavra.size(); i++){

        //while (i < palavra.size()){
           maiusculo = toupper(palavra[i]);
        i++;
    }
    cout << maiusculo;
    return 0;
}
