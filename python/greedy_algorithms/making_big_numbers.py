# # 시간 체크
# import time
# start_time = time.time()

# 입력
N, M, K = map(int, input().split())
number = list(map(int, input().split()))
sum = 0

# 다음 정렬
number.sort()

# 제일 큰 수와 두번째 큰수를 나눔
first = number[N-1]
second = number[N-2]

while True:
    for i in range(K):
        if M == 0:
            break
        sum += first
        M -= 1
    if M == 0:
        break
    sum += second
    M -= 1

print(sum)

# end_time = time.time()
# print("time : ", end_time - start_time)
# time = 16
