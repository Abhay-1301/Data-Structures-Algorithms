#include <stdio.h>

int fibonacci(int n){
    if (n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else {
        int i = fibonacci(n-1) + fibonacci(n-2);
        return i;
    }
}

int main()
{
    int n;
    int output;
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        printf("%d\n",fibonacci(i));
    } 
    return 0;
}