//PGM TO DEMONSTRATE THE WORKING OF UNION
#include<stdio.h>
#include<conio.h>


union marks        
    {
    float perc;   
    char grade;    
    };

void main ( )
   {
    union marks student1;  
    clrscr();
    student1.perc = 98.5;    
    printf( “Marks are %f   address is  %p\n”, student1.perc, &student1.perc);   
    student1.grade = ‘A’;       
    printf( “Grade is  %c  address is  %p\n”, student1.grade, &student1.grade);  
   }
