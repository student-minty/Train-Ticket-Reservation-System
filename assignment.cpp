//This Project is about train ticket reservation for particular locations
//Following people are part of this project
//1.Isha Jaiswal - 2201CS32
//2.Janvi Kumari - 2201CE24
//3.Sravani      - 2201CE28
//4.Chanchal Tolani - 2201PH09
//5.Diksha Talukdar - 2201CB23
//6.Mounika       - 2201EE35
//7.Kavya Shree      2201CS37
//8.Rajesh        - 2201CB36
#include<stdio.h>                   
#include<stdlib.h>
#include<string.h>
struct node{                        //Creation Of Structures to store details of passenger
    char name[30];
    char gen[6];
    int age;
    struct node *next;
};
typedef struct node node;
node *start = NULL;                 //Initializing the node pointer
double amt;
int s[50];
double berth_price(int p, int np);          //Methods to be considered
void Details(int np);
int Food(int np);
double cancel_Ticket(double amt);
void seat_Matrix(int np);
node   *connect_Node(char str[30], int a, char g[6]);
int journey_details(int choice);
void printReceipt(int np,double amt,int famt);
double berth_price(int p, int np)           //Calculating the total berth price
{
    int i1, h = 0, i2, f = 1;
    amt = 0.0;
    printf("Select your choice : ");           //Selecting the options
    printf("\n1. Sleeper class ");
    printf("\n2. AC Class\n");
    scanf("%d",&i1);
    switch(i1)
    {
        case 1:
        h = p*np;
        break;
        case 2:
        printf("Select the type of AC Class : \n");
        printf("1: 1st class AC\n");
        printf("2 : 2nd class AC\n");
        printf("3 : 3rd class AC\n");
        scanf("%d",&i2);
        switch (i2)
        {
        case 1:
        h = (p+4000)*np;
         break;
        case 2:
        h = (p+2000)*np;
        break;
        case 3:
        h = (p+1000)*np;
        break;
        default:
        f = 0;
        printf("Wrong choice\n");
            break;
        }
        break;
        default:
        printf("Wrong choice\n");
        f = 0;
        break;
    }
    if(f==1)
    {
        amt = h + (h*0.18);
        printf("Price : %d\n",h);               //Printing the price and GST amount
        printf("GST : %lf\n",(h*0.18));
    }
    return amt;
}
void Details(int np)                        //Method to fill the details of passengers
{
    int i, age;
    char name[30];
    char gen[6];
    for(i = 1; i<=np; i++)
    {
        printf("Enter the details of Passenger %d :\n",i);  //Entering the Data
        printf("Name : ");
        scanf("%s",name);
        printf("Gender(F/M) : ");
        scanf("%s",gen);
        printf("Age : ");
        scanf("%d",&age);
        connect_Node(name,age,gen);                //passing the data to node functions
    }
}
int Food(int np)                            //Method for ordering food from the passengers
{
    char opt[3];
    int ch, famt = 0;
    printf("Do you want to have food (yes/no): ");
    scanf("%s",opt);
    if(strcasecmp(opt,"Yes")==0)
    {
        printf("Select the following options : \n");    //Available options
        printf("1: Veg Thali (Rs. 200/passenger)\n");
        printf("2: Non Veg Thali(Rs. 300/paasenger)\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        famt = 200*np;                          //calculating total price of food
        break;
        case 2:
        famt = 300*np;
        break;
        default:
        printf("Wrong Choice \n");
        }
    }
    return famt;
}
double cancel_Ticket(double amt)        //Method for cancelling tickets
{
    char opt[3];
    printf("Are you sure to cancel the tickets?\n");
    printf("10 percent Deduction will be there in refund\n");
    scanf("%s",opt);
    if(strcasecmp(opt,"Yes")==0)
    {
        amt-=(amt*0.1);                 //Deducting the refundable amount
        printf("Sorry for the inconvenience caused\n");
    }
    return amt;
}
void seat_Matrix(int np)                //Method for choosing the type of seat
{
    int i;
    printf("Seat Availability\n");
    printf("Type of Berth         Remaining seats:\n");     //Available options
    printf("1: Upper Berth :      50\n");
    printf("2: Lower Berth :      50\n");
    printf("3: Middle Berth :     50\n");
    printf("4: Side Lower Berth : 25\n");
    printf("5: Side Upper Berth : 25\n");
    for(i = 0; i<np; i++)
    {
        printf("Enter the choice for passenger %d : ",i+1);
         scanf("%d",&s[i]);
    }
}
node  *connect_Node(char str[30], int a, char g[6])    //node pointer connecting various passengers
{
    node *n, *ptr;
    n = (node *)malloc(sizeof(node));
    strcpy(n->name,str);                    //storing details of passengers in form of linked list
    strcpy(n->gen,g);
     n->age = a;
    n->next = NULL;
    if(start==NULL)
        start = n;
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = n;                      //connecting various nodes
    } 
    return n;   
}
int journey_details(int choice)         //Method to ask the journey details such as train name and time
{
    int n,sl=0;
    switch(choice){
        case 1:printf("Press 1 for Rajdhani express departs at 12:40 p.m and reaches at 12:30 p.m\n");
               printf("Press 2 for Duronto express departs at 11:20 p.m and reaches at 10:35 p.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=1086;
                       break;
                case 2:sl=925;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        case 2:printf("Press 1 for Rajdhani express departs at 10:15 p.m and reaches at 05:30 a.m\n");
               printf("Press 2 for Duronto express departs at 11:20 p.m and reaches at 07:35 a.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=845;
                       break;
                case 2:sl=790;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        case 3:printf("Press 1 for Rajdhani express departs at 14:40 p.m and reaches at 13:30 p.m\n");
               printf("Press 2 for Duronto express departs at 11:55 p.m and reaches at 11:25 p.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=1155;
                       break;
                case 2:sl=1120;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        case 4:printf("Press 1 for Rajdhani express departs at 12:05 p.m and reaches at 14:30 p.m\n");
               printf("Press 2 for Duronto express departs at 09:20 p.m and reaches at 11:55 p.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=675;
                       break;
                case 2:sl=615;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        case 5:printf("Press 1 for Rajdhani express departs at 06:40 a.m and reaches at 04:30 p.m\n");
               printf("Press 2 for Duronto express departs at 11:20 p.m and reaches at 10:10 p.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=1234;
                       break;
                case 2:sl=1199;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        case 6:printf("Press 1 for Rajdhani express departs at 11:46 p.m and reaches at 10:30 a.m\n");
               printf("Press 2 for Duronto express departs at 11:20 a.m and reaches at 10:35 p.m\n");
               printf("Enter your choice:");
               scanf("%d",&n);
               switch(n){
                case 1:sl=995;
                       break;
                case 2:sl=928;
                       break;
                default:printf("Invalid choice\n");
               }
               break;
        default:printf("Invalid choice\n");
    }
    return sl;              //returning the price of sleeper class
}
void printReceipt(int np,double amt2,int famt2)    //Printing the receipt of passengers travelling together
{
    int i;
    node *p = start;
    for(i = 0; i<np; i++)
    {
        printf("Details of Passenger%d:\n",i+1);
        printf("Name : %s\n",p->name);
        printf("Gender : %s\n",p->gen);
        printf("Age: %d\n",p->age);
        printf("Birth Allocated : ");
        switch(s[i])
        {
            case 1:printf("Upper berth\n");
                   break;
            case 2:printf("Lower berth\n");
                   break;
            case 3:printf("Middle berth\n");
                   break;
            case 4:printf("Side lower berth\n");
                   break;
            case 5:printf("Side upper berth\n");
                   break;
        }
        p = p->next;
    }
    printf("Amount paid : Rs.%lf\n",amt2);  //Printing the amount
    if(famt2!=0)
         printf("Food Price : Rs.%d\n",famt2); 
    printf("Total Amount paid : Rs.%lf\n",amt2+famt2); 
}
int main()                      //Main function
{
    int ch;
    do
    {
    printf("Welcome to Railway Ticket Reservation \n");
    int choice, np;
    printf("Select the source and Destination\n");  //Available train routes
    printf("Press 1 for Dehli to Chennai\n");
    printf("Press 2 for Dehli to kolkata\n");
    printf("Press 3 for kolkata to Chennai\n");
    printf("Press 4 for Dehli to Mumbai\n");
    printf("Press 5 for Mumbai to Chennai\n");
    printf("Press 6 for Mumbai to kolkata\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    int slamt = journey_details(choice);    //Filling and returning journey Details
    if(slamt==0)
    {
        printf("Your booking is cancelled, please re-enter your choice,\n");
        exit(0);
    }
    printf("Enter the Number of Persons : ");       //Number of passengers travelling together
    scanf("%d",&np); 
    Details(np);
    double amt1=berth_price(slamt,np);          //Returning the total amount
    seat_Matrix(np);                            //Choosing seat matrix
    int famt1=Food(np);                         //Returning food amount
    printReceipt(np,amt1,famt1);                //Printing receipt
    printf("Press 1 if you want to cancel the tickets and press any number if you don't want to cancel.");
    scanf("%d",&choice);
    if(choice==1)                       //option for cancellation
    {
        double refund = cancel_Ticket(amt1+famt1);
        if(refund!=(amt1+famt1))
            printf("The amount Rs. %lf is refunded, Please check your account.",refund);
    }
    printf("Press 0 to exit\n");    //asking the user whether he/she wants to continue or not
    scanf("%d",&ch);
    }while (ch!=0);
    printf("\tThank you\t");        //Thanking for using our system to book tickets
}
