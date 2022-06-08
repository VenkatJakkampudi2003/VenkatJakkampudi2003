//Program on the hotel management
//Linux version
/************************************************************************************************************************************************************************
|   PURPOSE OF THE PROGRAM : 
|   ------------------------
|   - For the sake of hotel management
|   
|    AIM:
|    ----
|   - The data has to taken from the user in the form of order or service and has to be computated and print the final  bill
| 
|   OBJECTIVE:
|   ----------
|   - Creation of such a loop which stores the data as long as the user gives them it will finally display the output after the computation part.
|   - The code has to run as long as the user desires it to run.
|   - The data has to be stored into a file.
|   - The data should also be efficient to retrive from the files in the way how they were stored into the files
|
************************************************************************************************************************************************************************/

//Header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Macro initialization
#define pf printf
#define sf scanf

//Global variable declaration variables
//String
char ch[100];
//Essential variables
char choice,cname[75],cn[20],cna[20];
int Resi[25],Resta[25],Final[25],Bill=0,i=0,j=0;
int cno;
//Stay & quantity
int stay;
int quantity;
//Data management part
char str[100];
int kaunt,cat,usd,psd,count;

//Function declaration
void data_management();

//Driver code
int main()
{
    //Time structure
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime (&currentTime);

    /*******************************************************************************************************************************************************************
    | 
    |   FILES:
    |   ------
    |   1.General         -> Tracks all the activities done by the user
    |   2.Customer        -> Collects the user details
    |   3.Residency       -> Collects residency details
    |   4.Revenue         -> Collects all the financial details
    |
    |   WORK:
    |   ------
    |    1.Opening all the files in the append plus mode because i have to write as well as read the information from the files
    |    2.Noting down the date and time so it will be easier to identify when did the activity take place 
    |
    |*******************************************************************************************************************************************************************/

    //Initializing files
    FILE *fp;       //To create a general file
    FILE *Revenue;  //To note down the revenue on daily basis
    FILE *Cus;      //To create a customer detail file
    FILE *Ro;       //To create a residency detail file

    //FILE NO - 1 this is used to note the activities done by the user
    fp = fopen("Hotel Data.txt","a+");
    fprintf(fp,"\n----------------------------------------------------------------------------------------------------");
    fprintf(fp,"\nDate:%d-%d-%d\nTime :%d:%d:%d",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year + 1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    //FILE NO - 2 This is used to store the information about the customer
    Cus = fopen("Custmer details.txt","a+");    //This file is simultaneously opened along with the residency file
    fprintf(Cus,"\n");
    //FILE NO - 3 This is used to store the data regarding the rooms 
    Ro = fopen("Room Details.txt","a+");     //Used to note down and track the room details
    //FILE NO - 4 This is used to note down the finalcial information of the hotel
    Revenue = fopen("Hotel Revenue.txt","a");

    //Preface of the program
    system("clear");
    pf("\n\n\t\t\t\t\t\t\t\t--------------------------------------------------------------\n");
    pf("\t\t\t\t\t\t\t\t|           V   E   N   K   A   T   G  R   A   N   D         |\n");
    pf("\t\t\t\t\t\t\t\t|------------------------------------------------------------|\n");
    pf("\t\t\t\t\t\t\t\t|                                                            |\n");
    pf("\t\t\t\t\t\t\t\t|                 W    E   L   C   O   M   E                 |\n");
    pf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------\n");
    pf("\t\t\t\t\t\t\t\t|->   Date    :    %d/%d/%d                                   \n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year + 1900);
    pf("\t\t\t\t\t\t\t\t|->   Time    :    %d:%d:%d                                   \n",myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    pf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------\n");
    pf("\t\t\t\t\t\t\t\t|                                                            |\n");
    pf("\t\t\t\t\t\t\t\t|                L  O  C  A  L  I  T  Y                      |\n");
    pf("\t\t\t\t\t\t\t\t|------------------------------------------------------------|\n");
    pf("\t\t\t\t\t\t\t\t|->   Location : Rushikonda beach road, Visakhapatnam        |\n");
    pf("\t\t\t\t\t\t\t\t|->   Pincode : 530045                                       |\n");
    pf("\t\t\t\t\t\t\t\t|------------------------------------------------------------|\n");
    pf("\t\t\t\t\t\t\t\t|                                                            |\n");
    pf("\t\t\t\t\t\t\t\t|                 C   O   N   T   A   C   T                  |\n");
    pf("\t\t\t\t\t\t\t\t|------------------------------------------------------------|\n");
    pf("\t\t\t\t\t\t\t\t|->   Gmail           : VenkatGrand415@gmail.com             |\n");
    pf("\t\t\t\t\t\t\t\t|->   Hotel telephone : 0863-246462, 0863-246463             |\n");
    pf("\t\t\t\t\t\t\t\t|->   Mobile number   : 9845246462                           |\n");
    pf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------\n");
    pf("\t\t\t\t\t\t\t\t|''Press any key to continue........'' : ");
    sf(" %[^\n]S",ch);

    Main_Menu:
    //Displaying main menu
    system("clear");
    pf("\n\t\t\t\t\t\t\t\t---------------------------------------------------------");
    pf("\n\t\t\t\t\t\t\t\t|              M   a   i   n   M   e   n   u            |");
    pf("\n\t\t\t\t\t\t\t\t|-------------------------------------------------------|");
    pf("\n\t\t\t\t\t\t\t\t|                                                       |");
    pf("\n\t\t\t\t\t\t\t\t|1.  Residency                                          |");
    pf("\n\t\t\t\t\t\t\t\t|                                                       |");
    pf("\n\t\t\t\t\t\t\t\t|2.  Restaurant                                         |");
    pf("\n\t\t\t\t\t\t\t\t|                                                       |");
    pf("\n\t\t\t\t\t\t\t\t|3.  Data management                                    |");
    pf("\n\t\t\t\t\t\t\t\t|                                                       |");
    pf("\n\t\t\t\t\t\t\t\t|         Any other key to exit                         |");
    pf("\n\t\t\t\t\t\t\t\t|                                                       |");
    pf("\n\t\t\t\t\t\t\t\t|-------------------------------------------------------|");
    pf("\n\t\t\t\t\t\t\t\t|       Enter  :     ");
    sf(" %c",&choice);
    //Swictching in between the choices made by the user
    switch (choice)
    {
    case '1':
        fprintf(fp,"\nUser choosed Residency");     //Incase if the user chooses the residency as a choice
        Resta[i] = 0;
        goto customer_details;
        break;
    case '2':
        fprintf(fp,"\nUser choosed Restaurant");
        Resi[i] = 0;
        goto Restaurant;
        break;
    case '3':
        Resi[i] = 0;
        Resta[i] = 0;
        fprintf(fp,"\nUser choosed to check data management");
        data_management();
    default:
        if (j>0)
        {
            goto Done;
        }
        else
        {
            fprintf(fp,"\nProgram terminated");
            printf("\n\t\t\t\t\t\t                E            X            I            T    ");
            exit(0);   
        }
        break;
    }

    //Storing Customer details
    customer_details:
    system("clear");
    pf("\t\t\t\t\t\t\t-----------------------------------------------\n");
    pf("\t\t\t\t\t\t\t|            Enter Custmer details            |");
    pf("\n\t\t\t\t\t\t\t|---------------------------------------------|");
    pf("\n\t\t\t\t\t\t\t|   Customer number     : ");
    sf("%d",&cno);
    pf("\t\t\t\t\t\t\t|   Customer name       : ");
    sf(" %[^\n]s",cname);
    pf("\t\t\t\t\t\t\t|   Mobile number       : ");
    sf(" %[^\n]s",cn);
    pf("\t\t\t\t\t\t\t|   Alternative number  : ");
    sf(" %[^\n]s",cna);
    pf("\t\t\t\t\t\t\t|---------------------------------------------|\n");

    //Entering the data into the files
    fprintf(Cus,"\n------------------------------------------------------------------------------------------------------------------------------------");
    fprintf(Cus,"\nDate:%d-%d-%d\nTime :%d:%d:%d",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year + 1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    fprintf(Cus,"\n\t\t\t\t\t\t\t-----------------------------------------------");
    fprintf(Cus,"\n\t\t\t\t\t\t\t|            Enter Custmer details            |");
    fprintf(Cus,"\n\t\t\t\t\t\t\t|---------------------------------------------|");
    fprintf(Cus,"\n\t\t\t\t\t\t\t|   Customer number     : %d",cno);
    fprintf(Cus,"\n\t\t\t\t\t\t\t|   Customer name       : %s",cname);
    fprintf(Cus,"\n\t\t\t\t\t\t\t|   Mobile number       : %s",cn);
    fprintf(Cus,"\n\t\t\t\t\t\t\t|   Alternative number  : %s",cna);
    fprintf(Cus,"\n\t\t\t\t\t\t\t|---------------------------------------------|\n");
    cat++;

    //Residency Part
    Residency:
    
    fprintf(Ro,"\n----------------------------------------------------------------------------------------------------");
    fprintf(Ro,"\nDate:%d-%d-%d\nTime :%d:%d:%d",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year + 1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    fprintf(Ro,"\n");
    system("clear");
    pf("\n\t\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------");
    pf("\n\t\t\t\t|                                                      R   E   S   I   D   E   N   C   Y                                                      |");
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|  >>   Choose your room depending upon your requirements the types of rooms and their specifications are as follows                          |");
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");
    pf("\n\t\t\t\t|                                             S   P   E   C   I   F   I   C   A   T   I   O   N   S                                           |");
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");        
    pf("\n\t\t\t\t|         Name           |      Size      |                               F   A   C   I   L   I   T   I   E   S                               |");
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|  >>   Suite             2 - 4 persons        1 Double sharing Bed, 2 Seprate beds for kids, Central AC, Sofa, TV, Bathroom with tub         |");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|  >>   King              2 Persons            1 King size Bed, Central AC, Sofa, TV, Bathroom with tub,  Balcony                             |");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|  >>   Queen             2 Persons            1 Queen size Bed, 1 single Bed for kid, Central AC, Sofa, TV, Bathroom with tub                |");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|  >>   Quad              4 Persons            1 Queen size Bed, 2 single Bed for kid, Central AC, Sofa, TV, Bathroom with tub, Balcony       |");
    pf("\n\t\t\t\t|                                                                                                                                             |");    
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");
    pf("\n\t\t\t\t|                                                                                                                                             |");
    pf("\n\t\t\t\t|                               R   O   O   M       C   O   D   E           &           P   R   I   C   I   N   G                             |");
    pf("\n\t\t\t\t|---------------------------------------------------------------------------------------------------------------------------------------------|");
    pf("\n\t\t\t\t|  >>   1        Suite            :   12500                                                                                                   |");
    pf("\n\t\t\t\t|  >>   2        King             :   10000                                                                                                   |");
    pf("\n\t\t\t\t|  >>   3        Queen            :   8000                                                                                                    |");
    pf("\n\t\t\t\t|  >>   4        Quad             :   9500                                                                                                    |");
    pf("\n\t\t\t\t|  >>   P        Prevoius Menu                                                                                                                |");
    pf("\n\t\t\t\t|  >>   E        Exit                                                                                                                         |");
    pf("\n\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------------------");
    pf("\n\t\t\t\t|         Enter room code :   ");
    sf(" %c",&choice);
    system("clear");
    switch (choice)
    {
    case '1':    
        printf("\n\t\t\t\t\t\t\t------------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t|   Room Type   :   Suite                            |");
        printf("\n\t\t\t\t\t\t\t|----------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t|   Rooms available   :                              |");
        printf("\n\t\t\t\t\t\t\t|   -------------------                              |");
        printf("\n\t\t\t\t\t\t\t|   Enter stay : ");
        scanf("%d",&stay);
        fprintf(Ro,"custmer choosed Suite room for %d days",stay);
        Resi[i] = 12500*stay;
        goto Done;
        break;
    case '2':
        printf("\n\t\t\t\t\t\t\t------------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t|   Room Type   :   King                             |");
        printf("\n\t\t\t\t\t\t\t|----------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t|   Rooms available   :                              |");
        printf("\n\t\t\t\t\t\t\t|   -------------------                              |");
        printf("\n\t\t\t\t\t\t\t|   Enter stay : ");
        scanf("%d",&stay);
        Resi[i] = 10000*stay;
        fprintf(Ro,"custmer choosed King room for %d days",stay);
        goto Done;
        break;
    case '3':
        printf("\n\t\t\t\t\t\t\t------------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t|   Room Type   :   Queen                            |");
        printf("\n\t\t\t\t\t\t\t|----------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t|   Rooms available   :                              |");
        printf("\n\t\t\t\t\t\t\t|   -------------------                              |");
        printf("\n\t\t\t\t\t\t\t|   Enter stay : ");
        scanf("%d",&stay);
        fprintf(Ro,"custmer choosed Queen room for %d days",stay);
        Resi[i] = 8000*stay;
        goto Done;
        break;
    case '4':
        printf("\n\t\t\t\t\t\t\t------------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t|   Room Type   :   Quad                             |");
        printf("\n\t\t\t\t\t\t\t|----------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t|   Rooms available   :                              |");
        printf("\n\t\t\t\t\t\t\t|   -------------------                              |");
        printf("\n\t\t\t\t\t\t\t|   Enter stay : ");
        scanf("%d",&stay);
        fprintf(Ro,"custmer choosed Quad room for %d days",stay);
        Resi[i] = 9500*stay;
        goto Done;
        break;
    case 'P':
        goto Main_Menu;
        break;
    case 'p':
        goto Main_Menu;
        break;
    case 'e':
        goto Done;
        break;
    case 'E':
        goto Done;
        break;
    default:printf("Invalid choice");
        goto Residency;
        break;
    }
    fprintf(Ro,"\n----------------------------------------------------------------------------------------------------\n");

    //Restaurant part
    Restaurant:
    system("clear");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t-----------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t|                     R   E   S   T   U   R   A   N   T               |");
    printf("\n\t\t\t\t\t\t\t\t|---------------------------------------------------------------------|");
    printf("\n\t\t\t\t\t\t\t\t|                                                                     |");
    printf("\n\t\t\t\t\t\t\t\t|                  Choose your meals as per the time                  |");
    printf("\n\t\t\t\t\t\t\t\t|-------------------------------------------------------------------- |");
    printf("\n\t\t\t\t\t\t\t\t|                                                                     |");
    printf("\n\t\t\t\t\t\t\t\t|                      T   I   M   I   N   G   S                      |");
    printf("\n\t\t\t\t\t\t\t\t|---------------------------------------------------------------------|");
    printf("\n\t\t\t\t\t\t\t\t|     M   E   A   L     |     F   R   O   M    |        T   O         |");
    printf("\n\t\t\t\t\t\t\t\t|-----------------------|----------------------|----------------------|");
    printf("\n\t\t\t\t\t\t\t\t|     Breakfast         |      06:00 AM        |       11:00 AM       |");
    printf("\n\t\t\t\t\t\t\t\t|     Lunch             |      12:00 PM        |       03:00 PM       |");
    printf("\n\t\t\t\t\t\t\t\t|     Snacks            |      04:00 PM        |       07:30 PM       |");
    printf("\n\t\t\t\t\t\t\t\t|     Dinner            |      07:30 PM        |       12:00 AM       |");
    printf("\n\t\t\t\t\t\t\t\t|---------------------------------------------------------------------|");
    printf("\n\t\t\t\t\t\t\t\t|                 M    E   A   L        C   O   D   E                 |");
    printf("\n\t\t\t\t\t\t\t\t|---------------------------------------------------------------------|");        
    printf("\n\t\t\t\t\t\t\t\t|     Breakfast               :   1                                   |");
    printf("\n\t\t\t\t\t\t\t\t|     Lunch or dinner         :   2                                   |");
    printf("\n\t\t\t\t\t\t\t\t|     Snacks                  :   3                                   |");
    printf("\n\t\t\t\t\t\t\t\t|     For previous menu       :   P                                   |");
    printf("\n\t\t\t\t\t\t\t\t|     Exit                    :   E                                   |");
    printf("\n\t\t\t\t\t\t\t\t|---------------------------------------------------------------------|");
    printf("\n\t\t\t\t\t\t\t\t|         Enter Meal code : ");
    scanf(" %c",&choice);
    switch (choice)
    {
    case '1':
        //Breakfast part
        Breakfast:
        system("cls");
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t|             B   R   E   A   K   F   A   S   T             |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t|                       M   E   N   U                       |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t| >>>>  Choose your dish by using the code                  |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t|     C O D E          I   T   E   M             P R I C E  |\n");
        printf("\t\t\t\t\t\t\t\t|    ---------        ----------------          ----------- |\n");
        printf("\t\t\t\t\t\t\t\t| >>     1             Idli                     :    30     |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t| >>     2             Vada                     :    40     |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t| >>     3             Puri                     :    55     |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t| >>     4             Dosa                     :    50     |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t| >>     R             For previous menu                    |\n");
        printf("\t\t\t\t\t\t\t\t|                                                           |\n");
        printf("\t\t\t\t\t\t\t\t| >>     E             To exit                              |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t|           Enter your order   :   ");
        scanf(" %c",&choice);
        system("cls");
        printf("\t\t\t\t\t\t\t\t--------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t|     C O D E       D  I   S   H      P R I C E  |\n");
        printf("\t\t\t\t\t\t\t\t|    ---------     --------------    ------------|\n");
        printf("\t\t\t\t\t\t\t\t|                                                |\n");
        switch (choice)
        {
        case '1':
            printf("\t\t\t\t\t\t\t\t| >>     1            Idli           :    30     |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------\n\t\t\t\t\t\t\t\t|   Enter quantity  :     ");
            scanf("%d",&quantity);
            Resta[i] = 30*quantity;
            goto Done;
            break;
        case '2':
            printf("\t\t\t\t\t\t\t\t| >>     2            Vada           :    40     |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------\n\t\t\t\t\t\t\t\t|   Enter quantity  :     ");
            scanf("%d",&quantity);
            Resta[i] = 40*quantity;
            goto Done;
            break;
        case '3':
            printf("\t\t\t\t\t\t\t\t| >>     3            Puri           :    55     |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------\n\t\t\t\t\t\t\t\t|   Enter quantity  :     ");
            scanf("%d",&quantity);
            Resta[i] = 55*quantity;
            goto Done;
            break;
        case '4':
            printf("\t\t\t\t\t\t\t\t| >>     4            Dosa           :    50     |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------\n\t\t\t\t\t\t\t\t|   Enter quantity  :     ");
            scanf("%d",&quantity);
            Resta[i] = 50*quantity;
            goto Done;
            break;
        case 'R':
            goto Restaurant;
            break;
        case 'r':
            goto Restaurant;
            break;
        case 'E':
            goto Done;
            break;
        case 'e':
            goto Done;
            break;
        default:printf("Invalid choice");
            goto Breakfast;
            break;
        }
        break;
    case '2':
        //Lunch and dinner part
        L_AND_D:
        system("clear");
        printf("\n\t\t\t\t\t\t\t\t--------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t\t|                   M   E   N   U                |");
        printf("\n\t\t\t\t\t\t\t\t|------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t\t|                                                |");
        printf("\n\t\t\t\t\t\t\t\t| >>  1    Vegetarian                            |");
        printf("\n\t\t\t\t\t\t\t\t| >>  2    Non-Vegetarian                        |");
        printf("\n\t\t\t\t\t\t\t\t| >>  Q    For previous menu                     |");
        printf("\n\t\t\t\t\t\t\t\t| >>  E    Exit                                  |");
        printf("\n\t\t\t\t\t\t\t\t|------------------------------------------------|");
        printf("\n\t\t\t\t\t\t\t\t|     Enter   :   ");
        scanf(" %c",&choice);
        switch (choice)
        {
        case '1':
            //Vegetarian menu part
            VEG:
            system("clear");
            
            printf("\t\t\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|                     V   E   G   E   T   A   R   I   A   N                     |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|                                M   E   N   U                                  |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t| >>>>  Choose your dish by using the code                                      |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t|     C O D E                    I   T   E   M                       P R I C E  |\n");
            printf("\t\t\t\t\t\t\t\t|    ---------        -------------------------------------         ----------- |\n");
            printf("\t\t\t\t\t\t\t\t| >>     1              Ulavacharu Biryani                          :    200    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     2              Veg Biryani                                 :    250    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     3              Mushroom Biryani                            :    250    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     4              Roti & Curries                              :    150    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     R              For previous menu                                       |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     E              Any other key to exit                                   |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|           Enter your order   :   ");
            scanf(" %c",&choice);
            system("cls");
            switch (choice)
            {
            case '1':
                printf("\t\t\t\t\t\t\t\t--------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t|   S.no  |            ITEM              | Price |\n\t\t\t\t\t\t\t\t|------------------------------------------------|\n");
                printf("\t\t\t\t\t\t\t\t|    1    |    Ulavacharu Biryani        |  200  |\n");
                printf("\t\t\t\t\t\t\t\t|------------------------------------------------|\n\t\t\t\t\t\t\t\t| Enter quantity = ");
                scanf("%d",&quantity);
                Resta[i] = 200*quantity;
                goto Done;
                break;
            case '2':
                printf("\t\t\t\t\t\t\t\t--------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t|   S.no  |            ITEM              | Price |\n\t\t\t\t\t\t\t\t|------------------------------------------------|\n");
                printf("\t\t\t\t\t\t\t\t|    2    |    Veg biryani               |  250  |\n");
                printf("\t\t\t\t\t\t\t\t|------------------------------------------------|\n\t\t\t\t\t\t\t\t| Enter quantity = ");
                scanf("%d",&quantity);
                Resta[i] = 250*quantity;
                goto Done;
                break;
            case '3':
                printf("\t\t\t\t\t\t\t\t--------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t|   S.no  |            ITEM              | Price |\n\t\t\t\t\t\t\t\t|------------------------------------------------|\n");
                printf("\t\t\t\t\t\t\t\t|    3    |    Mushroom Biryani          |  250  |\n");
                printf("\t\t\t\t\t\t\t\t|------------------------------------------------|\n\t\t\t\t\t\t\t\t| Enter quantity = ");
                scanf("%d",&quantity);
                Resta[i] = 250*quantity;
                goto Done;
                break;
            case '4':
                printf("\t\t\t\t\t\t\t\t--------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t|   S.no  |            ITEM              | Price |\n\t\t\t\t\t\t\t\t|------------------------------------------------|\n");
                printf("\t\t\t\t\t\t\t\t|    4    |    Roti & Curries            |  150  |\n");
                printf("\t\t\t\t\t\t\t\t|------------------------------------------------|\n\t\t\t\t\t\t\t\t| Enter quantity = ");
                scanf("%d",&quantity);
                Resta[i] = 150*quantity;
                goto Done;
                break;
            case 'r':
                goto L_AND_D;
                break;
            case 'R':
                goto L_AND_D;
                break;
            case 'e':
                goto Done;
                break;
            case 'E':
                goto Done;
                break;
            default:printf("Invalid choice");
                goto VEG;
                break;
            }
        case '2':
            //Non-Vegetarian menu part
            NONVEG:
            system("clear");
            printf("\t\t\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|             N   O   N   -   V   E   G   E   T   A   R   I   A   N             |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|                                M   E   N   U                                  |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t| >>>>  Choose your dish by using the code                                      |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t|     C O D E                    I   T   E   M                       P R I C E  |\n");
            printf("\t\t\t\t\t\t\t\t|    ---------        -------------------------------------         ----------- |\n");
            printf("\t\t\t\t\t\t\t\t| >>     1              Chicken Dum Biryani                         :    350    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     2              Mutton Dum Biryani                          :    350    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     3              Special Chicken Biryani                     :    400    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     4              Fish & Prawns biryani                       :    450    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     5              Venkat Grand Family pack                    :   1000    |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     R              For previous menu                                       |\n");
            printf("\t\t\t\t\t\t\t\t|                                                                               |\n");
            printf("\t\t\t\t\t\t\t\t| >>     E              Any other key to exit                                   |\n");
            printf("\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|           Enter your order   :   ");
            scanf(" %c",&choice);
            switch (choice)
            {
            case '1':
                printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t| S.no |                     Item                | Price |\n");
                printf("\t\t\t\t\t\t\t\t|------|-----------------------------------------|-------|\n");
                printf("\t\t\t\t\t\t\t\t|  1   | Chicken Dum Biryani                     |  350  |\n");
                printf("\t\t\t\t\t\t\t\t|Enter quantity : ");
                scanf("%d",&quantity);
                Resta[i] = 350*quantity;
                goto Done;
                break;
            case '2':
                printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t| S.no |                     Item                | Price |\n");
                printf("\t\t\t\t\t\t\t\t|------|-----------------------------------------|-------|\n");
                printf("\t\t\t\t\t\t\t\t|  2   | Chicken Fry piece Biryani               |  350  |\n");
                printf("\t\t\t\t\t\t\t\t|Enter quantity : ");
                scanf("%d",&quantity);
                Resta[i] = 350*quantity;
                goto Done;
                break;
            case '3':
                printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t| S.no |                     Item                | Price |\n");
                printf("\t\t\t\t\t\t\t\t|------|-----------------------------------------|-------|\n");
                printf("\t\t\t\t\t\t\t\t|  3   | Special Chicken Biryani                 |  400  |\n");
                printf("\t\t\t\t\t\t\t\t|Enter quantity : ");
                scanf("%d",&quantity);
                Resta[i] = 400*quantity;
                goto Done;
                break;
            case '4':
                printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t| S.no |                     Item                | Price |\n");
                printf("\t\t\t\t\t\t\t\t|------|-----------------------------------------|-------|\n");
                printf("\t\t\t\t\t\t\t\t|  4   | Mutton Dum Biryani                      |  450  |\n");
                printf("\t\t\t\t\t\t\t\t|Enter quantity : ");
                scanf("%d",&quantity);
                Resta[i] = 450*quantity;
                goto Done;
                break;
            case '5':
                printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t| S.no |                     Item                | Price |\n");
                printf("\t\t\t\t\t\t\t\t|------|-----------------------------------------|-------|\n");
                printf("\t\t\t\t\t\t\t\t|  5   | Venkat Grand Family pack                | 1000  |\n");
                printf("\t\t\t\t\t\t\t\t|Enter quantity : ");
                scanf("%d",&quantity);
                Resta[i] = 1000*quantity;
                goto Done;
                break;
            case 'r':
                goto L_AND_D;
                break;
            case 'R':
                goto L_AND_D;
                break;
            case 'E':
                goto Done;
                break;
            case 'e':
                goto Done;
                break;
            default:printf("Invalid choice");
                goto NONVEG;
                break;
            }
        //Outer loop for the main switch case
        case 'q':
            goto Restaurant;
            break;
        case 'Q':
           goto Restaurant;
           break;
        case 'E':
           exit(1);
        case 'e':
           exit(1);
        default:printf("Invalid choice");
            goto L_AND_D;
            break;
        }
        break;
    case '3':
        //Snacks part
        printf("Snacks");
        SNACKS:
        system("clear");
        printf("\t\t\t\t\t\t\t\tYou chose Snacks\n");
        printf("\t\t\t\t\t\t\t\t________________________\n\n");
        printf("\t\t\t\t\t\t\t\tSnack menu\n");
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t|                                   S   N   A   C   K   S                                 |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t|                                       M   E   N   U                                     |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t| >>>>  Choose your dish by using the code                                                |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t|     C O D E                    I   T   E   M                                P R I C E   |\n");
        printf("\t\t\t\t\t\t\t\t|    ---------        -------------------------------------                   ----------- |\n");
        printf("\t\t\t\t\t\t\t\t| >>     1            VGS-1 : 2pc Samosa, 2pc Puff, 2 Coke                    :    180    |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t| >>     2            VGS-2 : Pakoda, 10pc Pani poori, Chat                   :    250    |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t| >>     3            VGS-3 : Chiken Pizza, Hakka noodles, Lemon Logan        :    350    |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t| >>     4            VGS-4 : Pasta, Shawarma, Chicken Manchurian             :    220    |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t| >>     Q              For previous menu                                                 |\n");
        printf("\t\t\t\t\t\t\t\t|                                                                                         |\n");
        printf("\t\t\t\t\t\t\t\t| >>     E              To exit                                                           |\n");
        printf("\t\t\t\t\t\t\t\t|-----------------------------------------------------------------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t|           Enter your order   :   ");
        scanf(" %c",&choice);
        system("clear");
        switch (choice)
        {
        case '1':
            printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|  S.no  |                               Items                     |  price |\n");
            printf("\t\t\t\t\t\t\t\t|--------|---------------------------------------------------------|--------|\n");
            printf("\t\t\t\t\t\t\t\t|    1   |   VGS-1 - 2pc Samosa, 2pc Puff, 2 Coke                  |   180  |\n");
            printf("\t\t\t\t\t\t\t\t|---------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|   Enter quantity : ");
            scanf("%d",&quantity);
            Resta[i] = 180*quantity;
            goto Done;
            break;
        case '2':
            printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|  S.no  |                               Items                     |  price |\n");
            printf("\t\t\t\t\t\t\t\t|--------|---------------------------------------------------------|--------|\n");
            printf("\t\t\t\t\t\t\t\t|    2   |   VGS-2 - Pakoda, 10pc Pani poori, Chat                 |   250  |\n");
            printf("\t\t\t\t\t\t\t\t|---------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|   Enter quantity : ");
            scanf("%d",&quantity);
            Resta[i] = 250*quantity;
            goto Done;
            break;
        case '3':
            printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|  S.no  |                               Items                     |  price |\n");
            printf("\t\t\t\t\t\t\t\t|--------|---------------------------------------------------------|--------|\n");
            printf("\t\t\t\t\t\t\t\t|    3   |   VGS-3 - Chiken Pizza, Hakka noodles, Lemon Logan      |   350  |\n");
            printf("\t\t\t\t\t\t\t\t|---------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|   Enter quantity : ");
            scanf("%d",&quantity);
            Resta[i] = 350*quantity;
            goto Done;
            break;
        case '4':
            printf("\t\t\t\t\t\t\t\t-----------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t|  S.no  |                               Items                     |  price |\n");
            printf("\t\t\t\t\t\t\t\t|--------|---------------------------------------------------------|--------|\n");
            printf("\t\t\t\t\t\t\t\t|    4   |   VGS-4 - Pasta, Shawarma, Chicken Manchurian           |   220  |\n");
            printf("\t\t\t\t\t\t\t\t|---------------------------------------------------------------------------|\n");
            printf("\t\t\t\t\t\t\t\t|   Enter quantity : ");
            scanf("%d",&quantity);
            Resta[i] = 220*quantity;
            goto Done;
            break;
        case 'Q':
            goto Restaurant;
            break;
        case 'q':
            goto Restaurant;
            break;
        case 'E':
            goto Done;
            break;
        case 'e':
            goto Done;
            break;
        default:printf("\t\t\t\t\t\t\t\t    Invalid choice  ");
            goto SNACKS;
            break;
        }
        break;
    case 'P':
        goto Main_Menu;
        break;
    case 'p':
        goto Main_Menu;
        break;
    case 'e':
        goto Done;
        break;
    case 'E':
        goto Done;
        break;
    default:printf("Exit");
        break;
    }

    //Final summing
    Done:
    Final[i] = Resi[i]+Resta[i];                            /*Sums the elements                             */
    Bill += Final[i];
    condition:
    printf("\n\t\t\t\t\t\t\t\t Do you want to continue : [Y/N] ? : ");
    scanf(" %c",&choice);                                           /*Condition for the further execution or not    */
    if ((choice == 'Y') || (choice == 'y'))
    {
        i++;
        j = i+1; 
        goto Main_Menu;
    }
    else 
    {
        goto last;
    }

    last:
    //Array to print the bill                     /*This particular stores the information regarding the bill  */
    //  Final part  -   Displays the output       /*The bill will be printed                                   */
    //STORING DATA INTO THE REVENUE FILE
    fprintf(Revenue,"\n----------------------------------------------------------------------------------------------------");
    fprintf(Revenue,"\nDate:%d-%d-%d\nTime :%d:%d:%d",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year + 1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    fprintf(Revenue,"\n");
    fprintf(Revenue,"\n\t\t\t\t\t\t\t\t------------------------");
    fprintf(Revenue,"\n\t\t\t\t\t\t\t\t|S.no      Price       |");
    fprintf(Revenue,"\n\t\t\t\t\t\t\t\t|----------------------|\n");
    //Refreshing the screen before output
    system("clear");                                              
    printf("\n\t\t\t\t\t\t\t\t------------------------");
    printf("\n\t\t\t\t\t\t\t\t|S.no      Price       |");
    printf("\n\t\t\t\t\t\t\t\t|----------------------|\n");
    for (int i = 0; i < j; i++)
    {
        if (Resi[i] != 0)
        {
            printf("\t\t\t\t\t\t\t\t| %d.        %d\n",i+1,Resi[i]);
            fprintf(Revenue,"\t\t\t\t\t\t\t\t| %d.        %d\n",i+1,Resi[i]);
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t| %d.        %d\n",i+1,Resta[i]);
            fprintf(Revenue,"\t\t\t\t\t\t\t\t| %d.        %d\n",i+1,Resta[i]);
        }
    }   
    printf("\t\t\t\t\t\t\t\t|--------------------");  
    printf("\n\n\t\t\t\t\t\t\t\t| Total  :   %d\n\n",Bill); 
    printf("\t\t\t\t\t\t\t\t--------------------");

    //Entering the final statements into the file
    fprintf(Revenue,"\t\t\t\t\t\t\t\t|--------------------");  
    fprintf(Revenue,"\n\n\t\t\t\t\t\t\t\t| Total  :   %d\n\n",Bill);
    fprintf(Revenue,"\t\t\t\t\t\t\t\t--------------------");
    fprintf(Revenue,"\n----------------------------------------------------------------------------------------------------");
    exit(0);

    //Closing the files one by one in order.
    fclose(fp);
    fclose(Cus);
    fclose(Ro);
    fclose(Revenue);
}//End of the Driver code

void data_management()
{
    //Initializing files
    FILE *fp;       //To create a general file
    FILE *Revenue;  //To note down the revenue on daily basis
    FILE *Cus;      //To create a customer detail file
    FILE *Ro;       //To create a residency detail file

    //Security part
    Login:
    do
    {
        system("clear");
        if (kaunt !=0)
        {
            printf("Number of trails left : %d\n\n",(3-kaunt));
        }
        pf("\n\t\t\t\t\t\t\t\t---------------------------------------");
        pf("\n\t\t\t\t\t\t\t\t| L O G I N    T O    C O N T I N U E |");
        pf("\n\t\t\t\t\t\t\t\t|-------------------------------------|");
        pf("\n\t\t\t\t\t\t\t\t|     User id  : ");
        sf("%d",&usd);
        pf("\t\t\t\t\t\t\t\t|     Passcode : ");
        sf("%d",&psd);
        if ((usd == 13072022)&&(psd == 814))
        {
            count++;
            goto Data_Management;
        }
        else
            kaunt++;
        if(kaunt == 3)
        {
            printf("\nYou have entered Invalid credentials!\nExit");
            exit(1);
        }
    } while (count == 0);

    //Data Management part
    Data_Management:
    system("clear");
    pf("\n\t\t\t\t\t\t\t\t---------------------------------------------------------");
    pf("\n\t\t\t\t\t\t\t\t|       D  A  T  A  - M  A  N  A  G  E  M  E  N  T       |");
    pf("\n\t\t\t\t\t\t\t\t|--------------------------------------------------------|");
    pf("\n\t\t\t\t\t\t\t\t|                                                        |");
    pf("\n\t\t\t\t\t\t\t\t|1.  Genral data                                         |");
    pf("\n\t\t\t\t\t\t\t\t|2.  Custmer details                                     |");
    pf("\n\t\t\t\t\t\t\t\t|3.  Rooms data                                          |");
    pf("\n\t\t\t\t\t\t\t\t|4.  Financial data                                      |");
    pf("\n\t\t\t\t\t\t\t\t|                                                        |");
    pf("\n\t\t\t\t\t\t\t\t|>>       Any other key to exit                          |");
    pf("\n\t\t\t\t\t\t\t\t|                                                        |");
    pf("\n\t\t\t\t\t\t\t\t|--------------------------------------------------------|");
    pf("\n\t\t\t\t\t\t\t\t|       Enter  :     ");
    sf(" %c",&choice);
    system("clear");
    switch (choice)
    {
    case '1':
        fp = fopen("Hotel Data.txt","r");
        while (!feof(fp))
        {
            fgets(str,100,fp);
            printf(" %s",str);
        }
        fclose(fp);
        break;
    case '2':
        Cus = fopen("Custmer details.txt","r");
        while (!feof(Cus))
        {
            fgets(str,100,Cus);
            printf(" %s",str);
        }
        fclose(Cus);
        break;
    case '3':
        Ro = fopen("Room Details.txt","r");
        while (!feof(Ro))
        {
            fgets(str,100,Ro);
            printf(" %s",str);
        }
        fclose(Ro);
        break;
    case '4':
        Revenue = fopen("Hotel Revenue.txt","r");
        while (!feof(Revenue))
        {
            fgets(str,100,Revenue);
            printf(" %s",str);
        }
        fclose(Revenue);
        break;
    default:system("clear");
        printf("\n\t\t\t\t\t\t\t\t----------------------------------");
        printf("\n\t\t\t\t\t\t\t\t*****    E    X    I    T    *****");
        printf("\n\t\t\t\t\t\t\t\t----------------------------------");
        break;
    }
    printf("\nEnd of the file");
    //condition
    printf("\n\t\t\t\t\t\t\t\t Do you want to continue : [Y/N] ? : ");
    scanf(" %c",&choice);                                           /*Condition for the further execution or not    */
    if ((choice == 'Y') || (choice == 'y'))
    {
        goto Data_Management;
    }
    else 
    {
        exit(0);
    }
}//End of the data management function

/**                                                                     END: OF: THE: PROGRAM:                                                                       **/
/****************************************************************************** THE: END:******************************************************************************/