#include <iostream>
#include <iomanip>
#include <fstream>

#include "time_class.h"

Time::Time() : minutes(0), seconds(0) {}
Time::Time(int m, int s) : minutes(m + s / 60), seconds(s % 60) {}
Time::Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}

Time Time::operator=(const Time& t)
{
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

Time& Time::operator+=(const Time& t)
{
	*this = Time(minutes + t.minutes, seconds + t.seconds);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
    return out << std::setfill('0') << std::setw(2) << t.minutes << ":"
        << std::setw(2) << t.seconds << std::setfill(' ');
}

std::istream& operator>>(std::istream& in, Time & t)
{
    int m, s;
    std::cout << "\tMinutes: "; in >> m;
    std::cout << "\tSeconds: "; in >> s;
    t = Time(m, s);
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const Time& t)
{
	out << t.minutes << " " << t.seconds << "\n";
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Time& t)
{
	in >> t.minutes >> t.seconds;
	return in;
}

bool operator==(const Time& t1, const Time& t2)
{
    return (t1.minutes == t2.minutes) && (t1.seconds == t2.seconds);
}

bool operator!=(const Time& t1, const Time& t2)
{
    return !(t1 == t2);
}

bool operator<(const Time& t1, const Time& t2)
{
    return (t1.minutes < t2.minutes) ||
        ((t1.minutes == t2.minutes) && (t1.seconds < t2.seconds));
}

bool operator>(const Time& t1, const Time& t2)
{
    return !(t1 < t2) && (t1 != t2);
}

Time operator+(const Time& t1, const Time& t2)
{
    return Time(t1.minutes + t2.minutes, t1.seconds + t2.seconds);
}

Time operator/(const Time& t, int x)
{
    int secs = (t.minutes * 60 + t.seconds) / x;
    return Time(0, secs);
}