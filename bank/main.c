#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   int correct_pin = 1234;
   int user_pin;
   bool isValid = false;
   bool pinValid = false;
   bool loansValid = false;
   int attempt = 0;
   int pin_attempt = 0;
   int loanspin_attempt = 0;
   char fullname[30];
   char password[10];
   char correct_password[] = "mybank";


  printf("Welcome to Jaiz bank. Enter Your name?\n");
  fgets(fullname,sizeof(fullname), stdin);
  printf("you are welcome to jaiz bank %s \n",fullname);

   do
    {
        printf("Enter your password: ");
        scanf("%s", password);
        int valid = strcmp(password, correct_password);
        if (valid == 0)
       {
            printf("Password correct!\n");
           isValid = true;

       }
       else
        {
          attempt++;
          printf("Invalid pin! Enter again.\n");
           if (attempt >= 5 ){
          printf("Too many attempts try in next 20 minutes!");
            break;
           }
       }
    }

    while (!isValid);


     if(isValid)
       {
      printf("Access Granted\n");
      int deposit;
      int withdrawAmt;
      int balance = 0;
      int choice;
      int loansAmt;
      int interest;

    do{
       printf("\n 1. Deposit \n 2. Withdraw \n 3. Loans\n 4. Check Balance\n 5. Exit\n");
       printf("Enter your choice ");
       scanf("%d", &choice);

      switch (choice){
        case 1:
           printf("How much do you want to deposit?:\n");
           scanf("%d", &deposit);
           balance += deposit;
           printf("deposit succesful \n");
           printf("Your current balance is %i\n", balance);
          break;

       case 2:
           do
             {
               printf("Enter your pin: ");
               scanf("%d", &user_pin);

               if (user_pin == correct_pin)
                  {
                   printf("Pin correct!\n");
                   pinValid = true;

                   printf("How Much Did You Want To Withdraw\n");
                   scanf("%i", &withdrawAmt);
                   printf("you are about to withdraw %i\n",withdrawAmt);
                   (withdrawAmt < balance) ? (balance -= withdrawAmt) : printf("Insufficient fund! ");
                   printf("%i is the remaining balance\n", balance);
                   }
              else
                {
                   pin_attempt++;
                   printf("Invalid pin! Enter again.");
                   if (pin_attempt >= 5 ){
                   printf("Too many attempts try in next 20 minutes!");
                     break;
                       }
                }
         }
    while (!pinValid);
    break;

   case 3:
       do
         {
          printf("Enter your pin: ");
          scanf("%d", &user_pin);

         if (user_pin == correct_pin)
        {
            printf("Pin correct!\n");
            loansValid = true;

            printf("how much do you need \n");
            scanf("%i", &loansAmt);
            printf("%i\n", loansAmt);
            interest = (loansAmt * 0.05) + loansAmt;
            printf("You are going to be  paying %i\n", interest);
            break;
        }
        else
        {
            loanspin_attempt++;
            printf("Invalid pin! Enter again.\n");
            if (loanspin_attempt >= 5 ){
            printf("Too many attempts try in next 20 minutes!");
            break;
            }
        }
    }
    while (!loansValid);
    break;

   case 4:
    printf("your balance is %i\n", balance);
    break;

    case 5:
            printf("Exit\n");
            break;
        default:
            printf("invalid choice try again\n");
      }

    } while (choice != 5);
    };

    return 0;
}
