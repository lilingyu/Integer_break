#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int integerBreak(int n) {
#if 0

#define max(a,b) (((a)>(b))?(a):(b))

    //leetcode doesn't support assert
    //assert(n>=2);

    if(2 == n){
        return 1;
    }

    int result=0;

    int half1 = n/2 + 2;

    int* arr = (int*)malloc((n+1)*sizeof(*arr));
    //assert(0 != arr);


    int i=1;

    for(i=0; i<=n; i++){
        arr[i]=0;
    }


    arr[1]=1;
    arr[2]=1;

    for(i=3; i<=n; i++){
        int j=1;
        for(j=1; j<=i/2; j++){
            int tmp = max(j,arr[j])*max(i-j, arr[i-j]);
            arr[i] = max(tmp, arr[i]);
        }

    }

    result = arr[n];

    free(arr);

    return result;
#else
    if(n<=2)
        return 1;
    else if(n==3)
        return 2;
    else if(n==4)
        return 4;

    int re = 4;
    int i=5;
    for(i=5;i<=n;i++){
        if(re%2==0)
            re*=1.5;
        else
            re = re*4/3;
    }
    return re;
#endif
}

int main()
{
    int n=0;
    int result = 0;
    while(1){
        printf("\n\n\npls input n:");
        scanf("%d", &n);
        printf("\nThe input is %d\n", n);

        if(n<=2){
            printf("n is less than 2! exit\n");
            return 0;
        }

        result = integerBreak(n);

        printf("The result is: %d\n", result);


    }
    return 0;
}
