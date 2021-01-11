#include "appointment.h"
#include <iostream>
#include <string>

using namespace std;

Appointment::Appointment()
{
	day = 0;
	month = 0;
	year = 0;
	string = " ";
}

void Appointment::input_appt()
{

	word = "Enter the date for the appointment (dd mm yyyy): "
	cin >> day >> month >> year;

}

void Appointment::output_appt()
{
	string = " ";
	cout << day << " " << month << " " << year;
}


bool Appointment::compare_key(num1, num2)
{
	if (info[num1] == info[num2])
		return true;

	return false;
}
