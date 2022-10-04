#include <iostream>
int S=0, x;
void add(int x);
void remove(int x);
void check(int x);
void toggle(int x);
void all();
void empty();
void make(char temp[]);

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int M;
	char temp[7];
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> temp;
		make(temp);
	}
	return 0;

}



void make(char temp[])
{

	switch (temp[1])
	{
	case 'd'://add
		std::cin >> x;
		add(x);
		break;

	case 'e': //remove
		std::cin >> x;
		remove(x);
		break;

	case 'h': //check
		std::cin >> x;
		check(x);
		break;

	case 'o': //toggle
		std::cin >> x;
		toggle(x);
		break;

	case 'l':  //all
		all();
		break;

	default:
		empty();
		break;
	}
}

void add(int x)
{
	S |= 1 << x;
}

void remove(int x)
{
	S &= ~(1 << x);
}

void check(int x)
{
	(S & (1 << x) ) ? std::cout << "1\n" : std::cout << "0\n";
}

void toggle(int x)
{
	S ^= 1 << x;
}

void all()
{
	S = ~0;
}

void empty()
{
	S = 0;
}
