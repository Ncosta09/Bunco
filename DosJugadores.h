#ifndef DOSJUGADORES_H_INCLUDED
#define DOSJUGADORES_H_INCLUDED

#include "FuncionesDados.h"
#include "FuncionesDados_Menu.h"
#include "AnalisisDados_DJ.h"
#include "AnalisisDados.h"

void DosJugadores (char Jugador1[], char Jugador2[], int PuntajeObtenido[], char GANADOR[]){

///DECLARACION DE FUNCIONES
void TirarDados(int VecDados[], int TAM);
void MostrarDados(int VecDados[], int TAM);
void AnalizaDados(int Dados[], int TAM, int Rondas);

PuntajeObtenido[1]={0}; ///PONE EN 0 EL VECTOR
PuntajeObtenido[2]={0}; ///PONE EN 0 EL VECTOR
bool TURNOS = true;
int Tiros;              ///CONTADOR DE TIROS
int Tiros2;
int Rondas=0;           ///CONTADOR DE RONDAS
int Busqueda = 0;       ///PONE EN 0 AL PUNTERO
int Busqueda_2 = 0;       ///PONE EN 0 AL PUNTERO
int Resta_Puntaje = 0;  ///PONE EN 0 AL PUNTERO
int Resta_Puntaje2 = 0;  ///PONE EN 0 AL PUNTERO
int C_Bunco = 0;        ///PONE EN 0 AL PUNTERO
int C_Bunco2 = 0;        ///PONE EN 0 AL PUNTERO
int T_Fallo = 0;        ///PONE EN 0 AL PUNTERO
int T_Fallo2 = 0;        ///PONE EN 0 AL PUNTERO
int PuntosAcumulados=0; ///ACUMULADOR DE PUNTOS (TOTAL)
int PuntosAcumulados2=0;
const int TAM=3;        ///CANTIDAD DE DADOS
int Dados[TAM];         ///DECLARAR EL VECTOR DE DADOS CON EL RESPECTIVO TAMAÑO


cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "BIENVENIDO AL MODO DE DOS JUGADORES" << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "INGRESA TU NOMBRE, JUGADOR 1: ";
cin >> Jugador1;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "INGRESA TU NOMBRE, JUGADOR 2: ";
cin >> Jugador2;
cout << "----------------------------------------------------------------------------------------------------------" << endl;

for(int i=1;i<=6;i++){  ///RONDAS
Rondas = i;             ///CAMBIO LA VARIABLE DE I A RONDAS
Tiros=0;                ///PONE EN 0 LA CANTIDAD DE TIROS POR RONDA
Tiros2=0;
int Puntos_Ronda=0;     ///DECLARACION Y PUESTA EN 0 DE LOS PUNTOS POR RONDA
int Puntos_Ronda2=0;
bool PUNTOS_21 = false;

while(PUNTOS_21==false){ ///SI LOS PUNTOS SON 21 O MAS SALE DE LA RONDA

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

    gotoxy(35,7);printf ("=============================================");
    gotoxy(35,8);printf ("RONDA N: ");cout << Rondas << endl;
    gotoxy(35,9);printf ("PROXIMO TURNO: ");cout << Jugador1 << endl;
    gotoxy(35,10);printf("=============================================");
    gotoxy(35,11);printf("PUNTAJE DEL JUGADOR "); cout << Jugador1 << ":" << PuntosAcumulados << endl;
    gotoxy(35,12);printf("VECES QUE OBTUVO BUNCO: "); cout << C_Bunco << endl;
    gotoxy(35,13);printf("=============================================");
    gotoxy(35,14);printf("PUNTAJE DEL JUGADOR "); cout << Jugador2 << ":" << PuntosAcumulados2 << endl;
    gotoxy(35,15);printf("VECES QUE OBTUVO BUNCO: "); cout << C_Bunco2 << endl;
    gotoxy(35,16);printf("=============================================");

    gotoxy(35,21);system("pause");

        while(TURNOS==true){

    Tiros++;            ///CONTADOR DE TIROS
    T_Fallo=0;
    system("cls");

cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PARA EL JUGADOR: " << Jugador1 << " | RONDA N: "  << Rondas << " | TIRO N: " << Tiros << "|" << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << endl;

    TirarDados(Dados,TAM);      ///LLAMA A LA FUNCION
    MostrarDados(Dados,TAM);    ///LLAMA A LA FUNCION
    AnalizarDados(Dados, TAM, Rondas, Busqueda, C_Bunco, Resta_Puntaje, T_Fallo);   ///LLAMA A LA FUNCION Y RECIBE LOS PUNTEROS (Busqueda(RECIBE EL PUNTAJE), C_Bunco(RECIBE LA CANTIDAD DE BUNCOS), Resta_Puntaje(RECIBE EL PUNTAJE A RESTAR), T_Fallo(RECIBE LA CANTIDAD DE TIRADAS FALLIDAS)) QUE DEVUELVEN LOS VALORES DE ANALISIS DADOS
    if(Busqueda==0){
      TURNOS=false;
    }
    PuntosAcumulados+=Busqueda; ///ACUMULA LOS PUNTOS TOTALES
    Puntos_Ronda += Busqueda;   ///ACUMULA LOS PUNTOS POR RONDA
    if(Puntos_Ronda>=21 || (Puntos_Ronda == 21 && Rondas==1)){
        PUNTOS_21=true;
        TURNOS=false;
    }

cout << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE RONDA: " << Busqueda << " | PUNTAJE TOTAL ACUMULADO: "  << PuntosAcumulados << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE ACUMULADO POR RONDA: " << Puntos_Ronda << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "VECES QUE OBTUVO BUNCO: " << C_Bunco << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
/*cout << "VECES QUE OBTUVO TIRADA FALLIDA: "<< T_Fallo << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;*/
system("pause");

    }

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

    gotoxy(35,7);printf ("=============================================");
    gotoxy(35,8);printf ("RONDA N: ");cout << Rondas << endl;
    gotoxy(35,9);printf ("PROXIMO TURNO: ");cout << Jugador2 << endl;
    gotoxy(35,10);printf("=============================================");
    gotoxy(35,11);printf("PUNTAJE DEL JUGADOR "); cout << Jugador1 << ":" << PuntosAcumulados << endl;
    gotoxy(35,12);printf("VECES QUE OBTUVO BUNCO: "); cout << C_Bunco << endl;
    gotoxy(35,13);printf("=============================================");
    gotoxy(35,14);printf("PUNTAJE DEL JUGADOR "); cout << Jugador2 << ":" << PuntosAcumulados2 << endl;
    gotoxy(35,15);printf("VECES QUE OBTUVO BUNCO: "); cout << C_Bunco2 << endl;
    gotoxy(35,16);printf("=============================================");

    gotoxy(35,18);system("pause");

///---------------------------------------------------------------------------- JUGADOR 2 ---------------------------------------

        while(TURNOS==false && PUNTOS_21==false){

    Tiros2++;            ///CONTADOR DE TIROS
    T_Fallo2=0;
    system("cls");

cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PARA EL JUGADOR: " << Jugador2 << " | RONDA N: "  << Rondas << " | TIRO N: " << Tiros2 << "|" << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << endl;

    TirarDados(Dados,TAM);      ///LLAMA A LA FUNCION
    MostrarDados(Dados,TAM);    ///LLAMA A LA FUNCION
    AnalizarDados_DJ(Dados, TAM, Rondas, Busqueda_2, C_Bunco2, Resta_Puntaje2, T_Fallo2);   ///LLAMA A LA FUNCION Y RECIBE LOS PUNTEROS (Busqueda(RECIBE EL PUNTAJE), C_Bunco(RECIBE LA CANTIDAD DE BUNCOS), Resta_Puntaje(RECIBE EL PUNTAJE A RESTAR), T_Fallo(RECIBE LA CANTIDAD DE TIRADAS FALLIDAS)) QUE DEVUELVEN LOS VALORES DE ANALISIS DADOS
    if(Busqueda_2==0){
      TURNOS=true;
    }
    PuntosAcumulados2+=Busqueda_2; ///ACUMULA LOS PUNTOS TOTALES
    Puntos_Ronda2 += Busqueda_2;   ///ACUMULA LOS PUNTOS POR RONDA
        if(Puntos_Ronda2>=21){
        PUNTOS_21=true;
        TURNOS=true;
    }

cout << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE RONDA: " << Busqueda_2 << " | PUNTAJE TOTAL ACUMULADO: "  << PuntosAcumulados2 << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "PUNTAJE ACUMULADO POR RONDA: " << Puntos_Ronda2 << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
cout << "VECES QUE OBTUVO BUNCO: " << C_Bunco2 << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;
/*cout << "VECES QUE OBTUVO TIRADA FALLIDA: "<< T_Fallo2 << endl;
cout << "----------------------------------------------------------------------------------------------------------" << endl;*/
system("pause");

    }

}


    }///FOR (TERMINA LA PARTIDA)

system("cls");
PuntajeObtenido[1] = {PuntosAcumulados};                ///ALMACENA EN LA POSICION 0 DL VECTOR EL PUNTAJE FINAL PROXIMO A COMPARAR
PuntajeObtenido[2] = {PuntosAcumulados2};

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

    if(PuntosAcumulados>PuntosAcumulados2)
        {PuntajeObtenido[1]=PuntosAcumulados;
         strcpy(GANADOR,Jugador1);}

    else if(PuntosAcumulados<PuntosAcumulados2)
            {PuntajeObtenido[2]=PuntosAcumulados2;
            strcpy(GANADOR,Jugador2);}


    if(PuntosAcumulados>PuntosAcumulados2||PuntosAcumulados<PuntosAcumulados2){

    gotoxy(35,11);printf("=============================================");
    gotoxy(35,12);printf("             FIN DE LA PARTIDA!              ");
    gotoxy(35,13);printf("=============================================");
    gotoxy(35,14);printf("          PUNTAJE FINAL DE "); cout << Jugador1 << ":" << PuntosAcumulados  << " | " << PuntajeObtenido[1] << " PUNTOS" << endl;
    gotoxy(35,15);printf("          PUNTAJE FINAL DE "); cout << Jugador2 << ":" << PuntosAcumulados2 << " | " << PuntajeObtenido[2] << " PUNTOS" << endl;
    gotoxy(35,16);printf("          EL GANADOR ES: "); cout << GANADOR << endl;
    gotoxy(35,17);printf("=============================================");}

    else{
    gotoxy(35,11);printf("=============================================");
    gotoxy(35,12);printf("             FIN DE LA PARTIDA!              ");
    gotoxy(35,13);printf("=============================================");
    gotoxy(35,14);printf("          PUNTAJE FINAL DE "); cout << Jugador1 << ":" << PuntosAcumulados  << " PUNTOS" << endl;
    gotoxy(35,15);printf("          PUNTAJE FINAL DE "); cout << Jugador2 << ":" << PuntosAcumulados2 << " PUNTOS" << endl;
    gotoxy(35,16);printf("          HAY UN EMPATE "); cout << endl;
    gotoxy(35,17);printf("=============================================");
    }

    gotoxy(35,19);system("pause");
}

#endif // DOSJUGADORES_H_INCLUDED
