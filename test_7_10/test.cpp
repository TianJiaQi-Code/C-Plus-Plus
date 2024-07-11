#include <iostream>
#include <string>

int main()
{

	std::string str = "";
	for (int i = 0; i < str.size(); i++)
	{
		printf("%X", str[i]);
	}
	return 0;
}