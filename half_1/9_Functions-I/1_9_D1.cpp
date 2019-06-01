#include <iostream>
#include <string>

using namespace std;

string StringXOR(string S, string K);

int main()
{
	string s, k;
	cin >> s >> k;

	s = StringXOR(s, k);

	for (int i = 0; i < s.size() - 1; i++) cout << int(s[i]) << " ";
	cout << int(s[s.size() - 1]) << endl;

	//system("pause");
	return 0;
}


string StringXOR(string S, string K)
{
	for (int i = 0; i < S.size(); i++) S[i] ^= K[i % K.size()];
	return S;
}