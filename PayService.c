/*PROJECT GROUP 11: CHAUFFEUR SERVICE SYSTEM
  Group Members :   Zetty Elica Binti Affandi (63879)
                    Nurul Annisa Binti Bulhan (64108)
                    Asnina Binti Ab Hamid (63115)
                    Alya Binti Ahmad (63078)
                    Harithza Assikin Binti Zaharuddin (60894)
*/

//Pay Service

#include<stdio.h>
#include<stdlib.h>
#include "PayService.h"

void input(struct PayServiceData *p) //Function to get customer data
{
    printf("Personal details\n");
    printf("----------------------------------------------------------------------------\n");
    printf("Name:"); //Prompt for user input
    fflush(stdin);
    gets(p->name);

    printf("Contact number\n"); //Prompt for user input
    printf("Country code: +");
    scanf("%d",&p->number1);
    printf("Phone Number:");
    scanf("%d",&p->number2); //Obtaining input from user for contact number
    fflush(stdin);
    printf("Nationality: 1. Malaysian |2. Others\n"); //Display option of nationality
    printf("Select nationality:"); //Prompt for user input
    scanf("%d",&p->nationality); //Obtaining input from user for nationality
    fflush(stdin);
    printf("\nChauffeur Service details\n");
    printf("----------------------------------------------------------------------------\n");
    a : printf("Vehicle type: 1. Perodua Myvi |2. Proton Perdana |3. Toyota Alphard\n"); //Display the option of vehicle type
    printf("Preferred vehicle type:"); //Prompt for user input
    scanf("%d",&p->vehicle); //Obtaining input from user for type of vehicle
    if(p->vehicle==1)
    {
        printf("You have chose Perodua Myvi\n");
    }
    else if(p->vehicle==2)
    {
        printf("You have chose Proton Perdana\n");
    }
    else if(p->vehicle==3)
    {
        printf("You have chose Toyota Alphard\n");
    }
    else
    {
        printf("Input error. Please try again\n");
        goto a;
    }
    printf("Part of the week: 1. Weekdays | 2. Weekends or Holidays\n"); //Display the option of part of week
    printf("Preferred part of the week to use the service: "); //Prompt for user input
    scanf("%d",&p->week); //Obtaining input from user for part of week
    if(p->week==1)
    {
        printf("You have chose to use our service during weekdays\n");
    }
    else if (p->week==2)
    {
        printf("You have chose to use our service during weekends or holidays\n");
    }
    else
    {
        printf("Input error. Please try again\n");
    }
    fflush(stdin);
    printf("Usage date (dd-mm-yyyy):"); //Prompt for user input
    scanf("%d%*c%d%*c%d",&p->day, &p->month, &p->year); //Obtaining input from user for date of service
    fflush(stdin);
    printf("Distance traveled (in km):"); //Prompt for user input
    scanf("%f",&p->distance); //Obtaining input from user for distance travelled
    b : printf("Pickup time (hhmm):"); //Prompt for user input
    scanf("%d", &p->time1); //Obtaining input from user for customer's pickup time
    if (p->time1<600) //Check if pickup time is less than 0600
    {
        printf("Our service starts at 0600\n");
        printf("Please enter pickup time again\n"); //Prompt for user input
        goto b; //Ask user to input pickup time for confirmation
    }//end if
    c : printf("Drop off time\n1. Before our operational hour ends\n2. After our operational hour ends\n");
    printf("Enter your choice:");
    scanf("%d",&p->dropoff);
    if(p->dropoff==1)
    {
        printf("You have chose to use the service within our operational hour\n");
    }
    else if(p->dropoff==2)
    {
        printf("You have chose to use the service until after our operational hour ends\n");

    }
    else
    {
        printf("Input error. Please Try Again\n");
        goto c;
    }
    fflush(stdin);
    printf("Drop off time (hhmm) :"); //Prompt for user input
    scanf("%d", &p->time2); //Obtaining input from user for customer's drop off time

    if (p->vehicle == 1)//Check if vehicle type is 1 (perodua myvi)
    {
		if ( p->week == 1)//Check if part of week is 1 (weekdays)
    	{
    		if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 50.00;
    			p->total=p->charges;

			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 50.00;
    			p->total = p->charges;
                p->total = p->total + (0.05*p->total);

			}//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges = 50.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 50.00;
				p->total= p->charges;
    			p->total = p->total + (0.05*p->total) + (0.1*p->total);
			}//end else if
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 50.00+(p->additionalkm*10);
    			p->total= p->charges;
    		}//end else if
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 50.00+(p->additionalkm*10);
    			p->total= p->charges;
    			p->total = p->total + (0.05*p->total);
    		}//end else if
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 50.00+(p->additionalkm*10);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 50.00+(p->additionalkm*10);
    			p->total= p->charges;
    			p->total= p->total + (0.05*p->total) + (0.1*p->total);
    		}//end else
		}//end if

    	else //If part of week is 2(Weekend or Holidays)
    	{
    		if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 100.00;
    			p->total=p->charges;

			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 100.00;
    			p->total = p->charges;
                p->total = p->total + (0.1*p->total);

			}//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges = 100.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 100.00;
				p->total= p->charges;
    			p->total = p->total + (0.1*p->total) + (0.1*p->total);
			}//end else if
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00+(p->additionalkm*15);
    			p->total= p->charges;
    		}
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00+(p->additionalkm*15);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00 + (p->additionalkm*15);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00 + (p->additionalkm*15);
    			p->total= p->charges;
    			p->total= p->total + (0.1*p->total) + (0.1*p->total);
    		}//end else
    	}//end else
        printf("\nTotal = %.2lf\n",p->total);//Display the total payment
	}//end if

	else if (p->vehicle == 2)//Check if vehicle type is 2 (proton perdana)
    {

		if ( p->week == 1)//Check if part of week is 1 (weekdays)
    	{
    		if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 100.00;
    			p->total=p->charges;
			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 100.00;
    			p->total = p->charges;
                p->total = p->total + (0.05*p->total);

			}//end if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges = 100.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 100.00;
				p->total= p->charges;
    			p->total = p->total + (0.05*p->total) + (0.1*p->total);
			}//end else if
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00+(p->additionalkm*15);
    			p->total= p->charges;
    		}//end else if
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00+(p->additionalkm*15);
    			p->total= p->charges;
    			p->total = p->total + (0.05*p->total);
    		}//end else if
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00 + (p->additionalkm*15);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 100.00 + (p->additionalkm*15);
    			p->total= p->charges;
    			p->total= p->total +(0.05*p->total) + (0.1*p->total);
    		}//end else
		}//end if
		else
        {
            if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 150.00;
    			p->total=p->charges;

			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 150.00;
    			p->total = p->charges;
                p->total = p->total + (0.1*p->total);

			}//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges = 150.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }//end else if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 150.00;
				p->total= p->charges;
    			p->total = p->total + (0.1*p->total) + (0.1*p->total);
			}//end else if
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    		}//end else if
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}//end else if
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    			p->total= p->total+(0.1*p->total)+(0.1*p->total);
    		}//end else
        }
        printf("\nTotal = %.2lf\n",p->total);//Display the total payment
    }//end else if

	else
    {

		if ( p->week == 1)
    	{
    		if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 150.00;
    			p->total=p->charges;

			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 150.00;
    			p->total = p->charges;
                p->total = p->total + (0.05*p->total);

			}//end if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges = 150.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 150.00;
				p->total= p->charges;
    			p->total = p->total + (0.05*p->total) + (0.1*p->total);
			}//end else
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    		}
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    			p->total = p->total + (0.05*p->total);
    		}
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+(p->additionalkm*20);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 150.00+ (p->additionalkm*20);
    			p->total= p->charges;
    			p->total= p->total +(0.05*p->total)+(0.1*p->total);
    		}
		}//end if
		else
		{
		    if (p->distance<=20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->charges = 200.00;
    			p->total=p->charges;

			}//end if
			else if (p->distance<=20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->charges = 200.00;
    			p->total = p->charges;
                p->total = p->total + (0.1*p->total);

			}//end if
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==1)
            {
                p->charges =200.00;
                p->total= p->charges;
                p->total = p->total + (0.1*p->total);

            }
			else if (p->distance<=20 && p->nationality==2 && p->dropoff==2)
			{
				p->charges = 200.00;
				p->total= p->charges;
    			p->total = p->total + (0.1*p->total) + (0.1*p->total);
			}//end else
            else if (p->distance>20 && p->nationality==1 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 200.00+(p->additionalkm*25);
    			p->total= p->charges;
    		}
    		else if (p->distance>20 && p->nationality==1 && p->dropoff==2)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges =200.00+(p->additionalkm*25);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}
    		else if (p->distance>20 && p->nationality==2 && p->dropoff==1)
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 200.00+(p->additionalkm*25);
    			p->total= p->charges;
    			p->total = p->total + (0.1*p->total);
    		}
            else
    		{
    			p->additionalkm = p->distance - 20;
    			p->charges = 200.00+(p->additionalkm*25);
    			p->total= p->charges;
    			p->total= p->total +(0.1*p->total) + (0.1*p->total);
    		}
		}
        printf("\nTotal = %.2lf\n",p->total);//Display the total payment
	}//end else
    d : printf("\nPayment method\n1.Cash| 2. Credit Card\n");
	printf("Enter payment method: ");
	scanf("%d",&p->payment);
	if(p->payment==1)
    {
        printf("You have chose to pay by cash\n");
    }
    else if (p->payment==2)
    {
        printf("You have chose to pay by credit card\n");
    }
    else
    {
        printf("Input error. Please try again\n");
        goto d;
    }
    fflush(stdin);
}//end function




