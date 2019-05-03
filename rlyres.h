#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{

    char p_name[50];
    char gender;
    char mob_no[13];
    int age;
    char train_no[10];
    char address[25];
    char p_class;
    int ticketno;
};
typedef struct Train Train;
typedef struct Passenger Passenger;

int enterchoice();
void add_trains();
void view_train();
int book_ticket(Passenger);
int *get_ticket(char*);
void view_ticket(int);
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);
Passenger *get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
void search_record(char*);
int accept_ticket_no();
char *accept_train_no();
char *accept_mob_no();
#endif // RLYRES_H_INCLUDED
