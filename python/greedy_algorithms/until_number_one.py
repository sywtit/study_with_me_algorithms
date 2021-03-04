# import time
# start_time = time.time()

N, K = map(int, input().split())
result = 0

while True:
    # 나누어 떨어질때까지 1을 뺀다
    count = (N//K) * K
    result += (N - count)

    N = count

    if N < K:
        break

    result += 1
    N //= K

result += (N-1)
print(result)

# end_time = time.time()
# print("time :", end_time - start_time)
