# 力扣第1344题，时钟指针的夹角
"""
给你两个数 hour 和 minutes 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。
"""

class Solution_00:
    def angleClock(self, hour, minutes):
        angle_per_hour = 30
        angle_per_minutes = 6

        minutes_angle = minutes * angle_per_minutes
        hour_angle = hour * angle_per_hour + minutes / 60 * 30
        
        angle = abs(hour_angle - minutes_angle)
        return min(angle, 360-angle)


if __name__ == '__main__':
    hour = 3
    minutes = 30

    s00 = Solution_00()
    angle = s00.angleClock(3, 30)
    print(angle)