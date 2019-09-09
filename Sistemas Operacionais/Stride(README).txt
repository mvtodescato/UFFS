Stride Scheduling - XV6
----------------------------------------------------------------------------------------------------------------------------------------------
Arquivos que foram modificados:
proc.c(modificado o escalonador, o fork, o allocproc e criado funçoes para organizar o vetor de processos)
sysproc.c(modificar a chamada de sistema do fork para receber por parametro a quantidade de bilhetes)
MAKEFILE(para modificar a quantidade de cpu pra 1 e adicionar o arquivo de teste)
proc.h(modificar a estrutura do processo para adicionar os bilhetes, o passo, o total de passos e a quantidade de vezes que o processo passou na CPU. Foi adicionado tbm o vetor dos processos aqui).
**Foi modificado todos os arquivos onde existia chamada para o fork() colocando numero 1 de bilhetes
----------------------------------------------------------------------------------------------------------------------------------------------
O arquivo de teste se chama teste.c
É o processo pai criando varios filhos que tem o numero controlado pela quantidade de filhos (variavel FILHOS). Os ifs são apra atribuição diferente de tickets para poder acompanhar o processo. Os filhos ficam em um for para gastar tempo de processamento e cada vez que eles rodam fica salvo na variavel do processo. Para ter acesso a informação de quantas vezes foi processado é apenas necessario dar um Cntrl + P.
