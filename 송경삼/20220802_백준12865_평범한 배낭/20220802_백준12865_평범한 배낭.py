import sys
N,K=map(int, sys.stdin.readline().split())  #물품의 숫자 N, 무게의 한도 K를 상수로 받습니다.
bag=[]  #물품을 저장할 공간입니다.

for i in range(N):
    bag.append(list(map(int, sys.stdin.readline().split()))) 
    #N개의 물품을 2차원 리스트에 저장합니다.

best=[[0]*N]    
#최선의 판단을 저장할 공간입니다.

for i in range(1,K+1):  
    # 첫번째 for문으로 무게를 순회합니다. 무게를 기준으로 삼은 이유는
    # 나중에 새로 갱신될 무게에서도 이전 무게에 대한 정보를 이용해 동적 계획법을 쓸 수 있기 때문입니다.

    i_best=[]       
    #무게 i일때 각 물품을 돌면서 베스트 판단을 저장할 임시공간입니다.

    for item in bag:        #배낭에있는 물품을 순회합니다.
        case1=i_best[-1] if i_best!=[] else 0          
        #case1은 해당 item을 포함하지않고 이전 item까지의 최선의 판단을 기록한 case입니다.

        case2=best[-1][len(i_best)]                    
        #case2는 해당 item을 넣었었던 이전의 최선의 case 입니다.
        
        if i_best!=[]:                                  
            case3=best[i-item[0]][len(i_best)-1]+item[1] if i-item[0]>=0 else 0
            #case3은 두가지로 나뉩니다. 해당 순회 차례가 맨 앞 물품이 아닐 때, 해당 물품을 넣으면서 최선의 가치를 낼 수있는 case입니다.
        else:               
            case3=item[1] if item[0]<=i else 0
            #해당 순회 차례가 맨 앞 물품이라면, 첫번째 물품을 넣을 수 있냐 마냐로 case가 변합니다.

        i_best.append(max(case1,case2,case3))   #case1~3중에 가장 가치가 큰 case를 저장합니다.

    best.append(i_best) #그렇게 전체 물품을 순회해서 모은 정보를 나중에 이용하기 위해 저장소에 저장합니다.

print(best[-1][-1]) #가장 마지막에 있는 요소가 최고의 값입니다.
