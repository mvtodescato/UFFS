#include<stdio.h>
#include <strings.h>
#include <time.h>
#include<windows.h>     //programa feito em WINDOWS
int n=0;//numero de turmas
typedef struct{
int matricula,turma_num;
char cpf[12],nome[50];
float np1,np2,media;
}ALUNO;
typedef struct{
int codigoturma,fase,horario_inicial,horario_final,numero_alunos,auxnp1,auxnp2;
char componente[30],diaaula[15];

ALUNO aluno[50];//struct dos alunos dentro da TURMA
}TURMA;

int valida_cpf(char *cpf){
    int i,somador=0,digito1,result1,result2,digito2,valor;
    int icpf[12];
    for(i=0;i<11;i++){
        icpf[i]=cpf[i]-48;//convertido para um inteiro conforme tabela ASC
    }
    for(i=0;i<9;i++){
        somador+=icpf[i]*(10-i);
    }
    result1=somador%11;
    if( (result1==0) || (result1==1) ) {
        digito1=0;
    }
    else{
        digito1 = 11-result1;       //fazendo o primeiro e segundo digito
    }
    somador=0;
    for(i=0;i<10;i++){
        somador+=icpf[i]*(11-i);
    }
    valor=(somador/11)*11;
    result2=somador-valor;
    if( (result2==0) || (result2==1) ){
        digito2=0;
    }
    else{
        digito2=11-result2;
    }
    if((digito1==icpf[9]) && (digito2==icpf[10])){   //validando...
        printf("CPF VALIDADO!");
        return 1;//retorna pra poder sair do laço de repetiçao
    }
    else{
        return 0;
    }
}

void cadastra_turma(TURMA turmas[]){
    system("cls");
    printf("Codigo da Turma: %d\n",n);
    fflush(stdin);
    printf("Componente curricular: ");
    fgets(turmas[n].componente,30,stdin);
    printf("Fase: ");
    scanf("%d",&turmas[n].fase);
    fflush(stdin);//windows
    printf("Dia das aulas: ");
    fgets(turmas[n].diaaula,15,stdin);
    printf("Horario inicial(horas): ");
    scanf("%d",&turmas[n].horario_inicial);
    printf("Horario final(horas): ");
    scanf("%d",&turmas[n].horario_final);
    n++;//numero de turmas aumentando a cada vez que a funçao e chamada
    system("cls");
}
void cadastra_aluno(TURMA turmas[]){
    int a,b,i;
    system("cls");
    printf("Turmas Disponiveis:\n\n");
    for(i=0;i<n;i++){
        printf("Turma %d\tComponente:%s\n",i,turmas[i].componente);
    }
    if(n>0){//se tiver turmas o valor de n vai se maior que 0
        printf("Em qual turma deseja cadastrar um novo aluno?\n");
        scanf("%d",&a);
        system("cls");
        fflush(stdin);
        printf("Nome do aluno: ");
        fgets(turmas[a].aluno[turmas[a].numero_alunos].nome,50,stdin);
        fflush(stdin);
        printf("Numero da matricula: ");
        scanf("%d",&turmas[a].aluno[turmas[a].numero_alunos].matricula);
        printf("Numero do CPF: ");
        while (1){
            fflush(stdin);
            fgets(turmas[a].aluno[turmas[a].numero_alunos].cpf,12,stdin);
            if(valida_cpf(&turmas[a].aluno[turmas[a].numero_alunos].cpf)==1){ //validando o CPF
                Sleep(2000);
                break;
            }
            else{
                printf("Por favor digite novamente o cpf\n");
            }
        }
        system("cls");
        turmas[a].numero_alunos++;
    }
    else{
        printf("Sem turmas\n");//Caso nao exista ainda turmas cadastradas
    }

}
void inserir_notas(TURMA turmas[]){
    int a,b,i;
    system("cls");
    printf("Qual nota deseja inserir?(1-Np1,2-Np2)\n");
    scanf("%d",&a);
    printf("Numero da Turma: ");
    scanf("%d",&b);
    system("cls");
    printf("Digite as notas:\n");
    fflush(stdin);
    if(a==1){
        for(i=0;i<turmas[b].numero_alunos;i++){
            printf("%s",turmas[b].aluno[i].nome);
            scanf("%f",&turmas[b].aluno[i].np1);
            turmas[b].auxnp1=1;//aumentando a auxiliar para utilizar nas funçoes que utilizam as notas
        }
    }
    else if(a==2){
        for(i=0;i<turmas[b].numero_alunos;i++){
            printf("%s: ",turmas[b].aluno[i].nome);
            scanf("%f",&turmas[b].aluno[i].np2);
            turmas[b].auxnp2=1;//aumentando a auxiliar para utilizar nas funçoes que utilizam as notas
        }
    }
    else{
        printf("Numero incorreto,voltando ao menu principal...\n");
        Sleep(2000);//funçao para travar o terminal, 2000 significa 2 segundos(tive que incluir a biblioteca <windows.h> para poder fazer isso.
    }
    system("cls");
}
void calcular_medias(TURMA turmas[]){
    int i,j;
    for(i=0;i<n;i++){//numero de turmas sendo usado pra auxiliar
        if(turmas[i].auxnp1==1 && turmas[i].auxnp2==1){//auxiliares que so validam a operaçao caso ja tenha sido colocado as notas
            for(j=0;j<turmas[i].numero_alunos;j++){
                turmas[i].aluno[j].media=(turmas[i].aluno[j].np1+turmas[i].aluno[j].np2)/2;

            }
        }
        else{
            printf("Notas faltando, favor registrar notas para a turma %d e retornar\n",i);
        }
    }
    system("cls");//funçao para windows, pois no linux e system("clear")
}
void encerrar_diario(TURMA turmas[]){
    int i,j;
    system("cls");
    for(i=0;i<n;i++){
        if(turmas[i].auxnp1==1 && turmas[i].auxnp2==1){//novamente utilizando as auxiliares quando for necessario das notas
            printf("Turma %d:\n",i);
            for(j=0;j<turmas[i].numero_alunos;j++){
                if(turmas[i].aluno[j].media>=6){
                    printf("-%s:APROVADO\tMEDIA FINAL:%.1f\n",turmas[i].aluno[j].nome,turmas[i].aluno[j].media);
                }
                else{
                 printf("-%s:REPROVADO\tMEDIA FINAL:%.1f\n",turmas[i].aluno[j].nome,turmas[i].aluno[j].media);
                }
            }
        }
        else{
            printf("NOTAS FALTANDO PARA A TURMA %d\n",i);//caso n exista notas registradas
        }
    }

    while(1){
        printf("Digite 1 para sair\n");//preferi fazer assim,ao inves do sleep, para ficar mais facil caso a pessoa queira ler oque escreveu antes
        scanf("%d",&i);
        if(i==1){
            break;
        }
    }
    system("cls");
}
void listar_alunos(TURMA turmas[]){
    int i,j;
    system("cls");
    for(i=0;i<n;i++){
        printf("Turma %d\t Componente: %s",i,turmas[i].componente);
        for(j=0;j<turmas[i].numero_alunos;j++){
            printf("-%s\n",turmas[i].aluno[j].nome);
        }
    }
    while(1){
        printf("Digite 1 para sair\n");
        scanf("%d",&i);
        if(i==1){
            break;
        }
    }
    system("cls");
}
void exibir_turmas(TURMA turmas[]){
    int i,a;
    system("cls");
    if(n!=0){
        printf("Qual turma voce deseja visualizar?\n");
        for(i=0;i<n;i++){
            printf("\tTurma %d:\n",i);
        }
        scanf("%d",&a);
        system("cls");
        printf("Turma %d:\n",a);
        printf("Componente: %s\n",turmas[a].componente);
        printf("Fase: %d\n",turmas[a].fase);
        printf("Dia das aulas: %s",turmas[a].diaaula);
        printf("Horario inicial: %d h\nHorario final: %d h\n",turmas[a].horario_inicial,turmas[a].horario_final);
    }
    while(1){
        printf("Digite 1 para sair\n");
        scanf("%d",&i);
        if(i==1){
            break;
        }
    }
    system("cls");
}
void notas_parciais(TURMA turmas[]){
    int i,j;
    system("cls");
    for(i=0;i<n;i++){
            printf("Turma %d:\n",i);
            for(j=0;j<turmas[i].numero_alunos;j++){
                if(turmas[i].auxnp1==1){//auxiliares usadas para identificar quais notas ja foram colocadas
                    printf("-%s \tNP1=%.1f\t",turmas[i].aluno[j].nome,turmas[i].aluno[j].np1);
                }
                else{
                     printf("-%s \tNP1=NAO REGISTRADA\t",turmas[i].aluno[j].nome,turmas[i].aluno[j].np1);
                }
                if(turmas[i].auxnp2==1){
                    printf("NP2=%.1f\n",turmas[i].aluno[j].np2);
                }
                else{
                    printf("NP2=NAO REGISTRADA\n");
                }
    }
    }
    while(1){
        printf("Digite 1 para sair\n");
        scanf("%d",&i);
        if(i==1){
            break;
        }
    }
    system("cls");
}
void notas_finais(TURMA turmas[]){
    int i,j;
    system("cls");
        for(i=0;i<n;i++){
        if(turmas[i].auxnp1==1 && turmas[i].auxnp2==1){
            printf("Turma %d:\n",i);
            for(j=0;j<turmas[i].numero_alunos;j++){
                printf("--%s\tMEDIA: %.1f\n",turmas[i].aluno[j].nome,turmas[i].aluno[j].media);
            }
        }
        else{
            printf("Notas incompletas para a turma %d\n",i);
        }
    }
    while(1){
        printf("Digite 1 para sair\n");
        scanf("%d",&i);
        if(i==1){
            break;
        }
    }
    system("cls");


}

int main(void){
    TURMA turmas[20];
    int a;//variavel para o case
    do{
    printf("\t\t\tPORTAL DO PROFESSOR\n");
    printf("\t\tMENU PRINCIPAL\n");
    printf("1-Cadastrar Turmas\n");
    printf("2-Cadastrar alunos\n");
    printf("3-Inserir notas\n");
    printf("4-Calcular medias\n");
    printf("5-Encerrar diario\n");
    printf("6-Listar alunos\n");
    printf("7-Exibir turmas\n");
    printf("8-Exibir notas parciais\n");
    printf("9-Exibir notas finais\n");
    printf("0- PARA SAIR\n");
    scanf("%d",&a);
    switch (a){
        case 1:
            cadastra_turma(turmas);
            break;
        case 2:
            cadastra_aluno(turmas);
            break;
        case 3:
            inserir_notas(turmas);
            break;
        case 4:
            calcular_medias(turmas);
            break;
        case 5:
            encerrar_diario(turmas);
            break;
        case 6:
            listar_alunos(turmas);
            break;
        case 7:
            exibir_turmas(turmas);
            break;
        case 8:
            notas_parciais(turmas);
            break;
        case 9:
            notas_finais(turmas);
            break;
        case 0:
            break;
        default:
            printf("Valor invalido\n");
            system("cls");
            break;

    }
    }while(a!=0);
    return 0;


}

