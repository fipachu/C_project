#include <stdio.h>
#include <string.h>

#define N 9


/*
---------------------------------------------
Zad. 2.
---------------------------------------------
*/
struct planeta{
    char name[20];
    float distance;
    unsigned int satelity;
};


/*
---------------------------------------------
Zad. 3.
---------------------------------------------
*/
void sort_planets(struct planeta tab[], int rozmiar, int po_czym){
    int zmiany = 0;

    switch(po_czym){
        // alfabetycznie
        case 1:
            do{
                zmiany = 0;
                for(int i = 1; i < rozmiar; i++){
                    if(strcmp(tab[i-1].name, tab[i].name) > 0){
                        struct planeta t = tab[i];
                        tab[i] = tab [i-1];
                        tab[i-1] = t;

                        zmiany++;
                    }
                }
            }while(zmiany);
            break;

        // po odległości
        case 2:
            do{
                zmiany = 0;
                for(int i = 1; i < rozmiar; i++){
                    if(tab[i-1].distance > tab[i].distance){
                        struct planeta t = tab[i];
                        tab[i] = tab [i-1];
                        tab[i-1] = t;

                        zmiany++;
                    }
                }
            }while(zmiany);
            break;

        // po liczbie satelitów
        case 3:
            do{
                zmiany = 0;
                for(int i = 1; i < rozmiar; i++){
                    if(tab[i-1].satelity > tab[i].satelity){
                        struct planeta t = tab[i];
                        tab[i] = tab [i-1];
                        tab[i-1] = t;

                        zmiany++;
                    }
                }
            }while(zmiany);
            break;
    }
}


int main(void){
    // 1.
    FILE *moje_dane;
    moje_dane = fopen("Moje_dane.txt", "w");
    fprintf(moje_dane, "Władimir Putin\n");
    fclose(moje_dane);


    // 2.
    struct planeta planety[N];
    FILE *planety_txt;
    planety_txt = fopen("planety.txt", "r");

    if(planety_txt == NULL){
        printf("Plik nie został otwarty!\n");
        return 1;
    }
    else{
        for(int i = 0; i < N; i++){
            fscanf(planety_txt, "%s %f %u", 
                planety[i].name, 
                &(planety[i].distance), 
                &(planety[i].satelity)
            );
        }
        fclose(planety_txt);

        printf("Liczba satelitów trzeciej planety: %u\n", 
            planety[2].satelity
        );
        printf("Liczba satelitów piątej planety: %u\n\n",
            planety[4].satelity
        );   
    }

    
    // 3.
    printf("Przed sortowaniem:\n"
           "--------------------------\n");
    for(int i = 0; i < N; i++){
        printf("%7s | %11f | %2u\n", planety[i].name, planety[i].distance, planety[i].satelity);
    }
    printf("\n");

    sort_planets(planety, N, 1);
    printf("Posortowane alfabetycznie:\n"
           "--------------------------\n");
    for(int i = 0; i < N; i++){
        printf("%7s | %11f | %2u\n", planety[i].name, planety[i].distance, planety[i].satelity);
    }

    FILE *posortowane_planety;
    posortowane_planety = fopen("Posortowane_Planety.txt", "w");
    for(int i = 0; i < N; i++){
        fprintf(posortowane_planety, "%s\n", planety[i].name);
    }
    fclose(posortowane_planety);
}
