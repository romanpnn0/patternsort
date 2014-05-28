#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

void printMatrix(int[][12], const int);

using namespace std;

int main()
{
    const int SIZE = 12;
    int matrix[SIZE][SIZE];
    int temp;
    srand(time(NULL));
   /**
Zapolniaem massiv sluchainim obrazom
*/
   	
   	for(int i = 0; i < SIZE; i++)
      	for(int j = 0; j < SIZE; j++)
        	 matrix[i][j] = 1 + rand() % 1000;
         /**
sortiruem
*/
   	
   	for(int N = 1; N < SIZE * SIZE; N++)
	{
       for(int i = 0; i < SIZE; i++)
       {
       		for(int j = 0; j < SIZE - 1; j++)
       		{
       			if(matrix[i][j + 1] < matrix[i][j])
       			{
                   temp = matrix[i][j + 1];
                   matrix[i][j + 1] = matrix[i][j];
                   matrix[i][j] = temp;
               	}
 			}
            
            
			/**
sravnivaem posledniy element stroki
s pervim elementom sleduushiy
*/
            if(matrix[i + 1][0] < matrix[i][SIZE - 1])
           	{
                temp = matrix[i + 1][0];
                matrix[i + 1][0] = matrix[i][SIZE - 1];
                matrix[i][SIZE - 1] = temp;
        	}
		}
   	}
   
	printMatrix(matrix, SIZE);
    
	return 0;
}

//print massiv
void printMatrix(int mx[][12], const int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
    	cout << endl;
        
    	for(int j = 0; j < SIZE; j++)
    		cout << setw(4) << mx[i][j];
            
    	cout << endl;
    }
}