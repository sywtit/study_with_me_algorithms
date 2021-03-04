# #시간 계산
# import time
# start_time = time.time()
# 입력 받기
N, M = map(int, input().split())

answer = 0

# g한 줄씩 입력 받아 확인
for i in range(N):
    # 입력
    data = list(map(int, input().split()))

    # min 값 구하기
    minimum = min(data)
    # 혹은 이중 포문으로 두개만 비교해서 최솟값 구하기

    # minimum값에서 가장 큰 값 answer에 저장
    answer = max(answer, minimum)


print(answer)

# end_time = time.time()
# print("time : " , end_time - start_time)
