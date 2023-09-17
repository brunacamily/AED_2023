# Exercício Pratico - 56 LeetCode

#### NOME: Bruna Camily Domingues Novack


#### TURMA: M1 - AED


##### - Código feito em aula: aula.c


##### - Código feito em casa: casa.c


**Código feito em aula:** Código não excuta corrtamente e tem uma falha de segmentação, em aula eu consegui entender o objetivo principal de exercício que era retirar as sobreposições dos intervalos passados, o que eu não consegui entender na aula foram os parametros da função passados no leetcode e acabei os utilizando de forma errada, em casa parti do código feito na aula utilizando os parâmetros da maneira que havia interpretado em aula e acabou não dando certo porque sempre faltava um intervalo no retorno, pois eu estava guardando o ultimmo intevalo lido em um ponteiro auxiliar e comparando com o proximo ao invés de já colocar o intervalo anterior no ponteiro de retorno e editar ele quando houvesse sobreposição,  assim o retorno sempre se manteria atualizado e não dependeria das passagens o while para a introdução de um novo intervalo no retorno, em relação a ordenação: como os dois exemplos dados no leetcode os intervalos já estavam ordenados, não implementei nem citei algoritmos de ordenação no exercício da aula.


**Não há testes** código com falha de segmentação.




**Código feito em casa:** Código é aceito pelo LeetCode. Usei duas funções Quicksort(põe em ordem o array de arrays, matriz) e Merge(retorna uma matriz sem nenhuma sobreposição de intervalos apartir da matriz passada como parâmetro), nesta versão logo no inicio já coloco o primeiro intervalo na matriz retorno depois comparo com o próximo intervalo em caso de sobreposição ajusto o fim do intervalo do retorno, caso não haja sobreposição insiro o novo intervalo no retorno e isso se repete para todos os intervalos do arrays passado como parâmetro.


sobre a complexibilidade o código tem 3 funções: Quicksort, Merge e Zera1( libera a memória toda que fooi alocada )


Quicksort: O(n log n);


Merge: O(n);


Zea1: O(m).


O(n log n) + O(n) + O(m) = O(n log n);




**TESTE 01 - Resultado esperado:**


Entrada: [ [4, 5], [1, 4] ]


Saída esperada: [1, 5]


Saída obtida: [1, 5]


**TESTE 02 - Resultado esperado:**


Entrada: [ [2, 3], [4, 5], [6, 7], [8, 9], [1, 10] ]


Saída esperada: [1, 10]


Saída obtida: [1, 10]


**TESTE 03 - Resultado errado:** 


Entrada: [ [1, 3], [2, 6], [8, 10], [15, 18] ]


Saída esperada: [ [1, 6], [8, 10], [15, 18] ]


Saída obtida: [ [1, 6], [8, 10], [15, 18] ]

