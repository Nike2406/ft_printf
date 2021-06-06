#include <stdio.h>
#include "./includes/ft_printf.h"

int main (void)
{
 printf ("1. Вывод простой строки\n");

 printf ("\n2. Вывод целых чисел\n");

 printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
 { int d1=123;
   printf ("Example:\t%d\n",d1);
   ft_printf ("Mine:\t%d\n",d1);
 }
 printf ("\n2.2 Вывод чисел c выравниванием по правому краю:\n");
 { int d1=123, d2=42, d3=1543;
   printf ("Example:\t%6d\n%6d\n%6d\n",d1,d2,d3);
   ft_printf ("Mine:\t%6d\n%6d\n%6d\n",d1,d2,d3);
 }
 printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
 { int d1=123, d2=42, d3=1543;
   printf ("Example:\t%-6d\n%-6d\n%-6d\n",d1,d2,d3);
   ft_printf ("Mine:\t%-6d\n%-6d\n%-6d\n",d1,d2,d3);
 }
 printf ("\n2.4 Вывод числа с выводом 0 в недостающих символах:\n");
 { int d1=-123;
   printf ("Example:\t%06d\n",d1);
   ft_printf ("Mine:\t%06d\n",d1);
 }
 printf ("\n2.5 Вывод числа 123 с заданной шириной 6 символов:\n");
 { int d1=123;
   printf ("Example:\t%6d\n",d1);
   ft_printf ("Mine:\t%6d\n",d1);
 }
 printf ("\n2.6 Вывод числа 123 с заданной точностью 6 символов:\n");
 { int d1=123;
   printf ("Example:\t%.6d\n",d1);
   ft_printf ("Mine:\t%.6d\n",d1);
 }
 printf ("\n2.7 Вывод числа типа char:\n");
 { char d1=123;
   printf ("Example:\t%hhd\n",d1);
   ft_printf ("Mine:\t%hhd\n",d1);
 }
 printf ("\n2.8 Вывод числа типа short int:\n");
 { short int d1=123;
   printf ("Example:\t%hd\n",d1);
   ft_printf ("Mine:\t%hd\n",d1);
 }
 printf ("\n2.9 Вывод числа типа long int:\n");
 { long int d1=123;
   printf ("Example:\t%ld\n",d1);
   ft_printf ("Mine:\t%ld\n",d1);
 }
 printf ("\n2.10 Вывод числа типа long long int:\n");
 { long long int d1=123;
   printf ("Example:\t%lld\n",d1);
   ft_printf ("Mine:\t%lld\n",d1);
 }
 printf ("\n2.11 Вывод целого без знакового числа:\n");
 { unsigned int d1=123;
   printf ("Example:\t%u\n",d1);
   ft_printf ("Mine:\t%u\n",d1);
 }
 printf ("\n2.12 Вывод целого числа в восьмеричном формате:\n");
 { unsigned int d1=123;
   printf ("Example:\t%o\n",d1);
   ft_printf ("Mine:\t%o\n",d1);
 }
 printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
 { unsigned int d1=123;
   printf ("Example:\t%x\n",d1);
   ft_printf ("Mine:\t%x\n",d1);
 }
 printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
 { unsigned int d1=123;
   printf ("Example:\t%#x\n",d1);
   ft_printf ("Mine:\t%#x\n",d1);
 }
 printf ("\n3. Вывод чисел c плавающей точкой\n");
 printf ("3.1 Вывод числа 123.456 с форматом по умолчанию:\n");
 { double d1=123.456;
   printf ("Example:\t%f\n",d1);
   ft_printf ("Mine:\t%f\n",d1);
 }
 printf ("\n3.2 Вывод числа 123.456 с точностью 2:\n");
 { double d1=123.456;
   printf ("Example:\t%.2f\n",d1);
   ft_printf ("Mine:\t%.2f\n",d1);
 }
 printf ("\n3.3 Вывод числа 123.456 в экспоненциальной форме:\n");
 { double d1=123.456;
   printf ("Example:\t%e\n",d1);
   ft_printf ("Mine:\t%e\n",d1);
 }
 printf ("\n3.4 Использование преобразователя g:\n");
 { double d1=123.4567, d2=1234567.34567;
   printf ("Example:\t%g\n%g\n",d1,d2);
   ft_printf ("Mine:\t%g\n%g\n",d1,d2);
 }
 printf ("\n3.5 Вывод числа 123.456 в шестнадцатеричной форме:\n");
 { double d1=123.456;
   printf ("Example:\t%a\n",d1);
   ft_printf ("Mine:\t%a\n",d1);
 }
 printf ("\n4. Вывод символа 'k':\n");
 { char d1='k';
   printf ("Example:\t%c\n",d1);
   ft_printf ("Mine:\t%c\n",d1);
 }
 printf ("\n5. Вывод строки 'abc':\n");
 { char d1[4]="abc";
   printf ("Example:\t%s\n",d1);
   ft_printf ("Mine:\t%s\n",d1);
 }
 printf ("\n6. Вывод указателя:\n");
 { char d1[4]="abc";
   printf ("Example:\t%p\n",d1);
   ft_printf ("Mine:\t%p\n",d1);
 }
 printf ("\n7. Подсчет выведенных символов:\n");
 { int d1=0;
   fflush (stdout);
   printf ("Example:\tDerived characters:%n",&d1);
   ft_printf ("Mine:\tDerived characters:%n",&d1);
   printf ("Example:\t %d\n",d1);
   ft_printf ("Mine:\t %d\n",d1);
 }

 //Принудительный вывод строки не дожидаясь заполнения буфера
 printf ("\n6. Вывод буферизированной строки\n");
 { char d1[4]="abc";
   printf ("%s",d1);
   fflush (stdout);
 }
   return 0;
}
