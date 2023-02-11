#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int a2i(char *txt) {
  int sum, digit, i;
  sum = 0;
  for (i = 0; i < strlen(txt); i++) {
    digit = txt[i] - 0x30;
    sum = (sum * 10) + digit;
  }
  return sum;
}
int main(void) {

  int numbers[100];
  char number[20];
  int num[100];
  int base = 0;
  int placeH = 0;
  int index = 0;
printf ("Enter a number to append to the number set. Enter \"\\\" to stop appending.\n");
  while (*number != 92) {
    printf(">");

    scanf("%s", number);

    // while (number!=10){
    // scanf("%c", &number);
    numbers[index] = a2i(number);
    // base++;
    //   }
    // for (int i=0;i<base;i++){
    //   placeH=placeH+(num[i])^(base-i-1);
    //     }

    // base=0;
    // numbers[index]=placeH;

    index = index + 1;
  }

  index = index - 1;
  // printf("%d\n",numbers[0]);
  // printf("%d\n",numbers[1]);
  // printf("%d\n",numbers[2]);
  // printf("%d\n",numbers[3]);



  
               // MEAN
  double sum = 0;
  int tempS;
  for (int i = 0; i < index; i++) {
    sum = sum + numbers[i];
  }
  double forAve = index;
  int temp;
  tempS = sum;

  // printf("\n%di\n",index);
  double mean = sum / forAve;
  if (tempS % index != 0) {
    printf("Mean=%.1lf", mean);
  } else if (tempS % index == 0) {
    printf("Mean=%.lf", mean);
  }

  for (int i = 0; i < index; i++) {
    sum = sum + i;
  }

  // sorting
  for (int i = 0; i < index; i++) {
    for (int g = 0; g < index; g++) {
      if (numbers[i] > numbers[g] && g > i) {
        temp = numbers[i];
        numbers[i] = numbers[g];
        numbers[g] = temp;
      }
    }
  }



           //MODE
  int mode[index];
  int curr = 0;
  int freq = 0;
  int mIndex = 0;
  int unique = 1;
  int samp = numbers[0];
  for (int i = 0; i < index; i++) {
    if (samp != numbers[i]) {
      samp = numbers[i];
      unique = unique + 1;
    }
  }
  // printf("\n%d",unique);
  for (int i = 0; i < index; i++) {
    freq = 0;
    for (int g = 0; g < index; g++) {
      if (numbers[i] == numbers[g]) {
        freq = freq + 1;
      }
      if (freq >= curr) {
        curr = freq;
      }
    }
  }
  // printf("\n%d",freq);
  // printf("\n%d",curr);
  for (int i = 0; i < index; i++) {
    freq = 0;
    for (int g = 0; g < index; g++) {
      if (numbers[i] == numbers[g]) {
        freq = freq + 1;
      }
    }

    if (freq == curr) {
      mode[mIndex] = numbers[i];
      mIndex = mIndex + 1;
      i = i + freq - 1;
    }
  }

  if (mIndex == unique) {
    printf("\nMode=No mode");
  } else {
    for (int i = 0; i < mIndex; i++) {
      printf("\nMode=%d", mode[i]);
    }
  }










  
                    // MEDIAN

  double median;
  if (index % 2 != 0) {
    median = (numbers[(index / 2)]);
    printf("\nMedian=%.0lf", median);

  } else {
    median =((double)numbers[index / 2] + (double)numbers[(index - 1) / 2]) / 2;
    tempS=(double)numbers[index / 2] + (double)numbers[(index - 1) / 2];
    if(tempS%2==0){
       printf("\nMedian=%.lf", median);
    }
    else{
    printf("\nMedian=%.1lf", median);
      }
    }

  // for (int z=0;z<index;z++){
  //    printf("  \n%d",numbers[z]);
  // }



  return 0;
}