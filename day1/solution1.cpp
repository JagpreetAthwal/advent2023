#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int extractNumber(const string& str)
{
   int first = str[str.find_first_of("0123456789")] - '0';
   int second = str[str.find_last_of("0123456789")] - '0';
   
   return first * 10 + second;
}


int main()
{
   ifstream infile("input.txt");
   string str;
   
   vector<int> values;
   while(getline(infile, str))
   {
      values.push_back(extractNumber(str));
   }

   auto total = accumulate(values.begin(), values.end(),0);

   cout << "Number of values: " << values.size() << " total: " << total << endl;
}
