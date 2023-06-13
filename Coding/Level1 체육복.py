def solution(n, lost, reserve):
    answer = n
    lost.sort()
    reserve.sort()
    for i in lost:
        if i in reserve:
            lost.remove(i)
            continue
        for j in reserve:
            if abs(i-j) == 1:
                answer +=1
                reserve.remove(j)
    answer -= len(lost)
    print(lost)
    return answer
