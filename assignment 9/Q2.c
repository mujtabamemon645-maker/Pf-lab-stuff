#include <stdio.h>

// Function to handle withdrawals via pointer
void withdraw(float *balance, float amount) {
    if (amount <= *balance) {
        *balance -= amount;
        printf("Withdrawal successful! New balance: PKR %.2f\n", *balance);
    } else {
        printf("Transaction Declined: Insufficient Balance\n");
    }
}

// Function to handle deposits via pointer
void deposit(float *balance, float amount) {
    *balance += amount;
    printf("Deposit successful! Updated balance: PKR %.2f\n", *balance);
}

int main() {
    float balance = 25000.0; // Initial account balance
    int choice;
    float amount;

    printf("Initial Account Balance: PKR %.2f\n", balance);
    printf("Select Transaction Type:\n");
    printf("1. Withdraw (Debit)\n");
    printf("2. Deposit (Credit)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter amount: PKR ");
    scanf("%f", &amount);

    if (choice == 1) {
        withdraw(&balance, amount);
    } else if (choice == 2) {
        deposit(&balance, amount);
    } else {
        printf("Invalid choice!\n");
    }

    printf("Final Account Balance: PKR %.2f\n", balance);
    return 0;
}