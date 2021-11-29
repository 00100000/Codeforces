import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class DivideAndMultiply1609A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());
			int twoPowers = 0;
			int[] a = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				// find how many times a[j] is divisible by 2 before writing
				// the odd left over to a[j]
				int temp = Integer.parseInt(st.nextToken());
				while (temp % 2 == 0) {
					twoPowers++;
					temp /= 2;
				}
				a[j] = temp;
			}
			// find largest odd left in a[]
			int max = 0;
			int maxIndex = -1;
			for (int j = 0; j < n; j++) {
				if (a[j] > max) {
					max = a[j];
					maxIndex = j;
				}
			}
			// sum up odds and multiply largest odd by 2**twoPowers
			long sum = 0;
			for (int j = 0; j < n; j++) {
				if (j == maxIndex) {
					sum += a[j] * Math.pow(2, twoPowers);
				} else {
					sum += a[j];
				}
			}
			pw.println(sum);
		}
		br.close();
		pw.close();
	}
}