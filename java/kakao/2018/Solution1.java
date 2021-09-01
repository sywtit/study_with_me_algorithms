package kakao.2018;

import java.util.*;
import java.io.*;

class Solution1 {
    public int solution(String[] lines) {
        int answer = 0;

        // 초당 최대 처리량 : 전체 count를 세보는 방식
        // 9월 15일의 전체 초 -> 3600*24
        int[] count = new int[3600 * 24 * 1000];

        for (int i = 0; i < lines.size(); i++) {
            String line = lines[i];
            StringTokenizer st = new StringTokenizer(line, " ");
            st.nextToken(); // 날짜

            String endTime = st.nextToken();
            String duration = st.nextToken();

            st = new StringTokenizer(endTime, ":");
            double endTimeValue = (double) (Integer.parseInt(st.nextToken) * 3600);
            endTimeValue += (double) (Integer.parseInt(st.nextToken) * 60);
            endTimeValue += Double.parseDouble(st.nextToken);

            st = new StringTokenizer(duration, "s");
            double durationValue = Double.parseDouble(st.nextToken);

            double startTimeValue = endTimeValue - durationValue;

            for (double time = startTimeValue; time <= endTimeValue; time += 0.001) {
                count[time]++;
            }

        }

        // count 한칸씩 이동하면서 가장 큰 값 구하기
        for (int i = 0; i < 3600 * 23 * 1000; i += 1000) {
            int sum = 0;
            for (j = i; j < i + 1000; j++) {
                sum += count[j];
            }
            answer = Math.max(answer, sum);
        }

        return answer;
    }
}
