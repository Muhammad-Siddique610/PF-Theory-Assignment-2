#include <stdio.h>

void updateSector(int grid[3][3]){
    int r, c, bit, action;
    printf("Enter row and column (1-3 & 1-3): ");
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 3 || c < 1 || c > 3){
        printf("Invalid coordinates\n");
        return;
    }
    printf("Enter flag to modify (0=Power, 1=Overload, 2=Maintenance): ");
    scanf("%d", &bit);
    if (bit < 0 || bit > 2){
        printf("Invalid flag\n");
        return;
    }
    printf("Enter 1 to set or 0 to clear: ");
    scanf("%d", &action);
    if (action == 1)
        grid[r-1][c-1] |= (1 << bit);
    else
        grid[r-1][c-1] &= ~(1 << bit);
    printf("Sector (%d,%d) updated. New status value: %d\n", r, c, grid[r-1][c-1]);
}

void querySector(int grid[3][3]){
    int r, c, s;
    printf("Enter row and column (1-3 & 1-3): ");
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 3 || c < 1 || c > 3){
        printf("Invalid coordinates\n");
        return;
    }
    s = grid[r-1][c-1];
    printf("\nSector (%d,%d) Status (value = %d):\n", r, c, s);
    printf("Power: %s\n", (s & (1 << 0)) ? "ON" : "OFF");
    printf("Overload: %s\n", (s & (1 << 1)) ? "Overloaded" : "Normal");
    printf("Maintenance: %s\n", (s & (1 << 2)) ? "Required" : "Not Required");
}

void runDiagnostic(int grid[3][3]){
    int i, j, overload = 0, maintenance = 0;
    for (i = 0 ; i < 3 ; i++){
        for (j = 0 ; j < 3 ; j++){
            if ((grid[i][j] >> 1) & 1)
                overload++;
            if ((grid[i][j] >> 2) & 1)
                maintenance++;
        }
    }
    printf("\nSystem Diagnostic Report:\n");
    printf("Total overloaded sectors: %d\n", overload);
    printf("Total sectors requiring maintenance: %d\n", maintenance);
}

int main(){
    int grid[3][3] = {0};
    int choice;
    do{
        printf("\nMenu:\n\t1. Update Sector Status\n\t2. Query Sector Status\n\t3. Run System Diagnostic\n\t4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                updateSector(grid);
                break;
            }
            case 2:{
                querySector(grid);
                break;
            }
            case 3:{
                runDiagnostic(grid);
                break;
            }
            case 4:{
                printf("Thankyou\n");
                break;
            }
            default:{
                printf("Invalid Choice\n");
            }
        }
    }while (choice != 4);
    return 0;
}
