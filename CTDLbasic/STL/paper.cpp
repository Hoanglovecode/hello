#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    // Loop through vector elements
    for (auto it = cars.begin(); it != cars.end();)
    {
        if (*it == "BMW")
        {
            it = cars.erase(it); // Remove the BMW element
        }
        else
        {
            ++it;
        }
    }
    // Print vector elements
    for (string car : cars)
    {
        cout << car << "\n";
    }
}