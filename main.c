/*PROJECT GROUP 11: CHAUFFEUR SERVICE SYSTEM
  Group Members :   Zetty Elica Binti Affandi (63879)
                    Nurul Annisa Binti Bulhan (64108)
                    Asnina Binti Ab Hamid (63115)
                    Alya Binti Ahmad (63078)
                    Harithza Assikin Binti Zaharuddin (60894)
*/

#include <stdio.h>
#include <stdlib.h>
#include "PayService.h"

void pay_service();//function prototype
void delete_receipt();//function prototype
void view_receipt();//function prototype
void monthly_summary();//function prototype
FILE *file; //Creates a FILE pointer called file
struct PayServiceData customer;

//function main begins program execution
int main()
{
    int choice, quit; //Declare choice as Integer input
    a: do
    {
       puts("");
            //display menu for user option
            printf("\t\t ________________________________________________\n");
            printf("\t\t| ______________________________________________ |\n");
            printf("\t\t||                                              ||\n");
            printf("\t\t||            CAT CITY CHAUFFEUR SERVICE        ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||                  MAIN MENU                   ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||             1. PAY SERVICE                   ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||             2. DELETE PAYMENT RECEIPT        ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||             3. VIEW RECEIPT                  ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||             4. MONTHLY SUMMARY REPORT        ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t||             5. QUIT                          ||\n");
            printf("\t\t||______________________________________________||\n");
            printf("\t\t|________________________________________________|\n\n");

            printf("\t\tEnter your choice: "); //Prompt for user input
            scanf("%d",&choice); //Obtaining input from user for select choice from menu
            system("cls");


        switch (choice)
        {
            case 1: //If user select the choice 1 (Pay Service)
                pay_service(); //Function to show the payment service of customer
                system("pause");
                break;//exit current switch case and go to "choice" switch case
                system("cls");

            case 2: //If the user select the option 2 (Delete Payment Receipt)
                delete_receipt();//Function to delete customers record
                system("pause");
                break;//exit current switch case and go to "choice" switch case
                system("cls");

            case 3: //If the user select the option 3 (View Receipt)
                view_receipt();//Function to view the customer receipt
                system("pause");
                break;//exit current switch case and go to "choice" switch case
                system("cls");

            case 4: //If the user select the option 4 (Monthly Summary Report)
                monthly_summary();//Function to view the monthly summary report
                system("pause");
                break;//exit current switch case and go to "choice" switch case
                system("cls");

        }//end switch
    }//end do
    while (choice !=5 );
    c : printf("Are you sure you want to quit this program?\n");
                printf("1. Yes |2. No\n");
                printf("Enter your choice:");
                scanf("%d",&quit);
                if (quit==1)
                {
                    printf("You are exiting this program. Thank you for using this program.\n");
                    goto b;
                }
                else if (quit==2)
                {
                    printf("You have chose to not exit this program.\n");
                    goto a;
                }
                else
                {
                   printf("Input error. Please try again\n");
                   goto c;
                }
    b : return 0;
} //end main

void pay_service()//Pay Service
{
    printf("\n\t\t\t------------------------\n");
    printf("\t\t\t\tPAY SERVICE\n");
    printf("\t\t\t------------------------\n\n");
    //Display the price of different type of type of car , week , and nationality
    printf(" ___________________________________________________________________________\n");
    printf("|                       <<<CAT CITY CHAUFFEUR SERVICE>>                     |\n");
    printf("|                                                                           |\n");
    printf("|___________________________________________________________________________|\n");
    printf("|                   |          CHARGE RATES(for local people)               |\n");
    printf("|                   |_______________________________________________________|\n");
    printf("|      TYPE OF      |          Weekdays         |    Weekend & Holidays     |\n");
    printf("|      VEHICLE      |___________________________|___________________________|\n");
    printf("|                   | 1st 20km | Additional km  | 1st 20km | Additional km  |\n");
    printf("|                   |(6am-10pm)|   (6am-10pm)   | 6am-12am)|   (6am-12am)   |\n");
    printf("|___________________|__________|________________|__________|________________|\n");
    printf("|   PERODUA MYVI    | RM50.00  | RM10.00 per km | RM100.00 | RM15.00 per km |\n");
    printf("|___________________|__________|________________|__________|________________|\n");
    printf("|   PROTON PERDANA  | RM100.00 | RM15.00 per km | RM150.00 | RM20.00 per km |\n");
    printf("|___________________|__________|________________|__________|________________|\n");
    printf("|   TOYOTA ALPHARD  | RM150.00 | RM20.00 per km | RM200.00 | RM25.00 per km |\n");
    printf("|___________________|__________|________________|__________|________________|\n");
    puts("");
    printf("1. Rates include Car Rental, Passengers Insurance, Petrol, Driver, Parking & Toll charges.\n");
    printf("2. Extra 10%% charge out of the total for foreigner.\n");
    printf("3. Extra 5%% out of the total will be charged if service is required until after 10pm on Weekdays.\n");
    printf("4. Extra 10%% out of the total will be charged if service is required until after 12 am on Weekend & Holidays.\n");

    int idno,a=0;//declare integer idno & a

    file = fopen("ChauffeurPay.txt","a+");//fopen opens file
    fclose(file);
    if((file = fopen("ChauffeurPay.txt","r"))==NULL)//fopen opens ChauffeurPay.txt
    {
        printf("File could not be opened\n");
    }
    else
    {
        printf("\nEnter customer ID number:");//prompt user input
        scanf("%d",&idno);
        while(fread(&customer,sizeof(struct PayServiceData),1,file)!=0)
        {
            if(customer.id==idno)
            {
                a=1;
                break;
            }//end if
        }//end while
        if (a==1)
        {
            printf("ID number is unavailable\n");
            printf("Please use a new ID number\n");
        }//end if
        else
        {
            printf("ID number is available to be used\n");
        }//end else
        fclose(file);//fclose closes file
        file = fopen("ChauffeurPay.txt","a+");//fopen opens file
        if(a==0)
        {
            printf("Please enter customer & service details\n");
            customer.id=idno;
            input(&customer); //Obtaining the input from user to enter the details
            fwrite(&customer, sizeof(struct PayServiceData), 1, file); //Insert customer's details in file
            printf("\nService successfully paid\n");
        }//end if
        fclose(file); //fclose closes the file
    }

} //end function

void delete_receipt() //Delete an existing record
{
    int id1,a=0;//Declare id1 & a
    FILE *file2;//Creates a file pointer called file2

    printf("\n\t\t\t-------------------------------\n");
    printf("\t\t\t\tDELETE RECEIPT\n");
    printf("\t\t\t-------------------------------\n\n");

    printf("Enter customer ID number to delete the receipt : ");//Prompt for user input
    scanf("%d", &id1);//Read input from user for customer id

    file = fopen("ChauffeurPay.txt", "r");//fopen opens the file
    while(fread(&customer,sizeof(struct PayServiceData),1,file)!=0)
    {
        if(customer.id==id1)
        {
            a=1;
            break;
        }
    }
    if (a==1)
    {
        int choice;//Declare choice
        printf("Customer name: %s\n",customer.name);//Display customer name
        printf("Total service paid: RM %.2lf\n",customer.total);//Display total service paid by customer
        printf("Are you sure you want to delete this payment receipt?\n");//Ask user before execute
        printf("Enter\n1. Yes\n2. No\n: ");
        scanf("%d", &choice);//read user input
        if (choice==1)
        {
            file2 = fopen("temp.bin", "wb");////fopen opens the file;exits program if file cannot be opened
            rewind(file);//Set the file position to the beginning file
            if (customer.id != id1)
                {
                    fwrite(&customer, sizeof(struct PayServiceData), 1, file2);//Write records in file2
                }//end if
            fclose(file2);//fclose closes file2
            fclose(file);//fclose closes file
            remove("ChauffeurPay.txt");//delete ChauffeurPay.txt
            rename("temp.bin", "ChauffeurPay.txt");//rename temp.bin to ChauffeurPay.txt
            printf("\nRecord deleted.\n");
        }//end if
        else
        {
            printf("Process is terminated\n");
            fclose(file); //fclose closes the file
        }//end else
    }
    else
    {
        printf("Record is not found\n");
        fclose(file); //fclose closes the file
    }

} //end function

void view_receipt() //View customer receipt
{
     int idn, a=0;//declare integer idn, a & intialize a to 0

     printf("\n\t\t\t---------------------------\n");
     printf("\t\t\t\tVIEW RECEIPT\n");
     printf("\t\t\t---------------------------\n\n");

     printf("Enter customer ID number to view the receipt : ");//prompt for user input
     scanf("%d", &idn);//read user input

     file = fopen("ChauffeurPay.txt", "r");//fopen opens ChauffeurPay.txt
     while (fread(&customer, sizeof(struct PayServiceData), 1, file)!=0)
     {
         if(customer.id == idn)
         {
             a=1;
             break;
         }//end if
     }//end while
     if(a==1)
     {
         display(&customer);//display the receipt
     }//end if
     else
     {
         printf("Record is not found\n");
     }//end else
    fclose(file);//fclose closes file
}//end function

void monthly_summary() //Monthly summary
{

    file = fopen("ChauffeurPay.txt", "rb"); //fopen opens the file
    int m,y; //Declare month as 'm' , year as 'y' as integer
    double sum=0; //Declare and initialize sum to 0 as a double
    double sum2=0; //Declare and initialize sum2 to 0 as a double
    double sum3=0; //Declare and initialize sum3 to 0 as a double

    printf("\n\t\t\t-------------------------------\n");
    printf("\t\t\t\tMONTHLY SUMMARY\n");
    printf("\t\t\t-------------------------------\n\n");

    printf("Enter month & year (mm/yyyy):"); //Prompt for user input
    scanf("%d/%d",&m,&y); //Obtaining input from user for month and year

    switch (m)
    {
    case 1 :
        printf("\n%-10s%-10d","JANUARY",y);
        break;
    case 2:
        printf("\n%-10s%-10d","FEBRUARY",y);
        break;
    case 3:
        printf("\n%-10s%-10d","MARCH",y);
        break;
    case 4:
        printf("\n%-10s%-10d","APRIL",y);
        break;
    case 5:
        printf("\n%-10s%-10d","MAY",y);
        break;
    case 6:
        printf("\n%-10s%-10d","JUNE",y);
        break;
    case 7:
        printf("\n%-10s%-10d","JULY",y);
        break;
    case 8:
        printf("\n%-10s%-10d","AUGUST",y);
        break;
    case 9:
        printf("\n%-10s%-10d","SEPTEMBER",y);
        break;
    case 10:
        printf("\n%-10s%-10d","OCTOBER",y);
        break;
    case 11:
        printf("\n%-10s%-10d","NOVEMBER",y);
        break;
    case 12:
        printf("\n%-10s%-10d","DECEMBER",y);
        break;
    }
    while (fread(&customer, sizeof(struct PayServiceData), 1, file)!=0) //Read record from file
    {
            if(customer.month==m && customer.year==y)
                switch (customer.vehicle)
                {
                case 1:
                    sum+=customer.total; //Accumulate the total
                    break;

                case 2:
                    sum2+=customer.total; //Accumulate the total
                    break;

                case 3:
                    sum3 += customer.total; //Accumulate the total
                    break;
                } //end switch

    } //end while

   printf("\n---------------------------------------------------------------------------------------\n");
   printf("%-30s%-20s%-20s%-20s\n","Vehicle","Perodua Myvi","Proton Perdana","Toyota Alphard");
   printf("---------------------------------------------------------------------------------------\n");
   printf("%-30s%-20.2lf%-20.2lf%-20.2lf\n","Total Monthly Income",sum,sum2,sum3);//Display total monthly income for Perodua Myvi, Proton Perdana & Toyota Alphard
   printf("\n_______________________________________________________________________________________\n");
   printf("Total Monthly Income for all vehicle = %.2lf",sum+sum2+sum3);//Display total monthly income for all type of vehicle
   printf("\n_______________________________________________________________________________________\n");

    fclose(file); //fclose closes the file

} //end function


