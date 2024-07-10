#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("****************************************\n");
    printf("*Bem vindo ao nosso jogo de adivinhação*\n");
    printf("****************************************\n");

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

    int semente = time(0);
    srand(semente);
    int numerosecreto = rand() % 100;

    int chute;
    int tentativa = 1;
    double pontuacao = 1000;
    int acertou = 0;

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

        tentativa++;
        pontuacao = pontuacao - (abs(chute - numerosecreto) / pontuador);
        if(pontuacao < 0) {
            pontuacao = 0;
        }
    }
    printf("Fim de jogo!\n");
    if(acertou) {
        printf("Você ganhou!\n");
        printf("Parabéns! Você acertou o número secreto %d em %d tentativas!\n", numerosecreto, tentativa);
        printf("Pontuação: %.1f\n", pontuacao);
    } else {
        printf("Você perdeu!\n");
        printf("O número secreto era %d!\n", numerosecreto);
        printf("Tente de novo!\n");
    }
}