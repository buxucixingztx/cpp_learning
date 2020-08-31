//strctfun.cpp -- functions with a structure argument
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

polar rect_to_polar(rect);
void show_polar(polar);

int main()
{
    using namespace std;
    rect rplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        polar pplace;
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two number (q to quit): ";
    }

    cout << "Done.\n";
    return 0; 
}

polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    const double Rad_to_deg = 57.29577951;

    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x) * Rad_to_deg;

    return answer;
}

void show_polar(polar dapos)
{
    using namespace std;

    cout << "distance = " << dapos.distance << ", angle = " << dapos.angle << " degrees\n";
}

