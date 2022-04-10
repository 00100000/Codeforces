import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SortingParts1637A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		testCases:
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());

			StringTokenizer st = new StringTokenizer(br.readLine());
			int last = Integer.parseInt(st.nextToken());
			for (int j = 0; j < n - 1; j++) {
				int current = Integer.parseInt(st.nextToken());
				if (last > current) {
					pw.println("YES");
					continue testCases;
				}
				last = current;
			}
			pw.println("NO");
		}
		br.close();
		pw.close();
	}
}