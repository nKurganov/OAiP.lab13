#ifndef TIME_CLASS_H
#define TIME_CLASS_H

#include <iosfwd>

class Time
{
    friend std::ostream& operator<<(std::ostream&, const Time&);
    friend std::istream& operator>>(std::istream&, Time&);
	friend std::ofstream& operator<<(std::ofstream&, const Time&);
	friend std::ifstream& operator>>(std::ifstream&, Time&);
    
    friend bool operator==(const Time&, const Time&);
    friend bool operator!=(const Time&, const Time&);
    friend bool operator<(const Time&, const Time&);
    friend bool operator>(const Time&, const Time&);
    
    friend Time operator+(const Time&, const Time&);
    friend Time operator/(const Time&, int);
    
public:
    Time();
    Time(int, int);
    Time(const Time&);
    Time operator=(const Time&);

	Time& operator+=(const Time&);
    
private:
    int minutes, seconds;
};

#endif