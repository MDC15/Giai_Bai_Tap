#include <iostream>
#include <unordered_map>

bool isIsomorphic(const std::string &a, const std::string &b)
{
    if (a.length() != b.length())
    {
        return false;
    }

    std::unordered_map<char, char> mapping_a_to_b;
    std::unordered_map<char, char> mapping_b_to_a;

    for (size_t i = 0; i < a.length(); ++i)
    {
        char char_a = a[i];
        char char_b = b[i];

        // Check mapping from a to b
        if (mapping_a_to_b.find(char_a) != mapping_a_to_b.end())
        {
            if (mapping_a_to_b[char_a] != char_b)
            {
                return false;
            }
        }
        else
        {
            mapping_a_to_b[char_a] = char_b;
        }

        // Check mapping from b to a
        if (mapping_b_to_a.find(char_b) != mapping_b_to_a.end())
        {
            if (mapping_b_to_a[char_b] != char_a)
            {
                return false;
            }
        }
        else
        {
            mapping_b_to_a[char_b] = char_a;
        }
    }

    return true;
}

int main()
{
    std ::string a, b;
    std ::cin >> a >> b;
    std ::cout << (isIsomorphic(a, b) ? "\nTrue" : "\nFalse") << std ::endl;
    system("pause");
    return 0;
}
