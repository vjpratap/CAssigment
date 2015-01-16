#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,tearDown,fixtureSetup,fixtureTearDown,test_should_give_0_when_numberOfTerms_is_10,test_should_give_1_when_numberOfTerms_is_minus10,test_check_arrays_are_concated_or_not,test_checks_array_is_filtered_or_not,test_check_given_array_is_reversed_or_not,test_check_given_array_is_devided_in_even_and_odd_or_not,test_checks_given_array_is_sliced_or_not,test_should_give_all_prime_number_that_is_in_the_range,test_should_give_0_when_string_is_equal,test_should_diffrence_when_are_not_equal,test_that_function_works_as_forEach_or_not,test_that_function_works_as_forEach_for_characters,test_that_function_works_as_forEach_for_String,test_that_function_words_as_filter_for_integer,test_that_function_words_as_filter_for_character,test_that_function_words_as_filter_for_string,test_that_function_words_as_filter_for_float;
Test test[] = {"test_should_give_0_when_numberOfTerms_is_10",test_should_give_0_when_numberOfTerms_is_10,"test_should_give_1_when_numberOfTerms_is_minus10",test_should_give_1_when_numberOfTerms_is_minus10,"test_check_arrays_are_concated_or_not",test_check_arrays_are_concated_or_not,"test_checks_array_is_filtered_or_not",test_checks_array_is_filtered_or_not,"test_check_given_array_is_reversed_or_not",test_check_given_array_is_reversed_or_not,"test_check_given_array_is_devided_in_even_and_odd_or_not",test_check_given_array_is_devided_in_even_and_odd_or_not,"test_checks_given_array_is_sliced_or_not",test_checks_given_array_is_sliced_or_not,"test_should_give_all_prime_number_that_is_in_the_range",test_should_give_all_prime_number_that_is_in_the_range,"test_should_give_0_when_string_is_equal",test_should_give_0_when_string_is_equal,"test_should_diffrence_when_are_not_equal",test_should_diffrence_when_are_not_equal,"test_that_function_works_as_forEach_or_not",test_that_function_works_as_forEach_or_not,"test_that_function_works_as_forEach_for_characters",test_that_function_works_as_forEach_for_characters,"test_that_function_works_as_forEach_for_String",test_that_function_works_as_forEach_for_String,"test_that_function_words_as_filter_for_integer",test_that_function_words_as_filter_for_integer,"test_that_function_words_as_filter_for_character",test_that_function_words_as_filter_for_character,"test_that_function_words_as_filter_for_string",test_that_function_words_as_filter_for_string,"test_that_function_words_as_filter_for_float",test_that_function_words_as_filter_for_float};
char testFileName[] = {"assignmentTest.c"};
void _setup(){/*CALL_SETUP*/}
void _tearDown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("\t%s\n",name);
	_setup();
		test();
	_tearDown();
	if(!currentTestFailed) passCount++;	
}

int main(){
	int i,total = sizeof(test)/sizeof(Test);
	fixtureSetup();
	testCount=0,passCount=0;
	printf("********* Starting tests of %s\n\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();
	return 0;
}