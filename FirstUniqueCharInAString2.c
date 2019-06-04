#include <stdio.h>
#include <stdlib.h>
#define NO_OF_CHARS 256

struct count{
  int count;
  int index;
};

/* Returns an array of above structure type. The size of 
   array is NO_OF_CHARS */
struct count* getCount(char *str){
  int i;
  struct count* count = (struct count*)calloc(sizeof(count), NO_OF_CHARS);
  for(i=0; *(str+i); i++){
    (count[*(str+i)].count)++;
    
    // If it's first occurrence, then store the index 
    if (count[*(str+i)].count == 1)
      count[*(str+i)].index = i;
  }
  return count;
}

/* The function returns index of the first non-repeating 
    character in a string. If all characters are repeating 
    then returns -1 */
int uniqueChar(char *str){
  struct count *count = getCount(str);
  int result = -1, i;
  
  for(i=0; *(str+i); i++){
    // If this character occurs only once and appears 
    // before the current result, then update the result
    if(count[*(str+i)].count == 1 && result < count[*(str+i)].index){
      result = count[*(str+i)].index;
      break;
    }
  }
  free(count);
  return result;
}


int main(int argc, char const *argv[]) {
  char *str = "geeksforgeeks";
  int index = uniqueChar(str);
  if(index == -1)
    printf("Either all the characters are repeating or string is NULL\n");
  else
    printf("The first unique char is %c\n", str[index]);
  return 0;
}
