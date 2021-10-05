#ifndef FUNCIONESDADOS_MENU_H_INCLUDED
#define FUNCIONESDADOS_MENU_H_INCLUDED

void dadoUno() { // la funcion que dibuja al dado en la primera posicion

    // HORIZONTAL
    for (int i = 2; i < 10; i++) {
        gotoxy(i, 3); printf("%c", 196);
        gotoxy(i, 7); printf("%c", 196);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        gotoxy(2, i); printf("%c",  179);
        gotoxy(10, i); printf("%c", 179);
    }
    ///ESQUINAS
    gotoxy(2, 3); printf("%c", 218);
    gotoxy(2, 7); printf("%c", 192);
    gotoxy(10, 3); printf("%c", 191);
    gotoxy(10, 7); printf("%c", 217);
}

void dadoDos() {// la funcion que dibuja al dado en la segunda posicion

    // HORIZONTAL
    for (int i = 13; i < 20; i++) {
        gotoxy(i, 3); printf("%c", 196);
        gotoxy(i, 7); printf("%c", 196);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        gotoxy(12, i); printf("%c", 179);
        gotoxy(20, i); printf("%c", 179);
    }
    //ESQUINAS
    gotoxy(12, 3); printf("%c", 218);
    gotoxy(12, 7); printf("%c", 192);
    gotoxy(20, 3); printf("%c", 191);
    gotoxy(20, 7); printf("%c", 217);
}

void dadoTres() {// la funcion que dibuja al dado en la tercera posicion

    // HORIZONTAL
    for (int i = 23; i < 30; i++) {
        gotoxy(i, 3); printf("%c", 196);
        gotoxy(i, 7); printf("%c", 196);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        gotoxy(22, i); printf("%c", 179);
        gotoxy(30, i); printf("%c", 179);
    }
    //ESQUINAS
    gotoxy(22, 3); printf("%c", 218);
    gotoxy(22, 7); printf("%c", 192);
    gotoxy(30, 3); printf("%c", 191);
    gotoxy(30, 7); printf("%c", 217);
}

//La idea de esta funcion es dependiendo de el valor de i,mostrar el dado
void MostrarDados(int Dados[], int TAM) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones

dadoUno(); dadoDos(); dadoTres();

for (int i = 0; i <TAM; i++) {
        switch (Dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { gotoxy(6, 5); printf("%c", 254); }
            if (i == 1) { gotoxy(16, 5); printf("%c", 254); }
            if (i == 2) { gotoxy(26, 5); printf("%c", 254); }
            if (i == 3) { gotoxy(36, 5); printf("%c", 254); }
            if (i == 4) { gotoxy(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                gotoxy(4, 4); printf("%c", 254);
                gotoxy(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                gotoxy(14, 4); printf("%c", 254);
                gotoxy(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                gotoxy(24, 4); printf("%c", 254);
                gotoxy(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                gotoxy(34, 4); printf("%c", 254);
                gotoxy(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                gotoxy(44, 4); printf("%c", 254);
                gotoxy(48, 6); printf("%c", 254);
            }

            ; break;
        /*dado 3*/  case 3:
            if (i == 0) {
                gotoxy(6, 5); printf("%c", 254);
                gotoxy(8, 4); printf("%c", 254);
                gotoxy(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                gotoxy(16, 5); printf("%c", 254);
                gotoxy(18, 4); printf("%c", 254);
                gotoxy(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                gotoxy(26, 5); printf("%c", 254);
                gotoxy(28, 4); printf("%c", 254);
                gotoxy(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                gotoxy(36, 5); printf("%c", 254);
                gotoxy(38, 4); printf("%c", 254);
                gotoxy(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                gotoxy(46, 5); printf("%c", 254);
                gotoxy(48, 4); printf("%c", 254);
                gotoxy(44, 6); printf("%c", 254);
            }

            ; break;

/*dado 4*/ case 4:
            if (i == 0) {
                gotoxy(4, 4); printf("%c", 254);
                gotoxy(4, 6); printf("%c", 254);
                gotoxy(8, 4); printf("%c", 254);
                gotoxy(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                gotoxy(14, 4); printf("%c", 254);

                gotoxy(14, 6); printf("%c", 254);
                gotoxy(18, 4); printf("%c", 254);
                gotoxy(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                gotoxy(24, 4); printf("%c", 254);
                gotoxy(24, 6); printf("%c", 254);
                gotoxy(28, 4); printf("%c", 254);
                gotoxy(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                gotoxy(34, 4); printf("%c", 254);
                gotoxy(34, 6); printf("%c", 254);
                gotoxy(38, 4); printf("%c", 254);
                gotoxy(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                gotoxy(44, 4); printf("%c", 254);
                gotoxy(44, 6); printf("%c", 254);
                gotoxy(48, 4); printf("%c", 254);
                gotoxy(48, 6); printf("%c", 254);
            }

            break;

        /*dado 5*/ case 5:
            if (i == 0)
            {
                gotoxy(4, 4); printf("%c", 254);
                gotoxy(4, 6); printf("%c", 254);
                gotoxy(8, 4); printf("%c", 254);
                gotoxy(6, 5); printf("%c", 254);
                gotoxy(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                gotoxy(14, 4); printf("%c", 254);
                gotoxy(14, 6); printf("%c", 254);
                gotoxy(18, 4); printf("%c", 254);
                gotoxy(16, 5); printf("%c", 254);
                gotoxy(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                gotoxy(24, 4); printf("%c", 254);
                gotoxy(24, 6); printf("%c", 254);
                gotoxy(28, 4); printf("%c", 254);
                gotoxy(26, 5); printf("%c", 254);
                gotoxy(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                gotoxy(34, 4); printf("%c", 254);
                gotoxy(34, 6); printf("%c", 254);
                gotoxy(38, 4); printf("%c", 254);
                gotoxy(36, 5); printf("%c", 254);
                gotoxy(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                gotoxy(44, 4); printf("%c", 254);
                gotoxy(44, 6); printf("%c", 254);
                gotoxy(48, 4); printf("%c", 254);
                gotoxy(46, 5); printf("%c", 254);
                gotoxy(48, 6); printf("%c", 254);
            }

            break;

        /*dado 6*/  case 6:
            if (i == 0) {
                gotoxy(4, 4); printf("%c", 254);
                gotoxy(4, 6); printf("%c", 254);
                gotoxy(8, 4); printf("%c", 254);
                gotoxy(4, 5); printf("%c", 254);
                gotoxy(8, 5); printf("%c", 254);
                gotoxy(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                gotoxy(14, 4); printf("%c", 254);
                gotoxy(14, 6); printf("%c", 254);
                gotoxy(18, 4); printf("%c", 254);
                gotoxy(14, 5); printf("%c", 254);
                gotoxy(18, 5); printf("%c", 254);
                gotoxy(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                gotoxy(24, 4); printf("%c", 254);
                gotoxy(24, 6); printf("%c", 254);
                gotoxy(28, 4); printf("%c", 254);
                gotoxy(24, 5); printf("%c", 254);
                gotoxy(28, 5); printf("%c", 254);
                gotoxy(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                gotoxy(34, 4); printf("%c", 254);
                gotoxy(34, 6); printf("%c", 254);
                gotoxy(38, 4); printf("%c", 254);
                gotoxy(34, 5); printf("%c", 254);
                gotoxy(38, 5); printf("%c", 254);
                gotoxy(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                gotoxy(44, 4); printf("%c", 254);
                gotoxy(44, 6); printf("%c", 254);
                gotoxy(48, 4); printf("%c", 254);
                gotoxy(44, 5); printf("%c", 254);
                gotoxy(48, 5); printf("%c", 254);
                gotoxy(48, 6); printf("%c", 254);
            }
            break;
        }
    }
}
#endif // FUNCIONESDADOS_MENU_H_INCLUDED
