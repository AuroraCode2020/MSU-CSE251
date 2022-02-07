#include <stdio.h>
#include <string.h>

/* 
 * Name : AuroraCode2020
 * Program to experiment with files
 */
 
 int main(int argc, char *argv[])
 {
    if(argc < 3)
    {
        printf("Insufficient arguments\n");
        return 1;
    }
    
    printf("Copy from file: %s\n", argv[1]);
    printf("Copy to file: %s\n", argv[2]);
 
 }
