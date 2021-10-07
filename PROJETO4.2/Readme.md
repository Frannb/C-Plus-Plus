# Projeto 4

Desde o início do semestre foi usada a biblioteca STL, que contém implementações das estruturas de dados estudadas. Na primeira etapa da disciplina se enfatizou conhecer e usar essas estruturas de dados. Na segunda etapa o foco está no projeto de uma estrutura de dados, e o resultado esperado é a criação de estruturas de dados pelas equipes. Podem ser criadas versões que reproduzam (possivelmente com um toque pessoal) as características das estruturas de dados estudadas, ou mesmo novas estruturas de dados, diferentes daquelas conhecidas.

As estruturas de dados que já conhecemos são:
* **Lineares**: filas, pilhas e listas
* **Associativas**: tabelas hash, conjuntos e árvores de pesquisa binária


Mais especificamente os **objetivos de aprendizagem** desta unidade são:
* Desenvolver (criar) uma estrutura de dados que possa ser utilizada em programas, possuindo uma interface de programação bem definida, e incluindo os algoritmos específicos necessários para a eficiência de suas operações quanto ao uso de memória e tempo computacional.
* Avaliar o projeto de uma estrutura de dados, usando sua documentação como referência para emitir um julgamento sobre sua eficiência e usabilidade


Algumas das estruturas conhecidas são bastante simples, e não serviriam como objeto de estudo nesta etapa da disciplina (refiro-me especificamente a filas e pilhas). As demais têm complexidade adequada para serem desenvolvidas neste último mês de aula. Além delas, outras estruturas de dados podem ser escolhidas:
* [Trie](https://en.wikipedia.org/wiki/Trie): uma trie é um tipo de árvore n-ária (que pode ter um número n de ramos por nodo), em que os dados estão armazenados nos ramos, e não nos nodos. Esse tipo de árvore armazena prefixos dos dados, então são adequadas para dados formados por cadeias de elementos (ex: strings, endereços IP, sequências de bits em geral, ...). Um uso conhecido para tries é como dicionário de termos para um sistema do tipo auto-completar. Uma variação de tries é [radix tree](https://en.wikipedia.org/wiki/Radix_tree).
* [Array Deques](https://en.wikipedia.org/wiki/Double-ended_queue#Implementations): um array deque é um tipo de fila que usa um array dinâmico (i.e. que pode ser expandido ou contraído) para armazenar dados. Ela possibilita a inserção e remoção eficiente de dados de seus extremos, e o acesso a qualquer dado pode ser feito com tempo constante (i.e. o custo de tempo computacional dessa operação é O(1)).
* [Hashed Array Tree](https://en.wikipedia.org/wiki/Hashed_array_tree): um hashed array tree (ou HAT) é parecido com um array deque, porém sua estrutura interna faz um melhor uso de memória. Apesar do nome, ela nada tem a ver com tabelas hash.
* [Lista desenrolada](https://en.wikipedia.org/wiki/Unrolled_linked_list): uma lista desenrolada é parecida com uma lista usual, porém ela possibilita armazenar múltiplos dados em cada nodo da lista. Isso traz algumas vantagens quanto ao uso de memória e localização dos dados.
* [Filtros Bloom](https://en.wikipedia.org/wiki/Bloom_filter): um filtro Bloom serve para informar sobre a existência ou não de um dado, porém probabilisticamente. Ele pode resultar em falsos positivos, quando retorna verdadeiro para um dado inexistente ou desconhecido, mas nunca retorna falsos negativos. Assim, se um filtro informa que um dado é desconhecido ou inexistente, com certeza isso é verdade. Essa estrutura de dados possui [várias aplicações importantes](https://en.wikipedia.org/wiki/Bloom_filter#Examples).
* ... e possivelmente [outras](https://en.wikipedia.org/wiki/List_of_data_structures#Linear_data_structures) !!!

Maiores detalhes estão na [wiki da unidade 4](https://wiki.sj.ifsc.edu.br/index.php/PRG29003:_Etapa_2:_Projeto_de_estruturas_de_dados#CURIOSIDADE%3A_como_um_processo_usa_a_mem.C3.B3ria).

# Um demo para o Projeto 4

Esta demonstração do projeto 4 inclui a implementação de uma fila circular.
A fila está declarada em libs/fila.h e implementada em libs/fila-impl.h. Ela foi criada como uma [classe](https://wiki.sj.ifsc.edu.br/index.php/Introdu%C3%A7%C3%A3o_C%2B%2B#Classes_e_objetos), que é uma construção da linguagem C++ (vocês já usaram classes em seus programas, tais como _string, list, queue, unordered_map_, ...). Mais especificamente, ela foi implementada como [classe template](https://wiki.sj.ifsc.edu.br/index.php/Introdu%C3%A7%C3%A3o_C%2B%2B#Templates), pois deve ser capaz de armazenar valores de qualquer tipo de dados. Nesse sentido, ela funciona como as estruturas de dados da STL que usamos até então.

Em main.cpp está um programa de demonstração de uso da estrutura de dados. Ele faz a listagem recursiva de um diretório, mostrando todos os arquivos e subdiretórios ali contidos.

  
