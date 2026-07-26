#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


char * reverse(const char *c){

  int len = strlen(c) + 1;

  char *result = (char*)malloc(len);

  char *begin = result;

  result[len-1] = '\0';

  int right = len-2;
  int left = 0;
  while(right >= 0){
    *result = c[right];
    right--;
    result++;
  }
  
  return begin;
  
}

void string_iterate(char *string){
  
  while(*string != '\0'){
    putchar(*string);
    string++;
  }

}

int int_to_string(int integer){

  char *result = (char*)malloc(12);

  char *begin = result;

  int tmp = integer;

  if(integer == 0){
    putchar('0');
    free(result);
    return 0;
  }

  while(tmp != 0){

    int curr = tmp % 10;
    
    *result = '0' + curr;

    tmp = tmp / 10;

    result++;
  
  }

  *result = '\0';

  char * reversed = reverse(begin);
  
  char *remember = reversed;

  string_iterate(reversed);

  free(begin);
  free(remember);

  return 0;

}

int dec_to_hex(unsigned int dec, char flag){

  char *result = (char*)malloc(11);
  
  char *begin = result;
  
  char *values_upper = "0123456789ABCDEF";

  char *values_lower = "0123456789abcdef";

  unsigned int tmp = dec;

  while(tmp != 0){

    int rest = tmp % 16;

    if (flag == 'X'){
      *result = values_upper[rest];
    }else{
      *result = values_lower[rest];
    }
    
    result++;
    
    tmp = tmp / 16;
  }

  *result = '\0';

  char *reversed = reverse(begin);

  char *remember = reversed;

  string_iterate(reversed);

  free(begin);
  free(remember);

  return 0;

}

int dec_to_oct(unsigned int oct){
  

  char *result = (char*)malloc(23);

  char *begin = result;
  

  unsigned int tmp = oct;

  while (tmp != 0){
    int mod = tmp % 8;
    
    *result = '0' + mod;

    tmp = tmp / 8;
    
    result++;
  }

  *result = '\0';

  char *reversed = reverse(begin);

  char *rev_begin = reversed;

  string_iterate(reversed);

  free(begin);
  free(rev_begin);
    
  return 0;
    
}


void myprintf(const char* string, ...){

  va_list args;

  va_start(args, string);

  int len = strlen(string);

  for(int i = 0;i < len; i++ ){

    if(string[i] == '%' && i < len){
      
      switch(string[i+1]){
        case 'd':{
          int param = va_arg(args,int);
          int_to_string(param);
          break;
        }
        case 'f':{
          putchar(va_arg(args,double));
          break;
        case 'i':{
          int param = va_arg(args,int);
          int_to_string(param);
          break;
        }
        case 's':{
          string_iterate(va_arg(args, char*));
          break;
        }
        case 'x':{
          int param = va_arg(args, int);
          dec_to_hex(param, 'x');
          break;
        }
        case 'X':{
          int param = va_arg(args, int);
          dec_to_hex(param, 'X');
          break;
        }
        case 'o':{
          int param = va_arg(args, int);
          dec_to_oct(param);
          break;
        }
        case '%':{
          putchar('%');
          break;
        }
        case 'c':{
          int character_to_change = va_arg(args,int);
          putchar((char) character_to_change);
          break;
        }
        default:
          break;
        }
      }
      i = i+1;
      continue;
    
    }


    putchar(string[i]);

  }

  va_end(args);
  

}


int main(){
  
  myprintf("hello im %s, im %x years old, octal number %o, random character %c","maciek", 0x12, 0103,'X');
}
