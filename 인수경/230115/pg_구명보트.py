def solution(people, limit):
    answer = 0
    people.sort(reverse=True)

    top = 0
    rear = len(people) - 1

    while top <= rear:
        if top == rear:
            answer += 1
            break

        if people[top] + people[rear] > limit:
            top += 1
            answer += 1
        else:
            top += 1
            rear -= 1
            answer += 1

    return answer
