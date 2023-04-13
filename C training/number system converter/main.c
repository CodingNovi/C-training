#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(void) {
  // long int strtol(const char *str, char **endptr, int base);
  char number[20];
  int currentSystem, desiredSystem;
  printf("Please enter a set of number:\n ");
  printf(">");
  scanf("%s", number);
  printf("Please enter the current system:\n ");
  printf(">");
  scanf ("%d",&currentSystem);
  
  int len = 0;
  int n =0;
  char* endPtr=NULL;
  long int newNum;
  
  while (number[n]!='\0'){
    len++;
    n++;
  }
  switch (currentSystem){
  
    case 2:  
    for (int i=0;i<len;i++){
      if (number[i] != '0' && number[i]!='1'){
        
        printf("Error! That set of number is not a binary number.");
        return 0;
        }
      }
    long int x = strtol(number, NULL, 2);
    newNum = x;
   
    
    break;

    case 10:{
    
    long int x = strtol(number, &endPtr, 10);
    newNum=x;
      if(*endPtr){
      printf("Error! That set of number is not a decimal number.");
      return 0;
      }
    

      break;
      }

    case 16:{
    
    long int x = strtol(number, &endPtr, 16);
    newNum=x;
      if(*endPtr){
      printf("Error! That set of number is not a hexadecimal number.");
      return 0;
      }
   
    break;  
      }
  
    default:
    printf("Error! The number system is not supported"); 
  
    }
  int forModulo = newNum;
  printf("Please enter the desired system:\n");  
  printf(">");
  scanf ("%d",&desiredSystem);
  switch (desiredSystem){
    case 2:{
      int temp[20];
      
      int index = 0;
      int x;
      while (forModulo>=1){
        x = forModulo%2;
        temp[index] = x;
        index = index + 1;
        forModulo= forModulo -x;
        forModulo= forModulo/2;

        }
      int result[index];
      int count = index-1;
      for (int z=0;z<index;z++){        
        result[z]= temp[count];
        count = count-1;
        printf("%d",result[z]);
        
      }
      
      
      break; 
      
    }
    case 10:{
      printf("Output=%ld",newNum);
      break;
    }
    case 16:{ 
      int temp[20];
      
      int index = 0;
      int x;
      while (forModulo>=1){
        x = forModulo%16;
        switch(x){
          case 10:{
            temp[index] = 65;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          case 11:{
            temp[index] = 66;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          case 12:{
            temp[index] = 67;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          case 13:{
            temp[index] = 68;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          case 14:{
            temp[index] = 69;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          case 15:{
            temp[index] = 70;
            index = index + 1;
            forModulo= forModulo -x;
            forModulo= forModulo/16;
            break;
          }
          
          default:
          temp[index] = x;
          index = index + 1;
          forModulo= forModulo -x;
          forModulo= forModulo/16;
          
        }
        
        }
      
    

      int result[index];
      int count = index-1;
      // for (int z=0;z<index;z++){        
      //   result[z]= temp[count];
      //   count = count-1;
      //   if (temp[count]>9){ 
      //   printf("%d",result[z]);
        
      // }
      
      for (int z=0;z<index;z++){
        if (temp[count]>9){
          printf("%c",temp[count]);
          count = count-1;
        }
        else{
        printf("%d",temp[count]);
        count = count-1;
          }
        
         
      }
      
      break;
    }
  }
  
  
  return 0;
}



