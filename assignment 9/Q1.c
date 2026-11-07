#include <stdio.h>

// Function to calculate discount based on membership and cart value
float calculateDiscount(float amount, char membership) {
    float rate = 0.0;
    
    // Determine membership discount rate
    if (membership == 'P' || membership == 'p') {
        rate = 0.20;
    } else if (membership == 'G' || membership == 'g') {
        rate = 0.10;
    } else if (membership == 'S' || membership == 's') {
        rate = 0.05;
    }
    
    // Additional 2% discount if shopping amount exceeds PKR 10,000
    if (amount > 10000.0) {
        rate += 0.02;
    }
    
    return amount * rate; // Returns discount amount in PKR
}

// Function to calculate final bill including sales tax and shipping
float calculateFinalBill(float discountedAmount) {
    float tax = discountedAmount * 0.15; // 15% sales tax
    float shipping = (discountedAmount <= 5000.0) ? 300.0 : 0.0; // Flat shipping or free
    
    return discountedAmount + tax + shipping;
}

int main() {
    float shoppingAmount, discountAmount, discountedAmount, finalBill;
    char membershipType;

    printf("Enter total shopping amount (PKR): ");
    scanf("%f", &shoppingAmount);

    printf("Enter membership type (P for Platinum, G for Gold, S for Standard): ");
    scanf(" %c", &membershipType);

    // Calculate discount amount
    discountAmount = calculateDiscount(shoppingAmount, membershipType);
    discountedAmount = shoppingAmount - discountAmount;

    // Calculate final payable amount
    finalBill = calculateFinalBill(discountedAmount);

    printf("\n--- Bill Summary ---\n");
    printf("Original Amount: PKR %.2f\n", shoppingAmount);
    printf("Discount Applied: PKR %.2f\n", discountAmount);
    printf("Discounted Amount: PKR %.2f\n", discountedAmount);
    printf("Final Payable Amount (incl. Tax & Shipping): PKR %.2f\n", finalBill);

    return 0;
}