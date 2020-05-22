#include "histogram.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>


using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
}
;

void find_minmax(struct Input Input, double& min, double& max)
{
    int p=Input.numbers.size();
    if(p!=0)
        {
            min = Input.numbers[0];
            max = Input.numbers[0];
            for (double number : Input.numbers)
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

