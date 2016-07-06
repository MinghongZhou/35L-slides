#include <stdlib.h>
#include <stdio.h>

int frobcmp(char const *a, char const *b);
int frobHelper(const void *a, const void *b);
int main()
{
  int stdIn;
  int index = 0;
  int size = 3;
  char* block = (char*) malloc(size);

  while((stdIn = getchar()) != EOF)
    {
      block[index] =(char) stdIn;
      index++;
      if (index != size)
	continue;
      else
	{
	  block = (char*) realloc(block, size*2);
        blockcheck(block);////
	  size*=2;
	}
    }

  //  if the file is empty, exit without doing a thing
  if (index==0)
    exit(0);
   
  // if the last character is not a space, then append a space to the end of the string
  if (block[index-1]!= (int) ' ')
  {
    block[index]=(int) ' ';
      
  }

  int numOfWords = 0;
  // in order to determine how many words there are in the block, we need to count the number of spaces
  for (int i = 0 ; i <= index ;i++)
    {
      if (block[i] == (int) ' ' )
	numOfWords++;
    }

  //printf("%d", numOfWords);

  //in this step, we strive to put all the words into a new array. Each element in the array should represent a pointer to the word
  char** ptrsToWords = (char**) malloc(sizenumOfWords);//
  int counter = 0;
  char*ptrToBlock = block; // initialize the block pointer to the first spot in block

  for (int i = 1; i <= numOfWords ; i++ )
  {
    ptrsToWords[i -1] = ptrToBlock;
    while (*ptrToBlock != (int) ' ')
      {
	ptrToBlock++;
      }
    if (i <= numOfWords - 1 )
    ptrToBlock++;
    
  }

   qsort(ptrsToWords, numOfWords, sizeof(char*), frobHelper);
   
  for (int i = 0; i < numOfWords; i++ )
    {
      char *p = ptrsToWords[i];
      while (*p !=(int) ' ')
	{
	  printf("%c", *p);
	  p++;
	}
      printf("%c", *p);
    }

    free(block);
  // free(ptrsToWords);
  exit(0);  
}

int frobcmp(char const *a, char const *b)
{
  const char *one = *(const char **)a;
  const char *two = *(const char **)b;

  for (; ;one++, two++)
    {
      char char_one = *one;
      char char_two = *two;
      //Due to the fact that space do not directly participate in the comparision, therefore 
      if (char_one == ' ' && char_two == ' ')
	return 0;
      else if (char_one == ' ')
	return -1;
      else if (char_two == ' ')
	return 1; 

      // decode the characters one by one and compare these two characters at the same time. 
      if ((char_one ^ '*') > (char_two ^ '*'))
	return 1;
      else if ((char_one ^ '*') < (char_two ^ '*'))
	return -1;
      else
	continue; // continue the comparision if we can not determine which string comes first yet.
    }
      
  
}

int frobHelper(const void *a, const void *b)
{
  return frobcmp(a, b);
}

