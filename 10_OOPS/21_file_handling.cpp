#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("z1.txt");
    fout<<"welcome to India\n";
    fout<<"Hello sonu\n";
    fout<<"How are you ?\n";
    fout.close();

    ifstream fin;
    fin.open("z1.txt");

    string line;
    while(getline(fin, line))
    {
        cout<<line<<endl;
    }

    fin.close();
    

}