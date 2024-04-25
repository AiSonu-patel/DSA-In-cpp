#include<iostream>
using namespace std;

int findK(int A[][4], int n, int m, int k)
{
    int top=0, right=m-1, bootom=n-1, left=0;
	int count=0;
	while(left<=right && top<=bootom)
	{
	    for(int i=left; i<=right; i++)
	    {
	        count++;
	        if(count==k)
	        return A[top][i];
	    }
        top++;
	    for(int i=top; i<=bootom; i++)
	    {
	        count++;
	        if(count==k)
	        return A[i][right];
	    }
        right--;
	    if(top<=bootom)
	    {
	        for(int i=right; i>=left; i--)
	        {
	            count++;
	            if(count==k)
	            return A[bootom][i];
	        }
            bootom--;
	    }
        
	    if(left<=right)
	    {
	        for(int i=bootom; i>=top; i--)
	        {
	            count++;
	            if(count==k)
	            return A[i][left];
	        }
            left++;
	    }
        
	}
	return count;
}

int main()
{
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    cout<<findK(arr, 4, 4, 10);
}