#include <stdio.h>

void bubble(int n, int* v){

    int i, j;

    for(i = n-1; i >= 1; i--){
        for(j = 0; j < i; j++){
            if(v[j] > v[j+1]){
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;  
            }
        } 
    }
}

void quick_sort(int n, int* v){

    if(n <= 1){
        return;
    } else {
        int x = v[0];
        int a = 1;
        int b = n-1;
        do{

            while(a < n && v[a] < x) a++;
            while(v[b] > x) b--;
            if(a < b){
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++; b--;
            }
        } while(a <= b);

        v[0] = v[b];
        v[b] = x;

        quick_sort(b,v);
        quick_sort(n-a,&v[a]);
    }
}

int main(){

    int v[8] = {4,6,8,1,7,2,9,0};
    printf("=-= [DISORDERED NUMBERS] =-=\n");
    for(int i = 0; i < 8; i++){
        printf("%d ",v[i]);
    }

    printf("\n\n=-= [SORTED NUMBERS - BUBBLE SORT] =-= \n");
    bubble(8,v);
    for(int i = 0; i < 8; i++){
        printf("%d ",v[i]);
    }

    int a[8] = {4,12,8,1,7,2,9,0};
    printf("\n\n=-= [SORTED NUMBERS - QUICK SORT] =-= \n");
    quick_sort(8,a);
    for(int i = 0; i < 8; i++){
        printf("%d ",a[i]);
    }

    return 0;
}