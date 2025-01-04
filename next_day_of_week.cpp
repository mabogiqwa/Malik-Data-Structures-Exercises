//Created: 29-11-2023
//Author: Mabo Giqwa
//Purpose: Implements the day of the week
#include <iostream>

const int MAX_SIZE = 7;

class dayType
{
public:
    void set_day(std::string);
    void print_day() const;
    std::string get_day() const;
    void retrieve_next_day();
    void retrieve_previous_day();
    dayType();
    dayType(std::string);
private:
    std::string day;
    std::string daysOfTheWeek[MAX_SIZE] = {"Mon","Tue","Wed","Thur","Fri","Sat","Sun"};
};

dayType::dayType()
{
    day = "";
}

dayType::dayType(std::string d)
{
    int sentinel = 0;
    int iter = 0;
    bool isFound = false;

    while (sentinel != -1)
    {
        if (daysOfTheWeek[iter] == d)
        {
            day = d;
            isFound = true;
            sentinel = -1;
        }
        if (iter > 6) {
            day = "";
            sentinel = -1;
        }
        iter = iter + 1;
    }

    if (!isFound)
        day = "Nothing here mate";
}

void dayType::set_day(std::string d)
{
    int sentinel = 0;
    int iter = 0;
    bool isFound = false;

    while (sentinel != -1)
    {
        if (daysOfTheWeek[iter] == d)
        {
            day = d;
            sentinel = -1;
            isFound = true;
        }
        if (iter > 6)
            sentinel = -1;
        iter = iter + 1;
    }

    if (!isFound)
        day = "Nothing here mate";
}

void dayType::print_day() const
{
    std::cout << "The day is: " << day << std::endl;
}

std::string dayType::get_day() const
{
    return day;
}

void dayType::retrieve_next_day()
{
    int index;
    std::string next_day;
    bool isFound = false;

    index = 0;
    int sentinel = 0;
    while(sentinel != -1)
    {
        if (daysOfTheWeek[index] == day)
        {

            if (index == 6)
            {
                index = 0;
                next_day = daysOfTheWeek[index];
                isFound = true;
                day = next_day;
                sentinel = -1;
            } else {
                next_day = daysOfTheWeek[index + 1];
                isFound = true;
                day = next_day;
                sentinel = -1;
            }
        }
        if (index > 6)
            sentinel = -1;
        index = index + 1;
    }

    if(!isFound)
        day = "Nothing here mate";
}

void dayType::retrieve_previous_day()
{
    int index, sentinel;
    std::string previous_day;
    bool isFound = false;

    sentinel = 0;
    index = 0;
    while (sentinel != -1)
    {
        if (daysOfTheWeek[index] == day)
        {
            if (index == 0)
            {
                index = 6;
                previous_day = daysOfTheWeek[index];
                day = previous_day;
                isFound = true;
                sentinel = -1;
            } else {
                previous_day = daysOfTheWeek[index - 1];
                day = previous_day;
                isFound = true;
                sentinel = -1;
            }

        }
        if (index > 6)
            sentinel = -1;
        index = index + 1;
    }
    if(!isFound)
        day = "Nothing here mate";
}

int main()
{
    dayType someDay("Sun");
    someDay.retrieve_previous_day();
    someDay.print_day();

    return 0;
}
