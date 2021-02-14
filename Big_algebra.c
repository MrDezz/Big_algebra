#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_EL 100

// Functions declaration - BEGIN

void big_sum(char *, char *, char *);
void big_subs(char *, char *, char *);
void big_prod(char *, char *, char *);

void big_sum_simple(char *, char *, char *);
void big_substract_simple(char *, char *, char *);
void big_prod_simple(char *, char *, char *);
int getstrsize(char *);
void showarray(char *, int);  
int getnum(char);  
void rshiftstr(char *, int);
char getsym(int); 
void zerotoend(char *, int);
void removezerob(char *);
void addsign(char *); 
char comparison(char *, char *);
void copyStr(char *, char *);
void make_inversion(char *, char *); 
void big_abs(char *, char *);

// Functions declaration - END


int main(void)
{

  char Str1[MAX_EL], Str2[MAX_EL], Result[MAX_EL] = {0}, Result1[MAX_EL] = {0}, Result2[MAX_EL] = {0};
  
  printf("Enter A = "); 
  gets(Str1);
  
  printf("Enter B = "); 
  gets(Str2);

  big_prod(Str1, Str2, Result);
  printf("A * B = ");
  puts(Result);
  
  big_sum(Str1, Str2, Result1);
  printf("A + B = ");
  puts(Result1);

  big_subs(Str1, Str2, Result2);
  printf("A - B = ");
  puts(Result2);

  return 0;

}


// Additional functions - BEGIN

void big_sum(char *Str1, char *Str2, char *Result)
{

  addsign(Str1);
  addsign(Str2);

  char absStr1[MAX_EL] = {0}, absStr2[MAX_EL] = {0}, zero = '0';
  char *_zero = &zero;
    
  big_abs(Str1, absStr1);
  big_abs(Str2, absStr2);

  if ( ( (comparison(Str1, _zero) == '>') && (comparison(Str2, _zero) == '>') ) || ( (comparison(Str1, _zero) == '<') && (comparison(Str2, _zero) == '<') ) ) {

    big_sum_simple(absStr1, absStr2, Result);

    if ( Str1[0] == '+' )
      Result[0] = '+';
    else
      Result[0] = '-';

  }
  else if ( comparison(absStr1, absStr2) == '>' ) {
    
    big_substract_simple(absStr1, absStr2, Result);
    
    if ( Str1[0] == '+' )
      Result[0] = '+';
    else 
      Result[0] = '-';    

  }
  else if ( comparison(absStr1, absStr2) == '<' ) {
    
    big_substract_simple(absStr2, absStr1, Result);

    if ( Str2[0] == '+' )
      Result[0] = '+';
    else 
      Result[0] = '-';    

  } 

}


void big_subs(char *Str1, char *Str2, char *Result)
{

  addsign(Str1);
  addsign(Str2);

  char invStr2[MAX_EL] = {0}, absStr1[MAX_EL] = {0}, absinvStr2[MAX_EL] = {0}, zero = '0';
  char *_zero = &zero;
  
  make_inversion(Str2, invStr2); 
  
  big_abs(Str1, absStr1);
  big_abs(invStr2, absinvStr2);

  if ( ( (comparison(Str1, _zero) == '>') && (comparison(invStr2, _zero) == '>') ) || ( (comparison(Str1, _zero) == '<') && (comparison(invStr2, _zero) == '<') ) ) {

    big_sum_simple(absStr1, absinvStr2, Result);

    if ( Str1[0] == '+' )
      Result[0] = '+';
    else
      Result[0] = '-';

  }
  else if ( comparison(absStr1, absinvStr2) == '>' ) {
    
    big_substract_simple(absStr1, absinvStr2, Result);
    
    if ( Str1[0] == '+' )
      Result[0] = '+';
    else 
      Result[0] = '-';    

  }
  else if ( comparison(absStr1, absinvStr2) == '<' ) {
    
    big_substract_simple(absinvStr2, absStr1, Result);

    if ( invStr2[0] == '+' )
      Result[0] = '+';
    else 
      Result[0] = '-';    

  } 

}


void big_prod(char *Str1, char *Str2, char *Result)
{

  addsign(Str1);
  addsign(Str2);

  char absStr1[MAX_EL] = {0}, absStr2[MAX_EL] = {0}, zero = '0';
  char *_zero = &zero;

  big_abs(Str1, absStr1);
  big_abs(Str2, absStr2);

  if ( ( (comparison(Str1, _zero) == '>') && (comparison(Str2, _zero) == '>') ) || ( (comparison(Str1, _zero) == '<') && (comparison(Str2, _zero) == '<') ) ) 
    big_prod_simple(absStr1, absStr2, Result);
  else {
    big_prod_simple(absStr1, absStr2, Result);
    Result[0] = '-';
  }

}


void big_sum_simple(char *Str1, char *Str2, char *Sum)
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

  for (i = getstrsize(Str1) - 1; i >= 2; i--) {

    if ( (getnum(Str1[i]) + getnum(Str2[i]) + add_p) >= 10 ) {
      Sum[i] = getsym( (getnum(Str1[i]) + getnum(Str2[i]) + add_p) % 10 );
      add_p = 1; 
    }
    else {
      Sum[i] = getsym( getnum(Str1[i]) + getnum(Str2[i]) + add_p );
      add_p = 0;
    }
  } 

  if ( (getnum(Str1[1]) + getnum(Str2[1]) + add_p) >= 10 ) {
    Sum[1] = getsym( (getnum(Str1[1]) + getnum(Str2[1]) + add_p) % 10 );
    Sum[0] = '+';
    rshiftstr(Sum, 1);
    Sum[1] = '1';
  } else {
    Sum[1] = getsym( getnum(Str1[1]) + getnum(Str2[1]) + add_p );
    Sum[0] = '+';
  } 

}


void big_substract_simple(char *Str1, char *Str2, char *Result)
{

  int diff; 
  
  if (getstrsize(Str1) != getstrsize(Str2)) {

    diff = abs(getstrsize(Str1) - getstrsize(Str2));
    
    if (getstrsize(Str1) > getstrsize(Str2)) 
      rshiftstr(Str2, diff); 
    else
      rshiftstr(Str1, diff);
  }

  int i, base_size = getstrsize(Str1);
  char duplStr1[MAX_EL] = {0};

  copyStr(Str1, duplStr1);
  
  for ( i = base_size - 1; i >= 1; i-- ) {

    if ( getnum(duplStr1[i]) - getnum(Str2[i]) >= 0 ) {
      Result[i] = getsym( getnum(duplStr1[i]) - getnum(Str2[i]) );      
    }
    else {

      int j = i - 1, stopLoop = 0;

      do {
        if ( duplStr1[j] != 0 ) {
          Result[i] = getsym( (getnum(duplStr1[i]) + 10) - getnum(Str2[i]) );
          duplStr1[j] = getsym( getnum(duplStr1[j]) - 1 );
          stopLoop = 1;
        }
        else 
          duplStr1[j] = '9';          

        j--;

      } while ( stopLoop != 1 );

    }

  }

  Result[0] = '+';
  
  removezerob(Result);

}


void big_prod_simple(char *Str1, char *Str2, char *Result)
{

  int diff;

  if (getstrsize(Str1) != getstrsize(Str2)) {

    diff = abs(getstrsize(Str1) - getstrsize(Str2));
    
    if (getstrsize(Str1) > getstrsize(Str2)) 
      rshiftstr(Str2, diff); 
    else
      rshiftstr(Str1, diff);
  }

  int count = 0, i, j, add_p, base_size = getstrsize(Str1);
  
  for (i = base_size - 1; i >= 1; i-- ) {

   char Temp_res[MAX_EL] = {0};
   add_p = 0;
    
   if ( getnum(Str2[i]) != 0 ) {

    for (j = base_size - 1; j >= 1; j-- ) {
     
      if ( (getnum(Str2[i]) * getnum(Str1[j]) + add_p) >= 10 ) {
        Temp_res[j] = getsym((getnum(Str2[i]) * getnum(Str1[j]) + add_p) % 10); 
        add_p = (getnum(Str2[i]) * getnum(Str1[j]) + add_p) / 10; 
      } 
      else {
        Temp_res[j] = getsym( getnum(Str2[i]) * getnum(Str1[j]) + add_p );
        add_p = 0;
      }
    
    }

    Temp_res[0] = '+';
        
    if ( add_p != 0 ) {
      rshiftstr(Temp_res, 1);
      Temp_res[1] = getsym(add_p);
    }

    if ( count != 0 ) {
      zerotoend(Temp_res, count);
    }
            
    big_sum(Result, Temp_res, Result); 
    
   } 

   count++;

  }
  
  removezerob(Result);

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
  
  for (i = size_ini - 1; i > 0; i--) {
    Str[i+pos] = Str[i];
  } 
  
  for (i = 1; i <= pos; i++) {
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

  int i, m_size, starting_point;

  if ( (Mass[0] == '+') || (Mass[0] == '-') )
    starting_point = 1;
  else 
    starting_point = 0;

  do {
    if ( Mass[starting_point] == '0' ) {
      m_size = getstrsize(Mass);

      for (i = starting_point + 1; i < m_size; i++) {
        Mass[i-1] = Mass[i];
      }
    
    Mass[m_size-1] = '\0';

    }
  } while (Mass[starting_point] == '0');
  
}


void addsign(char *Mass)
{

  int i, ini_size = getstrsize(Mass); 

  if ( (getnum(Mass[0]) >= 1) && (getnum(Mass[0]) <= 9) ) {

    for ( i = getstrsize(Mass) - 1; i >= 0; i-- ) {
      Mass[i+1] = Mass[i];
    }

    Mass[ini_size + 1] = '\0';    

    Mass[0] = '+';
  }

}


char comparison(char *Str1, char *Str2)
{

  if ( Str1[0] == Str2[0] ) {

    if ( ( (getstrsize(Str1) > getstrsize(Str2)) && (Str1[0] == '+') ) || ( (getstrsize(Str1) < getstrsize(Str2)) && (Str1[0] == '-') ) )
      return '>';
    else if ( ( (getstrsize(Str1) < getstrsize(Str2)) && (Str1[0] == '+') ) || ( (getstrsize(Str1) > getstrsize(Str2)) && (Str1[0] == '-') ) )    
      return '<';
    else
    {

      int i = 1;

      do {
        if ( (getnum(Str1[i]) > getnum(Str2[i])) && (Str1[0] == '+') ) 
          return '>';
        else if ( (getnum(Str1[i]) > getnum(Str2[i])) && (Str1[0] == '-') )
          return '<';
        else if ( (getnum(Str1[i]) < getnum(Str2[i])) && (Str1[0] == '+') )
          return '<';
        else if ( (getnum(Str1[i]) < getnum(Str2[i])) && (Str1[0] == '-') )
          return '>';
 
        i++;

      } while ( i < getstrsize(Str1) );
      
      return '=';

    }
      
  }
  else if ( Str1[0] == '+' )
    return '>';
  else 
    return '<';

}


void copyStr(char *parent, char *copy)
{

  int i; 

  for ( i = 0; i <= getstrsize(parent); i++ )
    copy[i] = parent[i];
  
}


void make_inversion(char *Str, char *invStr)
{

  int i; 

  copyStr(Str, invStr);

  if ( Str[0] == '-' )
    invStr[0] = '+';
  else 
    invStr[0] = '-';
  
}


void big_abs(char *Str, char *absStr)
{
  
  copyStr(Str, absStr);   
  absStr[0] = '+';

}

// Additional functions - END

