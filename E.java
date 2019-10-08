import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class E {


	static class Pair {
		int first,second;
		public Pair(int f,int s) {
			this.first = f;
			this.second = s;
		}
	}
	static boolean valid(int i,int j,int n, char arr[][]) {
		return i >= 0 && i < n && j >= 0 && j < n && arr[i][j] != 'x';
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner("maze.in");
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			char arr[][] = new char[n][];

			for (int i = 0 ; i < n ; ++i) {
				arr[i] = sc.next().toCharArray();
			}
			int dx[] = {1,-1,0,0};
			int dy[] = {0,0,1,-1};
			Queue<Pair> q = new LinkedList();
			boolean vis[][] = new boolean[n * n][n * n];
			for (int i = 0 ; i < n ; ++i ) {
				for (int j = 0 ; j < n ; ++j) {
					if (arr[i][j] == 'x') {
						continue;
					}
					q.add(new Pair(i * n + j, i * n + j));
					vis[i * n + j][i * n + j] = true;
					for (int k = 0 ; k < 4 ; ++k) {
						int xc = i + dx[k],yc = j + dy[k];
						if (valid(xc,yc,n,arr)) {
							q.add(new Pair(i * n + j,xc * n + yc));
							vis[i * n + j][xc * n + yc] = true;

						}
					}
				}
			}

			int d[] = new int[4];
			d[0] = 1;
			d[1] = 0;
			d[2] = 3;
			d[3] = 2;

			while (!q.isEmpty()) {
				Pair p = q.poll();

				vis[p.first][p.second] = true;
				int i1  = p.first / n , j1 = p.first % n;
				int i2 = p.second / n, j2 = p.second % n;
				if (arr[i1][j1] == 'x') {
					continue;
				}
				if (arr[i2][j2] == 'x') {
					continue;
				}
				for (int k = 0 ; k < 4 ; ++k) {
					int xc1 = i1 + dx[d[k]], yc1 = j1 + dy[d[k]];
					int xc2 = i2 + dx[k], yc2 = j2 + dy[k];
					if (valid(xc1,yc1,n,arr) && valid(xc2,yc2,n,arr)) {
						int a = xc1 * n + yc1 , b = xc2 * n + yc2;
						if (!vis[a][b]) {
							q.add(new Pair(a,b));
							vis[a][b] = true;
						}
					}
				}
			}
			ArrayList<Integer> g[] = new ArrayList[n * n];
			for (int i = 0 ; i < n * n ; ++i) {
				g[i] = new ArrayList();
			}
			for (int i1 = 0 ; i1 < n ; ++i1) {
				for (int j1 = 0 ; j1 < n ; ++j1) {
					for (int i2 = 0 ; i2 < n ; ++i2) {
						for (int j2 = 0 ; j2 < n ; ++j2) {
							int a = i1 * n + j1, b = i2 * n + j2;
							if (vis[a][b]) {
								g[a].add(b);
								g[b].add(a);
							}
						}
					}
				}
			}
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1, k = sc.nextInt();
			if (arr[x][y] == 'x') {
				System.out.println(0);
			} else {
				int s = x * n + y;
				int dis[] = new int[n * n];
				Arrays.fill(dis, 1 << 30);
				dis[s] = 0;
				int ans = 0;
				Queue<Integer> qq = new LinkedList();
				qq.add(s);
				while (!qq.isEmpty()) {

					int u = qq.poll();
					if (dis[u] > k) {
						continue;
					}
					++ans;
					for (Integer v : g[u]) {
						if (dis[u] + 1 < dis[v]) {
							dis[v] = dis[u] + 1;
							qq.add(v);
						}
					}
				}
				System.out.println(ans);
			}

		}
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}