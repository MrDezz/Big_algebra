#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_EL 100

// Functions declaration - BEGIN

void big_sum(char *, char *, char *);
int getstrsize(char *);
void showarray(char *, int);  
int getnum(char);  
void rshiftstr(char *, int);
char getsym(int); 
void zerotoend(char *, int);
void removezerob(char *);

// Functions declaration - END


int main(void)
{

  char Str1[MAX_EL], Str2[MAX_EL];
  int diff;

  printf("Enter A = "); 
  gets(Str1);
  printf("Enter B = "); 
  gets(Str2);

  if (getstrsize(Str1) != getstrsize(Str2)) {

    diff = abs(getstrsize(Str1) - getstrsize(Str2));
    
    if (getstrsize(Str1) > getstrsize(Str2)) 
      rshiftstr(Str2, diff); 
    else
      rshiftstr(Str1, diff);
  }

  int count = 0, i, j, add_p, base_size = getstrsize(Str1);
  char Result[MAX_EL] = {0}, Result_temp[MAX_EL] = {0};

  for (i = base_size - 1; i >= 0; i-- ) {

   char Temp_res[MAX_EL] = {0};
   add_p = 0;
    
   if ( getnum(Str2[i]) != 0 ) {

    for (j = base_size - 1; j >= 0; j-- ) {
     
      if ( (getnum(Str2[i]) * getnum(Str1[j]) + add_p) >= 10 ) {
        Temp_res[j] = getsym((getnum(Str2[i]) * getnum(Str1[j]) + add_p) % 10); 
        add_p = (getnum(Str2[i]) * getnum(Str1[j]) + add_p) / 10; 
      } 
      else {
        Temp_res[j] = getsym( getnum(Str2[i]) * getnum(Str1[j]) + add_p );
        add_p = 0;
      }
    
    }

    if ( add_p != 0 ) {
      rshiftstr(Temp_res, 1);
      Temp_res[0] = getsym(add_p);
    }

    if ( count != 0 ) {
      zerotoend(Temp_res, count);
    }
            
    big_sum(Result, Temp_res, Result); 
   } 

   count++;

  }
  
  removezerob(Result);
  puts(Result);

  return 0;

}


// Additional functions - BEGIN

void big_sum(char *Str1, char *Str2, char *Sum)
{

  int diff, add_p, i; 
    
  if (getstrsize(Str1) != getstrsize(Str2)) {

    diff = abs(getstrsize(Str1) - getstrsize(Str2));
    
    if (getstrsize(Str1) > getstrsize(Str2)) 
      rshiftstr(Str2, diff); 
    else
      rshiftstr(Str1, diff);
  }

  add_p = 0;

  for (i = getstrsize(Str1) - 1; i >= 1; i--) {

    if ( (getnum(Str1[i]) + getnum(Str2[i]) + add_p) >= 10 ) {
      Sum[i] = getsym( (getnum(Str1[i]) + getnum(Str2[i]) + add_p) % 10 );
      add_p = 1; 
    }
    else {
      Sum[i] = getsym( getnum(Str1[i]) + getnum(Str2[i]) + add_p );
      add_p = 0;
    }
  } 

  if ( (getnum(Str1[0]) + getnum(Str2[0]) + add_p) >= 10 ) {
    Sum[0] = getsym( (getnum(Str1[0]) + getnum(Str2[0]) + add_p) % 10 );
    rshiftstr(Sum, 1);
    Sum[0] = '1';
  } else {
    Sum[0] = getsym( getnum(Str1[0]) + getnum(Str2[0]) + add_p );
  } 

}


int getstrsize(char *mass)
{
  int i; 

  for (i = 0; mass[i] != '\0'; i++) {
  
  }

  return i; 

}


void showarray (char *arr, int p)
{

  int i;
  char ns;
  
  switch(p) {
      case 1: ns = ' ';
              break;
      case 2: ns = '\n';
              break;
      default: 
              ns = ' ';
    }
    
  for (i = 0; (arr[i] != '\0'); i++) {

    printf("%c%c", arr[i], ns); 
   
  } 

}


int getnum(char c)
{

  int ascii_code = c;
  return ascii_code - 48;

}

char getsym(int s)
{

  char ascii_code = s + 48;
  return ascii_code;

}


void rshiftstr(char *Str, int pos)
{

  int size_ini = getstrsize(Str), i; 
  
  for (i = size_ini - 1; i >=0; i--) {
    Str[i+pos] = Str[i];
  } 

  for (i = 0; i < pos; i++) {
    Str[i] = '0';
  }

  Str[size_ini+pos] = '\0';

}


void zerotoend(char *Mass, int c)
{

  int i, m_size = getstrsize(Mass); 

  for (i = 1; i <= c; i++) {
  
    Mass[m_size - 1 + i] = '0';

  }

}


void removezerob(char *Mass)
{

  int i, m_size;

  do {
    if ( Mass[0] == '0' ) {
      m_size = getstrsize(Mass);

      for (i = 1; i < m_size; i++) {
        Mass[i-1] = Mass[i];
      }
    
    Mass[m_size-1] = '\0';

    }
  } while (Mass[0] == '0');

}


// Additional functions - END

