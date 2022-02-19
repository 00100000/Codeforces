import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MEXAndArray1637B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());

			int[] zeros = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			zeros[0] = Integer.parseInt(st.nextToken()) == 0 ? 1 : 0;
			for (int j = 1; j < n; j++) {
				zeros[j] = zeros[j - 1] + (Integer.parseInt(st.nextToken()) == 0 ? 1 : 0);
			}
			// all subsegments
			int sum = 0;
			for (int j = 0; j < n; j++) {
				for (int k = j; k < n; k++) {
					// best partition is all elements alone
					// A zero adds +1 because the MEX is 1 and all other MEXes are 0
					sum += k - j + 1;
					sum += zeros[k];
					if (j > 0) {
						sum -= zeros[j - 1];
					}
				}
			}
			pw.println(sum);
		}

		br.close();
		pw.close();
	}
}