#include <stdio.h>
#include <windows.h>

HANDLE hConsole;

// Установка цвета: text — цвет символа, bg — цвет фона
void setColor(int text, int bg) {
    SetConsoleTextAttribute(hConsole, (bg << 4) | text);
}

// Сброс в стандартный цвет
void resetColor() {
    SetConsoleTextAttribute(hConsole, 7);
}
 
// Переопределение цвета в палитре консоли
void setPaletteColor(int index, int r, int g, int b) {                  //вайб код шняга для покарски
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
    info.ColorTable[index] = RGB(r, g, b);
    SetConsoleScreenBufferInfoEx(hConsole, &info);
}





void orobrazheniefigur(int f) {
    switch (f) {
        case -5: printf("♔"); break;
        case -6: printf("♕"); break;
        case -4: printf("♖"); break;
        case -2: printf("♗"); break;
        case -3: printf("♘"); break;
        case -1: printf("♙"); break;
        case  5: printf("♚"); break;
        case  6: printf("♛"); break;
        case  4: printf("♜"); break;
        case  2: printf("♝"); break;
        case  3: printf("♞"); break;
        case  1: printf("♟"); break;
        default: printf(" "); break;
    }
}


void doska(int pole[8][8]) {
    printf("    a   b   c   d   e   f   g   h\n");

    for (int i = 0; i < 8; i++) {
        resetColor();
        printf("  +---+---+---+---+---+---+---+---+\n");
        resetColor();
        printf("%d |", 8 - i);

        for (int j = 0; j < 8; j++) {
           
            int bg = ((i + j) % 2 == 0) ? 7 : 6;

           
            int text;
            if (pole[i][j] < 0) {
                text = 15;  
            } else if (pole[i][j] > 0) {
                text = 0;                                               //доска
            } else {
                text = 7;
            }

            setColor(text, bg);
            printf(" ");
            orobrazheniefigur(pole[i][j]);   
            printf(" ");

            resetColor();
            printf("|");
        }

        resetColor();
        printf(" %d\n", 8 - i);
    }

    resetColor();
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("    a   b   c   d   e   f   g   h\n");
}
int stolbec(char figura[3]) {
    char c = figura[0];

    
    if (c >= '1' && c <= '8') {
        c = figura[1];
    }

    switch (c) {
        case 'a':
         return 1;
        case 'b':
         return 2;
        case 'c':
         return 3;
        case 'd':
         return 4;
        case 'e':
         return 5;
        case 'f':
         return 6;                              //номер столбца, уходит в переменную nom_stolbca
        case 'g':
         return 7;
        case 'h':
        return 8;
        default: 
         return 0;   
         break;
    }
}

int stroka(char figura[3]) {
    char c = figura[0];

    if (c >= 'a' && c <= 'h') {
        c = figura[1];
    }

    switch (c) {
        case '1': 
        return 1;
        case '2': 
        return 2;
        case '3':
         return 3;
        case '4':
         return 4;
        case '5': 
        return 5;                               //номер строки, уходит в переменную nom_stroki
        case '6':
         return 6;
        case '7':
         return 7;
        case '8': 
        return 8;
        default: 
         return 0;   
         break;
}
}

int novii_stolbec(char kletka[3])
 {
    char m = kletka[0];

    
    if (m >= '1' && m <= '8') {
        m = kletka[1];
    }

    switch (m) {
        case 'a':
         return 1;
        case 'b':
         return 2;
        case 'c':
         return 3;
        case 'd':
         return 4;
        case 'e':
         return 5;
        case 'f':
         return 6;                              //номер столбца, уходит в переменную nom_stolbca
        case 'g':
         return 7;
        case 'h':
        return 8;
        default: 
         return 0;  
         break; 
    }
}

int novaya_stroka(char kletka[3]) {
    char m = kletka[0];

    if (m >= 'a' && m <= 'h') {
        m = kletka[1];
    }

    switch (m) {
        case '1': 
        return 1;
        case '2': 
        return 2;
        case '3':
         return 3;
        case '4':
         return 4;
        case '5': 
        return 5;                               //номер строки, уходит в переменную nom_stroki
        case '6':
         return 6;
        case '7':
         return 7;
        case '8': 
        return 8;
        default: 
         return 0;
         break;   
}
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setPaletteColor(7, 210, 180, 140);
    setPaletteColor(6, 150, 110, 70);  


    int pole[8][8] = {
        {-4,-3,-2,-5,-6,-2,-3,-4},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 1, 1, 1, 1, 1, 1, 1, 1},
        { 4, 3, 2, 5, 6, 2, 3, 4}
    };

    
    doska(pole);

   
    char figura[3];

    char kletka[3];

    
    printf("\nВведите клетку фигуры для ее выбора:");
        scanf("%2s",figura);
    int nom_stroki= stroka(figura);
    int nom_stolbca= stolbec(figura);
    
    

    printf("Введите поле для хода:");
        scanf("%2s",kletka);
    int novii_nom_stroki= novaya_stroka(kletka);
    int novii_nom_stolbca= novii_stolbec(kletka);
    
    
    printf("Ваш ход: %s--->%s \n Нажмите Enter чтобы поддвердить ход или введите любой символ для сброса параметров хода \n",figura,kletka);
    

    printf("Откуда: строка %d столбец %d\n",nom_stroki,nom_stolbca);
    printf("Куда: строка %d столбец %d\n",novii_nom_stroki,novii_nom_stolbca);
            return 0;


}
