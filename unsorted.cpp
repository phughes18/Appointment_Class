// Implementation file for Unsorted.h

#include "unsorted.h"
#include <iostream>

using namespace std;

typedef Appointment ItemType;


UnsortedType::UnsortedType()
{
  currentPos = 0;
  length = 0;
  capacity = 10;
  info = new ItemType[capacity];
}


UnsortedType::UnsortedType(int size_arr)
{
  currentPos = 0;
  length = 0;
  capacity = size_arr;
  info = new ItemType[capacity];
}


UnsortedType::~UnsortedType()
{
  delete [] info;
}

void operator[](int num)
{
  if (num >= capacity)
  {
    cout << "Array index is out of bounds, exiting.";
    exit(0);
  }

  return info[num];
}


bool UnsortedType::IsFull()
{
  if (length > capacity || length > MAX_ITEMS)
  {
    return true;
  }

  return false;
}


int UnsortedType::GetLength() const
{
  return length;
}


ItemType UnsortedType::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : location--;
                     moreToSearch = (location > length);
                     break; 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
  return item;
}


void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}


void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
  if (length >= capacity)
  {
    capacity = capacity * 2;
    ItemType* grown_info = new ItemType[capacity];

    for (int i = 0; i < length; i++)
      grown_info[i] = info[i];

    grown_info[length] = item;
    length++;

    delete [] info;
    info = grown_info;
  }

  else
  {
    info[length] = item;
    length++;
  }

}


void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}


void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}


ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}





