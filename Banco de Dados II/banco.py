arq = open('teste03.txt', 'r')  #abrindo arquivo
texto = arq.readlines() #linhas separadas
lista_valores = []      #lista de valores das variaveis
lista_undo = []         #lista de transaçoes que serao feitas undo
lista_redo = []         #lista de transaçoes que serao feitas redo
lista_ckpt = []         #lista de transaçoes ignoradas por conta do ckpt
aux = texto[0]
valor = aux.split('|')
ckpt_start = 0
ckpt = 0

for i in range(0,len(valor)):           #leitura e gravaçao dos valores iniciais das variaveis
    v= valor[i].strip()
    lista_valores.append(v)
print('Valores iniciais:')
print(lista_valores)
for linha in texto.__reversed__() :  #leitura de baixo para cima para definir o tipo de recuperaçao
    linha = linha.strip('<')
    teste = linha.split(" ")
    if(teste[0] == "start"):
        v = teste[1][1:2]
        if v not in lista_redo:
            if v not in lista_ckpt:
                lista_undo.append(v)

    elif(teste[0] == "commit"):
        v = teste[1][1:2]
        if ckpt_start == 1:
            lista_ckpt.append(v)
        else:
            lista_redo.append(v)
    elif(teste[0] == "End"):
        ckpt = 1
    elif(teste[0] == "Start"):
        if(ckpt == 1):
            ckpt_start = 1
print('Transaçoes redo:')
print(lista_redo)
print('Transaçoes undo:')
print(lista_undo)

for linha in texto:         #redo
    linha = linha.strip('<')

    teste = linha.split(",")
    if(teste[0][0:1] == 'T'):
        if teste[0][1:2] in lista_redo:
            for i in range(0,len(lista_valores)):
                if lista_valores[i].startswith(teste[1]):
                    aux1 = teste[3].split(">")
                    lista_valores[i] = teste[1] + '=' + aux1[0]
for linha in texto.__reversed__():      #undo
    linha = linha.strip('<')
    teste = linha.split(",")
    if (teste[0][0:1] == 'T'):
        if teste[0][1:2] in lista_undo:
            for i in range(0, len(lista_valores)):
                if lista_valores[i].startswith(teste[1]):
                    lista_valores[i] = teste[1] + '=' + teste[2]
print('\nValores Finais:')
print(lista_valores)