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
void printNumber(unsigned long n, int base)
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

    while(*str != '\0') { /* Loop until end of string */
        print_char_uart0 (*str);
        str++;
    }
}

void print_int_uart0(int n) {
    if (n < 0) {
      print_char_uart0('-');
      n = -n;
      return printNumber(n, 10);
    }
    return printNumber(n, 10);
}

int main() {
    print_string_uart0("Hello World!\n");
    print_int_uart0(10);
}
