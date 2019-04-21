#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<time.h>
#include<iostream>
using namespace std;

struct patient
{
	char Pname[100];
	char Yname[100];
	char disease[100];
	char no;
	
}h;
struct med{
	char name[100];
	char quantity[10];
	char price[15];
	char date[10];
}m;
string printRandomString() ;
void hospital();
void staff();
void staff1();
void bill();
void viewMed();
void addMed();
void delMed();
void stock();
void stockManagement();
void patients();
void newpatients();
void oldpatients();
void doctor();
void dispensary();
int main()
{

	 system("cls");
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t*********************************************\n\t\t\t\t*\t\t\t\t\t    *\n\t\t\t\t*\t\t AROGYA NIKETAN\t\t    *");
   printf("\n\t\t\t\t*\t\t    HOSPITAL                *\n");
   printf("\t\t\t\t*\t\t\t\t\t    *\n\t\t\t\t*********************************************\n\n");
   getch();
   system("cls");
	hospital();
	return 0;
}
void hospital(){
	char n;
	system("cls");
	while(1){
	
	printf("\t\t\t\t\t\t\t::Main Menu::\n1. Staff Details \n2. Patients \n3. Dispensary \n4. Exit\n");
    n=getche();
	switch(n){
		case '1':staff();break;
        case '2':patients();break;
		case '3':dispensary();break;
		case '4':printf("\n\nThank You For Using Hospital Management.\n\n \t\t\t\t\t Suraj Kumar Verma");
		         getch();
		        exit(1);
		default:
		        printf("\nPlease enter a Valid Choice.\n");				
	}
  }
}

void staff1(){
	char slogan[20];
	system("cls");
	FILE *fp;
	printf("Enter the Hospital Slogan : ");
	fflush(stdin);
	scanf("%[^\n]%*c",&slogan);
	
	if(strcmp(slogan,"Arogya bhava")==0)
		{
			char ch;
            FILE *fp;
            fp=fopen("staff.txt","r");
            if(fp==NULL)
                {
                    printf("Confidential....");
                    exit(1);
                }
            ch=fgetc(fp);
            while(!feof(fp))
                {
                    printf("%c",ch);
                    ch=fgetc(fp);
                }
            fclose(fp);
            printf("\n\n");
       }
       else{
       	    printf("\nWe are sorry.You are Not Authorised.\n");
	   }
}

void patients(){
	int n;
	system("cls");
	printf("\n\t\t\t\t\t::Patient registration and Inquery::\n");
	while(1){
	         printf("\n1. New Registration \n2. Existing Patients \n3. Exit\n\n");
	         scanf("%d",&n);
	         switch(n){
		               case 1: newpatients();break;
		               case 2: oldpatients();break;
		               case 3: hospital();break;
		               default: printf("\n\nPlease enter a valid choice.\n\n");
	                  }
	        }
}
void staff(){
	int n ;
	char slogan[10];
	system("cls");
	printf("\n\t\t\t\t\t\t\t::Staff Detail::\n1. Doctor Details \n2. Staff Details \n3. Exit\n\n");
	scanf("%d",&n);
	switch(n)
	  {
	  	case 1: doctor();break;
	  	case 2: staff1();break;
	  	case 3: hospital();break;
	  	default: printf("\n\nPlease enter a valid choice. \n\n");
	  }
	
}
void newpatients(){
	FILE *f;
	printf("\n\t\t\t\t\t\t\t::New Registration::\n");
          char test;
          system("cls");
          f=fopen("NewPatient.txt","ab+");
          if (f==0)
            { f=fopen("NewPatient.txt","wb+");
                printf("Please wait while we configure your computer...");
                printf("Press any key to continue..") ;
                getch();
            }
	while(1){
	fflush(stdin);
	printf("Enter the patients name : ");
	scanf("%[^\n]",&h.Pname);
	fflush(stdin);
	printf("Disease : ");
	scanf("%[^\n]",&h.disease);
	fflush(stdin);
	printf("Your name : ");
	scanf("%[^\n]",&h.Yname);
	fflush(stdin);
	printf("Enter the contact number : ");
	scanf("%[^\n]",&h.no);
	printf("\n");
	fwrite(&h,sizeof(h),1,f) ;
		fflush(stdin);

    printf("\n Contact saved successfully.");
    printf("\n Press esc key to exit.");
    test=getche();
    if (test==27)
    break;
  }
   fclose(f);
}

void doctor(){
     char ch;
     system("cls");
       FILE *fp;
       printf("\n\t\t\t\t::Our Doctors::\n");
       fp=fopen("Doc.txt","r");
        if(fp==NULL)
         {
           printf("No Doctor is available....");
           exit(1);
         }
        ch=fgetc(fp);
       while(!feof(fp))
         {
          printf("%c",ch);
           ch=fgetc(fp);
         }
         printf("\n\n");
fclose(fp);
}

void dispensary(){
	int n;
	system("cls");
	printf("\n1. Stock \n2. Bill Generation \n3. Exit\n\n ");
	scanf("%d",&n);
	switch(n){
		case 1:stock();break;
		case 2:bill();break;
		case 3:hospital();break;
		default:printf("\n\nEnter the valid data \n\n");
	}
}

void oldpatients(){
 FILE *f;
 int i;

 if ((f=fopen("NewPatient.txt","rb"))==NULL)
 {
   printf("There is No data");
   exit(0);
 }
 system("cls");
 printf("\nName \t\t\t Disease \t\t\t Relative \t\t\t contact Number\n");
 for(i=0;i<110;i++)
 printf("-");
  while(fread(&h,sizeof(h),1,f)==1)
 {
 printf("\n%s\t\t%s\t%s\t\t%s\n",h.Pname,h.disease,h.Yname,h.no);
 }
 printf("\n");
 for(i=0;i<110;i++)
 printf("-");
 fclose(f);
 getch();
}
void viewMed(){
	  system("cls");
      FILE *f;
      int i;
      if ((f=fopen("Medical.txt","rb"))==NULL)
      exit(0);
      printf("\n\t\t\t\t::Our Stock::\n\n\n");
      printf("\nName\t\t\t\tQuantity\t\t\tExpiry Date\t\t\tPrice\n");
      for(i=0;i<120;i++)
      printf("-");
      while(fread(&m,sizeof(m),1,f)==1)
      {
      printf("\n%-s\t\t\t%-s\t\t\t\t%s\t\t\tRs. %s",m.name,m.quantity,m.date,m.price);
      }
      printf("\n\n");
      for(i=0;i<120;i++)
      printf("-");
      fclose(f);

     getch();
}
	
	
	
void delMed()
{ 
  system("cls");
  FILE *f,*t;
  int i=1;
  char name[20];
  if((t=fopen("nameMed.txt","w+"))==NULL)
  exit(0);
  if ((f=fopen("Medical.txt","rb"))==NULL)
   exit(0);
   system("cls");
    fflush(stdin);
   printf("Enter the Name of the Medicine : ");
   scanf("%[^\n]",&name);
   fflush(stdin);
   while(fread(&m,sizeof(m),1,f)==1)
   {
    if (strcmp(m.name,name)==0)
      {
	 i=0;
	 printf("\n\n\t\t\t\nRecord deleted.");
	 continue;
      }
	fwrite(&m,sizeof(m),1,t)  ;
	}
   fclose(f);
   fclose(t);
   remove("Medical.txt");
   rename("nameMed.txt","Medical.txt") ;

	  if(i==1)
	  {
	   system("cls");
	   printf("Medicine %s doesn't found.",name);
	   getch();
	   system("cls");
	   }
}
void addMed()
{
FILE *f;
char test;
system("cls");
 f=fopen("Medical.txt","ab+");
 if (f==0)
 { f=fopen("Medical.txt","wb+");
    system("cls");
    printf("Please wait while we configure your computer...\n");
    printf("Press any key to continue...\n") ;
    getch();
 }
 while (1)
 {
 system("cls");
 fflush(stdin);
 printf("\n Enter Medicine name : ");
 scanf("%[^\n]",&m.name);
 fflush(stdin);
 printf("\n Enter the Quantity : ");
 scanf("%[^\n]",&m.quantity);
 fflush(stdin);
 printf("\n Enter Expiry Date(dd/mm/yy) : ");
 scanf("%[^\n]",&m.date) ;
 fflush(stdin);
 printf("\n Enter price(per unit) : ");
 scanf("%[^\n]",&m.price);
 fwrite(&m,sizeof(m),1,f) ;
 system("cls");
 printf("\n Data saved successfully..");
 printf("\n Press esc key to exit.");
 test=getche();
  if (test==27)
  break;
  }
   fclose(f);
}
void stock(){
	int n;
	system("cls");
	while(1){
	         printf("\n1. Stock Management \n2. Bill Generation \n3. Exit\n\n");
	         scanf("%d",&n);
            switch(n){
            	     case 1: stockManagement();break;
            	     case 2: bill();break;
            	     case 3: hospital();break;
            	     default:printf("Please enter a valid choice.\n\n");
			         }
			
			}
}
void stockManagement(){
		int n;
	system("cls");
	while(1){
	         printf("\n\n1. Add Medicine in Stock \n2. Remove Medicine from stock \n3. Medicine Details \n4 Exit\n\n");
	         scanf("%d",&n);
             switch(n){
            	       case 1: addMed();break;
            	       case 2: delMed();break;
            	       case 3: viewMed();break;
            	       case 4: hospital();break;
            	       default:printf("Please enter a valid chioce.\n\n");
			         }
			
			}
}
void bill()
{
	char name[50],s;
	int age ;
	float price[20],sum=0 ;
	char med[20][80];
	int quantity[50];
	int count=0,i;
	 fflush(stdin);
	printf("Enter the Name : ");
    scanf("%[^\n]%*c",&name);
    fflush(stdin);
    printf("\nEnter the Age : ");
    scanf("%d",&age);
    m:{
		fflush(stdin);
	   	printf("\nName of Medicine:");
	   	scanf("%[^\n]%*c",&med[count]);
		fflush(stdin);
	    printf("\nEnter desired quantity : ");
	    scanf("%d",&quantity[count]);
	    fflush(stdin);
	   	printf("\nPrice per unit : ");
	   	scanf("%f",&price[count++]);
	   }
	   	fflush(stdin);
	 	printf("\nWant to add more medicine Y/N ? : ");
	  	scanf("%c",&s);
	  	if(s=='Y'||s=='y')
	      	goto m;
	  else
	  {
	  	system("cls");
	  	printf("\t\t\t::Arogya Niketan Dispensary::\n");
	  	printf("Name of patient : %s\n",name);
	  	printf("Age : %d\n",age);
	  	printf("Description : \n");
	  	printf("----------------------------------------------------");
	  	printf("\n\n Medicine   Quantity    \tPrice per Unit   Price\n");
	  	for( i=0;i<count;i++)
	  	{
	  		printf("\n %s\t\t%d\t\t%.2f\t\t%.2f\n",med[i],quantity[i],price[i],quantity[i]*price[i]);
		}
	 	for(i=0;i<count;i++)
	  	sum+=price[i]*quantity[i];
	}
	  
	  	printf("----------------------------------------------------");
	    printf("\nTotal\t\t\t\t\t\t%.2f\n",sum);
	  	printf("----------------------------------------------------\n");
	  	exit(1);
}
