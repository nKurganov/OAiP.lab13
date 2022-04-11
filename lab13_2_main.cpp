#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

#include "time_class.h"

typedef std::stack<Time> MyContainer;
typedef std::vector<Time> TempContainer;

void stack_to_vector(MyContainer&, TempContainer&);
void vector_to_stack(TempContainer&, MyContainer&);

void print(MyContainer&, const std::string&);
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

void stack_to_vector(MyContainer& c, TempContainer& v)
{
	while (!c.empty()) {
		v.push_back(c.top());
		c.pop();
	}
}

void vector_to_stack(TempContainer& v, MyContainer& c)
{
	for (TempContainer::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
		c.push(*it);
}

void print(MyContainer& c, const std::string& message)
{
	TempContainer temp;
	stack_to_vector(c, temp);

    std::cout << message << "\n";
    std::copy(temp.begin(), temp.end(), std::ostream_iterator<Time>(std::cout, " "));
    std::cout << "\n\n";

	vector_to_stack(temp, c);
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
        
        c.push(t);
    }
}

void replace_max(MyContainer& c)
{
    std::cout << "Enter replacing element:\n";
    Time t;
    std::cin >> t;

	TempContainer temp;
	stack_to_vector(c, temp);
    
    TempContainer::iterator max = std::max_element(temp.begin(), temp.end());
    std::cout << "Max element: " << *max << "\n";
	std::replace(temp.begin(), temp.end(), *max, t);

	vector_to_stack(temp, c);
}

void erase_min(MyContainer& c)
{
	TempContainer temp;
	stack_to_vector(c, temp);

    TempContainer::iterator min = std::min_element(temp.begin(), temp.end());
    std::cout << "Min element: " << *min << "\n";
    temp.erase(std::remove(temp.begin(), temp.end(), *min), temp.end());

	vector_to_stack(temp, c);
}

void sort_ascending(MyContainer& c)
{
	TempContainer temp;
	stack_to_vector(c, temp);
	std::sort(temp.begin(), temp.end());
	vector_to_stack(temp, c);
}

void sort_descending(MyContainer& c)
{
	TempContainer temp;
	stack_to_vector(c, temp);
	std::sort(temp.begin(), temp.end(), std::greater<Time>());
	vector_to_stack(temp, c);
}

void find(MyContainer& c)
{
	TempContainer temp;
	stack_to_vector(c, temp);

	Time t;
	std::cout << "Enter value to find:\n";
	std::cin >> t;
	if (std::find(temp.begin(), temp.end(), t) != temp.end())
		std::cout << "Element found!\n\n";
	else
		std::cout << "Element NOT found!\n\n";

	vector_to_stack(temp, c);
}

void add_average(MyContainer& c)
{
	TempContainer temp;
	stack_to_vector(c, temp);
	
	Time avg = std::accumulate(temp.begin(), temp.end(), Time()) / temp.size();
    std::cout << "Average: " << avg << "\n";
    std::transform(temp.begin(), temp.end(), temp.begin(),
        [avg](const Time& t) { return t + avg; });
	
	vector_to_stack(temp, c);
}
