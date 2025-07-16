#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Function to calculate total amount
float calculateTotal(struct Item items[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

// Function to display invoice
void displayInvoice(struct Item items[], int itemCount, float totalAmount) {
    printf("\n********** INVOICE **********\n");
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-15s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("\nTotal Amount: %.2f\n", totalAmount);
    printf("******************************\n");
}

int main() {
    int choice, itemCount = 0;
    float totalAmount;
    struct Item items[10]; // Assuming maximum 10 items can be added

    do {
        printf("\n********** MENU **********\n");
        printf("1. Add Item\n");
        printf("2. Generate Invoice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (itemCount < 10) {
                    printf("Enter item name: ");
                    scanf("%s", items[itemCount].name);
                    printf("Enter quantity: ");
                    scanf("%d", &items[itemCount].quantity);
                    printf("Enter price per item: ");
                    scanf("%f", &items[itemCount].price);
                    itemCount++;
                } else {
                    printf("Maximum items limit reached!\n");
                }
                break;

            case 2:
                if (itemCount > 0) {
                    totalAmount = calculateTotal(items, itemCount);
                    displayInvoice(items, itemCount, totalAmount);
                    itemCount = 0; // Reset item count for next invoice
                } else {
                    printf("No items added!\n");
                }
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
