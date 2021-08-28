#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
// ORIENTA PARA O PC EM QUAL SENTIDO JOGARÁ
typedef enum{
NORTE,SUL,DIREITA,ESQUERDA
}SENTIDO;
// REGISTRAR DADOS DO JOGADOR
typedef struct
{
    char nome_jogador[50];
    int idade;
} DADOS;
// CONSTANTE USADA PARA CRIAR BARCOS
typedef enum
{
    SUBMARINO=1,
    ENCOURACADO,
    FRAGATA,
    PORTAAVIAO
} NAVIOS;


void registrar(DADOS* nome_jogador,int pc);


int converte(char posx);

// FUNÇÃO PARA VERIFICAR A JOGADA
int verifica_jogada(int*** tabuleiro,int jogX,int jogY,int tamX,int tamY,int jogador,int pc);

// FUNÇAO PARA ALOCAR AS EMBARCAÇOES
void aloc_nav(int*** tabuleiro,int x,int y,char sentido,int jogador,int celulas);

// FUNÇÃO PARA CRIAR TABULEIRO
int* criar_tab(int tamX,int tamY);

// CRIA NAVIOS
void criar_nav(int*** tabuleiro,int jogador,int tamX, int tamY,int pc);

//MOSTRA TABULEIRO REAL COM NAVIOS ALOCADOS
void mostrar_tab_real(int*** tabuleiro,int tamX,int tamY,int jogador);
// MOSTRA TABULEIRO VIRTUAL(QUE ESCONDE ONDE OS NAVIOS ESTAO GUARDADOS)
void mostrar_tab_virtual(int*** tabuleiro,int tamX,int tamY,int jogador);
// FAZ TESTE ANTES DA ALOCAÇÃ
int teste_aloc(int*** tabuleiro,int tamX,int tamY, int x,int y,char sentido,int jogador,int celulas,int pc);
// FAZ ALOCAÇÃO
void alocar_nav(int*** tabuleiro,int x,int y,int jogador,char sentido,int celulas);
// CRIADORES DO PROGRAMA
void creditos();
