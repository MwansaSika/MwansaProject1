
#include <iostream>
#include <iomanip>
using namespace std;

//Define constant variables
const char starSymbol = '*';
const char hashSymbol = '#';
const int numOfRows = 15;
const int numOfcolumns = 30;


//Declare variables
int totalAmount = 0;
int totalSeats = 450;
int conformSeat = 0;
int q = 1;
char ticket[numOfRows][numOfcolumns];
double cost;

//Function prototypes
int displayMenu();
void displayChart();

//main method
int main()
{
	//Declare variables
	int x, y, rate;
	int res;
	const int num = 15;
	int cost[num];

	//Prompt and read input from the user
	cout << "\tSeating capacity 15 rows, with 30 seats in each row." << endl;

	for (int i = 0; i < numOfRows; i++)
	{
		cout << "Enter the cost for row " << (i + 1) << ": ";
		cin >> cost[i];

	}
	for (int j = 0; j < numOfRows; j++)
	{
		for (int k = 0; k < numOfcolumns; k++)
			ticket[j][k] = hashSymbol;
	}
	int choice;
	do
	{
		choice = displayMenu();
		switch (choice)
		{
		case 1:
			cout << "View Seat Prices\n\n";

			for (int count = 0; count < numOfRows; count++)
			{
				cout << "The price for row " << (count + 1) << ": ";
				cout << cost[count] << endl;
			}
			break;
		case 2:
			do
			{
				cout << "Select the row: ";
				cin >> x;
				cout << "Select the seat: ";
				cin >> y;
				if (ticket[x][y] == '*')
				{
					cout << "Sorry that seat is sold-out, select an another seat.";
					cout << endl;
				}
				else
				{
					rate = cost[x] + 0;
					totalAmount = totalAmount + rate;
					cout << "Ticket cost: " << rate << endl;
					cout << "Book the Ticket(1 = YES / 2 = NO)):";
					cin >> res;
					totalSeats = totalSeats - res;
					conformSeat += res;

					if (res == 1)
					{
						cout << "Your ticket purchase has been confirmed." << endl;
						ticket[x][y] = starSymbol;
					}
					else if (res == 2)
					{
						cout << "Would you continue for another seat? (YES=1 / NO=2)";
						cout << endl;
						cin >> q;
					}

					cout << "Would you continue for another seat? (YES=1 / NO=2)";
					cin >> q;
				}
			} while (q == 1);

			break;
		case 3:
			cout << "Available Seats displays # symobl, filled seats displays * symbol\n\n";
			displayChart();
			break;
		case 4:
			cout << "Exit\n";
			break;
		default: cout << "Error input\n";
		}
	} while (choice != 5);
	return 0;
}
//Method definition of displayMenu
int displayMenu()
{
	int MenuChoice;
	cout << endl << endl;
	cout << " \t.......CHOICES.........\n";
	cout << " 1. Cost for seats.\n";
	cout << " 2. Buy a Ticket.\n";
	cout << " 3. Display Available Seats.\n";
	cout << " 4. Exit.\n";
	cout << "_____________________\n\n";
	cout << "Enter choice: ";
	cin >> MenuChoice;
	cout << endl << endl;
	return MenuChoice;
}

//Method definition of displayChart
void displayChart()
{
	cout << "\tSeats" << endl;
	cout << endl << "   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n";
	for (int i = 0; i <15; i++)
	{
		cout << endl << "Row " << (i + 1);
		for (int j = 0; j <30; j++)
		{
			cout << " " << ticket[i][j];
		}
	}
	cout << endl;
}

