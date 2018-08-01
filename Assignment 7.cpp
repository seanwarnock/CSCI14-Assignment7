/*

Sean Warnock
CSCI 14 Summer 2018
Assignment 7 due 8/1/2018
https://github.com/seanwarnock/CSCI14-Assignment7.git



1.	Ask the user to enter a minimum number of passengers (i.e. 1, 30, 50, 150, 255)
2.	Ask the user to enter a maximum number of passengers. The Coast Guard has rated this dinner cruise ship at no more than 500 passengers excluding crew. Minimum has to be at least one passenger (i.e. 1 to 500)
3.	Ask the user to enter the fixed cost for the cruise (i.e. $2,000, $2,500, $3,550, etc.)
4.	Ask the user to enter a discount per ticket per every group of 10 passengers (i.e. 0.10, 0.25, 0.50, etc.)
5.	Check that the minimum number of passengers is not greater than the user’s maximum passengers.
6.	Check that the maximum is not more than the ship’s maximum carrying capacity for passengers (same for the minimum)
7.	Determine the maximum PROFIT, the number of passengers needed to generate that profit, and the ticket price that will generate that profit.
8.	User can execute this any number of times. Logic should ask user if they wish to quit or continue running this application. You will be using some sort of loop to repeat the application possibly multiple times.
*/

//#include <math.h>
//#include <regex>
//#include <time.h>
#include <iostream>
#include <string>
#include <iomanip>
#ifdef _WIN32
  #include <windows.h>
#endif
#ifdef __linux__

#endif

#define ASSIGNMENT "CSCI 14 Assignment 7"


using namespace std;

//Structures
class TheShip
{
private :
  const int MinimumPassengers = 0;
  const int MaximumPassengers = 500;
  const string ShipName = "S.S. Rusty T. Buckette"; //"S.S. William F. Warnock";


  int intMinimumPassengers = MinimumPassengers;
  int intMaximumPassengers = MaximumPassengers;
  double doubleRunningCost = 0;
  double doubleTicketPrice = 0;
  double doubleTicketDiscount = 0;

public :
  void PassengerMinEnter()
  {
    int IncomingPassengers = intMinimumPassengers;

    do
      {
        system("cls");
        cout << "The current minimum number of potential passengers is : " << intMinimumPassengers << endl;
        cout << "Please enter the minimum number of potential passengers : ";
        cin >> IncomingPassengers;
      }while ((IncomingPassengers < MinimumPassengers) || (IncomingPassengers > MaximumPassengers) || (IncomingPassengers >= intMaximumPassengers));
      intMinimumPassengers = IncomingPassengers;
  }

  void PassengerMaxEnter()
  {
    int IncomingPassengers = intMaximumPassengers;

    do
      {
        system("cls");
        cout << "The current maximum number of potential passengers is : " << intMaximumPassengers << endl;
        cout << "Please enter the maximum number of potential passengers : ";
        cin >> IncomingPassengers;
      }while ((IncomingPassengers < MinimumPassengers) || (IncomingPassengers > MaximumPassengers) || (IncomingPassengers <= intMinimumPassengers));
      intMaximumPassengers = IncomingPassengers;
  }

  void Print()
  {
    cout.unsetf(ios::floatfield);
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);

    system("cls");
    cout << ShipName << endl;
    cout << setw(40) << left << "Current minimum passengers : " << intMinimumPassengers << endl;
    cout << setw(40) << "Current maximum passengers : " << intMaximumPassengers << endl;
    cout << setw(40) << "Current running cost of the ship : " << "$" << doubleRunningCost << endl;
    cout << setw(40) << "Current ticket price : " << "$" << doubleTicketPrice << endl;
    cout << setw(40) << "Current ticket discount : " << "$" << doubleTicketDiscount << endl;
    //system
  }

  string PrintShipName()
  {
    return ShipName;
  }

  void RunningCostEnter()
  {
    double doublelocalRunningCost;

    do
    {
      system("cls");
      cout << "The current running cost for the " << ShipName << " is " << doubleRunningCost << endl;
      cout << "Please enter a new running cost : ";
      cin >> doublelocalRunningCost;
    }while (doublelocalRunningCost < 0);
    doubleRunningCost = doublelocalRunningCost;
  }

  void TicketPriceEnter()
  {
    double doublelocalTicketPrice;

    do
    {
      system("cls");
      cout << "The current ticket price for the " << ShipName << " is " << doubleTicketPrice << endl;
      cout << "Please enter a new ticket price : ";
      cin >> doublelocalTicketPrice;
    }while (doublelocalTicketPrice < 0);
    doubleTicketPrice = doublelocalTicketPrice;
  }

  void TicketDiscountEnter()
  {
    double doublelocalTicketDiscount;

    do
    {
      system("cls");
      cout << "The current ticket discount rate is : " << doubleTicketDiscount << endl;
      cout << "Please enter a new ticket discount amount : ";
      cin >> doublelocalTicketDiscount;
    }while (doublelocalTicketDiscount < 0);
    doubleTicketDiscount = doublelocalTicketDiscount;
  }


  void CalcProfit()
 {
/*
NP is the Number of Passengers
TP is the Proposed Ticket Price
MP is the Minimum Number of Passengers

Cost of Ticket = TP - (((NP - MP) /10) * discount per very 10 passengers)
Profit = (NP * Cost of Ticket) � fixed cost
*/
    //Variables
    int n;
    int PassengerIncrement = 10;
    double doubleIncrementalTicketPrice;
    double doubleIncrementalProfitLow;
    double doubleBestTicketPrice = 0;
    double doubleBestProfit = 0;
    int intBestPassengerCount = 0;
//    int intRemainingPassengers;


    system("cls");
    for (n=intMinimumPassengers;n<=intMaximumPassengers;n+=PassengerIncrement)
    {
      doubleIncrementalTicketPrice = doubleTicketPrice - ((n - intMinimumPassengers) / PassengerIncrement) * doubleTicketDiscount;
      doubleIncrementalProfitLow = (doubleIncrementalTicketPrice * n) - doubleRunningCost;
      cout << "Ticket Price $" << doubleIncrementalTicketPrice << " ";
      cout << "between " << n << " passengers to ";

      if ((n+9) > intMaximumPassengers)
      {
        cout << intMaximumPassengers << " passengers. ";
      }
      else
      {
        cout <<  (n + 9) << " passengers. ";
      }
      cout << "Profit $" << doubleIncrementalProfitLow << endl;

      if (doubleIncrementalProfitLow > doubleBestProfit)
      {
        doubleBestProfit = doubleIncrementalProfitLow;
        doubleBestTicketPrice = doubleIncrementalTicketPrice;
        intBestPassengerCount = n;
      }
    }

    if (doubleBestProfit == 0)
    {
      cout << "This voyage is never profitable, do not leave port." << endl;
    }
    else
    {
      cout << endl;
      cout << "Best profit achieved is: $" << doubleBestProfit << " with between " << intBestPassengerCount << " to ";

      if ((intBestPassengerCount + 9) > intMaximumPassengers)
      {
        cout  << intMaximumPassengers << " passengers," << endl;
      }
      else
      {
        cout  << intBestPassengerCount + 9 << " passengers," << endl;
      }

      cout << "with a ticket price of: $" << doubleBestTicketPrice << endl;
      //cout << "and at " << intBestPassengerCount << " passengers."<< endl;
    }
    system("pause");
  }
};

//Functions
void ConsoleConfig()
{
//This just sets some basic parameters for the console display.

  SetConsoleTitle(ASSIGNMENT);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY );
}

void MenuPrint(TheShip localRustyBucket)
{

  char charlocalMenuChoice;

  do
  {
    system("cls");

    localRustyBucket.Print();
    cout << endl;
    cout << "[1] Enter the minimum number of passengers." << endl;
    cout << "[2] Enter the maximum number of passengers."  << endl;
    cout << "[3] Enter the cost to run the ship." << endl;
    cout << "[4] Enter the ticket price." << endl;
    cout << "[5] Enter Ticket discount amount." << endl;
    cout << "[6] Calculate ticket breakdown." << endl;
    cout << "[9] Send the " << localRustyBucket.PrintShipName() << " to the breakers (exit program)." << endl;

    cin >> charlocalMenuChoice;

    switch (charlocalMenuChoice)
    {
    case '1' :
      cout << "Choice 1";
      localRustyBucket.PassengerMinEnter();
      break;
    case '2' :
      cout << "Choice 2";
      localRustyBucket.PassengerMaxEnter();
      break;
    case '3' :
      cout << "Choice 3";
      localRustyBucket.RunningCostEnter();
      break;
    case '4' :
      cout << "Choice 4";
      localRustyBucket.TicketPriceEnter();
      break;
    case '5' :
      cout << "Choice 5";
      localRustyBucket.TicketDiscountEnter();
      break;
    case '6' :
      cout << "Choice 6";
      localRustyBucket.CalcProfit();
      break;
    case '9' :
      cout << "Welcome to Rosyth Scotland" << endl;
      system("pause");
      break;
    }
  }while (charlocalMenuChoice != '9');


}

int main()
{

//Variables
  TheShip RustyBucket;


  ConsoleConfig();

  MenuPrint(RustyBucket);

}
