import csv
AF = []
states = []
final = []
alphabet = []
state = 'S'
realState = 'S'
changes = {'S':'S'}
epsilons = {}
mortos = []

def newLine():
    AF.append([[] for _ in range(len(alphabet))])
    final.append(False)

def newCollumn():
    for i in range(len(AF)):
        AF[i].append([])

def addRG(line):
    rule = line.split('::=')[0].strip(' ')[1]
    productions = line.strip('\n').split(' ::= ')[1].split(' | ')
    if rule not in changes:
        changes[rule] = nextState()
        states.append(state)
        newLine()
        rule = state
    else:
        rule = changes[rule]
    for production in productions:
        if production[0] not in alphabet and production[0] != 'ε' and '<' not in production[0]:
            newCollumn()
            alphabet.append(production[0])
        elif production[0] == '<':
            if 'ε' not in alphabet:
                newCollumn()
                alphabet.append('ε')
            if production[1] not in changes:
                changes[production[1]] = nextState()
                states.append(state)
                newLine()
            AF[states.index(rule)][alphabet.index('ε')].append(changes[production[1]])
            continue;
        if '<' in production:
            if production[2] not in changes:
                changes[production[2]] = nextState()
                states.append(state)
                newLine()
            AF[states.index(rule)][alphabet.index(production[0])].append(changes[production[2]])
        elif 'ε' in production:
            final[states.index(rule)] = True
        elif '<' not in production:
            if 'X' not in states:
                states.append('X')
            newLine()
            AF[states.index(rule)][alphabet.index(production[0])].append('X')
            final[states.index('X')] = True

def nextState():
    global state
    global realState
    if realState == 'S':
        realState = 'A'
    elif realState == 'R':
        realState = 'U'
    elif realState == 'X':
        realState = 'Y'
    else:
        realState = chr(ord(realState)+1)
    state = realState
    return state

def addToken(line):
    global state
    state = 'S'
    for symbol in line:
        if '\n' != symbol:
            if symbol not in alphabet:
                newCollumn()
                alphabet.append(symbol)
            newLine()
            AF[states.index(state)][alphabet.index(symbol)].append(nextState())
            states.append(state)
    final[states.index(state)] = True

def removeEpsilon():
    if 'ε' in alphabet:
        for state in states:
            if state in epsilons:
                epsilons[state] += AF[states.index(state)][alphabet.index('ε')]
            else:
                epsilons[state] = AF[states.index(state)][alphabet.index('ε')]
        mudanca = True
        while mudanca:
            mudanca = False
            for state in epsilons:
                for transition in epsilons[state]:
                    if transition in epsilons:
                        for transition2 in epsilons[transition]:
                            if transition2 not in epsilons[state] and transition2 != state:
                                epsilons[state] += transition2
                                mudanca = True

        for state in epsilons:
            for transition in epsilons[state]:
                for i in range(len(AF[states.index(transition)])):
                    for production in AF[states.index(transition)][i]:
                        if production not in AF[states.index(state)][i]:
                            AF[states.index(state)][i].append(production)
                if final[states.index(transition)]:
                    final[states.index(state)] = True
        for state in AF:
            state.pop(alphabet.index('ε'))
        alphabet.pop(alphabet.index('ε'))

def determinize():
    mud = True
    str2 = ''
    while mud:
        mud = False
        for state in states:
            for tr in alphabet:
                reg = AF[states.index(state)][alphabet.index(tr)]

                if len(reg) > 1 :
                    reg.sort()
                    for i in range(len(reg)):
                        str1 = reg[i]
                        str2 = str2 + str1
                    if str2 not in states:
                        states.append(str2)
                        newLine()
                        for valor in reg:
                            if final[states.index(valor)]:
                                final[states.index(str2)] = True
                            for i in range(len(alphabet)):
                                for production in AF[states.index(valor)][i]:
                                    if production not in AF[states.index(str2)][i]:
                                        AF[states.index(str2)][i].append(production)

                        mud = True
                    AF[states.index(state)][alphabet.index(tr)] = [str2]
                    str2 = ''

def buscaAtingiveis(inicial):
    accessible = [inicial]
    for state in accessible:
        if state in states:
            for production in AF[states.index(state)]:
                if len(production) == 1:
                    if production[0] not in accessible:
                        accessible.append(production[0])
    return accessible

def removeInaccessible():
    accessible = buscaAtingiveis('S')
    for state in states:
        if state not in accessible:
            print('Removendo estado'+state)
            AF.pop(states.index(state))
            final.pop(states.index(state))
            states.pop(states.index(state))

def removeDead():
    global mortos
    for state in states:
        morto = True
        accessible = buscaAtingiveis(state)
        for stateAtingivel in accessible:
            if final[states.index(stateAtingivel)]:
                morto = False
                break
        if morto:
            mortos.append(state)
    for state in mortos:
        AF.pop(states.index(state))
        final.pop(states.index(state))
        states.pop(states.index(state))

def addError():
    states.append('Ø')
    newLine()
    final[states.index('Ø')] = True
    for state in AF:
        for transition in state:
            if len(transition) < 1:
                transition.append('Ø')
            elif transition[0] in mortos:
                transition[0] = 'Ø'


def main():

    file = open("input.txt","r")
    states.append('S')  #Adiciona o estado inicial S
    AF.append([]) #Adiciona linha na tabela
    final.append(False)


    for line in file:
        if line[0] == '<':  #Caso seja um Gramatica Regular ela é adicionada ao Automato
            addRG(line)
        else:
            addToken(line)  #Caso seja um Token ele é adicionado ao Automato
    print("TABELA MONTADA")
    print(alphabet)  #Print AF final
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    removeEpsilon()
    print("\n\nTABELA SEM EPSILONS")
    print(alphabet)  #Print AF final
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    determinize()
    print("\n\nTABELA DETERMINIZADA")
    print(alphabet)  #Print AF final
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    removeInaccessible()
    print("\n\nTABELA SEM INALCANSAVEIS")
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    removeDead()
    print("\n\nTABELA SEM MORTOS")
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    addError()
    print("\n\nTABELA COM ESTADO DE ERRO")
    for i in range(len(states)):    #Print AF final
        print(final[i],states[i],AF[i])    #Print AF final
    print(changes)
    file.close()
    with open('output.csv', 'w') as file:
        writer = csv.writer(file)
        linha = ['']
        linha += alphabet
        writer.writerow(linha)
        for i in range(len(AF)):
            if final[i]:
                linha = ['*'+states[i]]
            else:
                linha = [states[i]]
            linha += AF[i]
            writer.writerow(linha)
    file.close()
main()
