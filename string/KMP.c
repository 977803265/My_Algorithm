#include <stdio.h>
#include <string.h>
void 
construct_table(char P[], char T[], int len) {
	int k, q;
	for (k = 0, q = 1; q < len; ) {
		if (P[q] == P[k]) {
			k = k + 1;
			T[q] = k;
			q = q + 1;
		}
		else if (k > 0) {
			k = T[k-1];
		}
		else {
			T[q] = 0;
			q = q + 1;
		}
	}
}

int 
KMP(char S[], int s_len, char P[], int p_len) {
	int i, m;
	char T[p_len];
	construct_table(P, T, p_len);
	for (i = 0; i < p_len; i++) {
		printf("%d ", T[i]);
	}
	printf("\n");
	for (i = 0, m = 0; m + i < s_len; ) {
		if (P[i] == S[m+i]) {
			i = i + 1;
			// find it!
			if (i == p_len) {
				return m; 
			}
		}
		else { // not match
			if (i && T[i-1] > 0) {
				m = m + i - T[i-1];
				i = T[i-1];
				printf("\nm:%d, i:%d", m, i);
			}
			else {
				m = m + i + 1;
				i = 0;
			}
		}
	}
	return 0;
}
int main(int argc, char** argv) {
	char S[] = "ABC ABCDAB ABCDABCDABDE";
	char P[] = "ABCDABD";
	int i = KMP(S, strlen(S), P, strlen(P));
	printf("\n%d\n", i);
}
