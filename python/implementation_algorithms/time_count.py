#import time
#start_time = time.time()
# h입력 받기
h = int(input())
count = 0

# 3중 for문
for i in range(h+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1

print(count)

#end_time = time.time()
#print("time : ", end_time - start_time)
#time = 0.7
