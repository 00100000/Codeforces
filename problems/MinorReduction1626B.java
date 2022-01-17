import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class MinorReduction1626B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			String s = br.readLine();
			String res = "";
			boolean found = false;
			for (int j = s.length() - 1; j > 0; j--) {
				int sum = s.charAt(j) - 48 + s.charAt(j - 1) - 48;
				if (sum > 9) {
					found = true;
					res = s.substring(0, j - 1) + sum + s.substring(j + 1, s.length());
					break;
				}
			}
			if (!found) {
				res = s.charAt(0) - 48 + s.charAt(1) - 48 + s.substring(2, s.length());
			}
			pw.println(res);
		}

		br.close();
		pw.close();
	}
}