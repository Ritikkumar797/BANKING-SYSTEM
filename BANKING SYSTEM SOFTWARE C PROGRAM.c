#include <stdio.h>
#include <stdlib.h>

// Structure to store customer details for both accounts
struct Customer {
    char name[50];
    int accountNumber;
    float currentBalance;
    float savingsBalance;
    int isDebitCardIssued;
    int isTextMessageServiceOpted;
};

// Function to initialize a new customer
void initializeCustomer(struct Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);

    printf("Enter account number: ");
    scanf("%d", &customer->accountNumber);

    printf("Enter initial current account balance (minimum Rs 5000): ");
    scanf("%f", &customer->currentBalance);

    // Ensure the minimum balance requirement is met for current account
    if (customer->currentBalance < 5000) {
        printf("Minimum current account balance requirement not met. Exiting.\n");
        exit(1);
    }

    printf("Enter initial savings account balance (minimum Rs 100): ");
    scanf("%f", &customer->savingsBalance);

    // Ensure the minimum balance requirement is met for savings account
    if (customer->savingsBalance < 100) {
        printf("Minimum savings account balance requirement not met. Exiting.\n");
        exit(1);
    }

    printf("Debit card issued? (1 for Yes, 0 for No): ");
    scanf("%d", &customer->isDebitCardIssued);

    printf("Text message service opted? (1 for Yes, 0 for No): ");
    scanf("%d", &customer->isTextMessageServiceOpted);
}

// Function to handle surcharge on negative balance for current account
void handleCurrentSurcharge(struct Customer *customer) {
    if (customer->currentBalance < 0) {
        float surcharge = -customer->currentBalance * 0.06; // Surcharge at 6%
        printf("Current account surcharge applied: Rs %.2f\n", surcharge);
        customer->currentBalance -= surcharge;
    }
}

// Function to calculate compound interest on positive balance for current account
void calculateCurrentInterest(struct Customer *customer) {
    if (customer->currentBalance > 0) {
        float interest = customer->currentBalance * 0.04; // Interest at 4%
        printf("Current account interest earned: Rs %.2f\n", interest);
        customer->currentBalance += interest;
    }
}

// Function to apply fine on balance below Rs 50 for savings account
void applySavingsFine(struct Customer *customer) {
    if (customer->savingsBalance < 50) {
        float fine = customer->savingsBalance * 0.10; // Fine at 10%
        printf("Savings account fine applied: Rs %.2f\n", fine);
        customer->savingsBalance -= fine;
    }
}

// Function to calculate compound interest on balance for savings account
void calculateSavingsInterest(struct Customer *customer) {
    float interest = customer->savingsBalance * 0.05; // Interest at 5%
    printf("Savings account interest earned: Rs %.2f\n", interest);
    customer->savingsBalance += interest;
}

// Function to calculate charges for debit card and text message service for savings account
void calculateSavingsCharges(struct Customer *customer) {
    if (customer->isDebitCardIssued) {
        printf("Debit card charges applied for savings account: Rs 10\n");
        customer->savingsBalance -= 10;
    }

    if (customer->isTextMessageServiceOpted) {
        printf("Text message service charges applied for savings account: Rs 5\n");
        customer->savingsBalance -= 5;
    }
}

// Function to print monthly balance sheet for both accounts
void printBalanceSheet(struct Customer *customer) {
    printf("\n-------- Monthly Balance Sheet --------\n");
    printf("Customer Name: %s\n", customer->name);
    printf("Account Number: %d\n", customer->accountNumber);
    printf("Current Account Balance: Rs %.2f\n", customer->currentBalance);
    printf("Savings Account Balance: Rs %.2f\n", customer->savingsBalance);
    printf("--------------------------------------\n");
}

int main() {
    struct Customer customer;

    // Initialize the customer details
    initializeCustomer(&customer);

    // Perform account operations for current account
    handleCurrentSurcharge(&customer);
    calculateCurrentInterest(&customer);

    // Perform account operations for savings account
    applySavingsFine(&customer);
    calculateSavingsInterest(&customer);
    calculateSavingsCharges(&customer);

    // Print the monthly balance sheet for both accounts
    printBalanceSheet(&customer);

    return 0;
}
