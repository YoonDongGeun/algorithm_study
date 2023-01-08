def solution(s):
    answer = ""
    numList = ['zero', "one", "two", "three", "four",
               "five", "six", "seven", "eight", "nine"]

    for idx, string in enumerate(s):
        if not string.isdigit():
            for idxNum, numStr in enumerate(numList):
                length = len(numStr)
                checkS = s[idx:idx+length]
                if checkS == numStr:
                    answer += str(idxNum)
                else:
                    pass
        else:
            answer += str(string)
    return int(answer)
