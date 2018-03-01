#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) 
{
	double area;
	cout << "Enter the floor area, in square feet, of your home: ";
	cout << endl;
	cin >> area;
	double side;
	side=sqrt(area);
	cout << "That's the equivalent of a square " << side
		 << " feet to the side." << endl;
	cout << "How fascinating!" << endl;
	return 0;
}