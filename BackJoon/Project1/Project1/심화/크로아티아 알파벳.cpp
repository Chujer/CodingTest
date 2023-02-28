#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, string> table;
	table.insert(make_pair("c = ", "c = "));
	table.insert(make_pair("c-", "c-"));
	table.insert(make_pair("dz=", "dz="));
	table.insert(make_pair("d-", "d-"));
	table.insert(make_pair("lj", "lj"));
	table.insert(make_pair("nj", "nj"));
	table.insert(make_pair("s=", "s="));
	table.insert(make_pair("z=", "z="));

	string instring = "";
	cin >> instring;

	for(pair<string, string> t : table)
	{
		if(instring.find(t.second) != string::npos)
		{
			int a = instring.find((t.second));
			string temp;
			temp = instring.substr(0, a);
			instring = temp + instring.substr( instring.find((t.second))+ t.second.size(), instring.size());
			
		}
		
	}
}