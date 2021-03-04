# #시간 계산
# import time
# start_time = time.time()

# 입력
N, M, K = map(int, input().split())
number = list(map(int, input().split()))
sum = 0

# 정렬
number.sort()

# 제일 큰 수
first = number[N-1]
second = number[N-2]

# 반복되는 수열 과 제일 큰 수가 반복되는 마지막 개수 구하기
count = int(M/(K+1))
count_first = M % (K+1)

sum += (count * K + count_first) * first
sum += count * second

# #책에서 제시하는 방법
# count =  int(M/(K+1)) * K
# count += M % (K+1)

# result += (count) * first
# result += (m-count) * second

print(sum)

# end_time = time.time()

# print("time : ", end_time - start_time)
# time = 13
