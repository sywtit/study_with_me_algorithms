# 시간 체크
import time
start_time = time.time()
# 입력 받기
n = int(input())
plans = input().split()
x, y, nx, ny = 1, 1, 1, 1

# 이동 경로 선언
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

for plan in plans:

    for i in range(len(move_types)):
        if plan == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]

    if nx < 1 or nx > n or ny < 1 or ny > n:
        continue

    x, y = nx, ny

print(x, y)
end_time = time.time()
print("time: ", end_time-start_time)
