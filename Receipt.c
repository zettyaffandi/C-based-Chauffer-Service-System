/*PROJECT GROUP 11: CHAUFFEUR SERVICE SYSTEM
  Group Members :   Zetty Elica Binti Affandi (63879)
                    Nurul Annisa Binti Bulhan (64108)
                    Asnina Binti Ab Hamid (63115)
                    Alya Binti Ahmad (63078)
                    Harithza Assikin Binti Zaharuddin (60894)
*/

//Receipt

#include<stdio.h>
#include"PayService.h"

void display(struct PayServiceData *p) //Function to show customer receipt
{
    //view receipt
    // information about our company
    printf("\n\t\t\tCAT CITY CHAUFFEUR SERVICE\n\t\t\tUniversiti Malaysia Sarawak\n\t\t\tKota Samarahan, 94300\n");
    printf("\nPhone: 082-12345\t\tFax: 082-67890\t\t\tEmail: CatCityCS@gmail.com\n");
    printf("\nCustomer ID number:%d\n",p->id);// DIsplay customer's id number
	printf("Customer name:%s\t\t\t\t\tContact number:+%d%d\n",p->name,p->number1,p->number2);//DIsplay customer's name & contact number
	printf("____________________________________________________________________________________________\n");
    printf("                                 Description                                    \n");
    printf("____________________________________________________________________________________________\n");
    if (p->nationality==1)
    {
        printf("Customer's nationality : Malaysian\n");
    }
    else
    {
        printf("Customer's nationality : Non - Malaysian\n");
    }
    printf("Date Of Usage : %d/%d/%d\n",p->day,p->month,p->year);//Display the date of service
     //Display the type of vehicle
    if (p->vehicle==1)
    {
        printf("Vehicle type : Perodua Myvi\n");
    }
    else if(p->vehicle==2)
    {
        printf("Vehicle type : Proton Perdana\n");
    }
    else
    {
        printf("Vehicle type : Toyota Alphard\n");
    }
    printf("Distance traveled : %.2f km\n",p->distance);//Display the distance traveled
    printf("Pickup time : %d hours\n",p->time1);//Display the pickup time
    printf("Drop off time : %d hours\n",p->time2);//Display the drop-off time
    printf("_____________________________________________________________________________________________\n");
    printf("Total Charged\t\t\t\t\t\t| RM%.2lf\n",p->total);//Display the total payment
    printf("________________________________________________________|____________________________________\n");
    if (p->payment==1)
    {
       printf("Payment method : Cash\n");
    }
    else
    {
        printf("Payment method : Card\n");
    }
    printf("Service successfully paid\n");
    printf("_____________________________________________________________________________________________\n");
	printf("\n\t\t\tThank You for using our service\n");
    printf("_____________________________________________________________________________________________\n\n");

}//end function



