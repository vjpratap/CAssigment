#include "expr_assert.h"
#include "assignment.h"

int fibo(int numberOfTerms,int *numberNeeded){
	int a = -1,b = 1,i,c;
	for(i=0;i<numberOfTerms;i++){
		c = a + b;
		numberNeeded[i] = c;
		a = b;
		b = c;
	}
	if(numberNeeded[0] == 0)
		return 1;
	return 0;
}

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array){
	int lenghtOfResultArray = len_of_array1 + len_of_array2, i, j=0;
	for(i = 0; i < len_of_array1; i++){
		result_array[i] = array1[i];
	}
	for(i = len_of_array1; i < lenghtOfResultArray; i++){
		result_array[i] = array2[j];
		j = j+1;
	}
	return lenghtOfResultArray;
}

int filter(int *array, int length, int threshold, int *result_array){
	int i,j=0;
	for(i = 0; i < length; i++){
		if(array[i] > threshold){
			result_array[j] = array[i];
			j = j + 1;
		}
	}
	return j;
}

int reverse(int *array, int length, int *result_array){
	int j = 0,i;
	for(i = length - 1; i >= 0; i--){
		result_array[j] = array[i];
		j = j + 1;
	}
	return j;
}




