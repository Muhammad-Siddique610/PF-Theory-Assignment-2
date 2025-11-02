#include <stdio.h>

int addNewBook(int* numOfitems, int id[], char (*names)[50], float cost[], int amount[] ,int maxNumOfBooks);
void processASale(int* numOfitems, int id[] , int amount[], int maxNumOfBooks);
void genLowStockReport(int* numOfitems, int id[], char (*names)[50], float Cost[], int amount[] ,int maxNumOfBooks);

int main(){
    int num = 0;
    int* currentNumOfBooks;
    currentNumOfBooks = &num;
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];

    int menu;

    do{
        printf("Choose A Number Out Of Menu \n 1. Add New Book \n 2. Process A Sale \n 3. Generate Low-Stock Report\n 4. Exit \n\n Enter The Number :");
        scanf("%d",&menu);
        switch (menu){
            case 1:{
                addNewBook(currentNumOfBooks ,isbns, titles , prices , quantities, 100);
                break;
            }
            case 2:{
                processASale(currentNumOfBooks ,isbns , quantities, 100);
                break;
            }
            case 3:{
                genLowStockReport(currentNumOfBooks ,isbns, titles , prices , quantities, 100);
                break;
            }
            case 4: {
                printf("Exiting Program \n");
                break;
            }
            default: {
                printf("Invalid Input");
                break;
            }
        };
    } while(menu != 4);
    return 0;
}

int addNewBook(int* numOfBooks, int id[], char (*names)[50], float cost[], int amount[] ,int maxNumOfBooks){
    int i;
    int temp;
    int flag = 0; 

    if(*numOfBooks >= maxNumOfBooks){
        printf("There is no space to store more books\n");
        return 0;
    }
    printf("Enter The ISBN Of New Book: ");
    scanf("%d",&temp);
    
    for(i = 0 ; i < (*numOfBooks) ; i++){
        if(temp == id[i]){
            flag = 1; 
            break;
        }
    }

    if(flag == 1) {
        printf("The ISBN is already recorded in the records\n");
    }
    else{
        id[*numOfBooks] = temp;
        printf("Enter The Title Of Book: ");
        scanf(" %[^\n]",names[*numOfBooks]);
        printf("Enter The Price Of The Book: ");
        scanf("%f",&cost[*numOfBooks]);
        printf("Enter The Number Of Books In Stock: ");
        scanf("%d",&amount[*numOfBooks]);
        (*numOfBooks)++;
    }
    return 1;
}

void processASale(int* numOfitems, int id[] , int amount[], int maxNumOfBooks){
    int idToCheck;
    int reqIndex;
    int extraAmountSold;
    printf("Enter The ISBN Number Of The Book: ");
    scanf("%d",&idToCheck);
    int i;
    int flag=0;
    for(i = 0; i < (*numOfitems) ; i++ ){
        if(idToCheck == id[i]){
            reqIndex = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0) printf("The ISBN Is Not Found\n");
    else{
        printf("Enter The Number Of Copies Sold\n ");
        scanf("%d",&extraAmountSold);
        if(amount[reqIndex] < extraAmountSold) printf("The Amount Is Greater Than Amount Of Stock");
        else amount[reqIndex] -= extraAmountSold;
    }
}
void genLowStockReport(int* numOfitems, int id[], char (*names)[50], float cost[], int amount[] ,int maxNumOfBooks){
    int i;
    int num = 1;
    printf("\n Details Of Books Which Are Out Of Stock \n");
    for(i = 0; i < (*numOfitems) ; i++ ){
        if(amount[i] < 5){
            printf("Book No %d That Is Out Of Stock Has \nISBN %d \t Title %s \t Price %.3f \n",num , id[i] , names[i] , cost[i]);
            num++;
        }
    }
}