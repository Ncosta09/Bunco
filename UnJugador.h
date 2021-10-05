#ifndef UNJUGADOR_H_INCLUDED
#define UNJUGADOR_H_INCLUDED

#include "FuncionesDados.h"
#include "AnalisisDados.h"
#include "MayorPuntaje.h"
#include "FuncionesDados_Menu.h"
#include "GotoXY.h"

void UnJugador(char Jugador[], int PuntajeObtenido[]){///FUNCION

///DECLARACION DE FUNCIONES
void TirarDados(int VecDados[], int TAM);
void MostrarDados(int VecDados[], int TAM);
void AnalizaDados(int Dados[], int TAM, int Rondas);

PuntajeObtenido[0]={0}; ///PONE EN 0 EL VECTOR
int Tiros;              ///CONTADOR DE TIROS
int Rondas=0;           ///CONTADOR DE RONDAS
int Busqueda = 0;       ///PONE EN 0 AL PUNTERO
int Resta_Puntaje = 0;  ///PONE EN 0 AL PUNTERO
int C_Bunco = 0;        ///PONE EN 0 AL PUNTERO
int T_Fallo = 0;        ///PONE EN 0 AL PUNTERO
int PuntosAcumulados=0; ///ACUMULADOR DE PUNTOS (TOTAL)
const int TAM=3;        ///CANTIDAD DE DADOS
int Dados[TAM];         ///DECLARAR EL VECTOR DE DADOS CON EL RESPECTIVO TAMAÑO


cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "BIENVENIDO AL MODO DE UN JUGADOR" << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "INGRESA TU NOMBRE, JUGADOR 1: ";
cin >> Jugador;
cout << "----------------------------------------------------------------------------------------------------------" << endl;

for(int i=1;i<=6;i++){  ///RONDAS

Rondas = i;             ///CAMBIO LA VARIABLE DE I A RONDAS
Tiros=0;                ///PONE EN 0 LA CANTIDAD DE TIROS POR RONDA
int Puntos_Ronda=0;     ///DECLARACION Y PUESTA EN 0 DE LOS PUNTOS POR RONDA

while(Puntos_Ronda<21){ ///SI LOS PUNTOS SON 21 O MAS SALE DE LA RONDA

    Tiros++;            ///CONTADOR DE TIROS
    system("cls");

cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PARA EL JUGADOR: " << Jugador << " | RONDA N: "  << Rondas << " | TIRO N: " << Tiros << "|" << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << endl;

    TirarDados(Dados,TAM);      ///LLAMA A LA FUNCION
    MostrarDados(Dados,TAM);    ///LLAMA A LA FUNCION
    AnalizarDados(Dados, TAM, Rondas, Busqueda, C_Bunco, Resta_Puntaje, T_Fallo);   ///LLAMA A LA FUNCION Y RECIBE LOS PUNTEROS (Busqueda(RECIBE EL PUNTAJE), C_Bunco(RECIBE LA CANTIDAD DE BUNCOS), Resta_Puntaje(RECIBE EL PUNTAJE A RESTAR), T_Fallo(RECIBE LA CANTIDAD DE TIRADAS FALLIDAS)) QUE DEVUELVEN LOS VALORES DE ANALISIS DADOS
    PuntosAcumulados+=Busqueda; ///ACUMULA LOS PUNTOS TOTALES
    Puntos_Ronda += Busqueda;   ///ACUMULA LOS PUNTOS POR RONDA

cout << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE RONDA: " << Busqueda << " | PUNTAJE TOTAL ACUMULADO: "  << PuntosAcumulados << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE ACUMULADO POR RONDA: " << Puntos_Ronda << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "VECES QUE OBTUVO BUNCO: " << C_Bunco << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "VECES QUE OBTUVO TIRADA FALLIDA: "<< T_Fallo << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
system("pause");

        }///WHILE (TERMINA LA RONDA)

system("cls");

///LADO HORIZONTAL
    for(int i=25; i<90; i++){
        gotoxy(i,3);printf("%c",205);
        gotoxy(i,23);printf("%c",205);
    }
    ///LADO VERICAL
    for(int i=4; i<23; i++){
     gotoxy(25,i); printf("%c", 186);
     gotoxy(90,i); printf("%c",186);
    }
    ///ESQUINAS
     gotoxy(25,3); printf("%c", 201);
     gotoxy(25,23); printf("%c", 200);
     gotoxy(90,3); printf("%c",187);
     gotoxy(90,23); printf("%c",188);

    gotoxy(35,10);printf("=============================================");
    gotoxy(35,11);printf("RONDA N: ");cout << Rondas << endl;
    gotoxy(35,12);printf("=============================================");
    gotoxy(35,13);printf("PUNTAJE DEL JUGADOR "); cout << Jugador << ":" << PuntosAcumulados << endl;
    gotoxy(35,14);printf("VECES QUE OBTUVO BUNCO: "); cout << C_Bunco << endl;
    gotoxy(35,15);printf("TIRADAS FALIIDAS: "); cout << T_Fallo << endl;
    gotoxy(35,16);printf("TIRO N: "); cout << Tiros << endl;
    gotoxy(35,17);printf("=============================================");

    gotoxy(35,19);system("pause");
    }///FOR (TERMINA LA PARTIDA)

system("cls");
PuntosAcumulados = PuntosAcumulados - Resta_Puntaje;    ///RESTA DEL PUNTAJE PARA OBTENER EL PUNTAJE FINAL
PuntajeObtenido[0] = {PuntosAcumulados};                ///ALMACENA EN LA POSICION 0 DL VECTOR EL PUNTAJE FINAL PROXIMO A COMPARAR

///LADO HORIZONTAL
    for(int i=25; i<90; i++){
     gotoxy(i,3);printf("%c",205);
     gotoxy(i,23);printf("%c",205);
    }
    ///LADO VERICAL
    for(int i=4; i<23; i++){
     gotoxy(25,i); printf("%c", 186);
     gotoxy(90,i); printf("%c",186);
    }
    ///ESQUINAS
    gotoxy(25,3); printf("%c", 201);
    gotoxy(25,23); printf("%c", 200);
    gotoxy(90,3); printf("%c",187);
    gotoxy(90,23); printf("%c",188);

    gotoxy(35,11);printf("=============================================");
    gotoxy(35,12);printf("             FIN DE LA PARTIDA!              ");
    gotoxy(35,13);printf("=============================================");
    gotoxy(35,14);printf("          PUNTAJE FINAL DE "); cout << Jugador << ":" << PuntosAcumulados << " PUNTOS" << endl;
    gotoxy(35,15);printf("=============================================");

    gotoxy(35,17);system("pause");
}
#endif // UNJUGADOR_H_INCLUDED
