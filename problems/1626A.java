import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class 1626A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			String s = br.readLine();
			int[] flist = new int[26];
			for (int j = 0; j < s.length(); j++) {
				flist[s.charAt(j) - 97]++;
			}
			String ans = "";
			for (int j = 0; j < 26; j++) {
				char c = (char)(j + 97);
				if (flist[j] == 1) {
					ans = c + ans;
				} else if (flist[j] == 2) {
					ans = ans + c + c;
				}
			}
			pw.println(ans);
		}

		br.close();
		pw.close();
	}
}
