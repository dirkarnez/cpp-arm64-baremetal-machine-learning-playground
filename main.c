#define size_t unsigned int
#if !defined( __STDC_VERSION__ ) || __STDC_VERSION__ < 201112L
	#error "This compiler is too old or not supported. This program needs _Static_assert"
#endif

#define __is_same_type(a, b)	\
  __builtin_types_compatible_p(__typeof__(a), __typeof__(b))

#define __is_array(arr)	(!__is_same_type((arr), &(arr)[0]))
#define __must_be(e, msg)	(				\
	0 * (int)sizeof(						    \
		struct {						          \
			_Static_assert((e), msg);			\
			char ISO_C_forbids_a_struct_with_no_members__;	\
		}							\
	)								\
)
#define __must_be_array(arr)	__must_be(__is_array(arr), "Must be an array!")
#define __array_length(arr)	(sizeof(arr) / sizeof((arr)[0]))
#define array_length(arr)	(__array_length(arr) + __must_be_array(arr))

volatile unsigned int * const UART0DR = (unsigned int *) 0x09000000;





// #define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
// #define _MMIO_WORD(mem_addr) (*(volatile uint16_t *)(mem_addr))
// #define _MMIO_DWORD(mem_addr) (*(volatile uint32_t *)(mem_addr))


// #define _SFR_MEM8(mem_addr) _MMIO_BYTE(mem_addr)
// #define _SFR_MEM16(mem_addr) _MMIO_WORD(mem_addr)
// #define _SFR_MEM32(mem_addr) _MMIO_DWORD(mem_addr)
// #define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)
// #define _SFR_IO16(io_addr) _MMIO_WORD((io_addr) + __SFR_OFFSET)

// #define _SFR_MEM_ADDR(sfr) ((uint16_t) &(sfr))
// #define _SFR_IO_ADDR(sfr) (_SFR_MEM_ADDR(sfr) - __SFR_OFFSET)
// #define _SFR_IO_REG_P(sfr) (_SFR_MEM_ADDR(sfr) < 0x40 + __SFR_OFFSET)

// #define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)

// #endif /* !_SFR_ASM_COMPAT */

// #define _SFR_BYTE(sfr) _MMIO_BYTE(_SFR_ADDR(sfr))
// #define _SFR_WORD(sfr) _MMIO_WORD(_SFR_ADDR(sfr))
// #define _SFR_DWORD(sfr) _MMIO_DWORD(_SFR_ADDR(sfr))









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

void print_int_uart0(int n) {
    if (n < 0) {
      print_char_uart0('-');
      n = -n;
    }
    print_number_uart0(n, 10);
}

int power(int base, int exponent) {
    int ans = 1; // Initialize ans to 1
    for (int i = 0; i < exponent; i++) { // Loop for the exponent times
        ans *= base; // Multiply ans by base
    }
    return ans; // Return the result
}

void print_float_uart0(float n, int places) {
    if (n < 0) {
      print_char_uart0('-');
      n = -n;
    }

    /*
    12.3 + 2.4 = 14.7
    truncated = 14
    0.7 * 10

    */
    int truncated = (int)n;
    print_number_uart0(truncated, 10);
    print_char_uart0('.');

    print_number_uart0((int)((n - truncated) * (power(10, places))), 10);
}

void print_int_array_uart0(int* n, size_t length, const char* separator) {
  print_char_uart0('[');
  for (int i = 0; i < length; i++) {
    if (i > 0) {
      print_string_uart0(separator);
    }

    print_number_uart0(n[i], 10);
  }
  print_char_uart0(']');
}


void print_float_array_uart0(float* n, size_t length, const char* separator, int places) {
  print_char_uart0('[');
  for (int i = 0; i < length; i++) {
    if (i > 0) {
      print_string_uart0(separator);
    }

    print_float_uart0(n[i], places);
  }
  print_char_uart0(']');
}

void fill_with_zeros(float* array, size_t length) {
  for (int i = 0; i < length; i++) {
    array[i] = 0;
  }
}

//////////////////////////////////////////////////////
// Function to perform 1D convolution
void convolve_one_dimension(float* input, float input_size, float* kernel, int kernel_size, float* output, int output_size) {
    // for (int i = 0; i < output_size; i++) {
    //     output[i] = 0;
    //     for (int j = 0; j < kernel_size; j++) {
    //         output[i] += input[i + j] * kernel[j];
    //     }
    // }

    // must fill with zeros first
    fill_with_zeros(output, output_size);

    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < kernel_size; j++) {
            output[i + j] += input[i] * kernel[j];
        }
    }
}

// struct A{                                                
//         _Static_assert(0);                               
//         char ISO_C_forbids_a_struct_with_no_members__;  
// };                                               


int main() {
  _Static_assert(1, "3");

  // {
  //   while(1) 
  //   {
  //     print_string_uart0("Hello World!\r\n");
  //   }
  // }

  // should capture user input

  {
      float a = 12.3;
      float b = a + 2.4;
      print_float_uart0(b, 10);

      print_string_uart0("\n");
  }


  {
    print_string_uart0("Hello World!\n");
  }

  {
    int array[] = {1, 2, 3};
    size_t size = array_length(array);
    print_int_uart0(size);
    print_string_uart0("\n");
    print_int_array_uart0(array, size, ", ");
    print_string_uart0("\n");
  }

    {
      // convolution
      print_string_uart0("convolution\n");
      float input[] = {1.0, 2.0, 3.0, 4.0};
      float kernel[] = {4.0, 5.0, 6.0, 7.0};

      const int input_size = array_length(input);
      print_string_uart0("input array: ");
      print_float_array_uart0(input, input_size, ", ", 2);
      print_string_uart0(", size: ");
      print_int_uart0(input_size);
      print_string_uart0("\n");

      const int kernel_size = array_length(kernel);
      print_string_uart0("kernel array: ");
      print_float_array_uart0(kernel, kernel_size, ", ", 2);
      print_string_uart0(", size: ");
      print_int_uart0(kernel_size);
      print_string_uart0("\n");

      float output[array_length(input) + array_length(kernel) - 1];
      print_string_uart0("output array: ");
      const int output_size = array_length(output);
      print_float_array_uart0(output, output_size, ", ", 2);
      print_string_uart0(", size: ");
      print_int_uart0(output_size);
      print_string_uart0("\n");
      
      // Perform 1D convolution
      convolve_one_dimension(input, input_size, kernel, kernel_size, output, output_size);

      print_string_uart0("done 1D convolution: ");
      // 4 13 28 50 52 45 28 
      print_float_array_uart0(output, output_size, ", ", 2);
      print_string_uart0("\n");
    }

   print_string_uart0("end of program!\n");

   while(1);
}
