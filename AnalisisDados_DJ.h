#ifndef ANALISISDADOS_DJ_H_INCLUDED
#define ANALISISDADOS_DJ_H_INCLUDED

#include "GotoXY.h"
#include "AnalisisDados.h"

///FUNCIONES PUNTAJES

int CalcularBunco(int Dados[], int TAM, int Rondas);            ///DECALRA LA FUNCION BUNCO
int CalcularBuncoSinRonda(int Dados[], int TAM, int Rondas);    ///DECALRA LA FUNCION FALSO BUNCO
int SumaDivisibleEnCinco(int Dados[], int TAM, int Rondas);     ///DECALRA LA FUNCION DIVISIBLE EN 5
int CalcularEscalera(int Dados[], int TAM);                     ///DECALRA LA FUNCION ESCALERA
int DadoIgualNumeroRonda(int Dados[], int TAM, int Rondas);     ///DECALRA LA FUNCION DADO = N DE RONDA

void AnalizarDados_DJ(int Dados[], int TAM, int Rondas, int& Busqueda_2, int& C_Bunco2, int& Resta_Puntaje2, int& T_Fallo2){ ///INT& DEVUELVE LOS VALORES DE LOS PUNTEROS (Busqueda, C_Bunco, Resta_Puntaje, T_Fallo)

int Puntaje_2[6]={0};             ///PONE EN 0 EL VECTOR PUNTAJE
int ContadorBunco_2=0;            ///PONE EN 0 EL CONTADOR DE BUNCOS
int P_Acumulado=0;              ///PONE EN 0 LA VARIABLE DE ACUMULACION
int Vueltas=0;                  ///PONE EN 0 LA VARIABLE DEL SWITCH
int Puntaje_invalido = 0;       ///PONE EN 0 EL CONTADOR DE PUNTAJES FALLIDOS
Busqueda_2=0;                     ///PONE EN 0 EL PUNTERO DE PUNTOS

Puntaje_2[0] = CalcularBunco(Dados, TAM, Rondas);             ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY BUNCO
Puntaje_2[1] = CalcularBuncoSinRonda(Dados, TAM, Rondas);     ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY FALSO BUNCO
Puntaje_2[2] = SumaDivisibleEnCinco(Dados, TAM, Rondas);      ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY UNA SUMA DE LOS DADOS DIVISIBLE A 5
Puntaje_2[3] = CalcularEscalera(Dados, TAM);                  ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY ESCALERA
Puntaje_2[4] = DadoIgualNumeroRonda(Dados, TAM, Rondas);      ///LLAMA A LA FUNCION PARA QUE BUSQUE SI HAY UN DADO = AL N DE RONDA

///BUSQUEDA DEL MAYOR DEL VECTOR
for(int X=0;X<5;X++){

        if (Puntaje_2[X]>0){

        Busqueda_2+=Puntaje_2[X];
        P_Acumulado+=Puntaje_2[X];
        Vueltas=X;
        }

     else{
            Puntaje_invalido++;
     }

            if(Puntaje_invalido==5){       ///SI NINGUNA DE LAS 5 OPCIONES DEL VECTOR NO SE CUMPLE, LE DA EL ESPACIO A LA POSICION 5

                T_Fallo2++;
                Vueltas=5;
                Resta_Puntaje2=T_Fallo2*2;    ///CALCULA LA RESTA DEL PUNTAJE

            }

    }

switch(Vueltas){    ///MUESTRA SEGUN LA POSICION MAYOR (CADA POSICION ES UN CASO Y ESTAN ORDENADOS DEL MAYOR PUNTAJE AL MENOR)

                    case 0:///0
                        ContadorBunco_2++;             ///CONTADOR DE BUNCOS
                        C_Bunco2 += ContadorBunco_2;   ///ACUMULADOR DE BUNCOS
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("OBTUVISTE BUNCO! ");
                            break;
                    case 1:///1
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("OBTUVISTE TRES NUMEROS REPETIDOS DIFERENTE A LA RONDA! ");
                            break;
                    case 2:///2
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("OBTUVISTE UNA SUMA DE DADOS DIVISIBLE A CINCO! ");
                            break;
                    case 3:///3
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("OBTUVISTE ESCALERA! ");
                            break;
                    case 4:///4
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("OBTUVISTE CUALQUIER NUMERO IGUAL AL NUMERO DE RONDA! ");
                            break;
                    case 5:///TIRADA FALLIDA (5)
                        gotoxy(0,8);printf("----------------------------------------------------------------------------------------------------------");
                        gotoxy(0,9);printf("TIRADA FALLIDA");
                        break;
    }

}

#endif // ANALISISDADOS_DJ_H_INCLUDED
