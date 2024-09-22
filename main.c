volatile unsigned int * const UART0DR = (unsigned int *) 0x09000000;

void print_char_uart0(const char s) {
    *UART0DR = (unsigned int)(s); /* Transmit char */
}

void print_string_uart0(const char *s) {
    while(*s != '\0') { /* Loop until end of string */
        print_char_uart0 (*s);
        s++;
    }
}

// https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.cpp
void print_number_uart0(unsigned long n, int base)
{
  char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
    char c = n % base;
    n /= base;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  print_string_uart0(str);
}

#include <stdio.h>

void print_int_uart0(int n) {
    if (n < 0) {
      print_char_uart0('-');
      n = -n;
      print_number_uart0(n, 10);
    } else {
      print_number_uart0(n, 10);
    }
}

void print_int_array_uart0(int* n, size_t length) {
  for (int i = 0; i < length; i++) {
    print_number_uart0(n[i], 10);
  }
}

#define get_array_length(x) ((sizeof(array)) / (sizeof(array[0])))

int main() {
    print_string_uart0("Hello World!\n");
    int array[] = {1, 2, 3};
    size_t size = get_array_length(array);
    print_int_uart0(size);
    print_string_uart0("\n");
    print_int_array_uart0(array, size);
}
