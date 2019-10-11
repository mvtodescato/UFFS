# Tarefa 2 - Fazer um simulador de um processador com Conjunto de Instruções Baseado em Pilha.
# Requisitos:
# - Linguagem de programação: Python;
# - Pilha de 8 níveis (8 bits de largura);
# - Aritmética básica + inst. pop e pusch;
# - Comando extra: mostrar pilha;
# - Mostrar sempre o valor do Stack-Pointer.
pl = []
pont = -1
while x != 0:
	print("1 - Add")
	print("2 - -")
	print("3 - + ")
	print("4 - /")
	print("5 - *")
	print("6 - Print")
	print("7 - Remover")
	print("0 - Sair")
	x = int(input("Escolha uma opçao: "))
	if x == 1:
		if len(pl) < 8:
			n = int(input())
			if n < 255 and n > -255:
				pl.append(n)
				pont = pont+1
			else:
				print('Only permited number between 255 or -255!')
		elif len(pl) >= 8:
			print('Stack full!')
	elif x == 2:
        if pont == 0 or pont == -1:
			print('Not Permited!')
		else:
			aux = pl.pop()
			aux1 = pl.pop()
			aux = aux - aux1
			pont = pont-1
			pl.append(aux)
		
	elif x == 3:
        if pont == 0 or pont == -1:
			print('Not Permited!')
		else:
			aux = pl.pop()
			aux1 = pl.pop()
			aux = aux + aux1
			pont = pont-1
			pl.append(aux)
		
	elif x == 4:
        if pont == 0 or pont == -1:
			print('Not Permited!')
		else:
			aux = pl.pop()
			aux1 = pl.pop()
			aux = aux / aux1
			pont = pont-1
			pl.append(aux)
		
	elif x == 5:
        if pont == 0 or pont == -1:
			print('Not Permited!')
		else:
			aux = pl.pop()
			aux1 = pl.pop()
			aux = aux * aux1
			pont = pont-1
			pl.append(aux)
		
	elif x == 6:
		print(pl)
		print 'pont Pointer is:',pont
	elif x == 7:
		if pont == -1:
			print('Not Permited! pont Empty.....')
		else:
			pl.pop()
			pont = pont-1
	elif x == 0:
		exit(1)