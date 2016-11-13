#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

typedef unsigned int uni;

using namespace std;

template<typename T>
uni count_digits(T number) //counts how many digits a number has
{
	if (number == 0)
		return 1;

	uni digits = 0;

	while (number != 0)
	{
		number /= 10;
		digits++;
	}

	return digits;
}
