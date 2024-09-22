#define size_t unsigned int
#if defined( __STDC_VERSION__ ) && __STDC_VERSION__ >= 201112L
  #define MY_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

# define __is_same_type(a, b)	\
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
      print_number_uart0(n, 10);
    } else {
      print_number_uart0(n, 10);
    }
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

void fill_with_zeros(int* array, size_t length) {
  for (int i = 0; i < length; i++) {
    array[i] = 0;
  }
}

//////////////////////////////////////////////////////
// Function to perform 1D convolution
void convolve_one_dimension(int* input, int input_size, int* kernel, int kernel_size, int* output, int output_size) {
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
    MY_STATIC_ASSERT(1, "3");

    // struct A aa;
    print_string_uart0("Hello World!\n");
    int array[] = {1, 2, 3};
    size_t size = array_length(array);
    print_int_uart0(size);
    print_string_uart0("\n");
    print_int_array_uart0(array, size, ", ");
    print_string_uart0("\n");

    {
      // convolution
      print_string_uart0("convolution\n");
      int input[] = {1, 2, 3};
      int kernel[] = {4, 5, 6};

      const int input_size = array_length(input);
      print_string_uart0("input array: ");
      print_int_array_uart0(input, input_size, ", ");
      print_string_uart0(", size: ");
      print_int_uart0(input_size);
      print_string_uart0("\n");

      const int kernel_size = array_length(kernel);
      print_string_uart0("kernel array: ");
      print_int_array_uart0(kernel, kernel_size, ", ");
      print_string_uart0(", size: ");
      print_int_uart0(kernel_size);
      print_string_uart0("\n");

      int output[array_length(input) + array_length(kernel) - 1];
      print_string_uart0("output array: ");
      const int output_size = array_length(output);
      print_int_array_uart0(output, output_size, ", ");
      print_string_uart0(", size: ");
      print_int_uart0(output_size);
      print_string_uart0("\n");
      
      // Perform 1D convolution
      convolve_one_dimension(input, input_size, kernel, kernel_size, output, output_size);

      print_string_uart0("done 1D convolution: ");
      print_int_array_uart0(output, output_size, ", ");
      print_string_uart0("\n");
    }

   print_string_uart0("end of program!\n");
}
