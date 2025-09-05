#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
 
#define SIZE 50


  struct Student {
         char name[50];
         int age;
         float grade;
     };



 void add_student( struct Student *students, int size );
 void print_student( struct Student *students, int size ); 
 void find_student( struct Student *students, int size, const char* f_st_name ); 
 void find_highest_grade( struct Student *students, int size ); 


int main() 
{ 
		
	struct Student *students = (struct Student*)malloc( SIZE * sizeof(struct Student)); 
		if ( students == NULL )  { 
			printf(" Memory allocation failed.\n");
			return 1; 	} 

	printf(" Enter the studets data. \n" ); 

 add_student( students, SIZE ); 

 printf("\n");
 printf("These are the entered students' data.\n");
 printf("\n");
 print_student( students, SIZE ); 

 printf("\n");
 char f_st_name[50]; 
 printf(" Search student: \n "); 
 scanf("%s", f_st_name);
 
 printf("\n");
 find_student( students, SIZE, f_st_name ); 
 
 printf("\n");
 printf(" Student data with the highest grade. \n"); 
 printf("\n");
 find_highest_grade( students, SIZE ); 

 free( students );
 students = NULL;

 return 0; 
 } 






void add_student( struct Student *students, int size )
{	 
		char ch[50];
		printf(" To finish, enter 'x' \n");

	for ( int i = 0; i < SIZE; i++ ) 
	{ 	printf(" STUDENT %d \n", i + 1 ); 
		printf("NAME: "); 
		scanf("%s", ch ); 

	 if ( strcmp(ch, "x") == 0 ) 
	{   printf(" Data entry finished. \n");
		 return;		} 

	strcpy( students[i].name, ch ); 


		printf("AGE: "); 
		scanf("%d", &students[i].age ); 
		printf("GRADE: "); 
		scanf("%f", &students[i].grade); 

	if ( strcmp(ch, "x") == 0 ) return;

	} 
	printf(" Data entry finished. \n");

 return; 
 } 


void print_student( struct Student *students, int size )
 {
		int i;
	for (  i = 0; i < SIZE; i++ ) 
	{	
		if ( *students[i].name == '\0') return;

		printf(" NAME: %s \n", students[i].name); 
		printf(" AGE: %d \n", students[i].age); 
		printf(" GRADE: %.2f \n", students[i].grade ); 	
		printf("\n");


	}
 return; 
 } 


void find_student( struct Student *students, int size, const char *f_st_name ) 
 { 	
	for ( int i = 0; i < SIZE; i++ ) 
	{	if ( strcmp( students[i].name, f_st_name ) == 0 ) 
		{ 	printf(" NAME: %s \n", students[i].name ); 
			printf(" AGE: %d \n", students[i].age ); 
			printf(" GRADE: %.2f \n", students[i].grade ); 
				return; 	} 
	}		
	 	printf("Student data not found. \n");	
				return;	
 
 } 



void find_highest_grade( struct Student *students, int size ) 
 {	
		int max = 0;  
	for( int  i = 1; i < SIZE; i++ ) 
	{
		if ( students[i].grade > students[max].grade ) {
				max = i; 		} 
	     
	}
		float max_grade = students[max].grade; 

	for ( int i = 0; i < SIZE; i++ )
 { 	  if( students[i].grade == max_grade )  { 
		printf(" NAME: %s \n", students[i].name); 
		printf(" AGE: %d \n", students[i].age); 
		printf(" GRADE: %.2f \n", students[i].grade); 
 		printf("\n"); 
	}
 } 
return; 

 } 





		
