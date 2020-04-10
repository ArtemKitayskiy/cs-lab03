#include "histogram.h"
#include <vector>
#include <iostream>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    int p=numbers.size();
    if(p!=0)
        {
            min = numbers[0];
            max = numbers[0];
            for (double number : numbers)
                {
                    if (number < min)
                    {
                        min = number;
                    }
                    if (number > max)
                        {
                            max = number;
                        }
                }
        }
}
