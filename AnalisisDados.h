#ifndef ANALISISDADOS_H_INCLUDED
#define ANALISISDADOS_H_INCLUDED

#include "GotoXY.h"

///FUNCIONES PUNTAJES
int CalcularBunco(int Dados[], int TAM, int Rondas);            ///DECALRA LA FUNCION BUNCO
int CalcularBuncoSinRonda(int Dados[], int TAM, int Rondas);    ///DECALRA LA FUNCION FALSO BUNCO
int SumaDivisibleEnCinco(int Dados[], int TAM, int Rondas);     ///DECALRA LA FUNCION DIVISIBLE EN 5
int CalcularEscalera(int Dados[], int TAM);                     ///DECALRA LA FUNCION ESCALERA
int DadoIgualNumeroRonda(int Dados[], int TAM, int Rondas);     ///DECALRA LA FUNCION DADO = N DE RONDA

void AnalizarDados(int Dados[], int TAM, int Rondas, int& Busqueda, int& C_Bunco, int& Resta_Puntaje, int& T_Fallo)  ///INT& DEVUELVE LOS VALORES DE LOS PUNTEROS (Busqueda, C_Bunco, Resta_Puntaje, T_Fallo)
{

    int Puntaje[6]= {0};            ///PONE EN 0 EL VECTOR PUNTAJE
    int ContadorBunco=0;            ///PONE EN 0 EL CONTADOR DE BUNCOS
    int P_Acumulado=0;              ///PONE EN 0 LA VARIABLE DE ACUMULACION
    int Vueltas=0;                  ///PONE EN 0 LA VARIABLE DEL SWITCH
    int Puntaje_invalido = 0;       ///PONE EN 0 EL CONTADOR DE PUNTAJES FALLIDOS
    Busqueda=0;                     ///PONE EN 0 EL PUNTERO DE PUNTOS

    Puntaje[0] = CalcularBunco(Dados, TAM, Rondas);             ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY BUNCO
    Puntaje[1] = CalcularBuncoSinRonda(Dados, TAM, Rondas);     ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY FALSO BUNCO
    Puntaje[2] = SumaDivisibleEnCinco(Dados, TAM, Rondas);      ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY UNA SUMA DE LOS DADOS DIVISIBLE A 5
    Puntaje[3] = CalcularEscalera(Dados, TAM);                  ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY ESCALERA
    Puntaje[4] = DadoIgualNumeroRonda(Dados, TAM, Rondas);      ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY UN DADO = AL N DE RONDA

///BUSQUEDA DEL MAYOR DEL VECTOR
    for(int X=0; X<5; X++)
    {

        if (Puntaje[X]>0)
        {

            Busqueda+=Puntaje[X];
            P_Acumulado+=Puntaje[X];
            Vueltas=X;
        }

        else
        {
            Puntaje_invalido++;
        }

        if(Puntaje_invalido==5)        ///SI NINGUNA DE LAS 5 OPCIONES DEL VECTOR NO SE CUMPLE, LE DA EL ESPACIO A LA POSICION 5
        {

            T_Fallo++;
            Vueltas=5;
            Resta_Puntaje=T_Fallo*2;    ///CALCULA LA RESTA DEL PUNTAJE

        }

    }

    switch(Vueltas)     ///MUESTRA SEGUN LA POSICION MAYOR (CADA POSICION ES UN CASO Y ESTAN ORDENADOS DEL MAYOR PUNTAJE AL MENOR)
    {

    case 0:///0
        ContadorBunco++;            ///CONTADOR DE BUNCOS
        C_Bunco += ContadorBunco;   ///ACUMULADOR DE BUNCOS
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("OBTUVISTE BUNCO! ");
        break;
    case 1:///1
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("OBTUVISTE TRES NUMEROS REPETIDOS DIFERENTE A LA RONDA! ");
        break;
    case 2:///2
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("OBTUVISTE UNA SUMA DE DADOS DIVISIBLE A CINCO! ");
        break;
    case 3:///3
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("OBTUVISTE ESCALERA! ");
        break;
    case 4:///4
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("OBTUVISTE CUALQUIER NUMERO IGUAL AL NUMERO DE RONDA! ");
        break;
    case 5:///TIRADA FALLIDA (5)
        gotoxy(0,8);
        printf("----------------------------------------------------------------------------------------------------------");
        gotoxy(0,9);
        printf("TIRADA FALLIDA");
        break;
    }

}

///FUNCIONES PUNTAJES

int CalcularBunco(int Dados[], int TAM, int Rondas)   //P21
{

    int Vbunco=0;                    ///CONTADOR EN 0

    for(int X=0; X<TAM; X++)     ///LAS VUELTAS POR LOS DADOS
    {

        if (Dados[X]==Rondas)    ///SE FIJA SI LAS RONDAS SON IGUALES A LOS DADOS
        {

            Vbunco++;            ///CUENTA LAS VERDADERAS
        }
    }

    if(Vbunco==3)            ///SE FIJA SI EL CONTADOR SALIO TRES VECES(CANTIDAD DE DADOS)
    {

        return 21;           ///RETORNA EL PUNTAJE
    }

    else
    {
        return 0;            ///SINO, NO RETORNA NADA Y SIGUE
    }

}

int CalcularBuncoSinRonda(int Dados[], int TAM, int Rondas)   //P5
{

    if(Dados[0]==Dados[1] && Dados[1]==Dados[2] && Dados[0]!=Rondas)       ///SE FIJA SEGUN LA POSICION DEL DADO SI SON TODOS IGUALES Y SI SON TODOS IGUALES, SI SON DIFERENTES A LA RONDA
    {

        return 5;                                                          ///RETORNA EL PUNTAJE

    }
    else
    {
        return 0;                                                  ///SINO, NO RETORNA NADA Y SIGUE
    }

}

int SumaDivisibleEnCinco(int Dados[], int TAM, int Rondas)   //P3
{


    int B = CalcularBunco(Dados,TAM,Rondas);                                     ///LLAMA A LA FUNCION DEL BUNCO Y DEVUELVE B
    int SB = CalcularBuncoSinRonda(Dados,TAM,Rondas);                            ///LLAMA A LA FUNCION DEL FALSO BUNCO Y DEVUELVE SB

    int DadosT=0;                                                           ///PONE EN 0 EL ACUMULADOR

    for(int T=0; T<TAM; T++)                                            ///RECORRE LOS DADOS
    {

        DadosT=DadosT+Dados[T];                                         ///ACUMULA LOS NUMEROS DE LOS DADOS (SUMA DE DADOS)
    }

    if(DadosT%5==0&&B!=21&&SB!=5)                                      ///SI LA SUMA DE DADOS ES DIVISBLE DE 5 Y B ES DIFERENTE DE 21(PUNTAJE) Y SB DIFERENTE DE 5(PUNTAJE), PASA
    {

        if (DadosT%5==0)                                                ///SI LA SUMA DE LOS DADOS ES DIVISIBLE A 5, PASA
        {

            return 3;                                               ///SI LA SUMA DE DADOS ES DIVISIBLE DE 5, RETORNA PUNTAJE
        }

        else
        {
            return 0;                                                   ///SINO, NO RETORNA NADA Y SIGUE
        }
    }

    else
    {
        return 0;                                               ///SINO, NO RETORNA NADA Y SIGUE
    }

}

int CalcularEscalera(int Dados[], int TAM)   //P2
{

///ORDENAR EL VECTOR
    int i,j, posmin, aux;
    for(i=0; i<TAM-1; i++)                                          ///RECORRE LOS DADOS
    {

        posmin=i;                                                   ///LE ASIGNA LA POSICION MENOR AL INDICE

        for(j=i+1; j<TAM; j++)                                      ///SUMA UN VALOR AL INDICE Y LE ASIGNA J A ESE TOTAL, RECORRE LOS DADOS
        {

            if(Dados[j]<Dados[posmin])                              ///SI EL MENOR ES EL VECTOR DE DADOS EN J, PASA

                posmin=j;                                           ///Y LE ASIGNA POSMIN A J
        }

        aux=Dados[i];                                               ///VA INTERCAMBIANDO LOS VALORES HASTA QUE QUEDA ORDENADO
        Dados[i]=Dados[posmin];
        Dados[posmin]=aux;
    }

    int E=0;
    int SumaDados=0;

    for(int Z=0; Z<TAM; Z++)                                            ///RECORRE LOS DADOS
    {

        SumaDados+=Dados[Z];                                            ///ACUMULA EL VALOR DE LOS DADOS(SUMA EL VECTOR)
    }

    for(int Y=0; Y<TAM-1; Y++)                                      ///VUELVE A RECORRER LOS DADOS
    {

        if(Dados[Y+1]-Dados[Y]==1)                                  ///SE FIJA SI SON CONSECUTIVOS Y PASA
        {

            E++;                                                ///LO CUENTA
        }

    }
    if(E==2 && SumaDados<15)                                    ///SE UTILIZA SUMADADOS PARA SABER SI NO ES DIVISIBLE Y EFECTUAR LA ESCALERA SI EL CONTADOR ES IGUAL A 2
    {

        return 2;                                               ///RETORNA PUNTAJE
    }

    else
    {
        return 0;                                            ///SINO, NO RETORNA NADA Y SIGUE
    }

}

int DadoIgualNumeroRonda(int Dados[], int TAM, int Rondas)   //P1
{

    int dudaescalera = CalcularEscalera(Dados,TAM);                            ///LLAMA Y ASIGNA VARIABLE A LA FUNCION ESCALERA PARA QUE RETORNE
    int dudadivisible = SumaDivisibleEnCinco(Dados,TAM,Rondas);                ///LLAMA Y ASIGNA VARIABLE A LA FUNCION SUMA DIVISIBLE EN 5 PARA QUE RETORNE

    int P_RND=0;
    for(int X=0; X<TAM; X++)                                        ///RECORRE LOS DADOS
    {

        if (Dados[X]==Rondas)                                       ///SI EL DADO ES IGUAL AL NUMERO DE RONDA
        {

            P_RND++;                                                ///LO CUENTA
        }
    }

    if(P_RND<=2&&dudadivisible==0&&dudaescalera==0)                        ///SI EL CONTADOR ES MENOR O IGUAL A 2 Y LAS OTRAS DOS FUNCIONES SON IGUALES A 0, PASA
    {

        return P_RND;                                                   ///RETORNA EL PUNTAJE (CANTIDAD DE REPETICIONES 1 O 2)
    }

    else
    {
        return 0;                                                        ///SINO, NO RETORNA NADA Y SIGUE

    }
}
#endif // ANALISISDADOS_H_INCLUDED
