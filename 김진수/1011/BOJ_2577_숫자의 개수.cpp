#include <iostream> // count, cin, endl, ...
#include <string>

int main()
{
	using namespace std;

	int A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;
	
	int M = A*B*C;
	string N = to_string(M);

	int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
	for(int i = 0; i < N.length(); i++)
	{
		if (N[i] == '0')
		{
			count0++;
		}
		else if (N[i] == '1')
		{
			count1++;
		}
		else if (N[i] == '2')
		{
			count2++;
		}
		else if (N[i] == '3')
		{
			count3++;
		}
		else if (N[i] == '4')
		{
			count4++;
		}
		else if (N[i] == '5')
		{
			count5++;
		}
		else if (N[i] == '6')
		{
			count6++;
		}
		else if (N[i] == '7')
		{
			count7++;
		}
		else if (N[i] == '8')
		{
			count8++;
		}
		else if (N[i] == '9')
		{
			count9++;
		}
	}

	cout << count0 << endl;
	cout << count1 << endl;
	cout << count2 << endl;
	cout << count3 << endl;
	cout << count4 << endl;
	cout << count5 << endl;
	cout << count6 << endl;
	cout << count7 << endl;
	cout << count8 << endl;
	cout << count9 << endl;

	return 0;
}