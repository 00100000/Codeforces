import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class 831C {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] sum = new int[k];
		int last = 0;
		for (int i = 0; i < k; i++) {
			sum[i] = Integer.parseInt(st.nextToken()) + last;
			last = sum[i];
		}

		st = new StringTokenizer(br.readLine());
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = Integer.parseInt(st.nextToken());
		}
		// track all possible initial scores
		HashSet<Integer> initialScore = new HashSet<Integer>(0);
		for (int i = 0; i < k; i++) {
			initialScore.add(b[0] - sum[i]);
		}

		int cnt = 0;
		for (Iterator<Integer> i = initialScore.iterator(); i.hasNext();) {
			// store values of if next was the initial score
			int next = i.next();
			HashMap<Integer, Integer> sumMap = new HashMap<Integer, Integer>(0);
			for (int j = 0; j < k; j++) {
				if (sumMap.containsKey(next + sum[j])) {
					sumMap.put(next + sum[j], sumMap.get(next + sum[j]) + 1);
				} else {
					sumMap.put(next + sum[j], 1);
				}
			}
			boolean valid = true;
			for (int j = 0; j < n; j++) {
				if (sumMap.containsKey(b[j])) {
					sumMap.put(b[j], sumMap.get(b[j]) - 1);
				} else {
					valid = false;
					break;
				}
			}
			if (valid) cnt++;
		}

		pw.print(cnt);
		br.close();
		pw.close();
	}
}
