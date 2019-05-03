#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>

int enterchoice()
{

    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("Railway Reservation System\n");
    for(i=1; i<=79; i++)
        printf("-");
    printf("\nSelect an option\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No\n");
    printf("5- View All Bookings\n");
    printf("6- View Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- QUIT\n");
    printf("\nEnter Choice:");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}

void add_trains()
{
    FILE *fp=fopen("d:\\my project\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrain[4]=
        {
            {"123","BPL","GWA",2100,1500},
            {"546","BPL","DEL",3500,2240},
            {"345","HBJ","AGR",1560,1135},
            {"896","HBJ","MUM",4500,3360}
        };
        fp=fopen("d:\\my project\\alltrains.dat","wb");
        fwrite(alltrain,4*sizeof(Train),1,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
}
void view_train()
{
    clrscr();
    int i;
    textcolor(YELLOW);
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
    for(i=1; i<=78; i++)
        printf("-");
    FILE *fp=fopen("d:\\my project\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {

        printf("%s\t\t%s\t%s\t%d\t\t%d\n",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }
    fclose(fp);
    textcolor(WHITE);
    printf("\n\n\nPress any Key to go back to the main screen\n");
    getch();
    clrscr();
}
int check_train_no(char* trainno)
{
    FILE *fp=fopen("d:\\my project\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int check_mob_no(char* mobno)
{
    if(strlen(mobno)!=10)
        return 0;
    while(*mobno!='\0')
    {
        if(isdigit(*mobno)==0)
        {
            return 0;
        }
        mobno++;
    }
    return 1;
}
Passenger *get_passenger_details()
{
    clrscr();
    gotoxy(105,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,28);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    int valid;
    printf("Enter Gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            printf("Error!Gender should be M or F(in Uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            textcolor(YELLOW);
            printf(" \b");
        }
    }
    while(valid==0);
    gotoxy(1,28);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter Train Number:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(psn.train_no,10,stdin);
        pos=strchr(psn.train_no,'\n');
        *pos='\0';
        if(strcmp(psn.train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(check_train_no(psn.train_no)==0)
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            valid=0;
            printf("Error!Invalid Train No");
            gotoxy(20,3);
            printf("     \b\b\b\b\b");
            textcolor(YELLOW);
        }
    }
    while(valid==0);
    gotoxy(1,28);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter Travelling Class(First AC-F,Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            printf("Error!Travelling class should be F or S(in Uppercase)");
            valid=0;
            getch();
            gotoxy(48,4);
            textcolor(YELLOW);
            printf("     \b\b\b\b\b");
        }
    }
    while(valid==0);
    gotoxy(1,28);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,5);

    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,25,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,28);
        printf("\t\t\t\t\t\t\t\t\t");
        gotoxy(1,28);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter age:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(psn.age<0)
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            printf("Error!Age should be Positive)");
            valid=0;
            getch();
            gotoxy(11,6);
            textcolor(YELLOW);
            printf("      \b\b\b\b\b\b");
        }
    }
    while(valid==0);
    gotoxy(1,28);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter Mobile Number:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(psn.mob_no,11,stdin);
        pos=strchr(psn.address,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(check_mob_no(psn.mob_no)==0)
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            printf("Error!Invalid Mobile no.:");
            valid=0;
            getch();
            gotoxy(21,7);
            textcolor(YELLOW);
            printf("            \b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    while(valid==0);
    gotoxy(1,28);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,8);

    clrscr();
    return &psn;
}
int get_booked_ticket_count(char* train_no,char t_class)
{
    FILE *fp=fopen("d:\\my project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }

    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==t_class)
            ++count;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    Passenger pr;
    FILE *fp=fopen("d:\\my project\\\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    if(fread(&pr,sizeof(pr),1,fp)!=1)
                return 0;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}
int book_ticket(Passenger P)
{
    int count;
    if(get_booked_ticket_count(P.train_no,P.p_class)==30)
    {
        textcolor(LIGHTRED);
        printf("All seats full in Train no. %s in %c class!\n",P.train_no,P.p_class);

        return -1;
    }
    count=last_ticket_no()+1;
    P.ticketno=count;
    FILE *fp=fopen("d:\\my project\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File Cannot be opened");
        return -1;
    }
    fwrite(&P,sizeof(P),1,fp);
    fclose(fp);
    return P.ticketno;
}
void view_ticket(int ticket_no)
{
    textcolor(YELLOW);
    Passenger p;
    int found=0;
    FILE *fp=fopen("d:\\my project\\\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(ticket_no==p.ticketno)
        {
            clrscr();
            printf("Ticket no: %d\n",p.ticketno);
            printf("Passenger Name: %s\n",p.p_name);
            printf("Train no: %s\n",p.train_no);
            printf("Gender: %c\n",p.gender);
            printf("Address: %s\n",p.address);
            printf("Mobile no: %s\n",p.mob_no);
            printf("Age: %d\n",p.age);
            printf("Travelling class: %c\n",p.p_class);
            found=1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of ticket no %d found",ticket_no);
    }
    fclose(fp);

}
void view_all_bookings()
{
    clrscr();
    int i,j;
    Passenger p;
    FILE *fp=fopen("d:\\my project\\allbookings.dat","rb");
    printf("Name\tGender\tTrain Number\tTicket Number\tClass\tMobile Number\n");
    for(i=1; i<=78; i++)
        printf("-");
        j=3;
    while(fread(&p,sizeof(p),1,fp)==1)
    {

        printf("%s\n",p.p_name);
        gotoxy(11,j);
         printf("%c\n",p.gender);
        gotoxy(19,j);
        printf("%s\n",p.train_no);
        gotoxy(38,j);
        printf("%d\n",p.ticketno);
        gotoxy(51,j);
        printf("%c\n",p.p_class);
        gotoxy(57,j);
        printf("%s",p.mob_no);
        printf("\n");
        j++;
    }
    fclose(fp);
}
void view_bookings(char* Trno)
{
    int i,j;
    clrscr();
    Passenger p;
    int check=0;
    FILE *fp=fopen("d:\\my project\\allbookings.dat","rb");
    printf("Name\tGender\tTrain Number\tTicket Number\tClass\tMobile Number\n");
    for(i=1; i<=78; i++)
        printf("-");
        j=3;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
    if(strcmp(p.train_no,Trno)==0)
    {
        check=1;

        printf("%s",p.p_name);
        gotoxy(11,j);
        printf("%c",p.gender);
        gotoxy(19,j);
        printf("%s",p.train_no);
        gotoxy(38,j);
        printf("%d",p.ticketno);
        gotoxy(51,j);
        printf("%c",p.p_class);
        gotoxy(57,j);
        printf("%s",p.mob_no);
        printf("\n");
        j++;
    }
    }
    if(check==0)
    {
        int i;
        for(i=1;i<=120;i++)
        {
            gotoxy(i,1);
             printf(" \b");
        }
        gotoxy(1,2);
        textcolor(LIGHTRED);
        clrscr();
        printf("Error!No bookings performed yet on this train.");
        textcolor(YELLOW);
    }
    fclose(fp);
}
void search_record(char* mno)
{
    clrscr();
    textcolor(YELLOW);
    Passenger p;
    FILE *fp=fopen("d:\\my project\\allbookings.dat","rb");
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(strcmp(p.mob_no,mno)==0)
        {
            printf("Name: %s\n",p.p_name);
            printf("Gender: %c\n",p.gender);
            printf("Train Number: %s\n",p.train_no);
            printf("Travelling class: %c\n",p.p_class);
            printf("Ticket Number: %d\n",p.ticketno);
            printf("Address: %s\n",p.address);
            printf("Age: %d\n",p.age);
            printf("Mobile number: %s\n",p.mob_no);
            getch();
            clrscr();
            return ;
        }
    }
    fclose(fp);
    textcolor(LIGHTRED);
    clrscr();
    printf("Mobile number not found!");
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("d:\\my project\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("d:\\my project\\\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found)
    {
        remove("d:\\my project\\allbookings.dat");
        rename("d:\\my project\\temp.dat","d:\\my project\\allbookings.dat");
    }
    else
    {
        remove("d:\\my project\\temp.dat");
    }
    return found;
}
int accept_ticket_no()
{
    int valid;
    int ticket_no;
    clrscr();
    gotoxy(105,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
     printf("Enter Ticket Number:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Cancelling Input....!");
            textcolor(YELLOW);
            return 0;
        }
        if(ticket_no<0)
        {
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            valid=0;
            gotoxy(1,28);
            printf("Error!Ticket number should be positive");
            gotoxy(22,1);
            printf("     \b\b\b\b\b");
            textcolor(YELLOW);
        }
    }
    while(valid==0);
    return ticket_no;
}
char *accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(105,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("Enter Train Number:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(train_no,10,stdin);
       char *pos=strchr(train_no,'\n');
        *pos='\0';
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            printf("Cancelling Input.....!");
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(check_train_no(train_no)==0)
        {
            gotoxy(1,28);
            textcolor(LIGHTRED);
            valid=0;
            printf("Error!Invalid Train No");
            gotoxy(20,1);
            printf("     \b\b\b\b\b");
            textcolor(YELLOW);
        }
    }
    while(valid==0);
    return train_no;
}
int cancel_train(char* trnm)
{
FILE *fp1=fopen("d:\\my project\\allbookings.dat","rb+");
if(fp1==NULL)
{
    textcolor(LIGHTRED);
    printf("\nNo bookings done yet");
    return -1;
}
FILE *fp2=fopen("d:\\my project\\temp.dat","wb+");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
    if(strcmp(pr.train_no,trnm)!=0)
    {
        fwrite(&pr,sizeof(pr),1,fp2);
    }
    else
    {
        found=1;
    }
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
    remove("d:\\my project\\temp.dat");
}
else
{
    remove("d:\\my project\\allbookings.dat");
    rename("d:\\my project\\temp.dat","d:\\my project\\allbookings.dat");
}
return found;
}
char *accept_mob_no()
{
    static char mno[11];
    int valid;
    gotoxy(105,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("Enter Mobile Number:");
           do
           {
               valid=1;
           fflush(stdin);
           fgets(mno,11,stdin);
           char *pos=strchr(mno,'\n');
           if(pos!=NULL)
            *pos='\0';
           if(strcmp(mno,"0")==0)
           {
               textcolor(LIGHTRED);
           gotoxy(1,28);
           printf("\t\t\t\t\t\t\t\t\t\t\t\t");
           gotoxy(1,28);
           printf("Cancelling Input");
           textcolor(YELLOW);
           clrscr();
           return NULL;
           }
           if(check_mob_no(mno)==0)
            {
            gotoxy(1,28);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,28);
            textcolor(LIGHTRED);
            printf("Error!Invalid Mobile Number");
            valid=0;
            textcolor(YELLOW);
            gotoxy(21,1);
            printf("            \b\b\b\b\b\b\b\b\b\b\b\b");
            }
            }while(valid==0);
            return mno;

}

