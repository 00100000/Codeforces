import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HonestCoach1360B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());

			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] flist = new int[1001];
			for (int j = 0; j < n; j++) {
				flist[Integer.parseInt(st.nextToken())]++;
			}
			int minSpace = Integer.MAX_VALUE;
			int space = 1001;
			for (int j = 0; j < 1001; j++) {
				if (flist[j] == 0) {
					space++;
				} else if (flist[j] > 1) {
					minSpace = 0;
					break;
				} else {
					minSpace = Math.min(minSpace, space);
					space = 1;
				}
			}
			pw.println(minSpace);
		}

		br.close();
		pw.close();
	}
}