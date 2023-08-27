# Exercício Pratico - 671 LeetCode

#### NOME: Bruna Camily Domingues Novack


#### TURMA: M1 - AED


##### - Código feito em aula: exerc_671_aula.c


##### - Código feito em casa: exerc_671_casa.c


**Enunciado do exercício:** Dada uma árvore binária não vazia consistindo de nós com valor não negativo, onde cada nó nesta árvore possui exatamente dois ou zero subnós. Se o nó tiver dois subnós, então o valor deste nó será o menor valor entre seus dois subnós. Mais formalmente, a propriedade  root.val = min(root.left.val, root.right.val) sempre se mantém.
Dada essa árvore binária, você precisa gerar o segundo valor mínimo no conjunto formado pelos valores de todos os nós na árvore inteira.
Se não existir esse segundo valor mínimo, produza -1.


**Código feito em aula:** Código não é aceito pelo LeetCode, neste código encontrei uma lógica, ir encontrando a cada subarvore os dois menores nós e retornar o maior dentre este dois menores, porem não consegui implementar em aula. O código acabava sempre retornando -1, porque no fim acabava comparando um nó com ele mesmo e retornava -1.
Este código não possui main nem função insere, pois eu estava fazendo o exercício pelo leetCode e apenas colei as funções no arquivo.c para enviar no eaula.

**Código feito em casa:** Código é aceito pelo LeetCode. Usei duas fuções, findSecondMinimumValue() que apenas chama a função fmenor, que testa se número do nó passado como paramêtro é nulo (retorna -1) e diferente do valor inteiro passado como parâmetro (retorna o valor do nó atual), depois chama recursao para fazer os teste nos subnós seguintes left e right até o fim da arvore, no final dos testes ele testa quem dos ultimos dois returns é o maior e retorna o resultado.


**TESTE 01 - Resultado esperado:**


Entrada: 2, 2, 5, null, null, 5, 7


Saída esperada: 5


Saída obtida: 5


**TESTE 02 - Resultado esperado:** 


Entrada: 2, 2, 2


Saída esperada: -1


Saída obtida: -1


**TESTE 03 - Resultado esperado:**


Entrada: 2,2,3


Saída esperada: 3


Saída obtida: 3

