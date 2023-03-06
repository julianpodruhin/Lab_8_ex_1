#include <iostream>

class Time {
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) {
        hours = h + (m + s / 60) / 60;
        hours %= 24;
        minutes = (m + s / 60) % 60;
        seconds = s % 60;
    }
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void display() const {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
    Time operator+(const Time& other) const {
        int totalSeconds = toSeconds() + other.toSeconds();
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }
private:
    int hours;
    int minutes;
    int seconds;
};

int main() {
    int h, m, s;
    std::cout << "Enter time in hours, minutes and seconds: ";
    std::cin >> h >> m >> s;
    Time t1(h, m, s);

    std::cout << "Enter another time in hours, minutes and seconds: ";
    std::cin >> h >> m >> s;
    Time t2(h, m, s);

    Time t3 = t1 + t2;
    std::cout << "The sum of times is: ";
    t3.display();

    std::cout << "Enter time with invalid values (hours > 24 or minutes/seconds > 60): ";
    std::cin >> h >> m >> s;
    Time t4(h, m, s);
    std::cout << "The time with valid values is: ";
    t4.display();

    return 0;
}