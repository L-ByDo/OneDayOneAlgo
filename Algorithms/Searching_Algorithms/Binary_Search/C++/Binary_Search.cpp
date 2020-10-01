#include<iostream>
using namespace std;
int
main ()
{
    int arr[3][3];
    int n = 3, m = 3, max, mid, index;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int u = 3, l = 0;
    while (u > l)
    {
        mid = (l + u) / 2;   //find the mid column
        max = arr[0][mid];
        for (int i = 1; i < 3; i++)
        {
            if (arr[i][mid] > max)    //find largest element in that array
            {
                max = arr[i][mid];
                index = i;    //keep track of largest element index
            }
        }
        if (max < arr[index][mid - 1])  //if it is smaller than left element,search left
        {
            u = mid - 1;
        }
        if (max < arr[index][mid + 1])  //if right element is greater,search right
        {
            l = mid + 1;
        }
        else
        {
            cout << arr[index][mid];  //else we found the element because since, it is greatest element,it is greater then up,down,left and right element
            break;
        }
    }

}
