#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Creating the Car class
class Car {
  public:
    string brand;
    string model;
    int year;
    float price;
    string vin;
    string color;
    bool seats;
    void insertdata(void);
    void display(void);

};

// Function to enter car data from user input
void Car::insertdata()
{
	string temp;

	cout << "\n Enter brand of car \n";
	cin >> brand;
	cout << "\n Enter model of car \n";
	cin >> model;
	cout << "\n Enter year of car \n";
	cin >> year;
	cout << "\n Enter price of car \n";
	cin >> price;
	cout << "\n Enter vin \n";
	cin >> vin;
	cout << "\n Enter color of car \n";
	cin >> color;
	cout << "\n Does the car have leather seats?(y/n) ";
	cin >> temp;

	if (temp == "y")
	{
		seats = true;
	}
	else {
		seats = false;
	}

}

int main() {

	int selection;
	vector<Car> carlot;
	Car* carpointer;
	bool done = false;

// loop to allow user to choose an action to perform
	while (done == false) {
		cout << "\nWhat would you like to do? \nEnter 1 to add a car to inventory\nEnter 2 show inventory\nEnter 3 to remove a car from inventory\n Enter 4 to exit";
		cin >> selection;

		switch (selection){

		//Add a new car to inventory
		case 1:
			carpointer = new Car;
			carpointer->insertdata();
			carlot.push_back(*carpointer);
			break;

		//display inventory
		case 2:
			int j;
			for (j=0; j<carlot.size(); j++){
				cout<<"\n Car #"<<j+1;
				carlot[j].display();
			}
			break;

		//delete a car from inventory
		case 3:
			int k;
			cout << "\n Which car would you like to remove?";
			cin >> k;
			carlot.erase(carlot.begin()+k-1);
			break;

		//exit the program
		case 4:
			done = true;
			break;

		//if any other input from user, ask again
		default:
			cout << "\n Incorrect selection, please make another selection ";

		}
	}
  return 0;
}
