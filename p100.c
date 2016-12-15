#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int a, b, tmp;

    while (scanf("%d %d", &a, &b) == 2) {
        int a_o, b_o;
        a_o = a;
        b_o = b;
        /* swap number order */
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        int idx = 0, max_idx = 0;
        int i, ans;

        int size = (b - a + 1);
        int *arr = malloc ( sizeof (int) * size);
        /* initialize array */
        for (i = 0; i < size; i++) {
            arr[i] = 0;
        }
        for (i = a; i <= b; i++) {
            int num = i;
            bool flag = false;
            ans = 1;
            while (num > 1) {
                if (num < i && num > a) {
                    flag = true;
                    ans--;
                    break;
                }
                if (num % 2 == 0) { /* even number */
                    num = num / 2;
                    ans ++;
                } else { /* odd number */
                    num = 3 * num + 1;
                    ans++;
                }
            }

            if (flag) {
                arr[idx] = arr[(num - a)] + ans;
            } else {
                arr[idx] = ans;
            }

            if (arr[idx] > arr[max_idx]) {
                max_idx = idx;
            }
            idx++;
        }
        printf("%d %d %d\n", a_o, b_o, arr[max_idx]);
    }

}
