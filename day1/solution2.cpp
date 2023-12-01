#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>

using namespace std;

unordered_map<string, int> dictionary { {"0",0}, {"1", 1}, {"2",2}, {"3",3}, {"4",4}, {"5",5}, {"6",6},{"7",7},{"8",8},{"9",9},
	{"zero",0}, {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9}};


int extractNumber(const string& str)
{
	int min_index = INT_MAX;
	int max_index = 0;
	int first=0, second=0;

	for(auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		auto pos = str.find(it->first);
		if(pos != string::npos)
		{
			if(pos <= min_index)
			{
				min_index = pos;
				first = it->second;
			}
		}

		pos = str.rfind(it->first);
		if(pos != string::npos)
		{
			if(pos >= max_index)
			{
				max_index = pos;
				second = it->second;
			}
		}
	}

   	return (10 * first) + second;
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
