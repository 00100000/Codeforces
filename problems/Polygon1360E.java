import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class Polygon1360E {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());
			boolean[][] p = new boolean[n][n];
			for (int j = 0; j < n; j++) {
				String s = br.readLine();
				for (int k = 0; k < n; k++) {
					p[j][k] = s.charAt(k) == 49;
				}
			}
			boolean valid = true;
			solve:
			for (int j = 0; j < n - 1; j++) {
				for (int k = 0; k < n - 1; k++) {
					if (p[j][k]) {
						if (!p[j + 1][k] && !p[j][k + 1]) {
							valid = false;
							break solve;
						}
					}
				}
			}
			if (valid) {
				pw.println("YES");
			} else {
				pw.println("NO");
			}
		}

		br.close();
		pw.close();
	}
}