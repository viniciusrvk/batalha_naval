#include "FUNCOES.h"


// CONVERTE DE LETRA PRA NUMERO
int converte( char posx){/**<                                                                                                                           */
    // FUNÇÃO MUDA: MUDA A LETRA PRA UM NUMERO

    int x;
    if(posx>64&&posx<96) x=posx-64;
    else if(posx>96&&posx<123) x=posx-96;
    return x;
}

// CRIA E RETORNA TABULEIRO
int* criar_tab(int tamX,int tamY){ /**<                                                                                                          */

    /*CRIAR_TAB: --->CRIAR TABULEIROS

    FLUXOGRAMA:
    1: FAZ ALOCAÇÃO DINAMICA DE 2 TABULEIROS:
       1º TABULEIRO DO JOGADOR 1
       2º TABULEIRO DO JOGADOR 2
    2: RETORNA O TAB

     OK
    */

    int i,j,k, ***tabuleiro;
    tamX++;/**< UM A MAIS PRA NA HORA DE VERIFICAR NAO DAR ERRO */
    tamY++;
    tabuleiro=(int***)malloc(2*sizeof(int**));
    for(i=0; i<2; i++){
        tabuleiro[i]=(int**)malloc(tamX*sizeof(int*));
        for(j=0; j<tamX; j++){
            tabuleiro[i][j]=(int*)malloc(tamY*sizeof(int));
            for(k=0; k<tamY; k++){
                tabuleiro[i][j][k]=0;
            }
        }
    }
return (int*)tabuleiro;
}

// VERIFICA TIRO
int verifica_jogada(int*** tabuleiro,int jogX,int jogY,int tamX,int tamY,int jogador, int pc){/**<                                                                                        */
    /* FUNÇÃO VERIFICA A JOGADA DO TIRO---> RECEBE UMA JOGADA E VERIFICA SE ACERTOU OU NAO
                                        ---> VERIFICA SE GANHOU OU NAO
    FLUXOGRAMA:
    1: VERIFICA SE TEM O VALOR '1' DENTRO DA CELULA
        MUDA O VALOR DA CELULA PARA 2
        RETORNA ACERTOU
            VERIFICA SE ACERTOU TODOS OS NAVIOS FAZENDO UM LAÇO E CONTANDO QUANTOS '2' TEM NO TABULEIRO
            SE A QUANTIDADE FOR IGUAL A VARIAVEL 'VENCEU'
                RETORNA 100 PARA O GANHADOR

    2: SE NAO (1), VERIFICA SE JA JOGOU NAQUELA POSIÇÃO
        RETORNA 'VOCE JA JOGOU AQUI'

    3: SE NAO (1) E (2), IMPRIME AGUA
        RETORNA 10 PARA CONTINUAR O JOGO*/

    int vencer=20/*MODIFICAVEL PARA TESTE*/,i,j,ganhou=0;
    char temp;
    // VERIFICA JOGADA DENTRO DO TAB
    if(jogX>=tamX||jogY>=tamY||jogX==0||jogY==0){
        system("cls");
        printf("\nJOGADA INVALIDA\nVAMOS TENTAR NOVAMENTE.");
        printf("\n\nQUAL A CORDENADA (LETRA NÚMERO) QUE VAI BOMBARDEAR?\n\n ");
        if(pc==1){//JOGADA DO PC GEOGRAFICAMENTE PROXIMO
            do{
                if(rand()%2==0){//numero entre 0 e 1
                    if(rand()%2==0){// RANDOM NUMERO PAR  diminui um da jogada do pc
                        jogX--;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX-- JA TENHA SIDO ACERTADO
                            jogX--;
                        }
                        if(jogX<1||tabuleiro[jogador][jogX][jogY]==2) jogX+=2; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                            jogX++;
                        }
                    }
                    else {// --> 1 RANDO NUMERO IMPAR
                        jogX++;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX++ JA TENHA SIDO ACERTADO
                            jogX++;
                        }
                        if(jogX>=tamX||tabuleiro[jogador][jogX][jogY]==2) jogX-=2; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
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
                        if(jogY<1||tabuleiro[jogador][jogX][jogY]==2) jogY+=2; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                                jogY++;
                        }
                    }
                    else { //RANDO NUMERO IMPAR
                        jogY++;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGY++ JA TENHA SIDO ACERTADO
                            jogY++;
                        }
                        if(jogY>=tamY||tabuleiro[jogador][jogX][jogY]==2) jogY-=2; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                                jogY--;
                        }
                    }
                }
            }while(tabuleiro[jogador][jogX][jogY]==-1||tabuleiro[jogador][jogX][jogY]==2);

                printf("\n\n %c %i\n\n",jogY+64,jogX);
                system("\npause");
            if(100==verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,pc)){
                return 100;
            }
        }
        else{
            scanf(" %c %i",&temp,&jogX);
            jogY=converte(temp);}
            i=verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,pc);
    }
    else if((tabuleiro[jogador][jogX][jogY])==1){//CONDIÇÃO PARA ACERTOUU
        system("cls");
        printf("\n\nACERTOU!\n\n");
        tabuleiro[jogador][jogX][jogY]=2;
        mostrar_tab_virtual(tabuleiro,tamX,tamY,jogador);
        for(i=0; i<tamX; i++){// LAÇOM PARA VER SE GANHOU
            for(j=0; j<tamY; j++){
                if(tabuleiro[jogador][i][j]==2) ganhou++;
            }
            if(vencer==ganhou){

                    printf("\n   GGGGGGGG   AAAA   NNN   NN  HH  HH  OOOOOO  UU  UU  !!");
                    printf("\n   GG        AA  AA  NNNN  NN  HH  HH  OO  OO  UU  UU  !!");
                    printf("\n   GG   GGG  AAAAAA  NN NN NN  HHHHHH  OO  OO  UU  UU  !!");
                    printf("\n   GG    GG  AA  AA  NN  NNNN  HH  HH  OO  OO  UU  UU    ");
                    printf("\n   GGGGGGGG  AA  AA  NN   NNN  HH  HH  OOOOOO  UUUUUU  !!\n");
                    printf("\n  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO !!");
                    printf("\n  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO !!");
                    printf("\n  OOOOOOO                                      OOOOOOO !!");
                    printf("\n  OOOOOO                  O                     OOOOOO !!");
                    printf("\n  OOOOO                  OOO                     OOOOO !!");
                    printf("\n  OOOO                 OOOOOOO                    OOOO !!");
                    printf("\n  OOO                OOOOOOOOOOO                   OOO !!");
                    printf("\n  OO        OOOOOOOOOOOOOOOOOOOOOOOOOOOOO           OO !!");
                    printf("\n  O            OOOOOOOOOOOOOOOOOOOOOOO               O !!");
                    printf("\n  OO              OOOOOOOOOOOOOOOOO                 OO !!");
                    printf("\n  OOO                OOOOOOOOOOO                   OOO !!");
                    printf("\n  OOOO              OOOOO   OOOOO                 OOOO !!");
                    printf("\n  OOOOO            OOOO       OOOO               OOOOO !!");
                    printf("\n  OOOOOO          OO             OO             OOOOOO !!");
                    printf("\n  OOOOOOO        O                 O          OOOOOOOO !!");
                    printf("\n  OOOOOOOO                                   OOOOOOOOO !!");
                    printf("\n  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO !!");
                    printf("\n  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO !!\n\n");
               system("\npause");
                return 100;
            }
        }
        printf("VOCÊ ACERTOU. JOGUE NOVAMENTE\n");
        printf("\n\nQUAL A CORDENADA (LETRA NÚMERO) QUE VAI BOMBARDEAR?\n\n ");//RECURSAO PARA JOGAR NOVAMENTE
        if(pc==1){//JOGADA DO PC GEOGRAFICAMENTE PROXIMO
            do{
                if(rand()%2==0){//numero entre 0 e 1
                    if(rand()%2==0){// RANDOM NUMERO PAR  diminui um da jogada do pc
                        jogX--;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX-- JA TENHA SIDO ACERTADO
                            jogX--;
                        }
                        if(jogX<1||tabuleiro[jogador][jogX][jogY]==2) jogX+=2; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                            jogX++;
                        }
                    }
                    else {// --> 1 RANDO NUMERO IMPAR
                        jogX++;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGX++ JA TENHA SIDO ACERTADO
                            jogX++;
                        }
                        if(jogX>=tamX||tabuleiro[jogador][jogX][jogY]==2) jogX-=2; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
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
                        if(jogY<1||tabuleiro[jogador][jogX][jogY]==2) jogY+=2; // SE DIMINUIU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                                jogY++;
                        }
                    }
                    else { //RANDO NUMERO IMPAR
                        jogY++;
                        while(tabuleiro[jogador][jogX][jogY]==2){ // VOLTA, CASO JOGY++ JA TENHA SIDO ACERTADO
                            jogY++;
                        }
                        if(jogY>=tamY||tabuleiro[jogador][jogX][jogY]==2) jogY-=2; // SE AUMENTOU DEMAIS, PASSA A AUMETAR
                        while(tabuleiro[jogador][jogX][jogY]==2){
                                jogY--;
                        }
                    }
                }
            }while(tabuleiro[jogador][jogX][jogY]==-1||tabuleiro[jogador][jogX][jogY]==2);

                printf("\n\n %c %i\n\n",jogY+64,jogX);
                system("\npause");
            if(100==verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,pc)){
                return 100;
            }
        }//FIM JOGADA PC
        else {//JOGADA JOGADOR
            scanf(" %c %i",&temp,&jogX);
            jogY=converte(temp);
            i=verifica_jogada(tabuleiro,jogX,jogY,tamX,tamY,jogador,pc);
        }
    }
    else if(tabuleiro[jogador][jogX][jogY]==-1||tabuleiro[jogador][jogX][jogY]==2){//TESTE DE JA JOGOU NA POSIÇAO
        system("cls");
        printf("\n\nVOCE JA JOGOU AQUI!\n");
        printf("DISPERDICOU UM TIRO. AGORA SÓ MA PÓOXIMA JOGADA.\n\n\n");
    }
    else{//ERROU TIRO
        system("cls");
        printf("\n\nAGUA!\n\n");
        tabuleiro[jogador][jogX][jogY]=-1;
        mostrar_tab_virtual(tabuleiro,tamX,tamY,jogador);
    }
    return i;
}

// MOSTRA TABULEIRO COM NAVIOS
void mostrar_tab_real(int*** tabuleiro,int tamX,int tamY,int jogador){/**<                                                                                                                  */
    /*  FUNÇÃO MOSTRA_TAB: MOSTRA O TABULEIRO*/
    // MOSTRA O TABULEIRO COM OS NAVIOS

    int j,k;

    printf("\n");

    for(j=0; j<tamX; j++)
    {
        if(j==0)
            printf("   ");
        else
            printf(" %2i ",j);
        for(k=1; k<tamY; k++)
        {
            if(j==0)
                printf("  %c ",k+64);
            else
                printf(" %i  ",tabuleiro[jogador][j][k]);
        }
        printf("\n");
    }
    printf("\n");
}

// MOSTRA TABULEIRO VIRTUAL
void mostrar_tab_virtual(int*** tabuleiro,int tamX,int tamY,int jogador){/**<                                                                                         */
    /*  FUNÇÃO MOSTRA_TAB: MOSTRA O TABULEIRO
    ------------> MOSTRA TABULEIRO DO OPONENTE ESCONDENDO OS NAVIOS NAO DESTRUIDOS AINDA
    ------------> MOSTRA TIROS NA AGUA E ACERTADOS*/

    int j,k;
    printf("\n");

    for(j=0; j<tamX; j++)
    {
        if(j==0)
            printf("  ");
        else
            printf("%2i ",j);
        for(k=1; k<tamY; k++)
        {
            if(j==0)
                printf(" %c ",k+64);
            else if (tabuleiro[jogador][j][k]==1) printf("%i  ",0);
            else if (tabuleiro[jogador][j][k]==-1) printf("~  ");
            else if (tabuleiro[jogador][j][k]==2) printf("%c  ",15);
            else printf("%i  ",tabuleiro[jogador][j][k]);
        }
        printf("\n");
    }
    printf("\n");
}

// CRIAR BARCOS
void criar_nav(int*** tabuleiro,int jogador,int tamX,int tamY,int pc){/**<                                                                    */

    /* FUNÇÃO CRIAR_NAV: FUNÇÃO PARA ALOCAR NAVIOS NOS TABULEIROS DOS JOGADORE
                        ----> RECEBE TABULEIRO E JOGADOR

    FLUXOGRAMA:
    1: RECEBE TABULEIRO, TAMANHO E QUEM TA JOGANDO
    2: TESTA A ALOCAÇÃO
    3: ALOCA RECURSIVAMENTE
*/

    char sentido,temp;
    int x,y,nav,i,direcao;

    // NAVIOS = PORTAAVIAO;

    printf("  Voce tem 10 embarcaçoes:\n");
    printf("  UM PORTA AVIÃO\n  DOIS FRAGATAS\n  TRÊS ENCOURAÇADOS\n  QUATRO SUBMARINOS\n");

    for(nav=4; nav>=1; nav--){
        // PORTA-AVIOES
        if(nav==PORTAAVIAO){
            for(i=0; i<1; i++){
                if(pc==0)printf("\n\n  VAMOS ALOCAR O PORTA AVIÃO\n\n");
                if(pc==0)printf("  QUAL A POSIÇÃO <LETRA NUMERO> QUE DESEJA ALOCAR?  \n");
                if(pc==1){
                    x=1+rand()%(tamX-1);
                    y=1+rand()%(tamY-1);
                    direcao=rand()%4;
                    if(direcao==NORTE) sentido='N';
                    else if(direcao==SUL) sentido='S';
                    else if(direcao==DIREITA) sentido='D';
                    else if(direcao==ESQUERDA) sentido='E';

                   // printf("\n\n %c %i %c\n\n",y+64,x,sentido);
                    //system("\npause");
                }
                if(pc==0){
                    scanf(" %c %i",&temp,&x);
                    y=converte(temp);
                    printf("\n\n  EM QUAL DIREÇÃO DESEJA ALOCAR?\n  N: PARA CIMA\n  S: PARA BAIXO\n  E: PARA ESQUERDA\n  D: PARA DIREITA\n  QUERO COLOCAR NA DIREÇÃO ");
                    scanf(" %c",&sentido);
                    system("cls");
                }
                if(teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,PORTAAVIAO,pc)==0){
                    i--;
                    system("cls");
                   if(pc==0) printf("\n      ---- ERRO!!! ---\n\n");
                    teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,PORTAAVIAO,pc);// IMPRIME O ERRO.
                    if(pc==0)  mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }else{
                    //aloc_nav(tabuleiro,x,y,sentido,jogador,PORTAAVIAO/*USAR ENUM*/);
                    alocar_nav(tabuleiro,x,y,jogador,sentido,PORTAAVIAO);// ALOCAÇAO RECURSIVA ;)
                   // system("cls");
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }
            }
        }

        // FRAGATA
        if(nav==FRAGATA){
            for(i=0; i<2; i++){
              if(pc==0)  printf("\n  VAMOS ALOCAR AS FRAGATAS\n\n");
               if(pc==0) printf("  QUAL A POSIÇÃO < LETRA NUMERO > QUE DESEJA ALOCAR?  ");
                if(pc==1){
                    x=1+rand()%(1-tamX);
                    y=1+rand()%(1-tamY);
                    direcao=rand()%4;
                    if(direcao==NORTE) sentido='N';
                    else if(direcao==SUL) sentido='S';
                    else if(direcao==DIREITA) sentido='D';
                    else if(direcao==ESQUERDA) sentido='E';
                    //printf("\n %c %i %c\n",y+64,x,sentido);
                    //system("\npause");
                }
                if(pc==0){
                    scanf(" %c %i",&temp,&x);
                    y=converte(temp);
                    printf("\n\nEM QUAL DIREÇÃO DESEJA ALOCAR?\nN: PARA CIMA\nS: PARA BAIXO\nE: PARA ESQUERDA\nD: PARA DIREITA\nQUERO COLOCAR NA DIREÇÃO ");
                    scanf(" %c",&sentido);
                }
                if(teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,FRAGATA,pc)==0){
                    i--;
                    system("cls");
                   if(pc==0) printf("\n      ---- ERRO!!! ---\n\n");
                    teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,FRAGATA,pc);
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }
                else{
                    //aloc_nav(tabuleiro,x,y,sentido,jogador,FRAGATA);
                    alocar_nav(tabuleiro,x,y,jogador,sentido,FRAGATA);// ALOCAÇAO RECURSIVA ;)
                    system("cls\n");
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }
            }
        }

        // ENCOURAÇADO
        if(nav==ENCOURACADO){
            for(i=0; i<3; i++){
           if(pc==0)    printf("\n  VAMOS ALOCAR OS ENCOURAÇADOS\n\n");
              if(pc==0)  printf("  QUAL A POSIÇÃO < LETRA NUMERO > QUE DESEJA ALOCAR?  ");
                if(pc==1){
                    x=1+rand()%(1-tamX);
                    y=1+rand()%(1-tamY);
                    direcao=rand()%4;
                    if(direcao==NORTE) sentido='N';
                    else if(direcao==SUL) sentido='S';
                    else if(direcao==DIREITA) sentido='D';
                    else if(direcao==ESQUERDA) sentido='E';
                    //printf("\n %c %i %c\n",y+64,x,sentido);
                    //system("\npause");
                }
                if(pc==0){
                    scanf(" %c %i",&temp,&x);
                    y=converte(temp);
                    printf("\n\nEM QUAL DIREÇÃO DESEJA ALOCAR?\nN: PARA CIMA\nS: PARA BAIXO\nE: PARA ESQUERDA\nD: PARA DIREITA\nQUERO COLOCAR NA DIREÇÃO ");
                    scanf(" %c",&sentido);
                }
                if(teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,ENCOURACADO,pc)==0){
                    i--;
                    system("cls");
                    if(pc==0)printf("\n      ---- ERRO!!! ---\n\n");
                    teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,ENCOURACADO,pc);
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                    //system("\n\npause");
                }
                else{
                    //aloc_nav(tabuleiro,x,y,sentido,jogador,FRAGATA);
                    alocar_nav(tabuleiro,x,y,jogador,sentido,ENCOURACADO);// ALOCAÇAO RECURSIVA ;)
                    system("cls\n");
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                    //system("\n\npause");
            }
            }
        }

        // SUBMARINO
        if(nav==SUBMARINO){
            for(i=0; i<4; i++)
            {
               if(pc==0) printf("\n  VAMOS ALOCAR O SUBMARINO\n\n");
                if(pc==0)printf("  QUAL A POSIÇÃO <LETRA NUMERO> QUE DESEJA ALOCAR?  ");
                if(pc==1){
                    x=1+rand()%(1-tamX);
                    y=1+rand()%(1-tamY);
                    direcao=rand()%4;
                    if(direcao==NORTE) sentido='N';
                    else if(direcao==SUL) sentido='S';
                    else if(direcao==DIREITA) sentido='D';
                    else if(direcao==ESQUERDA) sentido='E';
                    //printf("\n %c %i %c\n",y+64,x,sentido);
                    //system("\npause");
                }
                if(pc==0){
                    scanf(" %c %i",&temp,&x);
                    y=converte(temp);
//                    printf("\n\nEM QUAL DIREÇÃO DESEJA ALOCAR?\nN: PARA CIMA\nS: PARA BAIXO\nE: PARA ESQUERDA\nD: PARA DIREITA\nQUERO COLOCAR NA DIREÇÃO ");
//                    scanf(" %c",&sentido);
                    sentido='E';
                }
                if(teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,SUBMARINO,pc)==0){
                    i--;
                    system("cls");
                   if(pc==0) printf("\n      ---- ERRO!!! ---\n\n");
                    teste_aloc(tabuleiro,tamX,tamY,x,y,sentido,jogador,SUBMARINO,pc);
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }
                else{
                    //aloc_nav(tabuleiro,x,y,sentido,jogador,FRAGATA);
                    alocar_nav(tabuleiro,x,y,jogador,sentido,SUBMARINO);// ALOCAÇAO RECURSIVA ;)
                    system("cls\n");
                    if(pc==0) mostrar_tab_real(tabuleiro,tamX,tamY,jogador);
                   // system("\n\npause");
                }
            }
        }
    }

}

// TESTAR CONDIÇOES DE ALOCAR
int teste_aloc(int*** tabuleiro,int tamX,int tamY, int x,int y,char sentido,int jogador,int celulas,int pc){/**<                                                       */
   /* FAZ O TESTE PARA A ALOCAÇÃO DOS BARCOS
      TESTE FEITOS PARA CADA DIREÇÃO:
        -SE JA TEM ALGUM BARCO EM CELULAR ADJACENTES
        -SE ESTA TENTANDO ALOCAR FORA DO TABULEIRO
        -SE ESTA TENTANDO ALOCAR EM CIMA DE OUTRO BARCO*/

    int ok=1,i;
    if(sentido=='n'||sentido=='N'){
        for(i=0; i<celulas; i++){
            if(x>=tamX||y>=tamY||x-i==0||y==0){// verifica fora do tab
                   if(pc==0) printf("ALOCAÇÃO FORA DO TABULEIRO\n\n");
                return 0;}
            else if(tabuleiro[jogador][x-i-1][y]==1||tabuleiro[jogador][x+1][y]==1){// verifica as celulas acima de onde vai ser alocado o nav
               if(pc==0) printf("JA TEM UM NAVIO NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x-i][y+1]==1){// verifica as celulas a direita de onde vao ser alocadas
                  if(pc==0)  printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                    return 0;}
            else if(tabuleiro[jogador][x-i][y-i]==1){// verifica as celulas a esquerda de onde esta sendo alocadop nav
               if(pc==0) printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
        }
    }
    else if(sentido=='s'||sentido=='S'){
        for(i=0;i<celulas; i++){
            if(x+i>=tamX||y>=tamY||x==0||y==0){// verifica fora do tab
                  if(pc==0)  printf("ALOCAÇÃO FORA DO TABULEIRO\n\n");
                return 0;}
            else if(tabuleiro[jogador][x+i+1][y]==1||tabuleiro[jogador][x-1][y]==1){// verifica as celulas abaixo de onde esta sendo alocado o nav
              if(pc==0)  printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x+i][y-1]==1)  {// verifica as celulas a esquerda de onde esta sendo alocadop nav
               if(pc==0) printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x+i][y+1]==1){// verifica as celulas a direita de onde vao ser alocadas
                  if(pc==0)  printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                    return 0;}
        }
    }else if(sentido=='d'||sentido=='D'){
        for(i=0; i<celulas; i++){
            if(x>=tamX||y+i>=tamY||x==0||y==0){// verifica fora do tab
                  if(pc==0)  printf("ALOCAÇÃO FORA DO TABULEIRO\n\n");
                return 0;}
            else if(tabuleiro[jogador][x][y+i+1]==1||tabuleiro[jogador][x][y-1]==1){// verifica as celulas a direita de onde vao ser alocadas
                   if(pc==0) printf("JA TEM UM NAVIO NA POSIÇÃO \n\n");
                    return 0;}
            else if(tabuleiro[jogador][x+1][y+i]==1){// verifica as celulas abaixo de onde esta sendo alocado o nav
              if(pc==0)  printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x-1][y+i]==1){// verifica as celulas acima de onde vai ser alocado o nav
               if(pc==0) printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
        }
    }else if(sentido=='e'||sentido=='E'){
        for(i=0; i<celulas; i++){

            if(x>=tamX||y>=tamY||x==0||y-i==0){ // verifica fora do tab
               if(pc==0) printf("ALOCAÇÃO FORA DO TABULEIRO\n\n");
                return 0;}
            else if(tabuleiro[jogador][x][y-i-1]==1||tabuleiro[jogador][x][y+1]==1){// verifica as celulas a esquerda de onde esta sendo alocadop nav
               if(pc==0) printf("JA TEM UM NAVIO NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x-1][y-i]==1){// verifica as celulas acima de onde vai ser alocado o nav
               if(pc==0) printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
            else if(tabuleiro[jogador][x+1][y-i]==1){// verifica as celulas abaixo de onde esta sendo alocado o nav
              if(pc==0)  printf("NAVIO ADJACENTE NA POSIÇÃO \n\n");
                return 0;}
        }
    }
return ok;
}

//ALOCAR EMBARCAÇÕES RECURSIVAMENTE
void alocar_nav(int*** tabuleiro,int x,int y,int jogador,char sentido,int celulas){
    /* FAZ ALOCAÇÃO POR RECURSÃO
        IDENTIFICA SENTIDO E ALOCA DIMINUINDO/AUMENTANDO CONFORME A DIREÇÃO
        PARA QUANDO CELULAS CHEGAR A ZERO */

    if(sentido=='n'||sentido=='N'){
        if(celulas>0){
            tabuleiro[jogador][x][y]=1;
            alocar_nav(tabuleiro,x-1,y,jogador,sentido,celulas-1);
        }
    }else if(sentido=='s'||sentido=='S'){
        if(celulas>0){
            tabuleiro[jogador][x][y]=1;
            alocar_nav(tabuleiro,x+1,y,jogador,sentido,celulas-1);
        }
    }else if(sentido=='d'||sentido=='D'){
        if(celulas>0){
            tabuleiro[jogador][x][y]=1;
            alocar_nav(tabuleiro,x,y+1,jogador,sentido,celulas-1);
        }
    }else if(sentido=='e'||sentido=='E'){
        if(celulas>0){
            tabuleiro[jogador][x][y]=1;
            alocar_nav(tabuleiro,x,y-1,jogador,sentido,celulas-1);
        }
    }
}

// CREDITOS
void creditos(){/**<    NOMES DOS CRIADORES DO PROGRAMA                                                 */

   printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  CREDITOS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
   printf("\n\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  PRODUTORES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ANDRE LOURENÇO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ROBERTO VINICIUS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
   printf("\n\n");

}


