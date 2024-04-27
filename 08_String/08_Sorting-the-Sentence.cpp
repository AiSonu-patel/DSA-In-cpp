#include<iostream>
#include<vector>
using namespace std;

string SortingSentence(string str)
{
    int n = str.size();
    vector<string>ans(n);
    string temp;
    int count = 0;
    int index = 0;
    while(index<str.size())
    {
        if(str[index]==' ')
        {
            int poss = temp[temp.size()-1]-'0';
            temp.pop_back();
            ans[poss] = temp;
            temp.clear();
            count++;
        }
        else
        {
            temp += str[index];
        }

        index++;
    }
    
    int poss = temp[temp.size()-1]-'0';
    temp.pop_back();
    ans[poss] = temp;
    temp.clear();
    count++;

    for(int i=1; i<=count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back();

    return temp;
}

int main()
{
    string str = "is2 sentence4 This1 a3";

    cout<<SortingSentence(str); // This is a sentence
}