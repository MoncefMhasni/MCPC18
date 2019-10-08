import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class G {

	static int a[];
	static int not_important[][];
	static int first[];
	static boolean found[];
	static int n, k;

	static void init() {
		a = new int[n];
		first = new int[k + 1];
		found = new boolean[k + 1];
		Arrays.fill(first, -1);
		not_important = new int[k + 1][n];
	}

	static void add(int i, int j, int val) {
		if (i > j)
			return;
		not_important[val][i]++;
		if (j < n - 1)
			not_important[val][j + 1]--;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("important.in"));
		PrintWriter out = new PrintWriter(System.out);
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		while (t-- > 0) {
			n = sc.nextInt();
			k = sc.nextInt();
			init();
			for (int i = 0; i < n; i++)
				a[i] = sc.nextInt();
			found[0] = true;
			for (int i = 0; i < n; i++)
				for (int j = k; j >= 1; j--) {
					if (j < a[i])
						continue;
					if (found[j - a[i]]) {
						found[j] = true;
						if (first[j] == -1)
							first[j] = i;
					}
				}

			for (int i = 1; i <= k; i++) {
				if (first[i] != -1) {
					add(first[i] + 1, n - 1, i);
				}
			}

			Arrays.fill(found, false);
			found[0] = true;

			for (int i = n - 1; i >= 0; i--)
				for (int j = k; j >= 1; j--) {
					if (j < a[i])
						continue;
					if (found[j - a[i]] && !found[j]) {
						found[j] = true;

						for (int v = j; v <= k; v++)
							if (j == v)
								add(0, i - 1, v);
							else if (first[v - j] != -1)
								add(first[v - j] + 1, i - 1, v);

					}

				}

			Arrays.fill(first, n);

			for (int val = 1; val <= k; val++) {
				for (int j = 0; j < n; j++) {
					if (j > 0)
						not_important[val][j] += not_important[val][j - 1];
					if (not_important[val][j] > 0)
						first[val]--;
				}


				if (!found[val])
					first[val] = 0;
				sb.append(first[val] + " ");

			}

			sb.append("\n");

		}

		out.print(sb);
		out.flush();
		out.close();

	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
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
