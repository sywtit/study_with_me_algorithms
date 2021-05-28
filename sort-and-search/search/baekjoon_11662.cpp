#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct xy {
	int x;
	int y;
}xy;

double getDistance(xy left, xy right) {
	double x_distance = pow((double)left.x - (double)right.x, 2);
	double y_distance = pow((double)left.y - (double)right.y, 2);
	return (double)sqrt(x_distance + y_distance);
}
int main() {
	xy A, B, C, D;

	scanf("%d %d %d %d %d %d %d %d", A.x, A.y, B.x, B.y,
		C.x, C.y, D.x, D.y);

	//binary search
	xy left_M = A;
	xy right_M = B;
	xy left_K = C;
	xy right_K = D;

	while (1) {
		xy mid_M, mid_K;
		mid_M.x = (left_M.x + right_M.x) / 2;
		mid_M.y = (left_M.y + right_M.y) / 2;
		mid_K.x = (left_K.x + left_K.x) / 2;
		mid_K.y = (left_K.y + left_K.y) / 2;

		double dist_start = getDistance(left_M, left_K);
		double dist_end = getDistance(right_M, right_K);

		//중간의 길이와 가장 처음과 끝을 비교
		double dist_mid = getDistance(mid_M, mid_K);

		if (dist_mid >= dist_end) {
			left_M = mid_M;
			left_K = mid_K;
		}
		else if (dist_mid >= dist_start) {
			right_M = mid_M;
			right_K = mid_K;
		}
		else if (dist_mid == dist_end && dist_mid == dist_start) {
			printf("%10f", dist_mid);
			return 0;
		}
		

	}


}
