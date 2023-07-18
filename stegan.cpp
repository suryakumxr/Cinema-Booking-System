#include<iostream.h> #include<conio.h> #include<stdio.h> #include<string.h> #include<process.h> #include<fstream.h> #include<dos.h> #include<iomanip.h> char c=254;
void vline(char);//Function Prototype class ID //Class for USER ID
{

public:
char user_name[20]; char password[20];
char get_username() //Member function to get username
{

cout<<"\n\n\t Enter the user name of the ID: "; gets(user_name);
return user_name[20];
}

char get_password() //Member function to get password
{

cout<<"\n\n\t Enter the password of the ID: ";
 
gets(password); return password[20];
}

}st_login;
class reserve //Class for the details of the bus
{

public:
int screen;
char movie[30]; char hero[20]; char heroin[20]; char showtime[5]; char runtime[5]; char seat[10][10];
char user_id[10][10][20]; int cost;
void display(); //Member function to display bus details void disp_seat(); //Member function to display seat details
int check_empticket(); //Member function to check number of empty tickets in bus
int check_empty(int i,int j) //Member function to check whether the seat is empty
{
if(seat[i][j]==c)
{
return 1;
 
}
else
{
return 0;
}
}
};
void reserve::display()
{
clrscr(); vline('.');
cout<<"\n\n\t\t\t	The details of Screen"; cout<<"\n\n";
vline('.');
cout<<"\n\n\n\Screen number: "; cout<<screen; cout<<"\n\n\tMovie's name: "; cout<<movie;
cout<<"\n\n\tStarring: "<<hero<<" and "<<heroin; cout<<"\n\n\Show time: ";
for(int x=0;x<5;x++)cout<<showtime[x]; cout<<"\n\n\tRun time: ";
for(x=0;x<5;x++)cout<<runtime[x]; cout<<"\n\n\tCost: ";
cout<<cost;
cout<<"\n\n\n\n\t\t Press any key to continue to seat map";
 
getch();
}

void reserve::disp_seat()
{
int s=0,p=0,c=0; for(int i=0;i<10;i++)
{
cout<<"\n"; if(i==4||i==7)cout<<endl; if(i==0)cout<<" ";
for(int j=0;j<10;j++)
{

s++;
if(j==3||j==7)cout<<"	"; if((j==3||j==7)&&i==0)cout<<" "; cout<<s<<".";
cout.width(3); cout.fill(' '); cout.width(3); cout.fill(' '); cout<<seat[i][j]; p++;
}

}
for(i=0;i<10;i++)for(int x=0;x<10;x++)if(seat[i][x]=='R')c++; cout<<endl<<endl;
 
vline('_');cout<<"\t\t\t\t	SCREEN THIS WAY";cout<<endl; vline('_'); cout<<"\t\t\tThere are "<<100-c<<" empty seats in screen"<<screen;
}

int reserve::check_empticket()
{
int e=0;
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
if(seat[i][j]==c) e++;
}
}
return e;
}
//Function prototypes void main_menu(void); void admin_login(void); void admin_mode(void); void create_id(void); void delete_id(void);
void standard_login(void); void standard_mode(void); void book_tickets(void); void install_movie(void);
 
void delete_screen(void); void show_movie(void); void show_seats(reserve); void cancel_ticket(void); void show_all(void);
void vline(char ch) //Function to insert line
{

for(int i=1;i<80;i++) cout<<ch;
}

void start_screen() //Start Screen Function
{
clrscr(); cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t	Welcome to Stegan Cinemas"; cout<<"\n\n";
vline('.');
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t	Press any key to continue"; getch();
}
void main_menu() //Main menu function
{
clrscr();
int choice1; cout<<"\n\n";
 
vline('.');
cout<<"\n\n\t\t\tWELCOME TO STEGAN CINEMAS"; cout<<"\n\n";
vline('.');
cout<<"\n\n\t\t\t	Choose the login mode"; cout<<"\n\n\t\t\t	1.ADMIN Mode"; cout<<"\n\n\t\t\t	2.Login"; cout<<"\n\n\t\t\t	3.Exit";
cout<<"\n\n\n\t Enter your choice (1 , 2 or 3): "; cin>>choice1;
switch(choice1)
{

case 1:admin_login(); break;
case 2:standard_login(); break;
case 3:cout<<"\n\n\n\n\t\t\t	Press any key to exit"; getch();
exit(0); break;
default:cout<<"\n\n\t\t\t	Enter a valid choice"; cout<<"\n\n\t\t\t Press any key to continue"; getch();
main_menu(); getch(); break;
 
}
}

void admin_login() //Function for admin login page
{
clrscr();
char admin_name[8],admin_pass[10],try_choice; cout<<"\n\n";
vline('.');
cout<<"\n\n\t\t\t\t ADMIN Login"; cout<<"\n\n";
vline('.');
cout<<"\n\n\n\t\t Enter the admin name: "; gets(admin_name);
cout<<"\n\n\t\t Enter the password: "; gets(admin_pass);
if(strcmp("Surya",admin_name)==0 && strcmp("lm10",admin_pass)==0)
{
cout<<"\n\n\n\n\t\t\t Press any key to continue";getch();admin_mode();
}
else
{
cout<<"\n\n\n\n\t\tIncorrect Password"; label1:
cout<<"\n\n\t\t\t Do you want to try again(y/n):"; cin>>try_choice;
switch(try_choice)
 
{
case 'y':admin_login();
break;
case 'n':cout<<"\n\n\t\t Press any key to return back to main menu"; getch();
main_menu(); break;
case 'Y':admin_login();
break;
case 'N':main_menu();
break;
default :cout<<"\n\n\t\t Enter a valid input"; goto label1;
}
}
getch();
}
void admin_mode() //Admin Page
{
clrscr(); cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t\t ADMIN MENU"; cout<<"\n\n";
vline('.');
cout<<"\n\n\t 1.To create a Stegan ID.";
 
cout<<"\n\n\t 2.To delete a existing Stegan ID."; cout<<"\n\n\t 3.Add a Movie to the database."; cout<<"\n\n\t 4.Delete a Movie."; cout<<"\n\n\t 5.Return to main menu."; cout<<"\n\n\t 6.Exit.";
cout<<"\n\n\t Enter your choice:"; int choice2;
cin>>choice2; switch(choice2)
{
case 1:create_id(); break;
case 2:delete_id(); break;
case 3:install_movie(); break;
case 4:delete_screen(); break;
case 5:cout<<"\n\n\t\t Press any key to return back to main menu"; getch();
main_menu(); break;
case 6:cout<<"\n\n\t\t\t	Press any key to exit"; getch();
exit(0); break;
 
default:cout<<"\n\n\t\t\t	Enter a valid choice"; cout<<"\n\n\t\t\t Press any key to continue"; getch();
admin_mode(); break;
}
getch();
}
void create_id() //Function to create a user ID
{
char choice='n'; do
{
label3:
fstream login("user.dat",ios::in|ios::out|ios::app|ios::binary); clrscr();
ID user,confirm,temp; cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t Create a Stegan ID"; cout<<"\n\n";
vline('.'); user.get_username(); cout<<"\n";
cout<<"\t	Retype the user name: "; gets(confirm.user_name);
 
if(strcmp(user.user_name,confirm.user_name)!=0)
{
cout<<"\n\n\n\n\n\t\tThe usernames that you have entered doesn't match"; cout<<"\n\n\n\n\t\t\t Press any key to try again";
getch(); goto label3;
}
fstream z("user.dat",ios::in|ios::binary); while(!z.eof())
{
z.read((char*)&temp,sizeof(temp)); if(strcmp(temp.user_name,user.user_name)==0)
{
cout<<"\n\n\t This Stegan ID already taken"; cout<<"\n\n\n\n\t\t\t Press any key to try again"; getch();
z.close(); goto label3;
}
}
z.close(); user.get_password(); cout<<"\n";
cout<<"\t	Retype the password: "; gets(confirm.password); if(strcmp(user.password,confirm.password)!=0)
 
{
cout<<"\n\n\n\n\n\t\tThe passwords that you have entered doesn't match"; cout<<"\n\n\n\n\t\t\t Press any key to try again";
getch(); goto label3;
}
login.write((char*)&user,sizeof(user));
cout<<"\n\n\n\t\t	Your ID has been created successfully"; login.close();
cout<<"\n\n\t\t	Do you want to create another ID: "; cin>>choice;
}
while(choice=='y'||choice=='Y');
cout<<"\n\n\t\t	Press any key to return to main menu"; getch();
admin_mode();
}
void delete_id() //Function to delete a user ID
{
char found='n'; label4:
clrscr();
ID del_user,temp_del,confirm,temp2; cout<<"\n\n";
vline('.');
cout<<"\n\n\t\t\t Delete a Stegan user ID";
 
cout<<"\n\n"; vline('.');
del_user.get_username(); cout<<"\n";
cout<<"\t	Retype the user name: "; gets(confirm.user_name); if(strcmp(del_user.user_name,confirm.user_name)!=0)
{
cout<<"\n\n\n\n\n\t\tThe usernames that you have entered doesn't match"; cout<<"\n\n\n\n\t\t\t Press any key to try again";
getch(); goto label4;
}
fstream y("user.dat",ios::in|ios::binary); while(!y.eof())
{
y.read((char*)&temp2,sizeof(temp2)); if(strcmp(temp2.user_name,del_user.user_name)==0)
{
found='y'; break;
}
}
y.close(); if(found=='n')
{
 
cout<<"\n\n\t The entered stegan ID not found"; cout<<"\n\n\t\t Returning to main menu"; getch(); admin_mode();
}
fstream del_org("user.dat",ios::in|ios::out|ios::binary);
fstream del_temp("temp.dat",ios::in|ios::out|ios::app|ios::binary); while(!del_org.eof())
{
del_org.read((char*)&temp_del,sizeof(temp_del)); if(strcmp(del_user.user_name,temp_del.user_name)!=0)
{
del_temp.write((char*)&temp_del,sizeof(temp_del));
}
}
del_org.close(); del_temp.close(); remove("user.dat"); rename("temp.dat","user.dat");
cout<<"\n\n\n\t\t		Your ID has been deleted successfully"; cout<<"\n\n\t\t	Press any key to return to main menu"; getch();
admin_mode();
}
void install_movie()
{

clrscr();
 
reserve ins; cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t Add details of the screen"; cout<<"\n\n";
vline('.');
cout<<"\n\n\n\tEnter Screen Number: "; cin>>ins.screen;
cout<<"\tEnter	Movie's Name: "; gets(ins.movie);
cout<<"\n\tEnter Hero's name: "; gets(ins.hero);
cout<<"\n\tEnter Heroin's name: "; gets(ins.heroin);
cout<<"\n\tEnter Show Time "; gets(ins.showtime); cout<<"\tEnter Run Time: "; gets(ins.runtime); cout<<"\n\tCost: "; cin>>ins.cost;
for(int i=0; i<10;i++)
{
for(int j=0;j<10;j++)
{
ins.seat[i][j]=c;
}
 
}
fstream inst("scrdata.dat",ios::app|ios::binary); inst.write((char*)&ins,sizeof(ins)); cout<<"\n\n\t#Added successfully."; inst.close();
getch(); admin_mode();
}
void delete_screen() //Function to delete a user ID
{
char found='n'; label11:
clrscr();
reserve del_screen,temp_del,confirm,temp2; cout<<"\n\n";
vline('.');
cout<<"\n\n\t\t\t Delete a Stegan screen"; cout<<"\n\n";
vline('.');
cout<<"\n\n\tEnter the screen no:"; cin>>del_screen.screen;
fstream q("scrdata.dat",ios::in|ios::binary); while(!q.eof())
{
q.read((char*)&temp2,sizeof(temp2)); if(del_screen.screen==temp2.screen)
 
{
found='y'; break;
}
}
q.close(); if(found=='n')
{
cout<<"\n\n\t The entered stegan screen not found"; cout<<"\n\n\t\t Returning to main menu"; getch(); admin_mode();
}
fstream del_org("scrdata.dat",ios::in|ios::out|ios::binary);
fstream del_temp("temp2.dat",ios::in|ios::out|ios::app|ios::binary); while(!del_org.eof())
{
del_org.read((char*)&temp_del,sizeof(temp_del)); if(del_screen.screen!=temp_del.screen)
{
del_temp.write((char*)&temp_del,sizeof(temp_del));
}
}
del_org.close(); del_temp.close(); remove("scrdata.dat");
rename("temp2.dat","scrdata.dat");
 
cout<<"\n\n\n\t\t		Your stegan screen has been deleted successfully"; cout<<"\n\n\t\t	Press any key to return to main menu";
getch(); admin_mode();
}
void standard_login() //Function for end user login
{
ID temp_user; fstream std_login;
std_login.open("user.dat",ios::out|ios::in|ios::binary); clrscr();
cout<<"\n\n\t\t\t\t\tLogin"; st_login.get_username(); st_login.get_password(); char found='n'; while(!std_login.eof())
{
std_login.read((char*)&temp_user,sizeof(temp_user)); if(strcmp(temp_user.user_name,st_login.user_name)==0)
{
if(strcmp(temp_user.password,st_login.password)==0)
{
found='y'; break;
}
}
 
}
if(found=='n')
{
cout<<"\n\n\n\n\n\n\n\n\n\t\t Either your name or password is incorrect"; label2:
cout<<"\n\n\t\t\t Do you want to try again(y/n):"; char try_choice1;
cin>>try_choice1; switch(try_choice1)
{
case 'y':standard_login(); break;
case 'n':main_menu();
break;
case 'Y':standard_login(); break;
case 'N':main_menu();
break;
default :cout<<"\n\n\t\t Enter a valid input"; goto label2;
}
}
std_login.close(); if(found=='y')
{
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t Press any key to continue";
 
getch(); standard_mode();
}
}
void standard_mode()
{
clrscr();
cout<<"\n\n\t\t\t	Welcome To Stegan Cinemas"; cout<<"\n\n\n\n\t 1.Book Tickets.";
cout<<"\n\n\t 2.Movies Running"; cout<<"\n\n\t 3.Cancel your Tickets"; cout<<"\n\n\t 4.Main Menu"; cout<<"\n\n\t 5.Instuctions"; cout<<"\n\n\t 6.Screens Available"; cout<<"\n\n\t 7.Exit"; cout<<"\n\n\n\n\t Enter your choice:"; int choice3;
cin>>choice3; switch(choice3)
{
case 1:book_tickets(); break;
case 2:show_movie(); break;
case 3:cancel_ticket(); break;
 
case 4:main_menu(); break;
case 5:clrscr(); cout<<"\n\n\n\t\tINSTRUCTIONS"; cout<<"\n\n\n\n\t #DONT CARRY BABIES WITH YOU"; cout<<"\n\t #ARRIVE TO CINEMA ON TIME"; cout<<"\n\t #DRUNKEN PEOPLE ARE NOT ALLOWED"; cout<<"\n\t #SMOKING IS STRICTLY PROHIBITED"; cout<<"\n\t #EXCHANGE THE TICKET IN TIME";
cout<<"\n\t #MUST STAND UP FOR THE NATIONAL ANTHEM"; cout<<"\n\t #SHOULD NOT BRING ANY EATABLES";
cout<<"\n\t #MANAGEMENT IS NOT RESPONSIBLE FOR ANY LOSS OF VALUBLES";
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t THANK YOU FOR VISITING";
break;
case 7:exit(0);
break;
case 6: show_all(); break; default:cout<<"\n\n\n\t\t\t	Enter a valid choice";
cout<<"\n\n\t\t\t Press any key to continue"; getch();
standard_mode();

}
getch();
}
void book_tickets() //Function to book tickets
{
 
reserve book_ticket,temp,temp1; clrscr();
vline('.');
cout<<"\n\n\t\t\t\t Book Tickets\n\n"; vline('.');
cout<<"\n\n\t Enter the Screen number: "; cin>>temp1.screen;
int n,temp_seat;
fstream ticket("scrdata.dat",ios::in|ios::out|ios::binary|ios::app); ticket.seekg(0);
while(!ticket.eof())
{
ticket.read((char*)&book_ticket,sizeof(book_ticket)); if(book_ticket.screen==temp1.screen)
{
if(book_ticket.check_empticket()!=0)
{
cout<<"\n\n\tEnter the number of tickets to be booked: "; cin>>n;
cout<<"\n\n"; top:
for(int i=1;i<=n;i++)
{
cout<<"\n\t Enter the seat "<<i<<": "; cin>>temp_seat;
if(temp_seat>100)
 
{
cout<<"\n\tThere are only 100 seats available in this screen."; goto top;
}
if(book_ticket.check_empty((temp_seat/10),(temp_seat%10)-1)==1)
{
book_ticket.seat[temp_seat/10][(temp_seat%10)-1]='R'; strcpy(book_ticket.user_id[temp_seat/10][(temp_seat%10)-
1],st_login.user_name);
}
else
{
cout<<"\n\t Already reserved !!"; goto top;
}
}
fstream del_temp("temp.dat",ios::in|ios::out|ios::app|ios::binary); ticket.seekg(0);
del_temp.seekp(0); while(!ticket.eof())
{
ticket.read((char*)&temp,sizeof(temp)); if(book_ticket.screen!=temp.screen)
{
del_temp.write((char*)&temp,sizeof(temp));
}
 
}
del_temp.close(); ticket.close(); remove("scrdata.dat");
rename("temp.dat","scrdata.dat");
fstream twrite("scrdata.dat",ios::app|ios::binary); twrite.write((char*)&book_ticket,sizeof(book_ticket)); twrite.close();
cout<<"\n\n\t\t Your tickets have been booked successfully"; cout<<"\n\n\t The cost for the ticket is "<<book_ticket.cost;
cout<<"\n\t Please pay the amount before you enter the cinema and get the ticket";
cout<<"\n\t Please carry each of the ticket for verification"; cout<<"\n\n\t\t	Press any key to return to main menu"; break;
}
else
{
cout<<"No tickets are available in this screen"; }

}
}
float a=n;
float m=book_ticket.cost; clrscr();
vline('-');
cout<<"\t\t\t\t	Stegan Cinemas"<<endl;
 
vline('-'); cout<<"\n\n\n";

cout<<"\n\n\t"<<setw(10)<<"Ticket(s)"<<setw(20)<<"Cost"<<setw(20)<<"Total "<<endl;
vline('-');
cout<<"\n\t"<<setw(8.5)<<n<<setw(22)<<book_ticket.cost<<setw(20)<<(n*bo ok_ticket.cost)<<endl;
vline('-'); cout<<"\n\n\n";
cout<<"\t\t\t Goods and service taxes(18%)"<<endl; vline('-');

cout<<"\n\n\t"<<setw(10)<<"CGST"<<setw(20)<<"SGST"<<setw(20)<<"IGST"<< endl;
cout<<"\n\t"<<setw(10)<<(0.18*m*a)<<setw(20)<<(0.18*m*a)<<setw(20)<<(0
.36*m*a)<<endl; vline('-');
cout<<"\n\n\t\t\t\t\t\t\t	Grand Total: "<<m*a+(0.36*m*a); getch();
standard_mode();
}
void show_movie()
{
reserve temp,search; clrscr();
vline('.');
cout<<"\n\n\t\t\t	The details of the Screen";
 
cout<<"\n\n"; vline('.');
cout<<"\n\n\n\t Enter the Screen number: "; cin>>temp.screen;
fstream disp("scrdata.dat",ios::in|ios::out|ios::binary); while(!disp.eof())
{
disp.read((char*)&search,sizeof(search)); if(search.screen==temp.screen)
{
search.display(); show_seats(search); break;
}
}
disp.close();
cout<<"\n\n\n\t\t	Press any key to return to main menu"; getch();
standard_mode();
}
void show_seats(reserve seat)
{
clrscr(); cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t The details of the seats of the screen";
 
cout<<"\n\n"; vline('.'); cout<<"\n"; seat.disp_seat();
}
void cancel_ticket()
{
label6:
clrscr();
reserve del,temp,temp2,temp3; char choice='n';
int seats; cout<<"\n\n"; vline('.');
cout<<"\n\n\t\t\t Cancel the booked tickets"; cout<<"\n\n";
vline('.'); cout<<"\n\n"; do
{
cout<<"\t Enter the Screen number: "; cin>>temp.screen;
fstream scr("scrdata.dat",ios::binary|ios::in); while(!scr.eof())
{
scr.read((char*)&del,sizeof(del));
 
if(del.screen==temp.screen)
{
cout<<"\n\n\t Enter the seat number to be cancelled: "; cin>>seats;
if(strcmp(del.user_id[seats/10][(seats%10)-1],st_login.user_name)!=0)
{
cout<<"\n\n\t\t The seat is not booked from your ID"; cout<<"\n\n\t Do yo want to try again(Y/N): " ; cin>>choice;
if(choice=='y'||choice=='Y') goto label6;
else
{

cout<<"\n\n\n\n\t\t	Press any key to return to main menu"; getch();
standard_mode();
}
}

if(del.seat[seats/10][(seats%10)-1]!=c)
{
del.seat[seats/10][(seats%10)-1]=c;
fstream temp1("temp1.dat",ios::app|ios::binary); scr.seekg(0);
while(!scr.eof())
{
scr.read((char*)&temp2,sizeof(temp2));
 
if(del.screen!=temp2.screen)
{
temp1.write((char*)&temp2,sizeof(temp2));
}
}
temp1.write((char*)&del,sizeof(del)); temp1.close();
scr.close(); remove("scrdata.dat");
rename("temp1.dat","scrdata.dat");
cout<<"\n\n\t Do yo want cancel one more ticket(Y/N): " ; cin>>choice;
break;
}
else
{
cout<<"\n\n\t The selected seat havent booked by anyone"; cout<<"\n\n\t Do yo want to try again(Y/N): " ;
cin>>choice; if(choice=='y'||choice=='Y') goto label6;
else
{

cout<<"\n\n\n\n\t\t	Press any key to return to main menu"; getch();
standard_mode(); }
 
}
}
}
}while(choice=='y'||choice=='Y');
cout<<"\n\n\n\n\t\t	Press any key to return to main menu"; getch();
standard_mode();
}
void screen()
{
cout<<"\n\n\n\n\t\t";
char t[]="WELCOME TO STEGAN CINEMAS";
cout<<"\n\n\n\n\t	"; for(int i=0;t[i]!='\0';i++)
{cout<<t[i]<<" "; delay(250);}
char s[]="PROJECT DESIGNED BY SURYA";
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t"; for(i=0;s[i]!='\0';i++)
{cout<<s[i]<<" "; delay(250);} getch();
}
void show_all()
{
clrscr(); reserve temp; cout<<"\n\n";
 
vline('.');
cout<<"\n\n\t\t\t Screens Available"; cout<<"\n\n";
vline('.'); cout<<"\n\n";
fstream t("scrdata.dat",ios::in|ios::binary); t.read((char*)&temp,sizeof(temp)); while(t.read((char*)&temp,sizeof(temp)))
{
cout<<"Screen "<<temp.screen<<": "<<temp.movie; cout<<endl<<endl;
}
t.close();
cout<<"\n\n\n\n\t\t	Press any key to return to main menu"; getch();
standard_mode();

}
void main()
{clrscr(); start_screen(); main_menu();
}
