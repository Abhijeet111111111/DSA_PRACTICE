#include <iostream>
#include <unordered_set>
using namespace std;

void permutations(string &input, int i)
{
    if (i == input.size() - 1)
    {
        cout << input << "\n";
        return;
    }
    unordered_set<char> s;
    for (int idx = i; idx < input.size(); idx++)
    {
        if (s.count(input[idx]))
            continue;
        s.insert(input[idx]);
        swap(input[i], input[idx]);

        permutations(input, i + 1);
        swap(input[i], input[idx]);
    }
}

int main()
{
    string s = "aba";
    permutations(s, 0);
}