
#include"timess.h"
#include"others.h"
struct UserSignup
{
    char number[12];
    char name[50];
};

int isLoggedIn = 1;
struct UserSignup loggedinUserDetails;


//Create a new account with number and username
void createAccount(struct UserSignup u)
{
    int numExist = checknumberExist(u.number);


    if(numExist == 1)
    {
        FILE *file;
        file =  fopen("users.db","a");
        if(file == NULL)
        {
            puts("Can't Open File");
            return;
        }
        else
        {
            int currenttime = currentEpochTime();//12344
            fprintf(file,"%s,%s,%d\n",u.name,u.number,currenttime);
            fclose(file);
            printf("%s",u.name);
            puts(" Created successfully!");
            strcpy( loggedinUserDetails.name,u.name);
            strcpy(loggedinUserDetails.number,u.number);
            isLoggedIn = 1;
            btn2continue(1);
        }
    }
    else
    {
        system("cls");
        printf("|--User found with this number! Try to login\n|--");
        btn2continue(0);

    }
}


//check number exist or not if exist it will make isLoggedIn true ;
int checkUserExist(char num[20])
{


    FILE *file;
    file =  fopen("users.db","r");
    if(file == NULL)
    {
        return 1;
    }
    else
    {
        int r = 0, rc = 0;
        do
        {
             char mobile[20],name[50],ept[25];
            r =  fscanf(file,
                        "%49[^,],%19[^,],%s\n",&name,mobile,ept);


            if(strcmp(mobile,num) == 0)
            {
                isLoggedIn = 1;
                strcpy( loggedinUserDetails.name,name);
                strcpy(loggedinUserDetails.number,mobile);
                return 2;
            }

            if(r == 3) rc++;

            if(r!= 3 && !feof(file))
            {
                puts("Data format incorectly");
                return 1;
            }
        }
        while(!feof(file));
    }
    fclose(file);
    return 1;
}


//check number already exist or not in users.db. if exist it will return 2 otherwise 1;
int checknumberExist(char num[20])
{
    FILE *file;
    file =  fopen("users.db","r");
    if(file == NULL)
    {
        //Error
        return 1;
    }
    else
    {
        int r = 0, rc = 0;
        do
        {
            char mobile[20],name[50],ept[25];
            r =  fscanf(file,
                        "%49[^,],%19[^,],%s\n",&name,mobile,ept);
            if(strcmp(mobile,num) == 0)
            {
                return 2;
            }
            if(r == 3) rc++;
            if(r!= 3 && !feof(file))
            {
                puts("Data format incorectly");
                return 1;
            }
        }
        while(!feof(file));
    }
    fclose(file);
    return 1;
}
