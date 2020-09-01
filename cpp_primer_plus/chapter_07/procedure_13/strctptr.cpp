// strctptr.cpp -- fimctopms with pointer to structure argument
#include <iostream>
#include <cmath>

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};


void rect_to_polar(rect *, polar *);
void show_polar(polar*);

int main()
{
    using namespace std;
    polar pplace;
    rect rplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): ";
    }
    
    cout << "Done.\n";
    return 0;
}

void show_polar(polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << pda->distance << ", angle = ";
    cout << pda->angle * Rad_to_deg << " degrees\n";
}


void rect_to_polar(rect * rxy, polar * pda)
{
    using namespace std;

    pda->distance = sqrt(rxy->x * rxy->x + rxy->y * rxy->y);
    pda->angle = atan2(rxy->y, rxy->x);
}