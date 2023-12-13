
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    char price[10];
    char rating [6];
    char  categories[3];
} Foods;

char categories[8][20] = {{"Breakfast"},{"Lunch"},{"Snacks"},{"Diner"},{"Coffee"},{"Shake"},{"Juice"},{"Ice Cream"}};


void showFoodsByID(int ordering)
{
    puts("\n\n\n");
    if(ordering)printf("               * * * Hello %s\n",loggedinUserDetails.name);
    puts("               ********************************************************************************");
    puts("               ********* Welcome to VECTOR STATICS FOOD MANAGEMENT & ORDERING SYSTEM **********");
    puts("               ********************************************************************************");
    puts("               *  SL\t\t\tFOOD CATEGORIES                                       *");
    puts("               ********************************************************************************");
    for(int i = 0; i< sizeof(categories)/sizeof(categories[0]); i++)
    {
        printf("               * %2d\t\t%20s                                          *\n",i+1,categories[i]);
    }
    puts("               ********************************************************************************");
    puts("               ********************************************************************************");
    printf("%s%s1 - 8 to select categories... ",space,(ordering == 1&&isLoggedIn == 1 )?"Press 0 to logout, ":"Press 0 to return home, ");
    char idd[2];
    scanf("%s",&idd);
    //Checking is the user ordering or not
    if(ordering == 1&&isLoggedIn == 1 )
    {
        if(idd[0]-'0' == 0)
        {
            isLoggedIn = 0;
            main();
        }
    }
    else
    {
        homeCls(idd[0]-'0');
    }

    if(idd[0]-'0' > 8)
    {
        printf("%s 1 - 8 Only ...",space);
        btn2continue(1);
        main();
    }
    Foods ff[10];
    system("cls");
    FILE *file;
    file =  fopen("foods.txt","r");
    int rc = 0;
    if(file == NULL)
    {
        fclose(file);
        puts("Food file not found.");
        btn2continue(1);
        main();
    }
    else
    {
        printf("*******************************************************************************\n");
        printf("* SL            %s      \t\t\t\tPrice\t      Ratings *\n",categories[atoi(idd)-1]);
        printf("*******************************************************************************\n");
        int r = 0,index = 1;
        do
        {
            Foods f;
            r =  fscanf(file,
                        "%50[^,],%10[^,],%6[^,],%s\n",f.name,f.price,f.rating,f.categories);
            if(strcmp(f.categories,idd)==0)
            {
                printf("* %d\t%-25s\t\t\t%-6s\t\t%-5s *\n",index,f.name,f.price,f.rating);

                strcpy(ff[index-1].categories,f.categories);
                strcpy(ff[index-1].name,f.name);
                strcpy(ff[index-1].rating,f.rating);
                strcpy(ff[index-1].price,f.price);
                index++;
            }
            if(r == 4)
            {
                rc = index-1;
            }
            if(r!= 4 && !feof(file))
            {
                //For Error Handling
                //printf("%s",&f.name);
                //printf("%d \n",r);
                fclose(file);
                puts("Data format incorectly");
                return;
            }
        }
        while(!feof(file));
    }
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    fclose(file);
    if(ordering == 1&&isLoggedIn == 1 )
    {
        int selectItm,quantity;
        printf("\nPress 0 to return home!\n");
        puts("\n\t\tSelect the food you want to order!");
        scanf("%d",&selectItm);
        homeCls(selectItm);
        puts("\n\t\tSelect How much you want to order!");
        scanf("%d",&quantity);
        clearScreen();
        homeCls(quantity);
        if(selectItm<=rc && selectItm>0 && quantity<51 && quantity >0)
        {
            printf("%d %d",selectItm,rc);
            double pprice = ((atof(ff[selectItm-1].price)*quantity)*0.15)+(atof(ff[selectItm-1].price)*quantity);
            foodOrderingHistory(ff[selectItm-1].name,pprice,quantity);
            printf("Customer: %-25s\nDate    : %-25s\nMobile  : %-25s\n\nItem List:\n----------------------------------------------------------\nItem\t\t\t\t  Quantity\tPrice\n----------------------------------------------------------\n",loggedinUserDetails.name,crrentTimeEpoch(),loggedinUserDetails.number);
            printf("%-25s\t\t%-2d\t%-10.2f\n",ff[selectItm-1].name,quantity,atof(ff[selectItm-1].price));
            puts("----------------------------------------------------------");
            printf("Subtotal:    $%-10.2f\nTax (15\%):    $%-10.2f\nTotal:       $%-12.2f",atof(ff[selectItm-1].price)*quantity,(atof(ff[selectItm-1].price)*quantity)*0.15,((atof(ff[selectItm-1].price)*quantity)*0.15)+(atof(ff[selectItm-1].price)*quantity));
            puts("\n");
            puts("Payment Method: Credit Card\nCard Number: **** **** **** 1234\n\nThank you for your purchase!");
            printf("1- Homepage\n2- Exit\n");
            int choiceHorE;
            scanf("%d",&choiceHorE);

            switch(choiceHorE)
            {
            case 1:
                system("cls");
                main();
                break;
            case 2:
                return 0;
                break;
            default:
                exit(0);
            }
        }
        else
        {
            if(selectItm>rc || selectItm<1)
            {
                printf("Sorry no food found with this number");
                showFoodsByID(1);
            }
            else if(quantity > 50)
            {
                printf("Our stock is limited. select less than 50!");
                showFoodsByID(1);
            }
            else if(quantity<1)
            {
                puts("Are you kidding me?");
                showFoodsByID(1);
            }
        }
    }
    else
    {
        getchar();
        btn2continue(1);
        main();
    }
}



//save food ordering history

void foodOrderingHistory(char fname[25],double tprice,int quantity)
{
    FILE *file;
    file =  fopen("orderhistory.db","a");
    if(file == NULL)
    {
        puts("Can't Open File");
        return;
    }
    else
    {
        int orderTime = currentEpochTime();
        fprintf(file,"%s,%s,%s,%d,%0.2lf,%d\n",loggedinUserDetails.name,loggedinUserDetails.number,fname,quantity,tprice,orderTime);
        fclose(file);
    }


}








