#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int checkBalance(float* balance){
    int continueTransaction = 0;

    printf("\t\tYour balance : %2.f\n", *balance);
    printf("\t\tWant to operate another transaction? 1 if yes, 0 if no : ");
    scanf("%d", &continueTransaction);
    return continueTransaction;
}

int printTransactions(){
    char option[1024];
    printf("\t\t\t\t\t\t======== AVAILABLE TRANSACTIONS =======\n\n");

    printf("\t\t1. Withdrawl\n");
    printf("\t\t2. Deposit\n");
    printf("\t\t3. Check balance\n\n");
    
    printf("\t\tPlease select 1, 2 or 3 : ");
    scanf("%s", option);
    printf("\n");

    if(atoi(option) != 1 && atoi(option) != 2 && atoi(option) != 3){
        printf("\t\tIncorrect input. Please type 1, 2 or 3 : ");
        scanf("%s", option);
    }
    return atoi(option);
}

int deposit(float* balance){
    float deposit;
    int continueTransaction;
    printf("\t\t\t\t\t\t=============== WITHDRAWL =============\n\n");
    printf("\t\tPut the amount you want to deposit please : ");
    scanf("%f", &deposit);
    printf("\n");

    while (deposit < 0 || deposit == 0){
        printf("\t\tERROR, please give a number higher than 0 : ");
        scanf("%f", &deposit);
        printf("\n");
    }

    *balance = *balance + deposit;
    printf("\t\tYou have deposited %.2f euros!\n", deposit);
    printf("\n");
    printf("\t\tWant to operate another transaction? 1 if yes, 0 if no : ");
    scanf("%d", &continueTransaction);
    return continueTransaction;
}

int withdrawl(float* amount, float* balance){
    printf("\t\t\t\t\t\t=============== WITHDRAWL =============\n\n");
    printf("\t\tPut the amount you want to withdrawl please : ");
    scanf("%f", &(*amount));
    printf("\n");
    int continueTransaction = 0;
    if (*balance < *amount){
        printf("\t\tSorry, you don't have enough to withdrawl.\n");
    }
    else{
        printf("\t\tWithdrawl succeded!\n");
        *balance = *balance - *amount;
    }
    printf("\t\tWant to operate another transaction? 1 if yes, 0 if no : ");
    scanf("%d", &continueTransaction);
    return continueTransaction;

}



int main(){

    int pin = 1234, option, enteredPin;
    float balance = 5000, amount;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t               %s\n", ctime(&now));
    printf("\t\t\t\t\t\t          SAHED Anis - V1 ®\n");
    printf("\t\t\t\t\t\t=============== WELCOME ===============\n\n");

    printf("\t\tPlease enter your pin :");
    scanf("%d", &enteredPin);
    printf("\n");

    int i = 3;

    while( pin != enteredPin && i > 0){
        printf("\t\tIncorrect pin (Remaining attempts (%d/3)). Please retry : ", i);
        scanf("%d", &enteredPin);
        i--;
    }
    
    if (i == 0 && pin != enteredPin){
        printf("\t\tMACHINE LOCKED\n\n");
        exit(0);
    }

    option = printTransactions();
    
    if (option == 1){
        continueTransaction = withdrawl(&amount, &balance);
    }
    else if(option == 2){
        continueTransaction = deposit(&balance);
    }
    else if(option == 3){
        continueTransaction = checkBalance(&balance);
    }

    while (continueTransaction == 1){
        printf("\n");
        option = printTransactions();

        if (option == 1){
            continueTransaction = withdrawl(&amount, &balance);
        }
        else if(option == 2){
            continueTransaction = deposit(&balance);
        }
        else if(option == 3){
            continueTransaction = checkBalance(&balance);
        }
    }

    if (continueTransaction == 0){
        printf("\t\tThank you for your visit!\n");
        exit(0);
    }
    return 0;
}