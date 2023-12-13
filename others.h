#define space "               "
#define appsname "VECTOR STATICS FOOD MANAGEMENT & ORDERING SYSTEM"
#define devlopers
void btn2continue(int clearScreen){
    printf("\tPress any key to return Home...");
    getchar();
    getchar();
    if(clearScreen){
        system("cls");
    }
}

void clearScreen(){
    system("cls");
}
void homeCls(int btn){
    if(btn == 0){
    clearScreen();
    main();
    }
}


