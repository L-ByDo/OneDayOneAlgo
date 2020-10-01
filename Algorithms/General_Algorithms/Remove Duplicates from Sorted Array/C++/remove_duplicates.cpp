class Solution
{

public:
    int removeDuplicates (vector < int >&nums)
    {

        int first = 0;		//initialize first pointer from 0
        if (nums.size () == 0)
        {   //if size is 0, return
            return 0;
        }

        for (int idx = 0; idx < nums.size (); idx++)
        {   //loop from starting, if current pointer is equal to second pointer, continue else copy value to next of first pointer
            if (nums[idx] == nums[first])
            {

                continue;
            }

            else
            {

                first++;

                nums[first] = nums[idx];
            }
        }

        return first + 1;		//return size of new array
    }

};
