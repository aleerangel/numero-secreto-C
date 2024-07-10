//incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //cabeçalho
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    //escolhendo a dificuldade
    int nivel;
    do {
        printf("Qual o nível de dificuldade?\n");
        printf("(1) Fácil (2) Médio (3) Difícil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);
        if (nivel < 1 || nivel > 3) {
            printf("Insira um nível válido!\n");
        }
    } while (nivel < 1 || nivel > 3);
    
    int numerodetentativas;
    double pontuador;
    if (nivel == 1) {
        numerodetentativas = 18;
        pontuador = 2;
    } else if(nivel == 2) {
        numerodetentativas = 12;
        pontuador = 4;
    } else if(nivel == 3) {
        numerodetentativas = 6;
        pontuador = 6;
    } else {
        printf("Insira um nível válido!");
        return 1;
    }

    //gerando numero secreto aleatorio 
    int semente = time(0);
    srand(semente);
    int numerosecreto = rand() % 100;

    //declarando variaveis que serao usadas mais tarde
    int chute;
    int tentativa = 1;
    double pontuacao = 1000;
    int acertou = 0;

    //loop principal
    for(int i = 0; i < numerodetentativas; i++) {
        printf("Tentativa %d\n", tentativa);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
        if(chute < 0) {
            printf("Insira um número válido!\n");
            continue;
        }
        if(acertou) {
            break;
        }
        else if(maior) {
            printf("O número secreto é menor que %d\n", chute);
        }
        else {
            printf("O número secreto é maior que %d\n", chute);
        }
        //contador de tentativas usadas
        tentativa++;
        //calcula a quantidade de pontos
        pontuacao = pontuacao - (abs(chute - numerosecreto) / pontuador);
        if(pontuacao < 0) {
            pontuacao = 0;
        }
    }
    printf("Fim de jogo!\n");
    //mensagem de vitoria ou derrota
    if(acertou) {
        printf("\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
        printf("Você ganhou!\n");
        printf("Parabéns! Você acertou o número secreto %d em %d tentativas!\n", numerosecreto, tentativa);
        printf("Pontuação: %.1f\n", pontuacao);
    } else {
        printf("\n\n");
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");
        printf("\n\n");
        printf("Você perdeu!\n");
        printf("O número secreto era %d!\n", numerosecreto);
        printf("Tente de novo!\n");
    }
    return 0;
}