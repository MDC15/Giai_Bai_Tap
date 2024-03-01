#include <iostream>
#include <string>
#include <vector>

// Function to sort binary strings
void sort_binary_string(std::string& s) {
    int count_0 = 0;
    int count_1 = 0;

    // Count the number of '0's and '1's in the string
    for (char c : s) {
        if (c == '0')
            count_0++;
        else if (c == '1')
            count_1++;
    }

    // Rebuild the string based on the count of '0's and '1's
    for (int i = 0; i < count_0; ++i) {
        s[i] = '0';
    }
    for (int i = count_0; i < count_0 + count_1; ++i) {
        s[i] = '1';
    }
}

// Function to calculate the minimum steps to sort binary strings
int min_steps_to_sort(std::string s) {
    int count_swaps = 0;
    int count_0 = 0;

    // Count the number of '0's
    for (char c : s) {
        if (c == '0')
            count_0++;
        else
            count_swaps += count_0; // Each '1' requires a swap with a '0'
    }

    return count_swaps;
}

int main() {
    std::vector<std::string> test_cases = {"101001110011", "110010", "100110101", "0011100", "11110000"};

    for (const auto& s : test_cases) {
        std::string sorted_string = s;
        sort_binary_string(sorted_string);
        std::cout << "Original string: " << s << std::endl;
        std::cout << "Sorted string: " << sorted_string << std::endl;
        std::cout << "Minimum steps to sort: " << min_steps_to_sort(s) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
