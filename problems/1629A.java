import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 1629A {
	static class Software {
		int takes, gives;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			Software[] s = new Software[n];
			for (int j = 0; j < n; j++) {
				Software temp = new Software();
				temp.takes = Integer.parseInt(st.nextToken());
				temp.gives = Integer.parseInt(st2.nextToken());
				s[j] = temp;
			}

			Arrays.sort(s, new Comparator<Software>() {
				@Override
				public int compare(Software a, Software b) {
					return a.takes - b.takes;
				}
			});
			for (int j = 0; j < n; j++) {
				if (s[j].takes <= k) {
					k += s[j].gives;
				} else {
					break;
				}
			}
			pw.println(k);
		}

		br.close();
		pw.close();
	}
}
