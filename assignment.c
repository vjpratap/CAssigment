#include <stdlib.h>
#include "expr_assert.h"
#include "assignment.h"

int fibo(int numberOfTerms,int *fibonacci){
	int a = -1,b = 1,i,c;
	for(i=0;i<numberOfTerms;i++){
		c = a + b;
		fibonacci[i] = c;
		a = b;
		b = c;
	}
	if(fibonacci[0] == 0)
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

int filter(int *array, int length, int threshold, int **result_array){
	int i,j=0,lengthOfResultArray=0;
	for(i = 0; i < length; i++){
		if(array[i] > threshold)
			lengthOfResultArray++;
	}
	*result_array = (int *)malloc(sizeof(int) * lengthOfResultArray);
	for(i = 0; i < length; i++){
		if(array[i] > threshold){
			(*result_array)[j] = array[i];
			j = j + 1;
		}
	}
	return 1;
}

int reverse(int *array, int length, int *result_array){
	int j = 0,i;
	for(i = length - 1; i >= 0; i--){
		result_array[j] = array[i];
		j = j + 1;
	}
	return j;
}

/*array that contamt integers devide it in to arrays one contant even integers and another content odd integers*/

int evenAndOdd(int *array, int length, int *evenArray, int *oddArray){
	int evenCount = 0,oddCount = 0,i;
	for(i = 0; i < length; i++){
		if(array[i] % 2== 0){
			evenArray[evenCount] = array[i];
			evenCount++;
		}
		else{
			oddArray[oddCount] = array[i];
			oddCount++;
		}
	}
	return 1;
}

int slice(int *array, int lenght, int startIndex, int endIndex, int **resultArray){
	int i,j = 0;
	*resultArray = (int *)malloc(sizeof(int)*(endIndex-startIndex));
	for(i = startIndex; i < endIndex; i++){
		(*resultArray)[j] = array[i];
		j++;
	}
	return j;
}

int checkPrime(int i){
	int primeCounter = 0,j;
	for(j = 2; j < i; j++){
		if(i % j == 0){
			primeCounter++;
			break;
		}
	}
	if(primeCounter == 1)
		return 1;
	return 0;
}

int primeNumber(int start, int end, int **primeArray){
	int i,j,primeCounter,primeArrayLength = 0,increament = 0;
	for(i = start; i <= end; i++){
		if(checkPrime(i) == 0)
			primeArrayLength++;
	}
	*primeArray = (int *)malloc(sizeof(int)*primeArrayLength);
	for(i = start; i <= end; i++){
		if(checkPrime(i) == 0){
			(*primeArray)[increament] = i;
			increament++;
		}
	}
	return primeArrayLength;
}

int strLen(char *string){
	int index = -1;
	while(string[index] == 0)
		index++;
	return index;
}

int strcmp(char *str1,char *str2){
	int l1,l2,i;
	l1 = strLen(str1);
	l2 = strlen(str2);
	l1 = (l1 > l2) ? l1 : l2;
	for (i = 0; i < l1; i++){
		if(str1[i] != str2[i]){
			return str1[i] - str2[i];
		}
	}
	return 0;
}

int forEach(int *array,int length,int (*fun)(int, int)){
	int i;
	for(i=0;i<length;i++){
		(*fun)(array[i],i);
	};
	return 1;
};

int forEachChar(char *array,int length,char (*fun)(char, int)){
	int i;
	for(i=0;i<length;i++){
		(*fun)(array[i],i);
	};
	return 1;
};

int forEachString(char **array,int length,int (*fun)(char *, int)){
	int i;
	for(i = 0; i < length; i++){
		(*fun)(array[i],i);
	}
	return 1;
}

int filterForInt(int *array, int lenght, int **resultArray,int (*fun)(int, int)){
	int i, lengthOfResultArray = 0,j = 0;
	for(i = 0; i < lenght; i++){
		if((*fun)(array[i],i) == 1)
			lengthOfResultArray++;
	}
	*resultArray = (int *)malloc(sizeof(int) * lengthOfResultArray);
	for(i = 0; i < lenght; i++){
		if((*fun)(array[i],i)){
			(*resultArray)[j] = array[i];
			j = j + 1;
		}
			
	}
	return lengthOfResultArray;
}

int filterForChar(char *array, int length, char **resultArray,int (*fun)(char, int)){
	int i, lengthOfResultArray = 0,j = 0;
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i))
			lengthOfResultArray++;
	}
	*resultArray = (char *)malloc(sizeof(char) * lengthOfResultArray);
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i)){
			(*resultArray)[j] = array[i];
			j = j + 1;
		}
			
	}
	return lengthOfResultArray;
}

int filterForString(char **array,int length,char **resultArray,int (*fun)(char *, int)){
	int i, lengthOfResultArray = 0,j = 0;
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i)){
			lengthOfResultArray++;
		}
	}
	*resultArray = (char *)malloc(sizeof(char) * lengthOfResultArray);
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i)){
			(*resultArray)[j] = array[i];
			j = j + 1;
		}
	}
	return lengthOfResultArray;
}

int filterForFloat(float *array,int length,float **resultArray,int (*fun)(float, int)){
	int i, lengthOfResultArray = 0,j = 0;
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i)){
			lengthOfResultArray++;
		}
	}
	*resultArray = (float *)malloc(sizeof(float) * lengthOfResultArray);
	for(i = 0; i < length; i++){
		if((*fun)(array[i],i)){
			(*resultArray)[j] = array[i];
			j = j + 1;
		}
	}
	return lengthOfResultArray;
}	









































