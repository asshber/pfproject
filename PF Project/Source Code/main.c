#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void password();
void wait(int j);
void menuscreen();
void new_acc();
void tran(void);
void loan(void);
void acc_del(void);
void acc_details();
void acc_info();
int loan_2();

struct account{
int number;
int age;
char name[60];
float balance;
int loanstatus;
}newacc,checking,acc;

void main()
{
    password();
}

void wait(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void password()
{
    int result,choice,i;
    char pass[20],opass[20]="pfproject";
    system("cls");
    printf("\t\t\t\t\tWelcome to National Bank of Pakistan\n");
    printf("\t\t\t\t\t====================================\n\n\n");
    printf("\t*This Program is only for Officials. If you are not an official please refrain from further usage.*\n\n");
    printf("Enter The password : ");
    fflush(stdin);
    gets(pass);
    result=strcmp(pass,opass);
    if (result==0)
    {
        printf("\nPlease wait while the program loads.");
        for(i=0;i<=5;i++)
        {
            wait(100000000);
            printf(".");
        }
        menuscreen();

    }
    else
    {
        printf("\nWrong Password\n\nEnter 0 to try again or Enter 1 to exit: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            system("cls");
            password();
            break;
        case 1:
            system("cls");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }

return;

}
void menuscreen()
{
    int choice,exit1;
    system("cls");
    printf("\t\t\t\t\tWelcome to National Bank of Pakistan\n");
    printf("\t\t\t\t\t====================================\n\n\n");
    printf("\t\t\t\t\t      Welcome to Main Menu\n\n");
    printf("\t\t\t\t\t1. Create a New Account\n\t\t\t\t\t2. Loan Management\n\t\t\t\t\t3. Transactions(Deposit/Withdrawal)\n\t\t\t\t\t4. Update Account holder information\n\t\t\t\t\t5. View All Accounts Information\n\t\t\t\t\t6. Remove Existing Accounts\n\t\t\t\t\t7. Exit");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        loan();
        break;
    case 3:
        tran();
        break;
    case 5:
        acc_details();
        break;
    case 4:
        acc_info();
        break;
    case 6:
        acc_del();
        break;
    case 7:
        exit(0);
    default:
        printf("\n\nYour option is not available.\n\nEnter 0 to try again or Enter 1 to exit:");
        scanf("%d",&exit1);
        if (exit1==0)
        {
            menuscreen();
        }
        else if(exit1==1)
        {
            exit(0);
        }

    }
}
void new_acc()
{
    int choice,accnumber,i;
    FILE *fp;
    fp=fopen("test1.dat","a+");
    system("cls");
    printf("\t\t\t\t\tCreating a New Account\n");
    printf("\t\t\t\t\t======================\n\n\n");
    printf("Enter the Account number: ");
    scanf("%d",&accnumber);
    if (accnumber<=0)
    {
        printf("\t\t\t\t\t      The Account number can't be a negative number.");
        printf("\t\t\t\t\t      If you want to start over enter 1 or enter 0 to exit.");
        scanf("%d",&choice);
        if(choice == 1)
            new_acc();
        else if(choice ==0)
            exit(0);
    }
    while(fscanf(fp,"%d %s %f %d %d\n",&newacc.number,&newacc.name,&newacc.balance,&newacc.age,&newacc.loanstatus)!=EOF)
          {
              if (accnumber==newacc.number)
            {
                printf("Account number already in Use.");
                printf("\n\nYou will redirected to the menu screen after a while.");
                for(i=0;i<=5;i++)
                {
                    wait(100000000);
                    printf(".");
                }
                menuscreen();
            }
          }
    newacc.number=accnumber;
    printf("\n\nEnter the Name of Bank Account Holder: ");
    scanf("%s",&newacc.name);
    printf("\n\nEnter the amount you want to Deposit: $");
    fflush(stdin);
    scanf("%f",&newacc.balance);
    printf("\n\nEnter your age:");
    scanf("%d",&newacc.age);
    if(newacc.age<18)
    {
        printf("\t\t\t\t\t      The customer should be atleast 18 years old. ");
        printf("\t\t\t\t\t      If you want to start over enter 1 or enter 0 to exit.");
        scanf("%d",&choice);
        if(choice == 1)
            new_acc();
        else if(choice ==0)
            exit(0);
    }
    newacc.loanstatus=0;
    fprintf(fp,"%d %s %f %d %d\n",newacc.number,newacc.name,newacc.balance,newacc.age,newacc.loanstatus);
    fclose(fp);
    printf("\n\nEnter 1 if you want to create another account or 0 if you want to go back to the menu screen ");
    scanf("%d",&choice);
    if(choice==1)
        new_acc();
    else if(choice==0)
        menuscreen();

}
void tran(void)
{
    FILE *oldfp,*newfp;
    int accnumber,choice,flag=100;
    float money;
    oldfp=fopen("test1.dat","r");
    newfp=fopen("testing.dat","w");
    system("cls");
    printf("\t\t\t\t\tDeposit/Withdraw\n");
    printf("\t\t\t\t\t=================\n\n\n");
    printf("Enter the Account number: ");
    scanf("%d",&accnumber);


    while(fscanf(oldfp,"%d %s %f %d %d\n",&checking.number,&checking.name,&checking.balance,&checking.age,&checking.loanstatus)!=EOF)
          {
              if(accnumber==checking.number)
              {
                  flag=1;
                  printf("\t\t\t\t\t1. Deposit\n\t\t\t\t\t2. Withdraw\nEnter your choice: ");
                  scanf("%d",&choice);
                  if(choice==1)
                  {
                      printf("\n\nEnter the Amount you want to deposit: $");
                      scanf("%f",&money);
                      checking.balance+=money;
                      fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
                      printf("\n\nYour amount is deposited succesfully..\n\nPress any key to return to the main menu.");
                  }
                  else if(choice==2)
                  {
                      printf("\n\nEnter the Amount you want to withdraw : $");
                      scanf("%f",&money);
                      if(money>checking.balance)
                      {
                          printf("\nYour balance is not sufficient for this Transaction.\n\nPress any key to return to the main menu.");
                          fflush(stdin);
                          fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
                          continue;

                      }
                      fflush(stdin);
                      checking.balance-=money;
                      fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
                      printf("\n\nYour amount is withdrawn succesfully.\n\nPress any key to return to the main menu.");
                  }
                }
                  else
                  {
                      fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
                  }

          }
    fclose(oldfp);
    fclose(newfp);
    remove("test1.dat");
    rename("testing.dat","test1.dat");
    if (flag!=1)
    {
        printf("\nYour Account Number could not be found.\nPress any key to retry.");
        getch();
        tran();
    }
    else if(flag==1)
    {
        getch();
        menuscreen();
    }




}
void loan(void)
{
	int accnumber,flag,creditscore;
	float networth,worth,loan1,ratio,check=0.2;
	int flag2;
	FILE *oldfp;
	FILE *newfp;
	oldfp=fopen("test1.dat","r");
	newfp=fopen("interm.dat","w");
	system("cls");
	if(oldfp==NULL)
	{
	printf("File not found\n\nPress any key to return to the main menu.");
	getch();
	menuscreen();
    }
	printf("\t\t\t\t\t\t Loan Management\n");
	printf("\t\t\t\t\t\t ===============\n\n\n");
	printf("Enter your Account Number: ");
	scanf("%d",&accnumber);
	while(fscanf(oldfp,"%d %s %f %d %d\n",&checking.number,&checking.name,&checking.balance,&checking.age,&checking.loanstatus)!=EOF)
	{
		if(accnumber==checking.number)
		{
			if(checking.loanstatus==1)
			{
				printf("\nYou have already availed the Loan Facility.\n\nPress any key to return to the main menu.");
				getch();
				menuscreen();
			}
			flag=1;
			flag2=loan_2();
			if(flag2==1)
            {
                checking.loanstatus=1;
                fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
                getch();
            }
            if (flag2==0)
            {
                checking.loanstatus=0;
                fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
            }
			//break;
		}
		else
		{
			fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
		}

	}
	fclose(oldfp);
    fclose(newfp);
    remove("test1.dat");
    rename("interm.dat","test1.dat");
	if(flag!=1)
	{
		printf("\n\nYour Account number is not available in our database.\n\nPress any key to return to the Main Menu.");
		getch();
		menuscreen();
	}
	if(flag2==1)
    {
                getch();
                menuscreen();
    }
    if(flag2==0)
    {
        getch();
        loan();
    }

}
int loan_2()
{
    float networth,worth,loan1,ratio,check=0.2;
    int creditscore,flag;
    printf("\nEnter the Net Worth of Account Holder: ");
	scanf("%f",&networth);
	worth=networth+checking.balance;
	printf("\nEnter your credit score (300-850): ");
	scanf("%d",&creditscore);
	if(creditscore<300||creditscore>850)
	{
		printf("\nInvalid Value of Credit Score\n\nPress any key to retry.");
		getch();
		loan();

	}
	if(creditscore<700)
	{
		printf("Sorry! Your credit score is too low to avail Loan Facilities.\n\nPress any key to return to Main Menu.");
		getch();
		menuscreen();
	}
	printf("\nEnter the amount you want to Loan: ");
	scanf("%f",&loan1);
	ratio=loan1/worth;
	if(ratio<=check)
	{
		printf("\n\nYour Loan is approved.\n\nPress any key to return to the main menu.");
		checking.loanstatus=1;
//        fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
        flag=1;
	}
	else
	{
    checking.loanstatus=0;
//	fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
	printf("\nYour portfolio is not eligible for this amount of loan\n\nPress any key to start over.");
	flag=0;
	}
	return flag;

}
void acc_del(void)
{
    system("cls");
    int accnumber,flag=100,res;
    printf("\t\t\t\t\t\t Delete Account\n");
	printf("\t\t\t\t\t\t ==============\n\n\n");
	FILE *newfp,*oldfp;
	char pass[20];
	oldfp=fopen("test1.dat","r");
	newfp=fopen("interm.dat","w");
	printf("\nEnter the Account Number you want to delete: ");
	scanf("%d",&accnumber);
	while(fscanf(oldfp,"%d %s %f %d %d\n",&checking.number,&checking.name,&checking.balance,&checking.age,&checking.loanstatus)!=EOF)
    {
        if(checking.number==accnumber)
        {
            printf("\n\nEnter the password to confirm your Operation: ");
            scanf("%s",pass);
            res=strcmp(pass,"pfproject");
            if(res==0)
            {
            flag=1;
            }
            else
            {
                flag=0;
            }
        }
        else
        {
            fprintf(newfp,"%d %s %f %d %d\n",checking.number,checking.name,checking.balance,checking.age,checking.loanstatus);
        }
    }
    fclose(newfp);
    fclose(oldfp);
    remove("test1.dat");
    rename("interm.dat","test1.dat");
    if(flag==1)
    {
        printf("\n\nYour account is Deleted Succesfully.\n\nPress any key to return to main menu.");
        getch();
        menuscreen();
    }
    else if(flag==0)
    {
        printf("\nIncorrect Password.\n\nPress any key to retry.");
        getch();
        acc_del();
    }
    else
    {
        printf("\nYour Account number is not available in our Database.\n\nPress any key to retry.");
        getch();
        acc_del();
    }
}
void acc_details()
{
    system("cls");
    printf("\t\t\t\t\t\t Account Details\n");
	printf("\t\t\t\t\t\t ==============\n\n\n");
	FILE *fp;
	fp=fopen("test1.dat","r");

	 while(fscanf(fp,"%d %s %f %d %d\n",&acc.number,&acc.name,&acc.balance,&acc.age,&acc.loanstatus)!=EOF)
	 	{
	 		printf("\nAccount Number: %d",acc.number);
	 		printf("\nAccount Holder Name: %s",acc.name);
	 		printf("\nAccount Balance: %.2f",acc.balance);
	 		printf("\nAccount Holder Age: %d",acc.age);
	 		if(acc.loanstatus==1)
	 		printf("\nAccount Loan Facility: Availed");
	 		else if(acc.loanstatus==0)
	 		printf("\nAccount Loan Facility: Available");
	 		printf("\n\n");
 	    }
 	fclose(fp);
 	printf("\n\n\nPress any key to return to the main menu.");
 	getch();
 	menuscreen();
}
void acc_info()
{
    system("cls");
    int accnumber,choice,flag=0;
    FILE *oldfp,*newfp;
	oldfp=fopen("test1.dat","r");
	newfp=fopen("interm.dat","w");
    char name[50];
    printf("\t\t\t\t\t\t Update Account Details\n");
	printf("\t\t\t\t\t\t ==============\n\n\n");

	printf("\nEnter the account number you want to update :");
	scanf("%d",&accnumber);
    while(fscanf(oldfp,"%d %s %f %d %d\n",&acc.number,&acc.name,&acc.balance,&acc.age,&acc.loanstatus)!=EOF)
	 	{
	 		if(accnumber == acc.number)
	 		{
	 			    flag=1;
	 				printf("\nAccount Number: %d",acc.number);
	 		        printf("\nAccount Holder Name: %s",acc.name);
	 		        printf("\nAccount Holder Age: %d",acc.age);
	 		        printf("\n\nEnter 1 to change account holder name or 0 to return to main menu");
					scanf("%d",&choice);
					if(choice==0){
						fprintf(newfp,"%d %s %f %d %d\n",acc.number,acc.name,acc.balance,acc.age,acc.loanstatus);
					}
					else if(choice==1)
					{
						printf("\nEnter the account holder name: ");
						scanf("%s",&name);
					    strcpy(acc.name,name);
						fprintf(newfp,"%d %s %f %d %d\n",acc.number,acc.name,acc.balance,acc.age,acc.loanstatus);
						printf("\nPress any key to return to the main menu.");
					}

			}
			else
			{
				fprintf(newfp,"%d %s %f %d %d\n",acc.number,acc.name,acc.balance,acc.age,acc.loanstatus);
			}
 	    }
 	    if(flag!=1)
        {
            printf("\n\nYou account Number is not available in our database.\nPress any key to return to the main menu.");
        }
 	    fclose(newfp);
        fclose(oldfp);
        remove("test1.dat");
        rename("interm.dat","test1.dat");
 	    getch();
 	    menuscreen();

}
