#include <iostream>
#include <string>
#include <vector>

// Function to sort binary strings
void sort_binary_strings(std::vector<std::string> &strings)
{
    for (auto &s : strings)
    {
        int count_0 = 0;
        int count_1 = 0;

        // Count the number of '0's and '1's in the string
        for (char c : s)
        {
            if (c == '0')
                count_0++;
            else if (c == '1')
                count_1++;
        }

        // Rebuild the string based on the count of '0's and '1's
        for (int i = 0; i < count_0; ++i)
        {
            s[i] = '0';
        }
        for (int i = count_0; i < count_0 + count_1; ++i)
        {
            s[i] = '1';
        }
    }
}

// Function to calculate the minimum steps to sort binary strings
std::vector<int> min_steps_to_sort(const std::vector<std::string> &strings)
{
    std::vector<int> steps;
    for (const auto &s : strings)
    {
        int count_swaps = 0;
        int count_0 = 0;

        // Count the number of '0's
        for (char c : s)
        {
            if (c == '0')
                count_0++;
            else
                count_swaps += count_0; // Each '1' requires a swap with '0's on its left
        }
        steps.push_back(count_swaps);
    }
    return steps;
}

int main()
{
    std::vector<std::string> test_cases = {"101001110011", "110010", "111000", "00110110", "0111100", "101010", "0101010", "11110000"};

    std::cout << "Original strings:" << std::endl;
    for (const auto &s : test_cases)
    {
        std::cout << s << std::endl;
    }

    sort_binary_strings(test_cases);

    std::cout << "\nSorted strings:" << std::endl;
    for (const auto &s : test_cases)
    {
        std::cout << s << std::endl;
    }

    std::vector<int> steps = min_steps_to_sort(test_cases);

    std::cout << "\nMinimum steps to sort:" << std::endl;
    for (int step : steps)
    {
        std::cout << step << std::endl;
    }

    return 0;
}
