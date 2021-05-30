#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void menu();
void newmap();
void printmap();
void about();
void help();
void save();
void sleep();
void spawn();
void command();
void farmer();
void trader();
void cook();
void check();
void profile();
void inventory();
void use();
void chest();
void fightcow();
void fightsheep();
void fightpig();
void fightchicken();
void fightgoose();
void fightwolf();
void fightfox();
void fightbandit();


int i, j;
int height = 20, width = 50; //map
char map[20][50]; //map
int x, y; //the user on the map
int heightH = 10, widthH = 15; //home
char home[10][15]; //home
int xH, yH; //the user in the house
int heightS = 30, widthS = 11; //shop
char shop[30][11]; //shop
int xS, yS; //the user in the shop
int m; //map
int loaded=0;
int alivemobs=0, win=0;
int quest[3];


int HP, MAXHP, STAMINA, MAXSTAMINA, XP, MAXXP, LV, AD, ARMOR, MONEY, SWORDID, ARMORID;
int MEAT, HIDE;
int COOKEDMEAT, LIFEPOTION, BISCUIT;
int MEATC, HIDEC;
int COOKEDMEATC, LIFEPOTIONC, BISCUITC; //items in the chest



struct mobs {
   char name[50];
   int HP;
   int AD;
   int ARMOR;
};

struct mobs cow;
    struct mobs sheep;
    struct mobs pig;
    struct mobs chicken;
    struct mobs goose;
    struct mobs wolf;
    struct mobs fox;
    struct mobs bandit;


int main()
{


    strcpy( cow.name, "Cow");
    cow.HP = 200;
    cow.AD = 2;
    cow.ARMOR = 3;
    strcpy( sheep.name, "Sheep");
    sheep.HP = 125;
    sheep.AD = 1;
    sheep.ARMOR = 4;
    strcpy( pig.name, "Pig");
    pig.HP = 300;
    pig.AD = 1;
    pig.ARMOR = 1;
    strcpy( chicken.name, "Chicken");
    chicken.HP = 40;
    chicken.AD = 6;
    chicken.ARMOR = 0;
    strcpy( goose.name, "Goose");
    goose.HP = 60;
    goose.AD = 5;
    goose.ARMOR = 1;
    strcpy( wolf.name, "Wolf");
    wolf.HP = 75;
    wolf.AD = 10;
    wolf.ARMOR = 2;
    strcpy( fox.name, "Fox");
    fox.HP = 70;
    fox.AD = 4;
    fox.ARMOR = 2;
    strcpy( bandit.name, "Bandit");
    bandit.HP = 100;
    bandit.AD = 5;
    bandit.ARMOR = 5;



    FILE *fp;
    char* filename = "stats.txt";
    char* filename1 = "inventory.txt";
    char* filename2 = "maps.txt";
    char* filename3 = "chest.txt";
    fp = fopen("stats.txt", "r");           //use data from files
    fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d", &HP, &MAXHP, &STAMINA, &MAXSTAMINA, &XP, &MAXXP, &LV, &AD, &ARMOR, &MONEY, &SWORDID, &ARMORID, &m);
    fclose(fp);
    fp = fopen("inventory.txt", "r");
    fscanf(fp, "%d %d %d %d %d", &MEAT, &HIDE, &COOKEDMEAT, &LIFEPOTION, &BISCUIT);
    fclose(fp);
    fp = fopen("maps.txt", "r");
    fscanf(fp, "%d %d %d %d %d %d %d %d %d %d", &m, &x, &y, &xH, &yH, &xS, &yS, &quest[0], &quest[1], &quest[2]);
    fclose(fp);
    fp = fopen("chest.txt", "r");
    fscanf(fp, "%d %d %d %d %d", &MEATC, &HIDEC, &COOKEDMEATC, &LIFEPOTIONC, &BISCUITC);
    fclose(fp);
    menu();

    do{
        if(XP>=MAXXP){
            XP=XP-MAXXP;
            MAXXP=MAXXP * 4;
            MAXHP+=5;
            MAXSTAMINA+=5;
            LV++;
            AD++;
            ARMOR++;

        }

    printmap();
    command();
    }while(1);
    return 0;
}

//Starting
void menu()
{
    char wish[30];
    int a;
    system("@cls");
    printf("xXxXx Killer On The Field xXxXx\n\n\n");
    printf("start\n\n");
    printf("about\n\n");
    printf("help\n\n");
    printf("quit\n\n\n");
    do{
        a=0;
        gets(wish);

        if(strcmp(wish,"start") == 0)start();
        else if (strcmp(wish,"about") == 0){about();a=1;}
        else if (strcmp(wish,"help") == 0){help();a=1;}
        else if (strcmp(wish,"quit") == 0)exit(0);
        else {printf("\nPlease select one of the options\n"); a=1;};
    }while(a==1);
}

//second menu
void start()
{
    int a;
    char wish[30];

    system("@cls");
    printf("new game\n\n");
    printf("load game\n\n");
    printf("back\n\n");

     do{
        a=0;
        gets(wish);
        if (strcmp(wish,"new game") == 0)newGame();
        else if (strcmp(wish,"load game") == 0)
            {
                loaded=1;
                newmap();
            }
        else if(strcmp(wish,"back") == 0)menu();
        else if (strcmp(wish,"quit") == 0)exit(0);
        else {printf("\nPlease select one of the options\n"); a=1;};
    }while(a==1);
}

//about file
void about()
{
    system("@cls");
    FILE *fp;
    fp = fopen("about.txt", "r");
    int a;
    char aa;
    printf("\n\n");
    if (fp) {
    while ((a = getc(fp)) != EOF)
        putchar(a);
    fclose(fp);
    }
    printf("\n\n");
    getch(aa);
    system("@cls");
    printf("xXxXx Killer On The Field xXxXx\n\n\n");
    printf("start\n\n");
    printf("about\n\n");
    printf("help\n\n");
    printf("quit\n\n\n");
}


//help file
void help()
{
    system("@cls");
    FILE *fp;
    fp = fopen("help.txt", "r");
    int a;
    char aa;
    printf("\n\n");
    if (fp) {
    while ((a = getc(fp)) != EOF)
        putchar(a);
    fclose(fp);
    }
    getch(aa);

    system("@cls");
    printf("xXxXx Killer On The Field xXxXx\n\n\n");
    printf("start\n\n");
    printf("about\n\n");
    printf("help\n\n");
    printf("quit\n\n\n");

}

//writing new data in the files and creating them if they don't exist
void newGame()
{
    HP=100, MAXHP=100, STAMINA=100, MAXSTAMINA=100, XP=0, MAXXP=1000, LV=1, AD=5, ARMOR=0, MONEY=0, SWORDID=0, ARMORID=0;
    MEAT=0, HIDE=0;
    COOKEDMEAT=2, LIFEPOTION=2, BISCUIT=2;
    MEATC=5, HIDEC=5;
    COOKEDMEATC=3, LIFEPOTIONC=3, BISCUITC=3;
    m=1, x=2, y=1, xH=13, yH=7, xS=5, yS=1;
    quest[0]=0;quest[1]=0;quest[2]=0;
    FILE *fp;
    char* filename = "stats.txt";
    char* filename1 = "inventory.txt";
    char* filename2 = "maps.txt";
    char* filename3 = "chest.txt";
    fp = fopen("stats.txt", "w");           //Writing data in the files
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d", HP, MAXHP, STAMINA, MAXSTAMINA, XP, MAXXP, LV, AD, ARMOR, MONEY, SWORDID, ARMORID, m);
    fclose(fp);
    fp = fopen("inventory.txt", "w");
    fprintf(fp, "%d %d %d %d %d", MEAT, HIDE, COOKEDMEAT, LIFEPOTION, BISCUIT);
    fclose(fp);
    fp = fopen("maps.txt", "w");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d", m, x, y, xH, yH, xS, yS, quest[0], quest[1], quest[2]);
    fclose(fp);
    fp = fopen("chest.txt", "w");
    fprintf(fp, "%d %d %d %d %d", MEATC, HIDEC, COOKEDMEATC, LIFEPOTIONC, BISCUITC);
    fclose(fp);

    newmap();
}


// Creating the map
void newmap()
{

	for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            if(i==0 || i==height-1 || j==0 || j==width-1) {
                map[i][j]='#';
            }
            else map[i][j]=' ';
        }
	}   //map


	map[2][1]='#';
	map[2][2]='#';
	map[3][48]='#';
	map[3][47]='#';
	map[3][46]='#';
	map[3][44]='#';
	map[2][44]='#';
	map[1][44]='#';
	map[18][4]='#';
	map[17][4]='#';
	map[18][6]='#';
	map[17][6]='#';
	map[18][5]='S';
	map[1][2]='O';
	map[1][1]='H';
	map[1][48]='F';

	for(i=0; i<heightH; i++){
        for(j=0; j<widthH; j++){
            if(i==0 || i==heightH-1 || j==0 || j==widthH-1) {
                home[i][j]='#';
            }
            else home[i][j]=' ';
        }
	} //house

	home[7][14]='E';
	if(loaded=0)
        {
            home[7][13]='O';
        }
	else home[yH][xH]='O';
	home[3][8]='B';
	home[8][1]='C';


	for(i=0; i<heightS; i++){
        for(j=0; j<widthS; j++){
            if(i==0 || i==heightS-1 || j==0 || j==widthS-1) {
                shop[i][j]='#';
            }
            else shop[i][j]=' ';
        }
	} //shop

    shop[1][5]='O';
    shop[0][5]='E';
    shop[25][5]='T';
    shop[10][1]='C';
}

//Printing the map
void printmap()
{
    system("@cls");
    if(m==1){
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            switch(map[i][j]){
            case '#': printf("#");break; //border
            case ' ': printf(" ");break; //space
            case 'O': printf("O");break; //player
            case 'S': printf("S");break; //shop
            case 'F': printf("F");break; //farmer
            case 'c': printf("c");break; //cow
            case 's': printf("s");break; //sheep
            case 'p': printf("p");break; //pig
            case 'h': printf("h");break; //chicken
            case 'g': printf("g");break; //goose
            case 'w': printf("w");break; //wolf
            case 'f': printf("f");break; //fox
            case 'b': printf("b");break; //bandit
            case 'H': printf("H");break; //house
            }

        }
        printf("\n");

	}
	printf("S - Shop      F - Farmer  H - House\nc - Cow       s - Sheep   p - Pig\nf - Fox       g - Goose   w - Wolf\nh - Chicken   b - Bandit");
    }

    if(m==2){
        for(i=0; i<heightH; i++){
            for(j=0; j<widthH; j++){
                switch(home[i][j]){
                case '#': printf("#");break;
                case ' ': printf(" ");break;
                case 'O': printf("O");break;
                case 'E': printf("E");break; //exit
                case 'C': printf("C");break; //chest
                case 'B': printf("B");break; //bed
            }

        }
        printf("\n");
        }
        printf("B - Bed     C - Chest      E - Exit");
    }

    if(m==3){
        for(i=0; i<heightS; i++){
            for(j=0; j<widthS; j++){
                switch(shop[i][j]){
                case '#': printf("#");break;
                case ' ': printf(" ");break;
                case 'O': printf("O");break;
                case 'E': printf("E");break;
                case 'T': printf("T");break; //trader
                case 'C': printf("C");break; //cook
            }

        }
        printf("\n");
        }
        printf("T - Trader      C - Cook    E - Exit");
    }
}

//the input of the user
void command()
{

    int action;
    action = getch();
    switch(action){
    case 'a':
    if(m==1){
    if(map[y][x-1]==' '){
        map[y][x]=' ';
        map[y][x-1]='O';
        x=x-1;
        }
    }
    if(m==2){
        if(home[yH][xH-1]==' '){
        home[yH][xH]=' ';
        home[yH][xH-1]='O';
        xH=xH-1;
        }
    }
    if(m==3){
        if(shop[yS][xS-1]==' '){
        shop[yS][xS]=' ';
        shop[yS][xS-1]='O';
        xS=xS-1;
        }
    }
        break;
    case 'w':
    if(m==1){
    if(map[y-1][x]==' '){
        map[y][x]=' ';
        map[y-1][x]='O';
        y=y-1;
        }
    }
    if(m==2){
        if(home[yH-1][xH]==' '){
        home[yH][xH]=' ';
        home[yH-1][xH]='O';
        yH=yH-1;
        }
    }
    if(m==3){
        if(shop[yS-1][xS]==' '){
        shop[yS][xS]=' ';
        shop[yS-1][xS]='O';
        yS=yS-1;
        }
    }
        break;

    case 'd':
    if(m==1){
    if(map[y][x+1]==' '){
        map[y][x]=' ';
        map[y][x+1]='O';
        x=x+1;
        }
    }
    if(m==2){
        if(home[yH][xH+1]==' '){
        home[yH][xH]=' ';
        home[yH][xH+1]='O';
        xH=xH+1;
        }
    }
    if(m==3){
        if(shop[yS][xS+1]==' '){
        shop[yS][xS]=' ';
        shop[yS][xS+1]='O';
        xS=xS+1;
        }
    }
        break;
    case 's':
    if(m==1){
    if(map[y+1][x]==' '){
        map[y][x]=' ';
        map[y+1][x]='O';
        y=y+1;
        }
    }
    if(m==2){
        if(home[yH+1][xH]==' '){
        home[yH][xH]=' ';
        home[yH+1][xH]='O';
        yH=yH+1;
        }
    }
    if(m==3){
        if(shop[yS+1][xS]==' '){
        shop[yS][xS]=' ';
        shop[yS+1][xS]='O';
        yS=yS+1;
        }
    }
        break;

    case 'e':
        check();
        break;

    case 'p':
        profile();
        break;

    case 'i':
        inventory();
        break;

    case 'u':
        use();
        break;
    }
}

//checking the area around the player
void check()
{
    int helpm;
    helpm=m;
    if(m==1&&helpm==1){
    switch(map[y-1][x]){
    case 'S':
        m=3;
        break;
    case 'H':
        m=2;
        break;
    case 'F':
        farmer();
        break;
    case 'c':
        fightcow();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 's':
        fightsheep();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'p':
        fightpig();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'h':
        fightchicken();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'g':
        fightgoose();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'w':
        fightwolf();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'f':
        fightfox();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'b':
        fightbandit();
        if(win==1){
            map[y-1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    }
    switch(map[y+1][x]){
    case 'S':
        m=3;
        break;
    case 'H':
        m=2;
        break;
    case 'F':
        farmer();
        break;
    case 'c':
        fightcow();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 's':
        fightsheep();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'p':
        fightpig();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'h':
        fightchicken();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'g':
        fightgoose();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'w':
        fightwolf();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'f':
        fightfox();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'b':
        fightbandit();
        if(win==1){
            map[y+1][x]=' ';
            win=0;
            alivemobs--;
        }
        break;
    }
    switch(map[y][x-1]){
    case 'S':
        m=3;
        break;
    case 'H':
        m=2;
        break;
    case 'F':
        farmer();
        break;
    case 'c':
        fightcow();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 's':
        fightsheep();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'p':
        fightpig();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'h':
        fightchicken();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'g':
        fightgoose();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'w':
        fightwolf();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'f':
        fightfox();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'b':
        fightbandit();
        if(win==1){
            map[y][x-1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    }
    switch(map[y][x+1]){
    case 'S':
        m=3;
        break;
    case 'H':
        m=2;
        break;
    case 'F':
        farmer();
        break;
    case 'c':
        fightcow();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 's':
        fightsheep();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'p':
        fightpig();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'h':
        fightchicken();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'g':
        fightgoose();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'w':
        fightwolf();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'f':
        fightfox();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    case 'b':
        fightbandit();
        if(win==1){
            map[y][x+1]=' ';
            win=0;
            alivemobs--;
        }
        break;
    }
    }
    if(m==2&&helpm==2){
        switch(home[yH-1][xH]){
        case 'B':
            sleep();
            save();
            break;
        case 'E':
            m=1;
            break;
        case 'C':
            chest();
            break;
        }
        switch(home[yH+1][xH]){
        case 'B':
            sleep();
            save();
            break;
        case 'E':
            m=1;
            break;
        case 'C':
            chest();
            break;
        }
        switch(home[yH][xH-1]){
        case 'B':
            sleep();
            save();
            break;
        case 'E':
            m=1;
            break;
        case 'C':
            chest();
            break;
        }
        switch(home[yH][xH+1]){
        case 'B':
            sleep();
            save();
            break;
        case 'E':
            m=1;
            break;
        case 'C':
            chest();
            break;
        }
    }
    if(m==3&&helpm==3){
        switch(shop[yS-1][xS]){
        case 'T':
            trader();
            break;
        case 'C':
            cook();
            break;
        case 'E':
            m=1;
            break;
        }
        switch(shop[yS+1][xS]){
        case 'T':
            trader();
            break;
        case 'C':
            cook();
            break;
        case 'E':
            m=1;
            break;
        }
        switch(shop[yS][xS-1]){
        case 'T':
            trader();
            break;
        case 'C':
            cook();
            break;
        case 'E':
            m=1;
            break;
        }
        switch(shop[yS][xS+1]){
        case 'T':
            trader();
            break;
        case 'C':
            cook();
            break;
        case 'E':
            m=1;
            break;
        }

    }
}

//printing the profile
void profile()
{
    system("@cls");
    printf("\n\n\nPROFILE\n\n\n");

    printf("%d/%d HP   ", HP, MAXHP);
    printf("%d/%d STAMINA\n", STAMINA, MAXSTAMINA);
    printf("%d/%d XP   ", XP, MAXXP);
    printf("%d LVL\n", LV);
    printf("%d MONEY\n", MONEY);
    printf("%d AD   %d ARMOR\n\n", AD, ARMOR);


    switch(SWORDID){
    case 0: printf("No sword");break;
    case 1: printf("Wooden sword");break;
    case 2: printf("Stone sword");break;
    case 3: printf("Silver sword");break;
    case 4: printf("Golden sword");break;
    case 5: printf("Diamond sword");break;
    case 6: printf("God sword");break;
    }
    printf("\n");
    switch(ARMORID){
    case 0: printf("No armor");break;
    case 1: printf("Hide armor");break;
    case 2: printf("Silver armor");break;
    case 3: printf("Golden armor");break;
    case 4: printf("Diamond armor");break;
    case 5: printf("God armor");break;
    }
    printf("\n\n\n");
    char a;
    getch(a);

}

//printing the inventory
void inventory()
{
    system("@cls");
    printf("\n\n\nINVENTORY\n\n\n");
    printf("RESOURCES\nMEAT : %d\nHIDE : %d\n\n", MEAT, HIDE);
    printf("CONSUMPTIVES\nCOOKED MEAT : %d\nLIFE POTION : %d\nBISCUIT : %d\n", COOKEDMEAT, LIFEPOTION, BISCUIT);
    printf("\n\n");
    char a;
    getch(a);

}

//using consumptives
void use()
{
    system("@cls");
    char wish[30];


    printf("\n\nWhat do you want to use:\ncooked meat : %d\nlife potion : %d\nbiscuit : %d\n", COOKEDMEAT, LIFEPOTION, BISCUIT);
    gets(wish);
    if (strcmp(wish,"cooked meat") == 0){
        if(COOKEDMEAT==0){
            printf("\nYou don't have cooked meat!\n");
            return 0;
        }
        else{
            printf("\nYou healed yourself for 50HP\n");
            HP+=50;
            if(HP>MAXHP)HP=MAXHP;
            COOKEDMEAT--;
        }
    }

    else if (strcmp(wish,"life potion") == 0){
        if(LIFEPOTION==0){
            printf("\nYou don't have life potions!\n");
            return 0;
        }
        else{
            printf("\nYou healed yourself for 100HP\n");
            HP+=100;
            if(HP>MAXHP)HP=MAXHP;
            LIFEPOTION--;
        }
    }

    else if (strcmp(wish,"biscuit") == 0){
        if(BISCUIT==0){
            printf("\nYou don't have biscuits!\n");
            return 0;
        }
        else{
            printf("\nYou healed yourself for 20HP\n");
            HP+=20;
            if(HP>MAXHP)HP=MAXHP;
            BISCUIT--;
        }
    }

    else if (strcmp(wish,"quit") == 0)return 0;

    char a;
    getch(a);
}

//printing the chest
void chest()
{
    system("@cls");
    char wish[30];
    char wish2[5];
    char a;

    printf("\nINVENTORY\n\n\n");
    printf("RESOURCES\nMEAT : %d\nHIDE : %d\n\n", MEAT, HIDE);
    printf("CONSUMATIVES\nCOOKED MEAT : %d\nLIFE POTION : %d\nBISCUIT : %d\n", COOKEDMEAT, LIFEPOTION, BISCUIT);
    printf("\n\n");
    printf("CHEST\n\n\n");
    printf("RESOURCES\nMEAT : %d\nHIDE : %d\n\n", MEATC, HIDEC);
    printf("CONSUMATIVES\nCOOKED MEAT : %d\nLIFE POTION : %d\nBISCUIT : %d\n", COOKEDMEATC, LIFEPOTIONC, BISCUITC);
    printf("\n\n");
    printf("NOTE: Use 'cooked' for 'COOKED MEAT' and 'potion' for 'LIFE POTION'. Otherwise the game will crash cuz C sucks!\n");

    scanf("%s", wish);
    if (strcmp(wish,"quit") == 0)return 0;
    printf("Enter amount : ");
    int amount=0;
    do{
        scanf("%d", &amount);
    }while(amount<1);

    printf("in or out?\n");

    scanf("%s", wish2);


    if (strcmp(wish,"meat") == 0){

        if(strcmp(wish2,"in") == 0){
                if(MEAT<amount){
                    printf("\nYou don't have enough meat!\n");
                }
                else{
                    MEAT=MEAT-amount;
                    MEATC=MEATC+amount;
                }
            return 0;
        }
        else if(strcmp(wish2,"out") == 0){
            if(MEATC<amount){
                    printf("\nYou don't have enough meat in your chest!\n");
                }
                else{
                    MEAT=MEAT+amount;
                    MEATC=MEATC-amount;
                }
        }
    }

    else if (strcmp(wish,"hide") == 0){
        if(strcmp(wish2,"in") == 0){
                if(HIDE<amount){
                    printf("\nYou don't have enough hide!\n");
                }
                else{
                    HIDE=HIDE-amount;
                    HIDEC=HIDEC+amount;
                }
            return 0;
        }
        else if(strcmp(wish2,"out") == 0){
            if(HIDE<amount){
                    printf("\nYou don't have enough hide in your chest!\n");
                }
                else{
                    HIDE=HIDE+amount;
                    HIDEC=HIDEC-amount;
                }
        }
    }

    else if (strcmp(wish,"cooked") == 0){
        if(strcmp(wish2,"in") == 0){
                if(COOKEDMEAT<amount){
                    printf("\nYou don't have enough cooked meat!\n");
                }
                else{
                    COOKEDMEAT=COOKEDMEAT-amount;
                    COOKEDMEATC=COOKEDMEATC+amount;
                }
            return 0;
        }
        else if(strcmp(wish2,"out") == 0){
            if(COOKEDMEATC<amount){
                    printf("\nYou don't have enough cooked meat in your chest!\n");
                }
                else{
                    COOKEDMEAT=COOKEDMEAT+amount;
                    COOKEDMEATC=COOKEDMEATC-amount;
                }
        }
    }

    else if (strcmp(wish,"potion") == 0){
        if(strcmp(wish2,"in") == 0){
                if(LIFEPOTION<amount){
                    printf("\nYou don't have enough life potions!\n");
                }
                else{
                    LIFEPOTION=LIFEPOTION-amount;
                    LIFEPOTIONC=LIFEPOTIONC+amount;
                }
            return 0;
        }
        else if(strcmp(wish2,"out") == 0){
            if(LIFEPOTIONC<amount){
                    printf("\nYou don't have enough life potions in your chest!\n");
                }
                else{
                    LIFEPOTION=LIFEPOTION+amount;
                    LIFEPOTIONC=LIFEPOTIONC-amount;
                }
        }
    }

    else if (strcmp(wish,"biscuit") == 0){
        if(strcmp(wish2,"in") == 0){
                if(BISCUIT<amount){
                    printf("\nYou don't have enough biscuits!\n");
                }
                else{
                    BISCUIT=BISCUIT-amount;
                    BISCUITC=BISCUITC+amount;
                }
            return 0;
        }
        else if(strcmp(wish2,"out") == 0){
            if(BISCUITC<amount){
                    printf("\nYou don't have enough biscuits in your chest!\n");
                }
                else{
                    BISCUIT=BISCUIT+amount;
                    BISCUITC=BISCUITC-amount;
                }
        }
    }


    getch(a);

}

//saving the game
void save()
{
    system("@cls");
    FILE *fp;
    char* filename = "stats.txt";
    char* filename1 = "inventory.txt";
    char* filename2 = "maps.txt";
    char* filename3 = "chest.txt";
    fp = fopen("stats.txt", "w");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d", HP, MAXHP, STAMINA, MAXSTAMINA, XP, MAXXP, LV, AD, ARMOR, MONEY, SWORDID, ARMORID, m);
    fclose(fp);
    fp = fopen("inventory.txt", "w");
    fprintf(fp, "%d %d %d %d %d", MEAT, HIDE, COOKEDMEAT, LIFEPOTION, BISCUIT);
    fclose(fp);
    fp = fopen("maps.txt", "w");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d", m, x, y, xH, yH, xS, yS, quest[0], quest[1], quest[2]);
    fclose(fp);
    fp = fopen("chest.txt", "w");
    fprintf(fp, "%d %d %d %d %d", MEATC, HIDEC, COOKEDMEATC, LIFEPOTIONC, BISCUITC);
    fclose(fp);

    printf("Your game is saved. Now you can close the game.");
    char a;
    getch(a);

}

//sleeping and regenerating stamina
void sleep()
{
    system("@cls");
    time_t curentTime, curentTime1;
    time(&curentTime);
    printf("Sleeping...\nPlease do not try to do anything\n");
    do{
        time(&curentTime1);
    }while(curentTime1-curentTime<60);
    system("@cls");
    printf("You rested and refilled 10 Stamina\n");
    STAMINA+=10;
    if(STAMINA>MAXSTAMINA)STAMINA=MAXSTAMINA;
    spawn();
    char a;
    getch(a);
}

//spawning new mobs on the map
void spawn()
{
    int num, xran, yran;
    srand(time(0));
    for(i=0;i<2;i++){
        if(alivemobs<10){
            num = (rand() %8) + 1;

        do{
            yran = rand() %20;
            xran = rand() %50;
        }while(map[yran][xran]!=' ');

        switch(num){
        case 1:
            map[yran][xran]='c';
            break;
        case 2:
            map[yran][xran]='s';
            break;
        case 3:
            map[yran][xran]='p';
            break;
        case 4:
            map[yran][xran]='h';
            break;
        case 5:
            map[yran][xran]='g';
            break;
        case 6:
            map[yran][xran]='w';
            break;
        case 7:
            map[yran][xran]='f';
            break;
        case 8:
            map[yran][xran]='b';
            break;
        }
        alivemobs++;
        }
    }
}

//The farmer and his missions
void farmer()
{
    system("@cls");
    srand(time(0));
    if(quest[0]==0){
        quest[0] = (rand() %10) + 1;
        quest[1] = (rand() %10) + 1;
        switch(quest[0]){
        case 1:
            printf("Kill %d cow/s", quest[1]);
            break;
        case 2:
            printf("Kill %d sheep/s", quest[1]);
            break;
        case 3:
            printf("Kill %d pig/s", quest[1]);
            break;
        case 4:
            printf("Kill %d chicken/s", quest[1]);
            break;
        case 5:
            printf("Kill %d goose/s", quest[1]);
            break;
        case 6:
            printf("Kill %d wolf/s", quest[1]);
            break;
        case 7:
            printf("Kill %d fox/es", quest[1]);
            break;
        case 8:
            printf("Kill %d bandit/s", quest[1]);
            break;
        case 9:
            printf("Bring me %d meat", quest[1]);
            break;
        case 10:
            printf("Bring me %d hide", quest[1]);
            break;
        }
    }
    else if(quest[0]>=0&&quest[0]<=8){
        if(quest[2]>=quest[1]){
            printf("You completed the quest! Your prize is %d Money and %d XP", quest[1] * 10, quest[1] * 15);
            MONEY = MONEY + (quest[1] * 10);
            XP = XP + (quest[1] * 15);
            quest[0]=0;
            quest[1]=0;
            quest[2]=0;
        }
        else{
            printf("You killed %d from %d!", quest[2], quest[1]);
        }
    }

    else if (quest[0]>=9&&quest[0]<=10){
            if(quest[0]==9)quest[2]=MEAT;
            if(quest[0]==10)quest[2]=HIDE;
        if(quest[1]>quest[2]){
            printf("You don't have enough resources!");
        }
        else{
            printf("Thank you! Your prize is %d Money and %d XP", quest[1] * 7, quest[1] * 7);
            MONEY = MONEY + (quest[1] * 7);
            XP = XP + (quest[1] * 7);
            if(quest[0]==9)MEAT=MEAT-quest[1];
            if(quest[0]==10)HIDE=HIDE-quest[1];
            quest[0]=0;
            quest[1]=0;
            quest[2]=0;
        }
    }



    char a;
    getch(a);
}

//The trader
void trader()
{
    system("@cls");
    int buy;
    char aa;

    printf("Welcome! Check my items, you may like some of them!\n");
    printf("1 - Life potion - 100 MONEY\n2 - Biscuit - 20 MONEY\n3 - Wooden sword(5AD) - 500 MONEY\n4 - Stone sword(12AD) - 2000 MONEY\n5 - Hide armor(2ARMOR) - 400 MONEY\n6 - Silver armor(6ARMOR) - 2800 MONEY\n7 - Sell sword\n8 - Sell armor\n9 - Leave\n\n");
    do{
        scanf("%d", &buy);
    }while(buy<1||buy>9);

    switch(buy){
    case 1:
        if(MONEY<100)printf("You don't have enough money!");
        else{
            LIFEPOTION++;
            MONEY-=100;
            printf("You bought one Life potion!");
        }
        break;
    case 2:
        if(MONEY<20)printf("You don't have enough money!");
        else{
            BISCUIT++;
            MONEY-=20;
            printf("You bought one Biscuit!");
        }
        break;
    case 3:
        if(MONEY<500)printf("You don't have enough money!");
        else if(SWORDID>0)printf("You already have a sword!");
        else{
            SWORDID=1;
            MONEY-=500;
            AD+=5;
            printf("You bought a Wooden sword!");
        }
        break;
    case 4:
        if(MONEY<2000)printf("You don't have enough money!");
        else if(SWORDID>0)printf("You already have a sword!");
        else{
            SWORDID=2;
            MONEY-=2000;
            AD+=12;
            printf("You bought a Stone sword!");
        }
        break;
    case 5:
        if(MONEY<400)printf("You don't have enough money!");
        else if(ARMORID>0)printf("You already have an armor!");
        else{
            ARMORID=1;
            MONEY-=400;
            ARMOR+=2;
            printf("You bought a Hide armor!");
        }
        break;
    case 6:
        if(MONEY<2800)printf("You don't have enough money!");
        else if(ARMORID>0)printf("You already have an armor!");
        else{
            ARMORID=2;
            MONEY-=2800;
            ARMOR+=6;
            printf("You bought a Silver armor!");
        }
        break;
    case 7:
        if(SWORDID==0)printf("You don't have a sword!");
        else{
            switch (SWORDID){
            case 1 :
                AD-=5;
                MONEY+=100;
                break;
            case 2 :
                AD-=12;
                MONEY+=400;
                break;
            }
            SWORDID=0;
            printf("You sold your sword!");
        }
        break;
    case 8:
        if(ARMORID==0)printf("You don't have an armor!");
        else{
            switch (ARMORID){
            case 1 :
                ARMOR-=2;
                MONEY+=80;
                break;
            case 2 :
                ARMOR-=6;
                MONEY+=700;
                break;
            }
            ARMORID=0;
            printf("You sold your armor!");
        }
        break;
    }
    getch(aa);
}

//The cook
void cook()
{
    system("@cls");
    int cooking;
    char aa;
    printf("Welcome! If you give me 1 Meat and 30 Money I can cook the meat for you!\n1 - Give\n2 - Leave\n\n");
    do{
        scanf("%d", &cooking);
    }while(cooking<1||cooking>2);
    switch(cooking){
    case 1:
        if(MEAT<1)printf("You don't have Meat");
        else if(MONEY<30)printf("You don't have enough Money");
        else{
            MEAT--;
            MONEY-=30;
            COOKEDMEAT++;
        }
        break;
    }
    getch(aa);

}

//Fight with cow
void fightcow()
{
    int attack;
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = cow.HP;
    MOBAD = cow.AD;
    MOBARMOR = cow.ARMOR;

    do{
        system("@cls");
        printf("You are fighting a %s\n", cow.name);
        printf("\nYour HP : %d      Cow's HP : %d\nYour AD : %d      Cow's AD : %d\nYour AR : %d      Cow's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 2 Hide and 2 Meat\n");
        HIDE+=2;
        MEAT+=2;
        XP+=20;
        win=1;
        if(quest[0]==1)quest[2]++;
    }

    char a;
    getch(a);
}

//Fight with sheep
void fightsheep()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = sheep.HP;
    MOBAD = sheep.AD;
    MOBARMOR = sheep.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", sheep.name);
        printf("\nYour HP : %d      Sheep's HP : %d\nYour AD : %d      Sheep's AD : %d\nYour AR : %d      Sheep's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 1 Hide and 3 Meat\n");
        HIDE+=1;
        MEAT+=3;
        XP+=25;
        win=1;
        if(quest[0]==2)quest[2]++;
    }

    char a;
    getch(a);
}

//Fight with pig
void fightpig()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = pig.HP;
    MOBAD = pig.AD;
    MOBARMOR = pig.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", pig.name);
        printf("\nYour HP : %d      Pig's HP : %d\nYour AD : %d      Pig's AD : %d\nYour AR : %d      Pig's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 6 Meat\n");
        MEAT+=6;
        XP+=30;
        win=1;
        if(quest[0]==3)quest[2]++;
    }

    char a;
    getch(a);

}

//Fight with chicken
void fightchicken()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = chicken.HP;
    MOBAD = chicken.AD;
    MOBARMOR = chicken.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", chicken.name);
        printf("\nYour HP : %d      Chicken's HP : %d\nYour AD : %d      Chicken's AD : %d\nYour AR : %d      Chicken's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 1 Meat\n");
        MEAT+=1;
        XP+=10;
        win=1;
        if(quest[0]==4)quest[2]++;
    }

    char a;
    getch(a);

}

//Fight with goose
void fightgoose()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = goose.HP;
    MOBAD = goose.AD;
    MOBARMOR = goose.ARMOR;


    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", goose.name);
        printf("\nYour HP : %d      Goose's HP : %d\nYour AD : %d      Goose's AD : %d\nYour AR : %d      Goose's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 2 Meat\n");
        MEAT+=2;
        XP+=15;
        win=1;
        if(quest[0]==5)quest[2]++;
    }

    char a;
    getch(a);

}

//Fight with wolf
void fightwolf()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = wolf.HP;
    MOBAD = wolf.AD;
    MOBARMOR = wolf.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", wolf.name);
        printf("\nYour HP : %d      Wolf's HP : %d\nYour AD : %d      Wolf's AD : %d\nYour AR : %d      Wolf's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 4 Hide and 2 Meat\n");
        HIDE+=4;
        MEAT+=2;
        XP+=40;
        win=1;
        if(quest[0]==6)quest[2]++;
    }

    char a;
    getch(a);

}

//Fight with fox
void fightfox()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = fox.HP;
    MOBAD = fox.AD;
    MOBARMOR = fox.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", fox.name);
        printf("\nYour HP : %d      Fox's HP : %d\nYour AD : %d      Fox's AD : %d\nYour AR : %d      Fox's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 2 Hide and 2 Meat\n");
        HIDE+=2;
        MEAT+=2;
        XP+=35;
        win=1;
        if(quest[0]==7)quest[2]++;
    }

    char a;
    getch(a);

}

//Fight with bandit
void fightbandit()
{
    int MOBHP, MOBAD, MOBARMOR;
    MOBHP = bandit.HP;
    MOBAD = bandit.AD;
    MOBARMOR = bandit.ARMOR;

    int attack;

    do{
        system("@cls");
        printf("You are fighting a %s\n", bandit.name);
        printf("\nYour HP : %d      Bandit's HP : %d\nYour AD : %d      Bandit's AD : %d\nYour AR : %d      Bandit's AR : %d\n\n\n", HP, MOBHP, AD, MOBAD, ARMOR, MOBARMOR);
        printf("\nYour stamina is %d/%d\nChoose type of attack : \n1 - Normal attack (no cost)\n2 - Power attack (5 Stamina)\n", STAMINA, MAXSTAMINA);
        if(LIFEPOTION>0)printf("3 - Use Life Potion\n");
        do{
        scanf("%d", &attack);
        }while(attack<1||attack>3);
        switch(attack){
        case 1: if(AD>MOBARMOR)MOBHP = MOBHP - AD + MOBARMOR;break;
        case 2:
            if(STAMINA<5)break;
            if(AD * 2>MOBARMOR)MOBHP = MOBHP - (AD * 2) + MOBARMOR;
            STAMINA-=5;
            break;
        case 3:
            if(LIFEPOTION>0){
                HP+=100;
                if(HP>MAXHP)HP=MAXHP;
                LIFEPOTION--;
            }
            break;
        }
        if(MOBAD>ARMOR)HP = HP - MOBAD + ARMOR;
    }while(HP>0&&MOBHP>0);
    if(HP<=0) {
        printf("You died!\n");
        XP=0;
        HP=MAXHP;
        STAMINA=MAXSTAMINA;
        MEAT=0, HIDE=0; COOKEDMEAT=0, LIFEPOTION=0, BISCUIT=0;
    }
    else{
        printf("You won!\nYou collected 10 Money\n");
        MONEY+=10;
        XP+=50;
        win=1;
        if(quest[0]==8)quest[2]++;
    }

    char a;
    getch(a);

}
