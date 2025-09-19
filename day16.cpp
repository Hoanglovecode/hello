// FOR lồng kép và in chữ L V H
#include <iostream>
using namespace std;
int main()
{
  for (int i = 1; i <= 7; i++)
  {
    for (int j = 1; j <= 7; j++)
    {
      if (j == 4 || i == 7 && j >= 4)
        cout << "*" << "*" << " ";
      else
        cout << " " << " " << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 1; i <= 7; i++)
  {
    for (int j = 1; j <= 7; j++)
    {
      if (i == 1 && j == 1 || i == 2 && j == 2 || i == 3 && j == 3 || i == 4 && j == 4 || i == 3 && j == 5 || i == 2 && j == 6 || i == 1 && j == 7)
        cout << "*" << "*" << " ";
      else
        cout << " " << " " << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 1; i <= 7; i++)
  {
    for (int j = 1; j <= 7; j++)
    {
      if (j == 1 || j == 7 || i == 4)
        cout << "*" << "*" << " ";
      else
        cout << " " << " " << " ";
    }
    cout << endl;
  }
  cout << endl;
}