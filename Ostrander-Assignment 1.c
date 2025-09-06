#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


int main(){
    char result[65];
    int tot = 0;
    int correct = 0;

    uint32_t div_test_n[] = {
    104,156,255,255,255,42,     // basic
    0,0,0,0,1,1,1,              // edge
    8,16,64,256,                // powers
    4294967295,4294967295,4294967295,4294967295, // large
    42,42,42,42,                // mixed
    7,15,31,                    // small compare
    1000,1000,1000,             // medium compare
    2147483647,1073741824,268435456, // stress
    4294967294,4294967294,      // boundary
    4,7,15,                     // single digit
    25,124,171,3405774592       // special
};

int div_test_base[] = {
    5,8,16,10,2,2,
    2,8,10,16,2,8,16,
    2,2,8,16,
    2,8,10,16,
    5,8,10,16,
    2,8,16,
    2,8,16,
    2,8,16,
    10,16,
    5,8,16,
    5,5,16,16
};

char *div_test_out[] = {
    "404","234","FF","255","11111111","101010",
    "0","0","0","0","1","1","1",
    "1000","10000","100","100",
    "11111111111111111111111111111111","37777777777","4294967295","FFFFFFFF",
    "132","52","42","2A",
    "111","17","1F",
    "1111101000","1750","3E8",
    "1111111111111111111111111111111","10000000000","10000000",
    "4294967294","FFFFFFFE",
    "4","7","F",
    "100","444","AB","CAFFFF00"
};


    printf("\n================ DIV TESTS ================\n");
    int num_tests = sizeof(div_test_base) / sizeof(div_test_base[0]);
    for(int i = 0; i<num_tests; i++){
        div_convert(div_test_n[i],div_test_base[i],result);
        if(strcmp(div_test_out[i],result)==0){
            printf("Test %i: div_convert(%u, %i) -> Expected: '%s', Got: '%s' [PASS]\n",i,div_test_n[i],div_test_base[i],div_test_out[i],result);
            tot++;
            correct++;
        }else{
            printf("Test %i: div_convert(%u, %i) -> Expected: '%s', Got: '%s' [FAIL]\n",i,div_test_n[i],div_test_base[i],div_test_out[i],result);
            tot++;
        }
    }

    uint32_t sub_test_n[] = {
    104,156,255,255,255,42,
    0,0,0,0,1,1,1,
    8,16,64,256,
    4294967295,4294967295,4294967295,4294967295,
    42,42,42,42,
    7,15,31,
    1000,1000,1000,
    2147483647,1073741824,268435456,
    4294967294,4294967294,
    4,7,15,
    25,124,171,3405774592
};

int sub_test_base[] = {
    5,8,16,10,2,2,
    2,8,10,16,2,8,16,
    2,2,8,16,
    2,8,10,16,
    5,8,10,16,
    2,8,16,
    2,8,16,
    2,8,16,
    10,16,
    5,8,16,
    5,5,16,16
};

char *sub_test_out[] = {
    "404","234","FF","255","11111111","101010",
    "0","0","0","0","1","1","1",
    "1000","10000","100","100",
    "11111111111111111111111111111111","37777777777","4294967295","FFFFFFFF",
    "132","52","42","2A",
    "111","17","1F",
    "1111101000","1750","3E8",
    "1111111111111111111111111111111","10000000000","10000000",
    "4294967294","FFFFFFFE",
    "4","7","F",
    "100","444","AB","CAFFFF00"
};

    printf("\n================ SUB TESTS ================\n");
    num_tests = sizeof(sub_test_base) / sizeof(sub_test_base[0]);
    for(int i = 0; i<num_tests; i++){
        sub_convert(sub_test_n[i],sub_test_base[i],result);
        if(strcmp(sub_test_out[i],result)==0){
            printf("Test %i: sub_convert(%u, %i) -> Expected: '%s', Got: '%s' [PASS]\n",i,sub_test_n[i],sub_test_base[i],sub_test_out[i],result);
            tot++;
            correct++;
        }else{
            printf("Test %i: sub_convert(%u, %i) -> Expected: '%s', Got: '%s' [FAIL]\n",i,sub_test_n[i],sub_test_base[i],sub_test_out[i],result);
            tot++;
        }
    }

    printf("\n================ PRINT TABLES TESTS ================\n");
    uint32_t print_tables_inputs[] = {5,0,1,7,15,8,16,32,255,256,511,1000,65535,4294967295};
    num_tests = sizeof(print_tables_inputs) / sizeof(print_tables_inputs[0]);
    for (int i = 0; i<num_tests;i++){
        print_tables(print_tables_inputs[i]);
    }
    
    printf("\n================ SUMMARY ================\n");
    printf("Summary: %i/%i tests passed",correct,tot);

}

