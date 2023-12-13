#include<stdlib.h>
int isAdmin = 0;
void AdminLogin(char username[20],char pass[20])
{
    if(strlen(username)>10&&strlen(pass)>5)
    {
        if(strcmp(username,"vectorstatic")==0&&strcmp(pass,"vector")==0)
        {
            isAdmin = 1;
            main();
        }
        else
        {
            puts("The number or password are incorrect.");
            adminLoginPopup();
        }
    }
    else
    {
        if(strlen(username)<5)
        {
            puts("username is too short.");

        }
        else if(strlen(pass)<6)
        {
            puts("Password is too short.");

        }
        adminLoginPopup();

    }
}

void viewUsers()
{
    FILE *file;
    file =  fopen("users.db","r");
    if(file == NULL)
    {
        printf("Error: users data not found");
        return;
    }
    else
    {
        int r = 0, rc = 0;
        system("cls");
        puts("****************************************************************************************");
        puts("***************************************UserList*****************************************");
        printf("*   No\t\t\tUsername\t\tNumber\t\tAccount created        *\n");
        do
        {
            char mobile[20],name[50],ept[25];
            r =  fscanf(file,
                        "%49[^,],%19[^,],%s\n",&name,mobile,ept);
            if(r == 3)
            {
                rc++;
                printf("- %3d\t%25s\t\t%11s\t%20s",rc,name,mobile,eptostdTime(atoi(ept)));
            };
            if(r!= 3 && !feof(file))
            {
                puts("Data format incorectly");
                return;
            }
        }
        while(!feof(file));
    }
    puts("****************************************************************************************");
    fclose(file);
    printf("Press any key to return home . .  ");
    getchar();
    getchar();
    system("cls");
    main();
}


//Adds foods
void addsFoods( Foods foods)
{
    FILE *file;
    file =  fopen("foods.txt","a");
    if(file == NULL)
    {
        puts("Can't Open File");
        return;
    }
    else
    {
        int currenttime = currentEpochTime();
        fprintf(file,
                "%s,%s,%s,%s\n",foods.name,foods.price,foods.rating,foods.categories);
        fclose(file);
        printf("%s",foods.name);
        puts(" Added successfully!");
        printf("Press any key to continue");
        getchar();
        main();
    }
}


//See order history

void viewOrderHistory()
{
    double totalPrice = 0.0;
    int totalOrdered = 0;
    FILE *file;
    file =  fopen("orderhistory.db","r");
    if(file == NULL)
    {
        printf("Error: users data not found");
        return;
    }
    else
    {
        int r = 0, rc = 0;
        system("cls");
           puts("****************************************************************************************************");
                   puts("***************************************Order History*****************************************");
        printf("*   No\tUser    \tNumber\t\tFoodName\t\t Total  Price\t\Order *\n");
        do
        {
            char umobile[12],uname[50],orderedT[25],foodName[25],tPrice[13],totalQ[4];
            r =  fscanf(file,
                        "%49[^,],%11[^,],%25[^,],%3[^,],%12[^,],%s\n",&uname,umobile,foodName,totalQ,tPrice,orderedT);
            if(r == 6)
            {
                rc++;
                printf("|--%3d\t%-15s\t%-11s\t%-25s  %s    %s\t%-20s",rc,uname,umobile,foodName,totalQ,tPrice,eptostdTime(atoi(orderedT)));
                totalOrdered += atoi(totalQ);
                totalPrice += atof(tPrice);

            };
            if(r!= 6 && !feof(file))
            {
                puts("Data format incorectly");
                return;
            }

        }
        while(!feof(file));

    }
    puts("");
    printf("Total Odered : %d\t\t Total Price : %0.2lf\n",totalOrdered,totalPrice);
    fclose(file);
    printf("Press any key to return home!");
    getchar();
    getchar();
    system("cls");
    main();
}
