#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define usd 1
#define inr 74.88
#define eur 0.90
#define pou 0.80
#define yuan 7.10
void gst(){
    system("clear");
    float oc,ga,gr,np;//original cost, gst amount, gst rate, net price
    
    char o;//option
    int ch;//choice
    printf("                        GST Calculator\n");
printf("----------------------------------------------------------------\n");
printf("Please select a choice: \n");
printf("\n\n");
printf("1. Choose this option if you wish to add GST to your base amount\n");
printf("2. Choose this option if you wish to know the GST added to your base amount\n");
printf("\n");
printf("---------------------------------------------------------------\n");
printf("Enter the choice :  ");
scanf("%d",&ch);
printf("Enter the original cost:\n");
scanf("%f",&oc);
printf("Enter the GST rate: \n (Note that the valid GST slab rates are 5, 12, 18 and 28) \n");
scanf("%d",&gr);
if(ch==1)
{
    ga=(oc*gr)/100;
    np=oc+ga;
    printf("The GST amount is : %f \n",ga);
    printf("The net price is : %f \n",np);
}
if(ch==2)
{
    ga=oc-(oc*(100/(100+gr)));
    np=oc-ga;
    printf("The GST amount is : %f \n",ga);
    printf("The net price is : %f \n",np);
}

}
void cur_con()
{
    int ch1,ch2;
    char cur[][10]={"USD","POUNDS","EUROS","YUAN","INR"};
    float a=0,b=0,rat=0,ca=0; //rat=ratio ca=converted amount
    char c1[10],c2[10];
    system("clear");
    printf("                                       CURRENCY EXCHANGE CALCULATOR \n");
    printf("-------------------------------------------------------------------------------------------------------------");
    printf("This calculator helps you calculate how much (currency 1) is equal to (currency 2)\n");
    printf("Select the first currency : \n");
    printf("1.US Dollar \n2.Pound \n3.Euro \n4.Yuan \n5.Indian Rupee \n");
    printf("Enter the option : ");
    scanf("%d",&ch1);
    printf("Select the second currency : \n");
    printf("1.US Dollar \n2.Pound \n3.Euro \n4.Yuan \n5.Indian Rupee \n");
    printf("Enter the option : ");
    scanf("%d",&ch2);
    switch(ch1)
    {
        case 1:
        {
        a=usd;
        }
        break;
        case 2:
        a=pou;
        break;
        case 3:
        a=eur;
        break;
        case 4:
        a=yuan;
        break;
        case 5:
        a=inr;
        break;
        default:
        printf("wrong choice\n");
        break;
    }
     switch(ch2)
    {
        case 1:
        b=usd;
        break;
        case 2:
        b=pou;
        break;
        case 3:
        b=eur;
        break;
        case 4:
        b=yuan;
        break;
        case 5:
        b=inr;
        break;
        default:
        printf("wrong choice\n");
        break;
    }
    rat=b/a;
    float ia;
    printf("Enter the number of %s you want to convert to %s",cur[0][ch1-1],cur[0][ch2-1]);
    scanf("%f",&ia);
    ca=rat*ia;
    printf("%f %s = %f %s",ia,cur[0][ch1-1],ca,cur[0][ch2-1]);
}

 void emi()
 {
     float p,r,n,emi;
     system("clear");
     printf("-----------------EMI CALCULATOR----------------------\n");
     printf("Use this tool to verify your EMI installments\n");
     printf("Enter the loan amount");
     scanf("%f",&p);
     printf("Enter the rate of interest\n");
     scanf("%f",&r);
     printf("Enter the number of monthly installments \n ");
     scanf("%f",&n);
     emi=(p*r*pow((1+r),n))/(pow((1+r),n)-1);
     printf("EMI calculated!\n");
     printf("Rs.%f per month",emi);
}
void menu()
{
    int ch,ch3;
    system("clear");
    printf("****************************Financial Calculator*********************");
    printf("\n\n\n");
    printf("choose the calculator of your desired operation\n");
    printf("\t\t 1.GST calculator\n");
    printf("\t\t 2.EMI calculator\n");
    printf("\t\t 3.Currency convertor\n");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        gst();
        break;
        case 2:
        emi();
        break;
        case 3:
        cur_con();
        break;
        default:
        printf("Wrong choice");
        printf("Enter 1 to enter the choice again \n Press 2 to exit");
        scanf("%d",&ch3);
        if(ch3==1)
        menu();
        else
        {
            printf("Message: Invalid choice. Exiting...");
            return;
        }
        
        

    }
    
}
void main()
{
    menu();
}
