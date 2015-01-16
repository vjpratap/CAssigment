#include "expr_assert.h"
#include <stdlib.h>
#include "assignment.h"

void test_should_give_0_when_numberOfTerms_is_10(){
	int n = 10;
	int *array;
	array = (int *)malloc(sizeof(int)*n);
	assertEqual(fibo(n,array),1);
	assertEqual(array[1],1);
	assertEqual(array[2],1);
	assertEqual(array[3],2);
	assertEqual(array[7],13);
}

void test_should_give_1_when_numberOfTerms_is_minus10(){
	int n = -10;
	int *array;
	array = (int *)malloc(sizeof(int)*n);

	assertEqual(fibo(n,array),0);
}

void test_check_arrays_are_concated_or_not(){
	// int size =4;
	int array1[] = {1,2,9,10};
	int array2[] = {4,5,6,7};
	int resultArray[8];
	// int *ptr1,*ptr2,*ptr3;
	int *pointToArray1 = (int *)malloc(sizeof(int)*4);
	int *pointToArray2 = (int *)malloc(sizeof(int)*4);
	int *pointToResultArray = (int *)malloc(sizeof(int)*8);
	pointToArray1 = &array1;
	pointToArray2 = &array2;
	pointToResultArray = &resultArray;
	assertEqual(concat(pointToArray1,4,pointToArray2,4,pointToResultArray), 8);
	assertEqual(resultArray[0], 1);
	assertEqual(resultArray[2], 9);
	assertEqual(resultArray[4], 4);
	assertEqual(resultArray[6], 6);
	assertEqual(resultArray[7], 7);
}

void test_checks_array_is_filtered_or_not(){
	int scores[]={100,90,80};
	int *result_array;
	int *pointToScores = (int *)malloc(sizeof(int)*3);
	pointToScores = &scores;
	assertEqual(filter(pointToScores,3,85,&result_array), 1);
	assertEqual(result_array[0], 100);
	assertEqual(result_array[1], 90);
}

void test_check_given_array_is_reversed_or_not(){
	int scores[]={100,80,90};
	int resultArray[3];
	int *pointToScores = (int *)malloc(sizeof(int)*3);
	int *pointToResultArray = (int *)malloc(sizeof(int)*3);	
	pointToScores = &scores;
	pointToResultArray = &resultArray;
	assertEqual(reverse(pointToScores,3,pointToResultArray), 3);
	assertEqual(resultArray[0], 90);
	assertEqual(resultArray[1], 80);
	assertEqual(resultArray[2], 100); 
}
/*evenAndOdd(int *array, int length, int *evenArray, int *oddArray)*/

void test_check_given_array_is_devided_in_even_and_odd_or_not(){
	int array[] = {1,2,3,4,5,6};
	int evenArray[6];
	int oddArray[6];
	int *pointToArray = (int *)malloc(sizeof(int)*6);
	int *pointToEvenArray = (int *)malloc(sizeof(int)*6);
	int *pointToOddArray = (int *)malloc(sizeof(int)*6);
	pointToArray = &array;
	pointToEvenArray = &evenArray;
	pointToOddArray = &oddArray;
	assertEqual(evenAndOdd(pointToArray,6,pointToEvenArray,pointToOddArray), 1);
	assertEqual(evenArray[0], 2);
	assertEqual(evenArray[1], 4);
	assertEqual(evenArray[2], 6);
	assertEqual(oddArray[0], 1);
	assertEqual(oddArray[1], 3);
	assertEqual(oddArray[2], 5);
}

void test_checks_given_array_is_sliced_or_not(){
	int array[] = {1,2,3,4,5,6,7,8};
	int *resultArray;
	int *pointToArray = (int *)malloc(sizeof(int)*8);
	pointToArray = &array;
	assertEqual(slice(pointToArray,8,2,5,&resultArray), 3);
	// assertEqual(resultArray)
}

void test_should_give_all_prime_number_that_is_in_the_range(){
	int *primeArray;
	assertEqual(primeNumber(1,15,&primeArray), 7);
}

void test_should_give_0_when_string_is_equal(){
	char *str1 = "hello", *str2 = "hello";
	assertEqual(strcmp(str1,str2), 0);
}

void test_should_diffrence_when_are_not_equal(){
	char *str1 = "hallooooooooooo", *str2 = "hello";
	assertEqual(strcmp(str1,str2), -4);
	assertEqual(strcmp(str2,str1), 4);
}

int print(int arrayElement, int index){
	return arrayElement + 5;
}

void test_that_function_works_as_forEach_or_not(){
	int (*fun)(int, int);
	int *array1, array[]={1,2,3,4,5};
	fun = &print;
	array1 = array;
	assertEqual(forEach(array1,5,fun), 1);	
	assertEqual((*fun)(array[0],0), 6);
}

char printChar(char arrayElement, int index){
	return arrayElement - 32;
} 

void test_that_function_works_as_forEach_for_characters(){
	char (*fun)(char, int);
	char *array1, array[]={'a','b','c','d','e'};
	fun = &printChar;
	array1 = array;
	assertEqual(forEachChar(array1,5,fun), 1);	
}

int printString(char *arrayElement, int index){
	return *arrayElement;
} 

void test_that_function_works_as_forEach_for_String(){
	int (*fun)(char *, int);
	char *array[]={"vijay","pratap","singh"};
	fun = &printString;
	// array1 = array;
	assertEqual(forEachString(array,3,fun), 1);	
}

int greaterThanTwo(int arrayElement, int index){
	return arrayElement>2;
}

void test_that_function_words_as_filter_for_integer(){
	int (*fun)(int, int);
	int *array1, array[] = {1,2,3,4,5},*filteredArray;
	fun = &greaterThanTwo;
	array1 = array;
	assertEqual(filterForInt(array1,5,&filteredArray,fun), 3);
	assertEqual(filteredArray[0],3);
	assertEqual(filteredArray[1],4);
	assertEqual(filteredArray[2],5);
}

int giveCapitalLetters(char arrayElement,int index){
	return arrayElement > 64 && arrayElement < 91;
}

void test_that_function_words_as_filter_for_character(){
	int (*fun)(char, int);
	char *array1, array[] = {'a','v','A','Y','w'},*filteredArray;
	fun = &giveCapitalLetters;
	array1 = array;
	assertEqual(filterForChar(array1,5,&filteredArray,fun), 2);
}

int giveLength5String(char *string, int i){
	int index = -1;
	while(string[++index] != '\0'){}
	return index == 5;
}

void test_that_function_words_as_filter_for_string(){
	int (*fun)(char *, int);
	char *array[] = {"vijay","vikas","singh","radhey","prashant","ankur"},*filteredArray;
	fun = &giveLength5String;
	assertEqual(filterForString(array,6,&filteredArray,fun), 4);
	// assertEqual(strcmp(filteredArray[0],"vijay"), 0);

}

int numberBetweenTwoAndThree(float arrayElement, int index){
	return arrayElement > 2 && arrayElement < 3;
}

void test_that_function_words_as_filter_for_float(){
	int (*fun)(float, int);
	float *array1, array[] = {1.4,2.2,2.4,4.6,2.3},*filteredArray;
	fun = &numberBetweenTwoAndThree;
	array1 = array;
	assertEqual(filterForFloat(array1,5,&filteredArray,fun), 3);
	assertEqual(filteredArray[0],2.2);
	assertEqual(filteredArray[1],2.4);
	assertEqual(filteredArray[2],2.3);
}






