#include <stdio.h>
#include <string.h>
const int MAXN = 100;
int addValue = 0, posCode = 0, posName = 0;
char code[MAXN][8];
char name[MAXN][20]; 
double salary[MAXN];
double allowance[MAXN];
//module
void add(char code[][8], char name[][20], double salary[], double allowance[]);
void find(char code[][8], char name[][20], double salary[], double allowance[]);
void removeE(char code[][8], char name[][20], double salary[], double allowance[]);
void printInOrder(char code[][8], char name[][20], double salary[], double allowance[]);
int findIndexForCode(char code[][8], char key[]);
int findIndexForName(char name[][20], char key[]);

int main() {
    int option;

    printf("----------\n");
    printf("1 - Add new employee\n");
    printf("2 - Find employee data using name\n");
    printf("3 - Remove employee using code\n");
    printf("4 - Print the list in descending order\n");
    printf("----------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Selected 1!\n");
            add(code, name, salary, allowance);
            main();
            break;
        case 2:
            printf("Selected 2!\n");
            find(code, name, salary, allowance);
            main();
            break;
        case 3:
            printf("Selected 3!\n");
            removeE(code, name, salary, allowance);
            main();
            break;
        case 4:
            printf("Selected 4!\n");
            printInOrder(code, name, salary, allowance);
            main();
            break;
        default:
            printf("%d is not an option! please try again!\n", option);
            main();
    }
}

void add(char code[][8], char name[][20], double salary[], double allowance[]) {
    printf("\n-------------\n");
    printf("ADD NEW EMPLOYEE\n\n");
    fflush(stdin);
    entercode:printf("Enter Code: "); gets(code[addValue]); fflush(stdin);
    if(strlen(code[addValue]) < 1 || strlen(code[addValue]) > 8) {
        printf("Code must from 1 - 8, please try again!\n");
        goto entercode;
    }
    printf("\nEnter Name: "); gets(name[addValue]); fflush(stdin);
    printf("\nEnter Salary: "); scanf("%lf", &salary[addValue]);
    printf("\nEnter Allowance: "); scanf("%lf", &allowance[addValue]);
    printf("\n-------------\n");
    printf("\nNew Employee with Information have been added: \n");
    printf("---------------------------------------------------------\n");
    printf("    CODE        NAME        SALARY      ALLOWANCE\n");
    printf("    %s      %s      %.2lf       %.2lf\n", code[addValue], name[addValue], salary[addValue], allowance[addValue]);
    printf("---------------------------------------------------------\n");
    addValue++;
}

void find(char code[][8], char name[][20], double salary[], double allowance[]) {
    char key[MAXN][20]; int count;
    fflush(stdin);
    //CASE NOTHING IN THE ARRAY
    if(addValue == 0) { 
        printf("\nThere is no employee in the list to search!\n\n");
        main();
    }
    //CASE HAVE VARIABLE IN THE ARRAY
    printf("\nEnter a name to search: ");
    gets(key);
    //CASE FOUND
    if(findIndexForName(name, key) == 1) {
        printf("\n---------------------------------------------------------\n");
        printf("    CODE        NAME        SALARY      ALLOWANCE\n");
        printf("     %s      %s      %.2lf       %.2lf\n", code[posName], name[posName], salary[posName], allowance[posName]);
        printf("---------------------------------------------------------\n");
    }
    else printf("Employee %s is not exist\n\n", key);
}


void removeE(char code[][8], char name[][20], double salary[], double allowance[]) {
    char removeKey[8]; int i, j, confirm;
    //CASE NOTHING IN THE ARRAY
    if(addValue == 0) {
        printf("\nThere is no employee in the list to remove!\n\n");
        main();
    }
    fflush(stdin);
    printf("\nEnter a code to remove: ");
    gets(removeKey);
    //SEARCHING FOR removeKey IN ARRAY code
    for(i = 0; i < addValue; i++) {
        if(findIndexForCode(code, removeKey) == 0) {
            printf("Employee with code %s is not exist!\n\n", removeKey);
            main();
        }
        if(strcmp(code[i], removeKey) == 0) { //CASE EMPLOYEE EXIST
            printf("Do you want to remove this employee?");
            printf("\n---------------------------------------------------------\n");
            printf("    CODE        NAME        SALARY      ALLOWANCE\n");
            printf("     %s      %s      %.2lf       %.2lf\n", code[i], name[i], salary[i], allowance[i]);
            printf("---------------------------------------------------------\n");
            optionConfirm:printf("1 - Confirm \n2 - Cancel\n");
            scanf("%d", &confirm);
            switch(confirm) {
                case 1: //Confirm
                    for(j = i; j < addValue; j++) {
                        //MOVE VALUE UP 1 SLOT (1 -> 0, 2 -> 1...)
                        strcpy(code[j], code[j+1]);
                        strcpy(name[j], name[j+1]);
                        salary[j] = salary[j+1];
                        allowance[j] = allowance[j+1];
                    }
                    printf("Employee with code %s have been removed!\n\n", removeKey);
                    addValue--;
                    break;
                case 2: //Cancel
                    printf("Canceled!\n\n");
                    main();
                    break;
                default:
                    printf("%d is not an option!\n", confirm);
                    goto optionConfirm;
            }
        }
    }
}

void printInOrder(char code[][8], char name[][20], double salary[], double allowance[]) {
    //CASE NOTHING IN THE ARRAY
    if(addValue == 0) {
        printf("\nThere is no employee in the list to remove!\n\n");
        main();
    }
    //Bubble Sort
    for(int i = 0;i <= addValue-1; i++) { 
        for(int j = addValue-1; j>i; j--) {
            if( salary[i] + allowance[i] <= salary[j] + allowance[j]) { 
                //SWAP
                //Salary
                double tmp = salary[i];
                salary[i] = salary[j];
                salary[j] = tmp;
                //Code
                char strTmp[MAXN]; 
                strcpy(strTmp, code[i]); 
                strcpy(code[i], code[j]); 
                strcpy(code[j], strTmp);
                //Name
                strcpy(strTmp, name[i]); 
                strcpy(name[i], name[j]); 
                strcpy(name[j], strTmp);
                //Allowance
                int tmp1 = allowance[i]; 
                allowance[i] = allowance[j]; 
                allowance[j] = tmp1;
            } 
        }
    }
    //PRINT EMPLOYEE LIST IN ASCENDING ORDER
    printf("\n---------------------------------------------------------\n");
    printf("    CODE        NAME        SALARY      ALLOWANCE\n");
    for(int i = 0; i < addValue; i++) {
        printf("     %s      %s      %.2lf       %.2lf\n", code[i], name[i], salary[i], allowance[i]);
    }
    printf("\n---------------------------------------------------------\n");
}

//find position with code
int findIndexForCode(char code[][8], char key[]) {
    int i;
    for(int i = 0; i < addValue; i++) {
        if(strcmp(code[i], key) == 0) {
            posCode = i;
            return 1;
        } 
    }
    return 0;
}

//Find Position with name
int findIndexForName(char name[][20], char key[]) {
    int i;
    for(int i = 0; i < addValue; i++) {
        if(strcmp(name[i], key) == 0) {
            posName = i;
            return 1;
        } 
    }
    return 0;
}