#include<stdio.h>

int menu();
void new_cust();
void reg_cust();
int search(int ac);
int auth();
char pin_change(int cpin);
void push(float deposite);
void pop(float withdraw);
void peek(int a);
int var_menu();

typedef struct cust
{
  char name[20];
  int ac;
  int pin;
}customer;

customer c1[1000];
int i=0,pos,flag=-1,m,ac,top=-1;
float deposite,withdraw,acc[1000],sum,sub;
int pin,opin,npin,cpin,a;
char q;

int menu()
{
  system("clear");
  int ch1;
  printf("\nPress '1' if you are a new customer \nPress '2' if you're a registered customer\n");
  scanf("%d",&ch1);
  switch(ch1)
  {
    case 1:
    new_cust();
    reg_cust();
    return 1;
    break;

    case 2:
    reg_cust();
    return 1;
    break;

    default:
    printf("\nenter the right choice\n");
  }
}

void new_cust()
{
  system("clear");
  printf("\nEnter your name:\n");
  scanf("%s",c1[i].name);
  printf("Enter your 4-digit A/C number:\n");
  scanf("%d",&c1[i].ac);
  printf("\nSet your 4-digit PIN:\n");
  scanf("%d",&c1[i].pin);
  i++;
}

void reg_cust()
{
    system("clear");
  printf("\nenter the 4-digit account number\n");
  scanf("%d",&ac);
  if (search(ac)==1)
  {
    auth();
  }
}
int search(int ac)
{
system("clear");
  int up=i-1; //upperbound
  int lb=0; //lowerbound
  while(lb<=up)
  {
    int m=(lb+up)/2;
    if(c1[m].ac==ac)//account number
    {
      pos=m;
      flag++;
    }
    if (acc[m] < ac)
    {
      lb = m + 1;
    }


    else
    {
      up = m - 1;
    }
  }
  if(flag>=0)
  {
    printf("\naccount found\n");
    return 1;
    a=pos;
  }
  else
  {
    printf("\nPlease enter valid credentials\n");
    scanf("%d",&ac);
    search(ac);

  }
}




int auth()
{
    
  int f=0;
  while(f<3)
  {
    printf("\nEnter the PIN\n");
    scanf("%d",&pin);
    if(c1[m].pin==pin)
     {
        var_menu();
        break;
      }
      else
      {
        printf("\nwrong pin\n");
      }
      f++;
  }
    if(f==3)
    {
      printf("\nThe PIN was entered wrong several times\n");
      menu();
    }
    
}
  int var_menu()
{
    
  system("clear");
    int ch2;
    do
    {
      printf("\nEnter '1' to withdraw money\nEnter '2' To deposit money\nEnter '3' To check the balnce of your account\nEnter '4' To change PIN\n Enter '5' To check the detailes of the account holder\nEnter '6' To go to the previous menu\nEnter '7' to EXIT\n");
     scanf("%d",&ch2);
     switch(ch2)
     {
      case 1:
      printf("\nEnter the amount to be withdrawn:");
      scanf("\n%f",&withdraw);
      pop(withdraw);
      
      break;

      case 2:
      printf("\nenter the amount to be deposited:\n");
      scanf("%f",&deposite);
      push(deposite);
      
      break;

      case 3:
      peek(1);
      break;

      case 4:
      
      q=pin_change(opin);
      if(q==1)
      {
        printf("\nThe PIN was successfully changed\n");
      }
      
      break;
      
      case 5:
      printf("\nenter the account number\n");
      scanf("%d",&ac);
      search(ac);
      printf("\nthe name of the account holder is\n%s",c1[a].name);
      printf("\nthe account number is\n%d",ac);
      break;
     
      case 6:
      menu();
      break;

      case 7:
      printf("\nEXIT\n");
      break;
     }
    }while(ch2<7);
  
}  


  char pin_change(int cpin)
    {
  system("clear");
    int cdpin;
    printf("\nEnter the 4-digit account number\n");
    scanf("%d",&ac);
    search(ac);
     printf("\nEnter the old PIN:\n");
     scanf("\n%d",&opin);
    
    if(c1[a].pin==cpin)
    {
      printf("\nEnter the NEW PIN\n ");
      scanf("%d",&npin);
      c1[a].pin=npin;
      return 1;
    }
    else
    {
      printf("\nEntered PIN is INCORRECT\n");
      printf("\nEnter the PIN\n");
      scanf("%d\n",&cdpin);
      pin_change(cdpin);
    }
  }

void push(float deposit)
{
    system("clear");
    acc[top]+=deposite;
    printf("\nthe account balance after the transaction is %f\n",acc[top]);
}

void pop(float deposite)
{
    system("clear");
    if(acc[top]<deposite)
    {
        printf("\nthere isn't sufficient Balance in your account\n");
    }
    else
    {
        acc[top]-=deposite;
        printf("\nthe account balance after the transaction if %f\n",acc[top]);
    }
}



  void peek(int x)
  {
      system("clear");
    if(x==1)
    {
      printf("\nThe Account Balance is %f",acc[top]);
    }
    else if(x==3)
    {
      printf("\nthe last 3 transactions are:\n");
      for(x=top;a>top-3;a--)
      {
        printf("%f\n",acc[x]);
      }
    }
  }
  
  void main()
  {
      system("clear");
      menu();
  }
