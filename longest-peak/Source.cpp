
#include <vector>
#include <iostream>

using namespace std;


//o(n) space and o(n2) time
int longestPeak(vector<int> array);

int main()
{

    int result = longestPeak({ 1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3 });


    cout << result << " ";

    return 0;
}

int longestPeak(vector<int> array){
    // Write your code here.
    int longestLengt = 0;
    if (array.empty())return 0;
    for (int i = 1; i < array.size() - 1; i++)
    {

        int count = 0;
        int idx1 = i - 1;
        int idx2 = i;
        int idx3 = i + 1;

        bool isPeak = array[idx1] < array[idx2] && array[idx3] < array[idx2];
        if (isPeak)
        {
            count = 2;
            int left = idx1;
            int right = idx3;

            while (array[left] < array[left+1] && left > 0)
            {
               
                left--;
            }

            while (array[right] < array[right-1] && right < array.size()-1)
            {
                
                right++;
            }

            count = right - left - 1;
            if (count > longestLengt)longestLengt = count;
        }


    }
    return longestLengt;
}
