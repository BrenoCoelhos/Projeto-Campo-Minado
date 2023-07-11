#include <stdio.h>
#include <windows.h>
// Prot�tipos:
int gerar_campo_minado(); // Gera e mostra campo minado com valores ocultos, caso sua ativa��o seja status = "falsa":
int verificar_ativacao(); // Se ativa��o for status = "verdadeira", atualiza campo_2:
int mostra_campo_minado();// Imprime o campo atualizado...
int Campo_1[10][10]; // Armazena valores gerados de 0 a 5...
int Campo_2[10][10]; // Armazena os STATUS (ativado (1), desativado (0))...

int main()
{
    int a;
    gerar_campo_minado();
    mostra_campo_minado();
    verificar_ativacao();
    system("cls");
    printf("\n\n");
    printf(" Menu:\n");
    printf("1.Iniciar jogo\n"); //Reinicia campo minado...
    printf("2.Continuar\n"); //Continua o campo minado antes da utima a��o...
    printf("3.Sair\n"); //Para o jogo...
    printf("Menu: ");
    scanf("%d", &a);
    if( a == 1)
    {
        for(int x=0; x<10 ; x++)
        {
            for(int y=0; y<10 ; y++)
            {
                Campo_2[x][y] = 0;
            }
        }
        main();
    }
    if( a == 2)
    {
        main();
    }
    if( a == 3)
    {
        system("exit");
    }
    system("exit");
}
// Se o status for ATIVADO (1), atualiza Campo minado mostrando valor...
// Se o valor da coordenada for ZERO (0), ent�o voc� encontrou uma mina...
int verificar_ativacao()
{
    int x, y;
    do
    {
        printf("\n Coordenada: ");
        scanf("%d %d", &x, &y);
        if(x > 8 || x < 0)
        {
            printf("\n VALOR INVALIDO! ");
            Sleep(2000);
            system("cls");
            mostra_campo_minado();
        }
        else if(Campo_1[x][y] > 0 && Campo_1[x][y] < 5)
        {
            Campo_2[x][y] = 1;
            system("cls");
            main();
        }
        else if(Campo_1[x][y] == 0)
        {
            printf("\n\n    BOOOM !!!");
            system("cls");
            break;
        }
    }
    while(1);
    printf("\n\n");
    printf("        BOOM !!!   \n");
    printf("        BOOM !!!   \n");
    printf("        BOOM !!!   \n");
    printf("        BOOM !!!   \n");
    Sleep(2000);
}
// Imprime Campo minado na tela...
int mostra_campo_minado()
{
    system("cls");
    printf("\n\n");
    printf("        1  2  3  4  5  6  7  8 \n");
    for(int x=0 ; x<10 ; x++)
    {
        if( x > 0 && x <9)
        {
            printf("  %d ", x);
        }
        else
        {
            printf("    ");
        }
        for(int y=0 ; y<10 ; y++)
        {
            if(Campo_1[x][y] == 8)
            {
                putchar(219);
                putchar(219);
                putchar(219);
            }
            else if(Campo_2[x][y] == 1)
            {
                putchar(32);
                printf("%d", Campo_1[x][y]);
                putchar(32);
            }
            else
            {
                putchar(32);
                putchar('*');
                putchar(32);
            }
        }
        Sleep(20);
        printf("\n");
    }
}
// Gera Valores aleat�rios para o campo minado...
int para=0;
int gerar_campo_minado()
{
    if(para == 0)
    {
        for(int x=0 ; x <10 ; x++)
        {
            for(int y=0 ; y <10 ; y++)
            {
                Campo_1[x][y] = rand()%5;
                if( x == 0 || x == 9 || y == 0 || y == 9)
                {
                    Campo_1[x][y] = 8;
                }
            }
        }
    }
    para++;
}
