#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

#include "time_class.h"

typedef std::vector<Time> MyContainer;

void print(const MyContainer&, const std::string&);
void fill(MyContainer&);
void replace_max(MyContainer&);
void erase_min(MyContainer&);
void sort_ascending(MyContainer&);
void sort_descending(MyContainer&);
void find(MyContainer&);
void add_average(MyContainer&);

int main()
{
    MyContainer vec;
    
    fill(vec);
    print(vec, "Initial container: ");
    
    replace_max(vec);
    print(vec, "After replace max: ");
    
    erase_min(vec);
    print(vec, "After erase min: ");

	sort_ascending(vec);
	print(vec, "After sort by ascending: ");

	sort_descending(vec);
	print(vec, "After sort by descending: ");

	find(vec);
    
    add_average(vec);
    print(vec, "After add average: ");
    
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
        
        c.push_back(t);
    }
}

void replace_max(MyContainer& c)
{
    std::cout << "Enter replacing element:\n";
    Time t;
    std::cin >> t;
    
    MyContainer::iterator max = std::max_element(c.begin(), c.end());
    std::cout << "Max element: " << *max << "\n";
	std::replace(c.begin(), c.end(), *max, t);
}

void erase_min(MyContainer& c)
{
    MyContainer::iterator min = std::min_element(c.begin(), c.end());
    std::cout << "Min element: " << *min << "\n";
    c.erase(std::remove(c.begin(), c.end(), *min), c.end());
}

void sort_ascending(MyContainer& c)
{
	std::sort(c.begin(), c.end());
}

void sort_descending(MyContainer& c)
{
	std::sort(c.begin(), c.end(), std::greater<Time>());
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

void add_average(MyContainer& c)
{
    Time avg = std::accumulate(c.begin(), c.end(), Time()) / c.size();
    std::cout << "Average: " << avg << "\n";
    std::transform(c.begin(), c.end(), c.begin(),
        [avg](const Time& t) { return t + avg; });
}
