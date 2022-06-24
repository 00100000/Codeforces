import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Kayaking863B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int n = Integer.parseInt(br.readLine()) * 2;

		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(w);
		// solve
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int sum = 0;
				int[] included = new int[n - 2];
				for (int k = 0, l = 0; l < n; l++) {
					if (l != i && l != j) {
						included[k] = w[l];
						k++;
					}
				}
				for (int k = 0; k < n - 3; k += 2) {
					sum += included[k + 1] - included[k];
				}
				min = Math.min(min, sum);
			}
		}

		pw.print(min);
		br.close();
		pw.close();
	}
}