#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
struct Day  
{ 
}; 
char* dayName; 
int date; 
char* activityDescription; 

struct Day* createDay()  
{ 
struct Day* newDay = (struct Day*)malloc(sizeof(struct Day)); 

newDay->dayName = (char*)malloc(20 * sizeof(char)); 
newDay->activityDescription = (char*)malloc(100 * sizeof(char)); 
printf("Enter day name: "); 
scanf("%s", newDay->dayName); 
printf("Enter date: "); 
scanf("%d", &(newDay->date)); 
printf("Enter activity description: "); 
scanf(" %[^\n]", newDay->activityDescription); 
return newDay; 
} 

void read(struct Day* calendar[], int size) { 
for (int i = 0; i < size; i++) { 
printf("Enter details for day %d:\n", i + 1); 
calendar[i] = createDay(); 
} 
} 

void display(struct Day* calendar[], int size) { 
printf("\nWeek's Activity Details:\n"); 
for (int i = 0; i < size; i++) { 
printf("Day %d:\n", i + 1); 
printf("Day Name: %s\n", calendar[i]->dayName); 
printf("Date: %d\n", calendar[i]->date); 
printf("Activity Description: %s\n", calendar[i]->activityDescription); 
printf("\n"); 
} 
} 

void freeMemory(struct Day* calendar[], int size) { 
for (int i = 0; i < size; i++) { 
free(calendar[i]->dayName); 
free(calendar[i]->activityDescription); 
free(calendar[i]); 
} 
} 
int main()  
{ 
int weekSize = 7; 
struct Day* week[weekSize]; 
read(week, weekSize); 
display(week, weekSize); 

freeMemory(week, weekSize); 
return 0; 
}
