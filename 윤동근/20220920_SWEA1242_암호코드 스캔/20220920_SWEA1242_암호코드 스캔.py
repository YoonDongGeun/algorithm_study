hex_bin = {'0': '0000', '1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111',
           '8': '1000', '9': '1001', 'A': '1010', 'B': '1011', 'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'}

secret = {(3, 2, 1): 0, (2, 2, 2): 1, (2, 1, 2): 2, (1, 4, 1): 3, (1, 1, 3): 4, (1, 2, 3): 5,
          (1, 1, 1): 6, (1, 3, 1): 7, (1, 2, 1): 8, (3, 1, 1): 9}


def cal(string, k):
    Length = 7 * 8 * k
    string = (Length - len(
        string)) * '0' + string  # 크기에 맞지 않는 문자열이 들어왔으면 앞에 '0'을 갯수에 맞게 추가(암호 1개의 가로길이는 최대 100이니까 7*14=98이다. '000'이 최대 14개 나올수 있다. 이를 감안한 것
    S = 0  # 16진법으로 받을때 가장 앞, 뒤의 0을 모두 제외하고 받았기 때문에, 앞에 '0'의 갯수 부족할 수 있고, 실제로 부족하면 값이 달라진다.
    S2 = 0
    b = string[0]
    A = []
    ch = []
    cnt = 0
    cnt2 = 0
    for i in range(7 * 8 * k):
        if (string[i] == b):
            cnt += 1
        else:
            if (cnt2 == 3):
                b = string[i]
                cnt2 = 0
                cnt = 1
                ch.append(tuple(A))  # 튜플 형태로 암호의 앞에 3개만 가져오기. 3개의 숫자의 알아도 된다.
                A = []
            else:
                b = string[i]
                A.append(cnt // k)
                cnt2 += 1
                cnt = 1
    ch.append(tuple(A))  # 마지막 3개는 위의 for문에서 안들어가기 때문에 넣어주기.
    c = 0
    for j in ch:  # ch에 (1,2,3) 과 같은 암호의 비율들이 들어가 있다. ex)ch=[(1,2,3), (2,2,1), (1,2,1)...] (암호갯수 만큼)
        if c == 0:
            S += 3 * secret[j]
            S2 += secret[j]
            c = 1
        else:
            S += secret[j]
            S2 += secret[j]
            c = 0
    if S % 10 == 0:  # S는 체크용, S2는 각 숫자의 합.
        return S2
    else:
        return 0  # 불량 코드면 0 반환.


T = int(input())
for _ in range(1, T + 1):
    N, M = map(int, input().split())
    num_list = set()
    new_string = set()
    ans = 0
    for q in range(N):
        temp = input()
        A = int(temp, 16)
        if A and A not in num_list:  # 계산을 줄이기 위해, A를 10진법으로 바꿨을때, 0이거나 num_list 안에 있으면 넘어간다.(continue)
            num_list.add(A)  # 이미 사용한 문자열 담기.(num_list)
        else:
            continue

        st = 0  # temp(input() 받은것)에서 '0'이 아닌지점의 시작지점 st
        ed = M - 1  # temp에서 '0'이 아닌지점의 끝지점 ed
        string = ''
        while (temp[st] == '0'):
            st += 1
        while (temp[ed] == '0'):
            ed -= 1
        for i in range(st, ed + 1):  # '0'아닌 지점의 시작지점, 끝지점 사이를 2진법 string으로 변환.
            string += hex_bin[temp[i]]
        start = (ed + 1 - st) * 4  # temp의 변환한 문자 1개당 4글자이기 때문에, ed-st+1(기존 바꾸는 문자열길이)*4를 하면 string의 가장 끝지점의 인덱스가 나온다.
        for i in range((ed + 1 - st) * 4, -1, -1):  # string의 가장 끝부터 0번 인덱스까지 탐색.
            if i < start:  # i번 인덱스가 start보다 작으면 시행. (start는 암호 탐색하면, 그 암호 길이만큼 뒤쪽에서 앞으로 start를 지정해준다.. (암호 길이만큼 탐색X)
                if string[i] == '1':  # 만약 1을 찾았으면, 암호코드계산.
                    f = 0
                    k = 0
                    cnt = 0
                    k = 1
                    while cnt != 4:  # cnt 는 0에서 1로 혹은 1에서 0으로 변환된 수. 0에서 1 혹은 1에서 0으로 4번째 바뀌면, 암호의 수 1개이다.ex) [1:3:1:2]
                        if string[i - k] != string[i - k + 1]:
                            cnt += 1
                        k += 1  # 암호 1개의 길이가 몇인지 알수 있다.
                    k //= 7  # k는 7로 나눠서 두께가 된다.
                    start = i + 1 - 7 * 8 * k  # i번째 인덱스에서 '1'을 찾았고 거기서 암호의 총 길이(7*8*k)만큼 빼준곳에서 암호가 시작된다.
                    if start < 0:  # 하지만 암호가 앞쪽에 있다면 start가 0 미만이 된다. 그렇기 때문에 0미만이면 start=0으로하고, cal 함수에서 '0'을 필요한 갯수만큼 달아준다.
                        start = 0
                    N2 = int(string[start:i + 1], 2)
                    if N2 not in new_string:
                        ans += cal(string[start:i + 1], k)  # 암호 판별 함수.
                        new_string.add(N2)  # new_string에는 이미 쓴 암호 담기.
    print(f'#{_} {ans}')