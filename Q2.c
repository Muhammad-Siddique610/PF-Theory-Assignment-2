#include <stdio.h>
#include <string.h>

void CustomerInfo(char name[50], int* CNIC){
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", name);
        printf("Enter Customer CNIC: ");
        scanf("%d", &*CNIC);
    }
void displayInventory(int qty[4], int price[4]){
    int i, j;
    printf("Product Code\tQuantity in Stock\tPrice per Product\n");
    for (i = 0 ; i < 4 ; i++){
        printf("\t%d\t\t%d\t\t\t%d\n", i + 1, qty[i], price[i]);
    }
}
void updateInventory(int qty[4], int code, int user){
    qty[code - 1] -= user;
}
void addItem(int qty[4] , int price[4], int cartQty[4], int cartPrice[4]){
    int code, user, i;
    printf("Enter the product code that you wanna add to cart: ");
    scanf("%d", &code);
    if (code > 0 && code <= 4){
        printf("How many qty purchase: ");
        scanf("%d", &user);
        if (user > qty[code - 1])
            printf("Insufficient qty:(\n");
        else {
            updateInventory(qty, code, user);
            cartPrice[code - 1] = price[code - 1] * user;
            cartQty[code - 1] = user;
            printf("The item with code %d and %d qty has been added to cart\n");
        }
    }
    else 
        printf("No any product is there with code %d\n", code);
}
void TotalBill(int prices[4], float* with, int* without){
    int i;
    char promo[8] = "Eid2025";
    char user[20];
    *without = 0;
    for (i = 0 ; i < 4 ; i++)
        *without += prices[i];
    printf("Enter the promocode (if you have) : ");
    scanf(" %s", user);
    if (strcmp(promo, user) == 0){
        *with = 0.75 * (*without);
        printf("Discount applied CONGRATS!!");
    }
    else{
        *with = *without;
        printf("You entered Invlid Promo-Code\n");
    }
}
void showInvoice(char name[50], int CNIC, int without, float with){
    printf("====================== Invoice ======================\n");
    printf("\tCustomer name : %s\n", name);
    printf("\tCNIC : %d\n", CNIC);
    printf("\tBill Without discount : %d\n", without);
    printf("\tBill with discount : %.2f\n", with);
}
int main(){
    int choice, without = 0;
    int CNIC, qty[4] = {50,10,20,8}, price[4] = {100,200,300,150};
    char name[50];
    float with = 0;
    int cartQty[4] = {0}, cartPrice[4] = {0};
    do{
        printf("\nMenu:\n\t1. Customer Info\n\t2. Display Inventory\n\t3. Update Inventory\n\t4. Add Item to Cart\n\t5. Display Total Bill\n\t6. Show Invoice\n\t7. Exit the System\n");
        printf("Your choice : ");
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                CustomerInfo(name, &CNIC);
                break;
            }
            case 2:{
                displayInventory(qty, price);
                break;
            }
            case 3:{
                // According to the scenario given in question for Add Item, inventory is being updated there so there is no logic to update it two times.
                printf("I have added a comment please read that.");
                break;
            }
            case 4:{
                addItem(qty, price, cartQty, cartPrice);
                break;
            }
            case 5:{
                TotalBill(cartPrice, &with, &without);
                break;
            }
            case 6:{
                showInvoice(name, CNIC, without, with);
                break;
            }
            case 7:{
                printf("Thankyou :)\n");
                break;
            }
            default:{
                printf("Invalid Choice\n");
            }
        }
    }while (choice != 7);
    
    return 0;
}