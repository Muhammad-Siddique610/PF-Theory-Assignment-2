#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char toggleBits(char ch) {
    ch ^= (1 << 1);
    ch ^= (1 << 4);
    return ch;
}

void encodeMessage(char message[]) {
    reverseString(message);
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
    printf("Encoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
    reverseString(message);
    printf("Decoded Message: %s\n", message);
}

int main() {
    int choice;
    char message[500];

    do {
        printf("\nMenu:\n\t1. Encode Message\n\t2. Decode Message\n\t3. Exit\n");
        printf("Your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter message to encode: ");
                scanf(" %[^\n]", message);
                encodeMessage(message);
                break;
            case 2:
                printf("Enter message to decode: ");
                scanf(" %[^\n]", message);
                decodeMessage(message);
                break;
            case 3:
                printf("Thankyou :)\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 3);

    return 0;
}
