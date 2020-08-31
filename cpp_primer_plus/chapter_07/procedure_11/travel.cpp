// travel.cpp -- using structures with functions
#include <iostream>

const int Min_per_hr = 60;
struct travel_time
{
    int hours;
    int mins;
};

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
    using namespace std;
    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = {4, 32};
    travel_time total = sum(trip, day3);
    cout << "Three-day: ";
    show_time(total);

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Min_per_hr;
    total.hours = (t1.hours + t2.hours) + (t1.mins + t2.mins) / Min_per_hr;

    return total;
}

void show_time(travel_time t)
{
    using namespace std;
    cout << t.hours << " hours, " << t.mins << " minutes\n";
}