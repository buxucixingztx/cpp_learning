// 力扣第1344题，时钟指针的夹角
/*
给你两个数 hour 和 minutes 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。
*/
#include <iostream>
using namespace std;

class Solution_00{
public:
    double angleClock(int hour, int minutes){
        double angle_per_hour = 30.0;
        double angle_per_minutes = 6.0;

        double minutes_angle = minutes * angle_per_minutes;
        double hour_angle = (hour % 12) * angle_per_hour + minutes / 60.0 * 30.0;
        cout << "minutes_angle: " << minutes_angle << ";  hour_angle: " << hour_angle << endl;

        double angle = (minutes_angle > hour_angle) ? (minutes_angle - hour_angle) : (hour_angle - minutes_angle);
        // double angle;
        // if (minutes_angle > hour_angle)
        //     angle = minutes_angle - hour_angle;
        // else
        //     angle = hour_angle - minutes_angle;

        cout << "in Solution_00 angle: " << angle << endl;
        angle = (angle < 360 - angle) ? angle : (360 - angle);
        return angle;
    }
};


int main()
{
    Solution_00 s00;
    int hour = 3;
    int minutes = 30;
    double angle = s00.angleClock(hour, minutes);

    cout << "angle: " << angle << endl;
    cin.get();

    return 0;
}