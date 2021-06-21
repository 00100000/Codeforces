import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
class A {
	public static void main (String[]args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
 
		for (int i = 0; i < t; i++) {
			// get n and the total of all values in a
			int n = Integer.parseInt(br.readLine());
			int total = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				total+= Integer.parseInt(st.nextToken());
			}
			// math stuff woohoo
			if (total / n >= 1) {
				System.out.println(total - n);
			} else {
				System.out.println(1);
			}
		}
	}
}