.global _start
_start:
menu:

ldr     r1, =opcoes
ldr     r2, =TAMopcoes
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =teclado
mov     r2, #4
mov     r0, #0
mov     r7, #3
svc     0x55

ldr 	r11, teclado

cmp	r11, #49 @49 = 1 em ascii
beq	adiciona

cmp	r11, #50 @50 = 2 em ascii
beq	printa

cmp 	r11, #51 @51 = 3 em ascii
beq	remove


cmp	r11, #48 @48 = 0 em ascii
mov     r0, #0
mov     r7, #1
svceq   0x55

b       menu

adiciona:

ldr     r10, =lista

achaPonteiro:
ldr     r9, [r10]
cmp     r9, #0
addne   r9, #88
movne   r10,r9
bne     achaPonteiro


ldr     r9, =lista
add     r9, #4

achaEspaco:
ldr     r8, [r9]
cmp     r8, #0
addne   r9, #92
bne     achaEspaco

str     r9, [r10]

ldr     r1, =dig
ldr     r2, =TAMdig
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =codigo
ldr     r2, =TAMcodigo
mov     r0, #1
mov     r7, #4
svc     0x55


mov     r1, r9
mov     r2, #4
mov     r0, #0
mov     r7, #3
svc     0x55

ldr     r1, =nome
ldr     r2, =TAMnome
mov     r0, #1
mov     r7, #4
svc     0x55

add     r9, #4
mov     r1, r9
mov     r2, #100
mov     r0, #0
mov     r7, #3
svc     0x55

ldr     r1, =preco
ldr     r2, =TAMpreco
mov     r0, #1
mov     r7, #4
svc     0x55

add     r9, #80
mov     r1, r9
mov     r2, #4
mov     r0, #0
mov     r7, #3
svc     0x55

add     r9, #4
b       menu

remove:
ldr     r1, =dig
ldr     r2, =TAMdig
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =codigo
ldr     r2, =TAMcodigo
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =teclado
mov     r2, #4
mov     r0, #0
mov     r7, #3
svc     0x55

ldr     r12, =lista
ldr     r9, teclado

encontraRecursivo:

ldr     r11, [r12]
ldr     r10, [r11]
cmp     r10, #0
beq     menu
cmp     r10, r9
addne   r11, #88
movne   r12, r11
bne     encontraRecursivo

add     r11, #88
ldr     r10, [r11]
str     r10, [r12]
sub     r11, #88

mov     r4, #0
mov     r3, #0

zerador:
str     r4, [r11]
add     r11, #4
add     r3, #1
cmp     r3, #23

bne      zerador
b        menu


printa:

ldr     r10, lista

printaRecursivo:

ldr     r9, [r10]
cmp     r9, #0
beq     menu


ldr     r1, =codigo
ldr     r2, =TAMcodigo
mov     r0, #1
mov     r7, #4
svc     0x55

mov     r1, r10
mov     r2, #4
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =nome
ldr     r2, =TAMnome
mov     r0, #1
mov     r7, #4
svc     0x55

add     r10, #4
mov     r1, r10
mov     r2, #80
mov     r0, #1
mov     r7, #4
svc     0x55

ldr     r1, =preco
ldr     r2, =TAMpreco
mov     r0, #1
mov     r7, #4
svc     0x55

add     r10, #80
mov     r1, r10
mov     r2, #4
mov     r0, #1
mov     r7, #4
svc     0x55

add     r10, #4
ldr     r10, [r10]
b       printaRecursivo

teclado:
        .skip   4

lista:
        .skip  2304

dig:
        .ascii  "Digite:\n"
TAMdig = . - dig


codigo:
        .ascii  "\n\nCodigo: "
TAMcodigo = . - codigo

opcoes:
        .ascii  "\n\t\tLISTA\n\n[1] Adiciona\n[2] Printa\n[3] Remove\n[0] SAIR\n Digite a opcao: "
TAMopcoes = . - opcoes

nome:
        .ascii  "\nNome: "
TAMnome = . - nome

preco:
        .ascii  "\nPreco: "
TAMpreco = . - preco
