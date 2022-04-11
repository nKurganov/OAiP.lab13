#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <numeric>
#include <functional>

#include "time_class.h"

typedef std::set<Time> MyContainer;
typedef std::set<Time, std::greater<Time>> TempContainer;

void print(const MyContainer&, const std::string&);
void print(const TempContainer&, const std::string&);
void fill(MyContainer&);
void replace_max(MyContainer&);
void erase_min(MyContainer&);
TempContainer sort_descending(MyContainer&);
void find(MyContainer&);
TempContainer add_average(MyContainer&);

int main()
{
    MyContainer vec;
    
    fill(vec);
    print(vec, "Initial container: ");
    
    replace_max(vec);
    print(vec, "After replace max: ");
    
    erase_min(vec);
    print(vec, "After erase min: ");

	print(sort_descending(vec), "After sort by descending: ");

	find(vec);
    
	print(add_average(vec), "After add average: ");
    
	std::cin.ignore();
	std::cin.get();
	return 0;
}

void print(const MyContainer& c, const std::string& message)
{
    std::cout << message << "\n";
    std::copy(c.begin(), c.end(), std::ostream_iterator<Time>(std::cout, " "));
    std::cout << "\n\n";
}

void print(const TempContainer& c, const std::string& message)
{
	std::cout << message << "\n";
	std::copy(c.begin(), c.end(), std::ostream_iterator<Time>(std::cout, " "));
	std::cout << "\n\n";
}

void fill(MyContainer& c)
{
    std::cout << "Enter number of elements: ";
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element #" << i + 1 << ":\n";
        Time t;
        std::cin >> t;
        
        c.insert(t);
    }
}

void replace_max(MyContainer& c)
{
    std::cout << "Enter replacing element:\n";
    Time t;
    std::cin >> t;
    
    MyContainer::iterator max = std::max_element(c.begin(), c.end());
    std::cout << "Max element: " << *max << "\n";

	c.erase(max);
	c.insert(t);
}

void erase_min(MyContainer& c)
{
    MyContainer::iterator min = std::min_element(c.begin(), c.end());
    std::cout << "Min element: " << *min << "\n";
    c.erase(min);
}

TempContainer sort_descending(MyContainer& c)
{
	TempContainer temp;
	std::copy(c.begin(), c.end(), std::inserter(temp, temp.begin()));
	return temp;
}

void find(MyContainer& c)
{
	Time t;
	std::cout << "Enter value to find:\n";
	std::cin >> t;
	if (std::find(c.begin(), c.end(), t) != c.end())
		std::cout << "Element found!\n\n";
	else
		std::cout << "Element NOT found!\n\n";
}

TempContainer add_average(MyContainer& c)
{
    Time avg = std::accumulate(c.begin(), c.end(), Time()) / c.size();
    std::cout << "Average: " << avg << "\n";

	TempContainer temp;
    std::transform(c.begin(), c.end(), std::inserter(temp, temp.begin()),
        [avg](const Time& t) { return t + avg; });
	return temp;
}
