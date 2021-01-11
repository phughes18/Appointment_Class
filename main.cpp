#include <iostream>
#include <string>
#include "appointment.h"


using namespace std;

int main()
{

    do
    {
    	Appointment date;
    	string command;

        cout << "Choose to (Display, Add, Search, Delete, Quit) for the Appointment schedule: ";
        cin >> command;

        if (command == "Display")
        {
            cout << "These are all the appoinments:";

            for (int i = 0; i < info.getLength(); i++)
                cout << info[i];
        }

        else if (command == "Add")
        {
        	date.input_appt();
        	bool val1 = false
        	
        	if (GetItem(date, val1))
        	{
        		PutItem(date);
        		cout << "Appointment has been added to the schedule."
        	}

        	else
        	{
        		cout << "We already have an appointment scheduled for that date.";
        	}

        }

        else if (command == "Search")
        {
        	bool val2 = false;
        	date.input_appt();

        	if (GetItem(date, val2))
        		cout << "We have confirmed an appointment for that date.";
        	else
        		cout << "There is no appointment scheduled then.";

        }

        else if (command == "Delete")
        {
        	date.input_appt();
        	DeleteItem(date);

        	cout << "The appointment has been deleted.";
        }

        else if (command == "Quit")
            exit(0);

        else
            cout << "Invalid operation please try again" << endl;

    } while (command != "Quit");

    cout << "Thank you!";

	return 0;
}