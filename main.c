#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"
int main()
{
    int choice;
    Passenger *ptr;
    int tno;
    int tktno;
    char Trno[11];
    char mno[10];
    char train_no[11];
    int ticket_no,tckt_no;
    int result;
    add_trains();
    while(1)
    {
    choice=enterchoice();
    if(choice==9)
        exit(0);
    switch(choice)
    {
        case 1:view_train();
            break;
    case 2:
            ptr=get_passenger_details();
            if(ptr!=NULL)
            {
                tno=book_ticket(*ptr);
                if(tno==-1)
                {
                    textcolor(LIGHTRED);
                    printf("Booking Failed");
                    getch();
                    clrscr();
                }
                else
                {
                    clrscr();
                    textcolor(LIGHTGREEN);
                    printf("Ticket Successfully Booked\n");
                    printf("Your Ticket Number is %d\n",tno);
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to main screen!");
                    getch();
                    clrscr();

                }

           }
            break;
    case 3: clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
                view_ticket(ticket_no);
            }
            textcolor(WHITE);
            printf("\n\n\nPress any key to go back to main screen");
            getch();
            clrscr();
            break;
    case 4:clrscr();
           strcpy(mno,accept_mob_no());
           if(mno!=NULL)
           {
            search_record(mno);
           }
            break;
    case 5:
            view_all_bookings();
            getch();
            clrscr();
            break;
    case 6:clrscr();
           printf("Enter train Number:");
           fflush(stdin);
           scanf("%s",&Trno);
           view_bookings(Trno);
           getch();
           clrscr();
            break;
    case 7:clrscr();
            tckt_no=accept_ticket_no();
            if(tckt_no!=0)
            {
                int result=cancel_ticket(tckt_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry!No ticket booked against ticket no %d",tckt_no);
                }
                else if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("Ticket number %d successfully cancelled!",tckt_no);
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
            }
            getch();
            clrscr();
            break;
    case 8:clrscr();
        strcpy(train_no,accept_train_no());
        if(train_no!=NULL)
        {
            result=cancel_train(train_no);
            if(result==0)
            {
                textcolor(LIGHTRED);
                printf("Sorry!No tickets booked in train no %s",train_no);
            }
            else
            {
                textcolor(LIGHTGREEN);
            printf("Train no %s successfully cancelled!",train_no);
            }
            textcolor(WHITE);
            printf("\n\n\n\nPress any key to go back to main screen");
        }
        getch();
        clrscr();
        break;
    default:textcolor(LIGHTRED);
    printf("Wrong Choice!TRY Again\n");
    getch();
    clrscr();
    }
    }
    return 0;
}
