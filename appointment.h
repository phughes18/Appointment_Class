#include <iostream>
#include <string>
#include "unsorted.h"

typedef Appointment ItemType;

using namespace std;

class UnsortedType : public Appointment
{
	public:
		Appointment();
		void input_appt();
		void output_appt();
		bool compare_key(num1, num2);

	private:
		int day, month, year;

};