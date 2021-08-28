#include "FUNCOES.h"

int main()
{system("mode con:cols=90 lines=70");
    //LINGUAGEM LOCAL (PORTUGUES)
    setlocale(LC_ALL,"Portuguese");
    // DECLARAÇÃO DE VARIAVEIS
    int jogador=0,termino_jogo=100;
    int jogY,jogX,pc;
    int tamX,tamY;
    int ***tabuleiro;
    char continuar_jogo,temp;
    int jogx_ant=NULL,jogy_ant=NULL;
    srand(time(NULL));
    DADOS pessoa1,pessoa2;

    //CÓDIGO --------------------------------------------------------------------------------------------------------------------
    do{
        printf("NOVO JOGO!\n\n\n");
        printf("VAMOS JOGAR?\n");
        printf("1: PARA JOGADOR X COMPUTADOR\n2: PARA JOGADOR X JOGADOR\n\n");
        scanf("%i",&pc);
        if(pc!=1) pc=0;


        printf("DIGITE O NOME DO PLAYER 1: ");
        //strcpy(pessoa1.nome_jogador,"VINICIUS");
        scanf(" %s",pessoa1.nome_jogador);
        if(pc==1){
            strcpy(pessoa2.nome_jogador,"COMPUTADOR");
        }
        else {
        printf("\nDIGITE O NOME DO PLAYER 2: ");
        scanf(" %s",pessoa2.nome_jogador);
        }
        system("cls\n\n");
        do{
        printf("\nDIGA O TAMANHO DO TABULEIRO? EXEMPLO (X Y) : ");//TAMANHO DO TABULEIRO
        scanf(" %i %i",&tamX,&tamY);
        system("cls\n");
        if(tamX<8||tamY<8) printf("\nINFELIZMENTE COM TAMANHO MENOR QUE 8 NAO FICA POSSIVEL ALOCAR OS BARCOS.\nDIGA OUTRO TAMANHO ACIMA DE 8\n");
        if(tamX>26||tamY>26) printf("\nINFELIZMENTE COM TAMANHO MAIOR QUE 26 NAO FICA POSSIVEL ALOCAR OS BARCOS.\nDIGA OUTRO TAMANHO ACIMA DE 8\n");

        }while(tamX<8||tamY<8||tamX>26||tamY>26);// VERIFICA SE O TAMANHO ESTA ENTRE 8 E 26
        tamX++;//ADICIONA PRA NAO ATRAPALHAR NA BORDA
        tamY++;


        // CRIAR TABULEIRO POR PARAMETRO

        tabuleiro=criar_tab(tamX,tamY);
        system("cls");

        // MOSTRA MODELO DO TABULEIRO
        mostrar_tab_real(tabuleiro,tamX,tamY,jogador);

/**<    ALOCAR NAVIO JOGADOR 1                                                            */
        printf("ALOCAR NAVIOS DO JOGADOR %s\n\n",pessoa1.nome_jogador);
        criar_nav(tabuleiro,jogador,tamX,tamY,0);
        system("pause");
        system("cls");
        jogador++;

/**<   ALOCAR NAVIO JOGADOR 2                                                 */
        printf("ALOCAR NAVIOS DO JOGADOR %s\n\n",pessoa2.nome_jogador);
        criar_nav(tabuleiro,jogador,tamX,tamY,pc);
        system("pause");
        system("cls");
        jogador--;




/*   AQUI COMEÇA O LAÇO DO JOGO */
        while(10){

            //JOGADOR =  1
           // if(jogador==0){
            printf("\n %s, É A SUA VEZ\n\n",pessoa1.nome_jogador);
            jogador++;
            printf("ESSE É TABULEIRO DO  %s : \n\n",pessoa2.nome_jogador);
            mostrar_tab_virtual(tabuleiro,tamX,tamY,jogador);// MOSTRA TAB VIRTUAL DO JOGADOR 2
            printf("\n\nQUAL A CORDENADA (LETRA NÚMERO) QUE VAI BOMBARDEAR?\n\n ");
          //  if(pc==1){
          //      jogX=1+rand()%(1-tamX);
          //      jogY=1+rand()%(1-tamY);
          //      printf("\n\n %c %i\n\n",jogY+64,jogX);
           //     system("pause");
           // }
           // else{
                scanf(" %c %i",&temp,&jogX);
                jogY=converte(temp);
           // }
            if (termino_jogo==verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,0)) break;// SE VERIFICA RETORNAR 100. PARA O JOGO

            system("pause");
            system("cls");
            //}
            //JOGADOR =  2
            printf("\nÉ A VEZ DO %s \n",pessoa2.nome_jogador);
            jogador--;
            printf("ESSE É MAR DO JOGADOR %s : \n\n",pessoa1.nome_jogador);
            mostrar_tab_virtual(tabuleiro,tamX,tamY,jogador);// MOSTRA O TAB VIRTUAL DO JOGADOR 1
            printf("\n\nQUAL A CORDENADA (LETRA NÚMERO) QUE VAI BOMBARDEAR?\n\n ");
            if(pc==1){   // PC JOGANDO
                    if(tabuleiro[jogador][jogx_ant][jogy_ant]==2){
                            jogX=jogx_ant;
                            jogY=jogy_ant;
                        do{
                                if(rand()%2==0){//numero entre 0 e 1
                                    if(rand()%2==0){// RANDOM NUMERO PAR  diminui um da jogada do pc
                                        jogX--;
                                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX-- JA TENHA SIDO ACERTADO
                                            jogX--;
                                        }
                                        if(jogX<1||tabuleiro[jogador][jogX][jogY]==2) jogX+=1; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                                        while(tabuleiro[jogador][jogX][jogY]==2){
                                            jogX++;
                                        }
                                    }
                                    else {// --> 1 RANDO NUMERO IMPAR
                                        jogX++;
                                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX++ JA TENHA SIDO ACERTADO
                                            jogX++;
                                        }
                                        if(jogX>=tamX||tabuleiro[jogador][jogX][jogY]==2) jogX-=1; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
                                        while(tabuleiro[jogador][jogX][jogY]==2){
                                                jogX--;
                                        }
                                    }
                                }else{ //---> RANDO NUMERO IMPAR
                                    if(rand()%2==0){  // RANDO NUMERO PAR
                                        jogY--;
                                        while(tabuleiro[jogador][jogX][jogY]==2){// VOLTA, CASO JOGY-- JA TENHA SIDO ACERTADO
                                            jogY--;
                                        }
                                        if(jogY<1||tabuleiro[jogador][jogX][jogY]==2) jogY+=1; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                                        while(tabuleiro[jogador][jogX][jogY]==2){
                                                jogY++;
                                        }
                                    }
                                    else { //RANDO NUMERO IMPAR
                                        jogY++;
                                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGY++ JA TENHA SIDO ACERTADO
                                            jogY++;
                                        }
                                        if(jogY>=tamY||tabuleiro[jogador][jogX][jogY]==2) jogY-=1; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
                                        while(tabuleiro[jogador][jogX][jogY]==2){
                                                jogY--;
                                        }
                                    }
                                }
                        }while(tabuleiro[jogador][jogX][jogY]==-1||tabuleiro[jogador][jogX][jogY]==2);
                                jogx_ant=jogX;
                                jogy_ant=jogY;
                        printf("\n\n %c %i\n\n",jogY+64,jogX);
                        system("pause");
                    }
                    else{
                        do{
                            jogX=1+rand()%(1-tamX);
                            jogY=1+rand()%(1-tamY);
                        }while(tabuleiro[jogador][jogX][jogY]==-1||tabuleiro[jogador][jogX][jogY]==2);
                        jogx_ant=jogX;
                        jogy_ant=jogY;
                    printf("\n\n %c %i\n\n",jogY+64,jogX);
                    system("pause");

                }
            }
            else {   // PESSOA JOGANDO
                scanf(" %c %i",&temp,&jogX);
                jogY=converte(temp);
            }
            if (termino_jogo==verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,pc)) break;//SE VERIFICA RETORNANR 100, PARA O JOGO

            system("pause");
            system("cls");

        }//<<<----- FIM DO LAÇO DAS JOGADAS
        printf("\n\n\n\nDESEJA JOGAR NOVAMENTE?\n S: PARA SIM\nN: PARA NAO\n");// CONDIÇÃO PARA NOVO JOGO
        scanf(" %c",&continuar_jogo);
        system("cls");

    }
    while(continuar_jogo=='s'||continuar_jogo=='S');  // -->> LAÇO PARA RODAR O JOGO NOVAMENTE.

    creditos();
    return 0;
}

