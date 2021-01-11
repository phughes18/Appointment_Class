#include <iostream>

using namespace std;

const int MAX_ITEMS = 30;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
	public:

	ItemType() {value = 0};

	RelationType ItemType::ComparedTo(ItemType other) const 
	{
  		if (value < other.value)
    		return LESS;
  		
  		else if (value > other.value)
    		return GREATER;
  		
  		else 
  			return EQUAL;
	}

	void ItemType::initialize(int num) const
	{
		value = num;
	}

	void ItemType::print() const
	{
		cout << value << endl;
	}



	private:
	int value;

};