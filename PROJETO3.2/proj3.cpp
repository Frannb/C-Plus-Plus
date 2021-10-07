#include "proj3.h"

//Função onde retorna uma arvore como resultado
arvore<geoname_ip> *le_arquivo(const string & nome_arquivo){
    //Cria a arvore do tipo geoname_ip
    arvore<geoname_ip> *dados = nullptr;
    string line;
    int i = 0;
    ifstream myfile (nome_arquivo);
    if (myfile.is_open()){
        //Pega a linha do arquivo e cham-a a função cria_geoname_ip, criando um valor geoname_ip
        while (getline(myfile, line)) {
            geoname_ip dado = cria_geoname_ip(line);
            if (dados == nullptr) {
                dados = new arvore<geoname_ip>(dado);
                i++;
            }
            //balanceia algumas vezes para garantir que a árvore não vai demorar a ser criada
            else if( i == 100 || i == 1000 || i == 5000 || i == 10000 || i == 25000 || i == 50000 || i == 150000){
                dados = dados->balanceia();
                i++;
            }

            else {
                dados->adiciona(dado);
                i++;
            }
        }
        myfile.close();
    }else throw -1;
    // balanceia a arvore
    dados = dados->balanceia();

    return dados;
}

//Função que cria um valor geoname_ip a partir de uma linha
geoname_ip cria_geoname_ip(const string & linha){
    uint32_t mascara;
    uint32_t ultimos[32] = {0xffffffff, 0x7fffffff, 0x3fffffff, 0x1fffffff, 0xfffffff, 0x7ffffff, 0x3ffffff,
                            0x1ffffff, 0xffffff, 0x7fffff, 0x3fffff, 0x1fffff, 0xfffff, 0x7ffff, 0x3ffff,
                            0x1ffff, 0xffff, 0x7fff, 0x3fff, 0x1fff, 0xfff, 0x7ff, 0x3ff, 0x1ff, 0xff, 0x7f,
                            0x3f, 0x1f, 0xf, 0x7, 0x3, 0x1};
    geoname_ip dado;
    //Separa o ip da localização
    list <string> l1, l2;
    separa(linha, ';', l1);
    while(!l1.empty()){
        //separa o ip da mascara
        separa(l1.front(), '/', l2);
        l1.pop_front();
    }
    //Adiciona cada dado da lista para geoname_ip
    auto it = l2.begin();
    mascara = stoi(*it);
    it++;
    dado.primeiro = getip(*it);
    it++;
    dado.local = *it;
    dado.ultimo = dado.primeiro + ultimos[mascara];

    //Retorna o valor geonamee_ip
    return dado;
}

uint32_t getip(const string & ip){
    uint32_t addr;
    // usa a função inet_pton para a conversão. Ela pede uma string no estilo C (char*)
    // então usa-se a operação c_str para obter essa representação do parâmetro ip
    // o resultado da conversão fica em addr
    if (! inet_pton(AF_INET, ip.c_str(), &addr)) {
        throw -1; // IP inválido !!
    }  // faz um ajuste na ordem dos octetos do endereço
    // (de big endian para little endian)
    addr = ntohl(addr);

    return addr;
}

geoname_ip transforma_ip_em_geoname_ip(const string & ip){
    geoname_ip dado;

    //primeiro e o ultimo do geoname_ip são iguais, e o local é vazio pois ainda vai ser descoberto na árvore
    dado.primeiro = getip(ip);
    dado.ultimo = getip(ip);
    dado.local = "";
    return dado;
}

//Por valor: o parâmetro recebe uma cópia do valor que foi passado.
// Se o parâmetro for alterado dentro da função, o valor original não é modificado.
////////////////////////////////////////////////////////////////////////////////
//Por referência: o parâmetro é uma referência ao valor que foi passado.
// Se o parâmetro for alterado, o valor original também será modificado.

//Um ponteiro é uma variável que guarda um endereço de memória de outra variável
//NULL é um endereço invalido
//nullptr endereço ponteiro invalido (usado para inciar um ponteiro)
