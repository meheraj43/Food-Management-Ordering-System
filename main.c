#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"userhandel.h"
#include"food.h"
#include "adminControl.h"
#include"numcheck.h"



void atE(text)
{
    printf("Thank you for using our software");
}

int main()
{
    atexit(atE);
    if(isLoggedIn == 1&&isAdmin!=1)
    {
        if(strlen(loggedinUserDetails.name)!=0|| strlen(loggedinUserDetails.number)!=0)
        {
            int  isNumExist = checknumberExist(loggedinUserDetails.number);
            if(isNumExist == 2)
            {
                showFoodsByID(1);
            }
            else
            {
                isLoggedIn = 0;
                main();
            }
        }
        else
        {
            isLoggedIn = 0;
            main();
        }

    }
    else if(isLoggedIn == 0&& isAdmin ==1)
    {
        puts("\n");
        puts("");
        puts("                        ******************************************");
        puts("                        *************** ADMIN PANEL **************");
        puts("                        ******************************************");
        puts("                        *              1  Add Foods              *");
        puts("                        *              2  View Order History     *");
        puts("                        *              3  View Users             *");
        puts("                        *              4  Exit Admin Panel       *");
        puts("                        *              5  View Foods             *");
        puts("                        ******************************************");
        puts("                        ******************************************");
        int userChoice;
        scanf("%d",&userChoice);
        switch(userChoice)
        {
        case 1:
        {
            Foods foods;
            printf("Enter Food Categories (1-7): ");
            scanf("%s",foods.categories );
            getchar();
            printf("Enter Food Name: ");
            fgets(foods.name, 24, stdin);
            printf("Enter Food Price: ");
            scanf("%s",foods.price);
            printf("Enter Food Rating ");
            scanf("%s",foods.rating );
            foods.name[strcspn(foods.name,"\n")] = '\0';
            addsFoods(foods);
            break;
        }
        case 2:
        {
            viewOrderHistory();
            break;
        }
        case 3:
        {
            viewUsers();
            break;
        }
        case 4:
        {
            isAdmin = 0;
            system("cls");
            main();
            break;
        }
        case 5:
        {
            showFoodsByID(0);
            break;
        }
        default:
            clearScreen();
            main();
            break;
        }
    }
    else
    {
        clearScreen();
        puts("    ");
        puts("   ");
        puts("   ");
        puts("   ");
        puts("                 ****** Welcome to VECTOR STATICS FOOD MANAGEMENT & ORDERING SYSTEM ******");
        puts("                 *************************************************************************");
        puts("                 *************************************************************************");
        puts("                 *                            1  Sign up                                 *");
        puts("                 *                            2  Sign in                                 *");
        puts("                 *                            3  Admin Login                             *");
        puts("                 *                            4  View Foods                              *");
        puts("                 *                            5  Exit                                    *");
        puts("                 *************************************************************************");
        puts("                 *************************************************************************");
        int userChoice;
        scanf("%d",&userChoice);
        switch(userChoice)
        {
        case 1:
        {
            createu();

            break;
        }
        case 2:
        {
            login();
            break;
        }
        case 3:
        {
            clearScreen();
            adminLoginPopup();
            break;
        }
        case 4:
        {
            clearScreen();
            showFoodsByID(0);
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
            clearScreen();
            main();
            break;
        }
    }
    return 0;
}


//create a new user
void createu()
{
    clearScreen();
    puts("\t\tSign up");
    struct UserSignup s;
    printf("Enter name: ");
    getchar();
    fgets(s.name, 49, stdin);
    printf("Enter Number: ");
    scanf("%s",s.number);
    s.name[strcspn(s.name,"\n")] = '\0';
    char checkNum[35];
    memcpy(checkNum,isValidNum(s.number),34);
    if(strcmp(s.number,checkNum) == 0)
    {
        createAccount(s);
    }
    else
    {
        printf("%s.. Try later\n",checkNum);
        btn2continue(1);
    }
    main();

}

void adminLoginPopup()
{
    puts("Admin Login");
    char num[12],pass[20];
    printf("Enter username: ");
    scanf("%s",&num);
    getchar();
    printf("Enter password: ");
    scanf("%s",&pass);
    getchar();
    AdminLogin(num,pass);
}

void login()
{

    char num[20];
    printf("Enter Number: ");
    scanf("%s", &num);
    char checkNum[35];
    memcpy(checkNum,isValidNum(num),34);
    if(strcmp(num,checkNum) == 0)
    {
        int rt = checkUserExist(num);
        if(rt==2)
        {
            clearScreen();
            main();
        }
        else
        {
            system("cls");
            puts("No Account Found With this number.");
            puts("Press 1 to Register, 0 to back , any key to login . . . ");
            int choice;
            scanf("%d", &choice);
            if(choice == 0)
            {
                main();
            }
            else if(choice == 1)
            {
                createu();
            }
            else
            {
                login();
            }

        }
    }
    else
    {
        printf("%s..\n",checkNum);
        login();
    }

}


