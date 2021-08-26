/*PROJECT GROUP 11: CHAUFFEUR SERVICE SYSTEM
  Group Members :   Zetty Elica Binti Affandi (63879)
                    Nurul Annisa Binti Bulhan (64108)
                    Asnina Binti Ab Hamid (63115)
                    Alya Binti Ahmad (63078)
                    Harithza Assikin Binti Zaharuddin (60894)
*/

//PayService.h
//declare struct name for Pay Service

struct PayServiceData
{

    char name[100]; //Declare name as string input
    int id, number1, number2, nationality, vehicle, week, day, month,year, time1, time2, dropoff,choice,payment; /*Declare id,number1,number2,
    nationality,vehicle,week,day,month,year,time1,time2,dropoff,choice & payment as Integer input*/
    float distance; //Declare distance as float input
    double charges, total, additionalkm; //Declare charges,total and additionalkm as Double input
};

//function of struct to get and show Pay Service Data
void display(struct PayServiceData *p);
void input(struct PayServiceData *p);

