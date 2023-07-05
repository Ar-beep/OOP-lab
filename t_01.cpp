#include <iostream>

class Time
{
    int hour, minute, second;

public:
    Time() : hour{0}, minute{0}, second{0} {};
    Time(int h, int m, int s) : hour{h}, minute{m}, second{s} {};
    Time operator+(Time t1)
    {
        int min{0}, hr{0};
        int t_sec = t1.second + second;
        if (t_sec >= 60)
        {
            min = t_sec / 60;
            t_sec = ((static_cast<float>(t_sec) / 60) - min) * 60;
        }
        int t_min = t1.minute + minute + min;
        if (t_min >= 60)
        {
            hr = (t_min) / 60;
            t_min = ((static_cast<float>(t_min) / 60) - min) * 60;
        }
        int t_hour = t1.hour + hour + hr;
        return (Time(t_hour, t_min, t_sec));
    }

    void getter()
    {
        std::cout << ((hour < 10) ? "0" : "") << hour << ":"
                  << ((minute < 10) ? "0" : "") << minute << ":"
                  << ((second < 10) ? "0" : "") << second << std::endl;
    }
    void show_12hr()
    {
        std::string meridem = "a.m";
        if (hour > 12)
        {
            meridem = "p.m";
            std::cout << "Time in 12 hr format \n"
                      << ((hour -12 < 10) ? "0" : "") << hour -12  << ":"
                      << ((minute < 10) ? "0" : "") << minute << ":"
                      << ((second < 10) ? "0" : "") << second <<" "<< meridem << std::endl;
                      return;
        }
        std::cout << "Time in 12 hr format \n"
                      << ((hour -12 < 10) ? "0" : "") << hour -12  << ":"
                      << ((minute < 10) ? "0" : "") << minute << ":"
                      << ((second < 10) ? "0" : "") << second <<" "<< meridem << std::endl;
                      return;
    }
};
int main(int argc, char *argv[])
{
    Time t1(9, 21, 46), t2(3, 45, 19), t3;
    t3 = t1 + t2;
    t3.getter();
    t3.show_12hr();
    return 0;
};