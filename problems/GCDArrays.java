import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GCDArrays1629B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());

			int odds = (r - l + 1) / 2 + (r % 2 == 1 && l % 2 == 1 ? 1 : 0);
			int evens = r - l  + 1 - odds;

			if (evens != 0 && odds != 0) {
				if (k >= odds) {
					pw.println("YES");
				} else {
					pw.println("NO");
				}
			} else {
				if (evens != 0) {
					pw.println("YES");
				} else if (l == r && r != 1 || k >= odds) {
					pw.println("YES");
				} else {
					pw.println("NO");
				}
			}
		}

		br.close();
		pw.close();
	}
}
