#include <string>
#include <iostream>

using namespace std;

int main()
{
	string text;
	while (getline(cin, text))
	{
		int count = 0;
		bool is_word = false;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ' ')
			{
				if (!is_word)
				{
					count++;
					is_word = true;
				}
			}
			else
			{
				if (is_word)
				{
					is_word = false;
				}
			}
		}
		if (count) cout << count << endl;
	}

	return 0;
}