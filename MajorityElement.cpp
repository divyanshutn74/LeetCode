#include <iostream>
#include <vector>
using namespace std;  // You can use this or add std:: before every vector

bool search(const vector<int> &vec, int k)  // Pass by reference
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == k)
            return true;
    }
    return false;
}

int majorityElement(vector<int> &nums)
{
    vector<int> visited;
    for (int i = 0; i < nums.size(); i++)
    {
        int freq = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                freq++;
            }
        }
        if (!search(visited, nums[i]))  // Check if element has been visited
        {
            visited.push_back(nums[i]);
            if (freq > nums.size() / 2)  // Check if frequency is greater than half
            {
                return nums[i];
            }
        }
    }
    return -1;  // If no majority element is found
}

int main()
{
    vector<int> Nums({1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5});
    int majorElem = majorityElement(Nums);
    cout << majorElem << endl;  // Output the majority element
    return 0;
}
