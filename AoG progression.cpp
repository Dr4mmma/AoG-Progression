/*
**************************************************************************************************************************
* Name: Mohammad Tayseer Mohammad Abu Mailiesh
* Date: May, 7th 2020
* Project: Arithmetic or Geometric progression
* Credits: geekforgeeks
* Overview: A program that finds if the sequence entered is an arithmetic or geometric
*           progression and finds the nth value entered by the user
**************************************************************************************************************************
*/

#include <iostream>
#include <algorithm>
using namespace std;

double rg = 0;
double ag = 0;
double ap = 0;
double dp = 0;

bool is_geometric(int arr[], int n)
{
    if (n == 1)
        return true;

    int ratio = arr[1] / (arr[0]);
    for (int i = 1; i < n; i++) {
        if ((arr[i] / (arr[i - 1])) != ratio) {
            return false;
        }
    }
    ag = arr[0];
    rg = ratio;
    return true;
}
bool checkIsAP(int arr[], int n)
{
    if (n == 1)
        return true;

    sort(arr, arr + n);

    int d = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
        if (arr[i] - arr[i - 1] != d)
            return false;
    ap = arr[0];
    dp = d;
    return true;
}
void Nth_of_GP(int a, int r, int n)
{
    cout << "The " << n << "th term of geometric progression is: " << a * (int)(pow(r, n - 1)) << endl;
}
void Nth_of_AP(int a, int d, int n)
{
    cout << "The " << n << "th term of arithmetic progression is: " << a + (n - 1) * d << endl;
}

int main()
{
    int n1;
    int arr[4];
    cout << "Please enter a 4 digit sequence: ";
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    int n = sizeof(arr) / sizeof(arr[0]);

    if (is_geometric(arr, n) == 1)
    {
        cout << "Sequence is geometric progression with a = " << ag << " and r = " << rg << endl;
    }
    else if (checkIsAP(arr, n == 1))
    {
        cout << "Sequence is arithmetic progression with a = " << ap << " and d = " << dp << endl;
    }

    cout << "Please enter the nth number to find its value: ";
    cin >> n1;
    cout << endl;

    if (is_geometric(arr, n) == 1)
    {
        Nth_of_GP(ag, rg, n1);
    }
    else if (checkIsAP(arr, n == 1))
    {
        Nth_of_AP(ap, dp, n1);
    }

    return 0;
}
