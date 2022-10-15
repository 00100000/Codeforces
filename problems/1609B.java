import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class 1609B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());

		/* int n = */Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		char[] c = br.readLine().toCharArray();
		// count the amount of "abc"s in the original string
		int cnt = abcCount(c, 0, c.length);
		// queries
		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(br.readLine());
			int index = Integer.parseInt(st.nextToken()) - 1;
			char newChar = st.nextToken().charAt(0);
			// do the replacement and see the effects on the "abc" count on the adjacent 5 characters
			int before = abcCount(c, index - 2, index + 2);
			c[index] = newChar;
			int after = abcCount(c, index - 2, index + 2);
			cnt += after - before;
			pw.println(cnt);
		}

		br.close();
		pw.close();
	}
	// counts number of abcs in a char[] from start to end
	static int abcCount(char[] c, int start, int end) {
		int cnt = 0;
		start = Math.max(start, 0);
		end = Math.min(end, c.length - 2);
		for (int i = start; i < end; i++) {
			if (c[i] == 'a') {
				if (c[i + 1] == 'b' && c[i + 2] == 'c') {
					cnt++;
				}
			}
		}
		return cnt;
	}
}
