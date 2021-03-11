# #시간 재기
# import time
# start_time = time.time()

# 입력 받기
input_data = input()
row = int(ord(input_data[0])) - int(ord('a')) + 1
column = int(input_data[1])

# direction 선언
steps = [(2, 1), (2, -1), (1, 2), (1, -2),
         (-2, 1), (-2, -1), (-1, 2), (-1, -2)]

# for문
count = 0

for step in steps:
    new_row = row+step[0]
    new_column = column+step[1]

    if new_row >= 1 and new_row <= 8 and new_column >= 1 and new_column <= 8:
        count += 1

print(count)
# end_time = time.time()

# print("time :", end_time - start_time)
# time 1.44
