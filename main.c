#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

    void Color(int TextColor, int Background);

int main(void) {
    char ch[0], chaine[100] = "9", rch[100];
    int i = 0, res, j, nb = 0, tres[8];
    int msec = 0, trigger = 120000; /* in milliseconde */
    clock_t before = clock();
    printf("Started ... \n");

    srand(time(NULL));
    for (i = 0; i < 7; i++) {
        nb = rand() % 9;
        sprintf(ch, "%d", nb);
        strcat(chaine, ch);
    }

    printf("Guess the number ! \n");

    do {
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        res = 0;
        scanf("%s", & rch);
        for (i = 0; i < 8; i++) {
            tres[i] = 3;
        }

        for (i = 0; i < 8; i++) {
            if (chaine[i] != rch[i]) {
                res = 1;
            }
        }

        if (res == 1) {
            for (i = 0; i < 8; i++) {
                if (chaine[i] == rch[i]) {
                    tres[i] = 1;
                } else {
                    for (j = 0; j < 8; j++) {
                        if ((i != j) && (chaine[j] == rch[i])) {
                            tres[i] = 2;
                        }
                    }
                }
                if (tres[i] == 1) {
                    Color(2, 0);
                    printf("V");
                } else if (tres[i] == 2) {
                    Color(5, 0);
                    printf("B");
                } else if (tres[i] == 3) {
                    Color(4, 0);
                    printf("R");
                }
                Color(15, 0);
            }
            printf("\n");
            printf("________ Still %d second\n",trigger/1000 - msec/1000);
        }
    } while (res != 0 && msec < trigger);
    if(msec > trigger){
    Color(14,4) ;
    printf("                                           \n");
    printf("!!!!!!!!!!   You Lose :/  !!!!!!!!!!!!!!!\n");
    printf("                                           ");
    Color(15, 0);
    }
    else{
    Color(14, 2);
    printf("                                           \n");
    printf("!!!!!!!!!!   You Win :D  !!!!!!!!!!!!!!!\n");
    printf("                                           ");
    Color(15, 0);
    }
    return 0;
}

void Color(int TextColor, int Background)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, Background * 16 + TextColor);
}
