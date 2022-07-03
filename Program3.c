#include <stdio.h>
#include <string.h>
const int MAX = 100;
int addValue = 0;
//ARRAY
char name[MAX][20];
char make[MAX][20];
int volume[MAX];
int price[MAX];
//MODULE
void addDrink(char name[][20], char make[][20], int volume[], int price[]);
void printDrinkList(char name[][20], char make[][20], int volume[], int price[]);
void printDrinkBetweenV1V2(char name[][20], char make[][20], int volume[], int price[]);
void sortDrinkBaseOnPriceVolume(char name[][20], char make[][20], int volume[], int price[]);
void printMenu();

int main() {
    int option;
    printMenu();
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Selected 1!\n");
            addDrink(name, make, volume, price);
            main();
            break;
        case 2:
            printf("Selected 2!\n");
            printDrinkList(name, make, volume, price);
            main();
            break;
        case 3:
            printf("Selected 3!\n");
            printDrinkBetweenV1V2(name, make, volume, price);
            main();
            break;
        case 4:
            printf("Selected 4!\n");
            sortDrinkBaseOnPriceVolume(name, make, volume, price);
            main();
            break;
        default:
            printf("%d is not an option, please try again!\n", option);
            main();
            break;
    }
}

void printMenu() {
    printf("-------------\n");
    printf("1 - Add new drink\n");
    printf("2 - Print drinks list\n");
    printf("3 - Print drinks between 2 Volume\n");
    printf("4 - Print drink list in ascending order base on price/volume\n");
    printf("-------------\n");
}

void addDrink(char name[][20], char make[][20], int volume[], int price[]) {
    printf("-------------\n");
    printf("Add new drink:\n");
    printf("This is your %d drink\n\n", addValue+1);
    //NAME
    fflush(stdin);
    printf("Enter drink name: ");
    gets(name[addValue]);
    //MAKE
    fflush(stdin);
    printf("Enter drink make: ");
    gets(make[addValue]);
    //VOLUME
    printf("Enter volume (ml): ");
    scanf("%d", &volume[addValue]);
    //PRICE
    printf("Enter price: ");
    scanf("%d", &price[addValue]);
    //CONFIRM
    printf("\n\nDrink with information have been added!\n");
    printf("------------------------------------------------------\n");
    printf("    NAME        MAKE        VOLUME (ML)     PRICE\n");
    printf("   %s       %s        %d           %d\n", name[addValue], make[addValue], volume[addValue], price[addValue]);
    printf("------------------------------------------------------\n");
    addValue++;
}

void printDrinkList(char name[][20], char make[][20], int volume[], int price[]) {
    printf("------------------------------------------------------\n");
    printf("    NAME        MAKE        VOLUME (ML)     PRICE\n");
    for(int i = 0; i < addValue; i++) {
        printf("   %s       %s        %d           %d\n", name[i], make[i], volume[i], price[i]);
    }
    printf("------------------------------------------------------\n");
}

void printDrinkBetweenV1V2(char name[][20], char make[][20], int volume[], int price[]) {
    int v1, v2;
    printf("Enter V1: "); scanf("%d", &v1);
    printf("Enter V2: "); scanf("%d", &v2);
    if(v2 < v1) {
        printf("V2 must greater than V1, please try again!\n\n");
        printDrinkBetweenV1V2(name, make, volume, price);
    }
    printf("------------------------------------------------------\n");
    printf("    NAME        MAKE        VOLUME (ML)     PRICE\n");
    for(int i = 0; i < addValue; i++) {
        if(volume[i] >= v1 && volume[i] <= v2) {
            printf("   %s       %s        %d           %d\n", name[i], make[i], volume[i], price[i]);
        }
    }
    printf("------------------------------------------------------\n");
}

void sortDrinkBaseOnPriceVolume(char name[][20], char make[][20], int volume[], int price[]) {
    //GENERATING NEW ARRAY
    char name2[MAX][20];
    char make2[MAX][20];
    int volume2[MAX];
    int price2[MAX];
    
    for(int i = 0; i < addValue; i++) {
        strcpy(name2[i], name[i]);
        strcpy(make2[i], make[i]);
        volume2[i] = volume[i];
        price2[i] = price[i];
    }
    //Bubble Sort
    for(int a = 0;a <= addValue-1; a++) { 
        for(int j = addValue-1; j>a; j--) {
            if( (price2[a]/volume2[a]) >= (price2[j]/volume2[j])) { 
                //SWAP
                //Price
                int pricechange = price2[a];
                price2[a] = price2[j];
                price2[j] = pricechange;
                //Volume
                int volumechange = volume2[a];
                volume2[a] = volume2[j];
                volume2[j] = volumechange;
                //Name
                char strTmp[MAX]; 
                strcpy(strTmp, name2[a]); 
                strcpy(name2[a], name2[j]); 
                strcpy(name2[j], strTmp);
                //Make
                strcpy(strTmp, make2[a]); 
                strcpy(make2[a], make2[j]); 
                strcpy(make2[j], strTmp);
            } 
        }
    }
    //Print
    printf("------------------------------------------------------\n");
    printf("    NAME        MAKE        VOLUME (ML)     PRICE\n");
    for(int b = 0; b < addValue; b++) {
        printf("   %s       %s        %d           %d\n", name2[b], make2[b], volume2[b], price2[b]);
    }
    printf("------------------------------------------------------\n");
}