#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// 혼자 구현 못해서 거의 보다시피 참고함
// 참고 블로그 : https://yabmoons.tistory.com/306

// 구현 단계
// 1. 암호코드 배열 입력받기 (16진수 그자리에서 바로 2진수로 바꿔주기)
// 2. 배열 따라서 탐색하다가 암호코드 시작되는 지점에서 확인
// 3. 암호코드 배열 입력받아서 비율 맞춰서 바꿔주기
// 4. 암호코드가 올바른지 검증 후 더해주기
//
// 이런 문제는 어떻게 구현하는지가 중요한 문제
// 1. 0~9까지 비율 중 0을 제외한 비율이 같지않아서 볼 필요 없다
// 2. 가장 작은 비율의 크기가 배율 숫자이다
// 3. 배열 활용이 매우 중요함!

int T,N,M;
// 범위는 500이지만 16진수 구현하려고 2000까지 함
char code[2000][2000];
// 16진수 > 2진수 배열
string sixteen[16] = {"0000", "0001", "0010", "0011","0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
// 0~9 까지 코드 배열
string num[10] = { "211", "221", "122","411","132","231","114","312","213","112" };
int ans = 0;

void binary()
{
	int idx = 7;
	int result[8] = { 0, };

	for (int y = 0; y < N; y++)
	{
		for (int x = 4 * M -1;x>=0;x--)
		{
			int part[3] = { 0,0,0 };
			// 숫자 코드 특징 - 0으로 시작하고 1로 끝난다(ex : 0 - 0001101)
			// 거꾸로 보기 때문에 1 > 0 > 1 순으로 보기, 0은 끝나는 지점을 확실히 모르니까 보지 않기
			// 앞의 0을 제회한 나머지 배열 비율이 같지 않기 때문에 가능

			//암호코드가 시작하는 시점에서만 보기. 세로길이가 정확하지 않기 때문에 중복 방지
			if (code[y][x] == '1' && code[y - 1][x] == '0')
			{
				while (code[y][x] == '1')
				{
					part[2]++; x--;
				}
				while (code[y][x] == '0')
				{
					part[1]++; x--;
				}
				while (code[y][x] == '1')
				{
					part[0]++; x--;
				}
				x++;
				
				// 비율 측정
				int div = part[2];
				if (part[1] < div) div = part[1];
				if (part[0] < div) div = part[0];

				for (int i = 0; i < 3; i++) part[i] /= div;

				string temp;
				// temp와 일치하는 비율 찾기
				temp += to_string(part[0]) + to_string(part[1]) + to_string(part[2]);
				for (int i = 0;i<10;i++)
					if (temp == num[i])
					{
						result[idx] = i;
						idx--;
						break;
					}

				// 8개 숫자 입력 다되면 이 암호코드가 올바른지 확인
				if (idx == -1)
				{
					int value = (result[0] + result[2] + result[4] + result[6]) * 3 + result[1] + result[3] + result[5] + result[7];
					// 올바르면 더해주기
					if (value % 10 == 0)
						for (int i = 0; i < 8; i++)
							ans += result[i];
					idx = 7;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				char temp;
				cin >> temp;
				if (temp <= '9') temp = temp - '0';
				else temp = temp - 'A' + 10;

				for (int z = 0; z < 4; z++)
					code[y][x * 4 + z] = sixteen[int(temp)][z];
			}
		}

		cout << "#" << tc << " " << ans << "\n";
		ans = 0;
	}
	return 0;
}