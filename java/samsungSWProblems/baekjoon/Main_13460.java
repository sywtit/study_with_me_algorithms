package samsungSWProblems.baekjoon;

import java.io.*;
import java.util.*;
public class Main_13460 {
	
	static class Pos{
		
		int blueX;
		int blueY;
		int redX;
		int redY;
		int count;
		
		public Pos(int blueX, int blueY, int redX, int redY, int count) {
			this.blueX = blueX;
			this.blueY = blueY;
			this.redX = redX;
			this.redY = redY;
			this.count = count;
		}
		
	}
	
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		char[][] board = new char[N][M];
		int[] red = new int[2]; // x,y
		int[] blue = new int[2]; // x,y
		
		for(int i =0; i<N; i++) {
			board[i] = in.readLine().toCharArray();
			for(int j =0; j<M; j++) {
				if(board[i][j] == 'B') {
					blue = new int[] {j,i};
				}else if(board[i][j] == 'R') {
					red = new int[] {j,i};
				}
			}
		}
		
		Deque<Pos> q = new ArrayDeque<>();
		q.offer(new Pos(blue[0],blue[1],red[0],red[1],0));
		
		// bfs 시작
		while(!q.isEmpty()) {
			
			Pos now = q.poll();
			
			// 10번 이하로 움직여서 빨간 구슬을 뺄 수 없을 경우
			if(now.count >= 10) {
				System.out.println("-1");
				return;
			}
			
			for(int i =0; i<4; i++) {
				
				// 파란색 공 먼저 이동
				int newBX = now.blueX;
				int newBY = now.blueY;
				boolean hole = false;
				boolean meetOther = false;
				
				while(board[newBY][newBX] != '#') {
					
					newBY += dy[i];
					newBX += dx[i];
					
					if(newBY == now.redY && newBX == now.redX) {
						meetOther = true;
					}
					
					if(board[newBY][newBX] == 'O') {
						hole = true;
						break;
					}
				}
				
				// 해당 위치에 파란색 공이 구멍에 빠졌을 경우는 제외
				if(hole) continue;
				if(meetOther) {
					newBX -= dx[i];
					newBY -= dy[i];
				}
				
				newBX -= dx[i];
				newBY -= dy[i];
				
				int newRX = now.redX;
				int newRY = now.redY;
				meetOther = false;
				
				while(board[newRY][newRX] != '#') {
					
					newRY += dy[i];
					newRX += dx[i];
					
					if(newRY == now.blueY && newRX == now.blueX) {
						meetOther = true;
					}
					
					if(board[newRY][newRX] == 'O') {
						hole = true;
						break;
					}
				}
				
				// 빨간 공만 빠졌을 경우 정답
				if(hole) {
					int answer = now.count + 1;
					System.out.println(answer);
					return;
				}

				if(meetOther) {
					newRX -= dx[i];
					newRY -= dy[i];
				}
				
				newRX -= dx[i];
				newRY -= dy[i];

				q.offer(new Pos(newBX, newBY, newRX, newRY, now.count+1));

			}
			
		}
		
		System.out.println("-1");
		return;

	}

}
