import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ReverseAndConcatenate1634A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			String s = br.readLine();

			boolean symmetrical = true;
			for (int j = 0, l = n - 1; j < n + 1 / 2; j++, l--) {
				if (s.charAt(j) != s.charAt(l)) {
					symmetrical = false;
					break;
				}
			}
			if (symmetrical || k == 0) {
				pw.println(1);
			} else {
				pw.println(2);
			}
		}
		br.close();
		pw.close();
	}
}