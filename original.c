#include <stdio.h>

int main() {
    int choice;
    int totalSaved = 0;
    int cumulativeTotal = 0;  // Initialize the cumulative total

    printf("Welcome to the Dollar Saving Program!\n");
    printf("How would you like to save?\n");
    printf("1. Increment by 1 dollar every day\n");
    printf("2. Custom savings\n");
    printf("Enter your choice (1 or 2) or press Ctrl+D to exit: ");

    while (scanf("%d", &choice) != EOF) {
        if (choice == 1) {
            int startingAmount;
            printf("Enter the starting amount: $");
            scanf("%d", &startingAmount);
        
            for (int day = 1; day <= 365; day++) {
                totalSaved += startingAmount;
                cumulativeTotal += startingAmount;  // Update the cumulative total
                printf("Day %d: Saved $%d, Cumulative Total: $%d\n", day, startingAmount, cumulativeTotal);
                startingAmount++;
            }
        } else if (choice == 2) {
            for (int day = 1; day <= 365; day++) {
                int customAmount;
                printf("Enter savings for day %d or press Ctrl+D to exit: $", day);

                if (scanf("%d", &customAmount) == EOF) {
                    printf("\nExiting...\n");
                    return 0;  // Exit gracefully
                }

                totalSaved += customAmount;
                cumulativeTotal += customAmount;  // Update the cumulative total
                printf("Day %d: Saved $%d, Cumulative Total: $%d\n", day, customAmount, cumulativeTotal);
            }
        } else {
            printf("Invalid choice. Please choose 1 or 2.\n");
        }

        printf("Enter your choice (1 or 2) or press Ctrl+D to exit: ");
    }

    printf("Total savings for the year: $%d\n", totalSaved);

    return 0;
}

