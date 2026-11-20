/*
 * KwikPay - Mobile Money USSD Simulator
 * Lab 1 - C Programming (Level 100)
 * Author: Shadrack Owusu Ansah | Index No: 2627403627 
 */

#include <stdio.h>

#define MAX_TRIES 3
#define MAX_HISTORY 5
#define FEE_RATE 0.01

/* Global data for our wallet*/
float balance = 500.00;
int pin = 1234;
float history[MAX_HISTORY];
int historyCount = 0;

void showWelcome() {
    printf("==============================\n");
    printf("  KwikPay Mobile Money (*777#)\n");
    printf("==============================\n");
}

int login() {
    int enteredPin;
    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("Login successful!\n");
            return 1;
        }
        tries++;
        printf("Wrong PIN. %d attempt(s) left.\n", MAX_TRIES - tries);
    }
    printf("Account locked. Please contact customer care.\n");
    return 0;
}

void showMenu() {
    printf("\n-------MAIN MENU-------\n");
    printf("1. Check balance\n");
    printf("2. Send money\n");
    printf("3. Buy airtime\n");
    printf("4. Mini statement\n");
    printf("5. Change PIN\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void addToHistory(float amount) {
    if (historyCount < MAX_HISTORY) {
        history[historyCount] = amount;
        historyCount++;
    } else {
        /* Shift old records left and put the new one at the end */
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            history[i] = history[i + 1];
        }
        history[MAX_HISTORY - 1] = amount;
    }
}

void checkBalance() {
    printf("Your balance is GHS %.2f\n", balance);
}

void sendMoney() {
    char phone[11];
    float amount, fee, total;

    printf("Enter receiver number (10 digits): ");
    scanf("%10s", phone);
    printf("Enter amount (GHS): ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount\n");
        return;
    }

    fee = amount * FEE_RATE;
    total = amount + fee;

    if (total > balance) {
        printf("Insufficient balance. You need GHS %.2f (fee GHS %.2f).\n", total, fee);
        return;
    }

    balance = balance - total;
    addToHistory(-total); // FIXED: Added history recording[cite: 9, 13]

    printf("Sent GHS %.2f to %s. Fee: GHS %.2f\n", amount, phone, fee);
    printf("New balance: GHS %.2f\n", balance);
}

void buyAirtime() {
    float amount;

    printf("Enter airtime amount (GHS): ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > balance) {
        printf("Invalid amount or insufficient balance.\n");
        return;
    }

    balance -= amount;
    addToHistory(-amount); // FIXED: Added history recording[cite: 9, 14]

    printf("Airtime of GHS %.2f bought successfully.\n", amount);
    printf("New balance: GHS %.2f\n", balance);
}

void miniStatement() {
    if (historyCount == 0) {
        printf("No transactions yet.\n");
        return;
    }
    printf("--- Last %d transaction(s) ---\n", historyCount);
    for (int i = 0; i < historyCount; i++) {
        printf("%d. GHS %.2f\n", i + 1, history[i]); // FIXED: Changed history[1] to history[i][cite: 9]
    }
    printf("Current balance: GHS %.2f\n", balance);
}

void changePin() {
    int oldPin, newPin, confirmPin;

    printf("Enter current PIN: ");
    scanf("%d", &oldPin);
    if (oldPin != pin) {
        printf("Wrong PIN. PIN not changed.\n");
        return;
    }
    printf("Enter new 4-digit PIN: ");
    scanf("%d", &newPin);
    printf("Confirm new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin < 1000 || newPin > 9999) {
        printf("PIN must be exactly 4 digits.\n");
    } else if (newPin != confirmPin) {
        printf("PINs do not match.\n");
    } else {
        pin = newPin;
        printf("PIN changed successfully.\n");
    }
}

int main() {
    int choice;
    showWelcome();
    if (login() == 0) {
        return 0;
    }
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                sendMoney();
                break;
            case 3:
                buyAirtime(); // FIXED: Added ()
                break;
            case 4:
                miniStatement();
                break;
            case 5:
                changePin(); // FIXED: Calls the actual function now[cite: 10]
                break;
            case 0:
                printf("Thank you for using KwikPay. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again later\n");
        }
    } while (choice != 0);

    return 0;
}