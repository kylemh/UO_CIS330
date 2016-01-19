#include <stdbool.h>
#include <stdio.h>
#define ROW 3
#define COL 4

bool arrayEqual(int a[ROW][COL], int b[ROW][COL], int m, int n)
{
    for(int i = 0; i<m; i++){
    	for(int j = 0; j<n; j++){
    		if(a[i][j] != b[i][j]){
    			return false;
    		}		
    	}
    }
}

bool arrayEqual2(int** a2, int** b2, int m, int n)
{
    for(int i = 0; i<m; i++){
    	for(int j = 0; j<n; j++){
    		if(a2 != b2){
    			return false;
    		}		
    	}
    }
}

bool arrayEqual3(int a3[ROW][COL], int b3[ROW][COL], int m, int n, int* z)
{	
    for(int i = 0; i<m; i++){
    	for(int j = 0; j<n; j++){
    		if(a3[i][j] == b3[i][j]){
    			z = z + 1;
    		}		
    	}
    }
    if(z==0){
    	printf("%d\n", *z);
    	return true;
    } else {
    	printf("%d\n", *z);
    }
}

int main(int argc, const char * argv[])
{

    int a[ROW][COL] = {
        {0, 1, 2, 3} ,
        {4, 5, 6, 7} ,
        {8, 9, 10, 11}
    };

    int b[ROW][COL] = {
        {0, 1, 2, 3} ,
        {4, -1, 6, 7} ,
        {8, 9, 10, 11}   
    };


   bool arrayEqual(int a[ROW][COL], int b[ROW][COL], int m, int n);
   bool arrayEqual2(int** a2, int** b2, int m, int n);
   bool arrayEqual3(int a3[ROW][COL], b3[ROW][COL], int m, int n, int* z);
   return 0;
}
