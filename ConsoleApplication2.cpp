#include <iostream>

using namespace std;

void print_array(const int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}
int* filter_simple(const int* original_numbers, int size, int& filtered_size) {
  int* filtered_primes = new int[size];
  filtered_size = 0;
  for (int i = 0; i < size; ++i) {
    bool is_prime = true;
    for (int j = 2; j * j <= original_numbers[i]; ++j) {
      if (original_numbers[i] % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime && original_numbers[i] > 1) {
      filtered_primes[filtered_size] = original_numbers[i];
      ++filtered_size;
    }
  }

  int* resized_primes = new int[filtered_size];
  for (int i = 0; i < filtered_size; ++i) {
    resized_primes[i] = filtered_primes[i];
  }
  delete[] filtered_primes;

  return resized_primes;
}

int* filter_multiple_of_three(const int* original_numbers, int size, int& filtered_size) {
  int* filtered_multiples_of_three = new int[size];
  filtered_size = 0;
  for (int i = 0; i < size; ++i) {
    if (original_numbers[i] % 3 == 0) {
      filtered_multiples_of_three[filtered_size] = original_numbers[i];
      ++filtered_size;
    }
  }

  int* resized_multiples = new int[filtered_size];
  for (int i = 0; i < filtered_size; ++i) {
    resized_multiples[i] = filtered_multiples_of_three[i];
  }
  delete[] filtered_multiples_of_three;

  return resized_multiples;
}

int* filter_even(const int* original_numbers, int size, int& filtered_size) {
  int* filtered_evens = new int[size];
  filtered_size = 0;
  for (int i = 0; i < size; ++i) {
    if (original_numbers[i] % 2 == 0) {
      filtered_evens[filtered_size] = original_numbers[i];
      ++filtered_size;
    }
  }

  int* resized_evens = new int[filtered_size];
  for (int i = 0; i < filtered_size; ++i) {
    resized_evens[i] = filtered_evens[i];
  }
  delete[] filtered_evens;

  return resized_evens;
}

int main() {
  const int size = 7;
  int original_numbers[size] = {99, 33, 8, 7, 77, 89, 44};

  int filtered_size;

  
  cout << "Original array: ";
  print_array(original_numbers, size);

  int* filtered_primes = filter_simple(original_numbers, size, filtered_size);
  cout << "Prime numbers: ";
  print_array(filtered_primes, filtered_size);
  delete[] filtered_primes;

  int* filtered_multiples_of_three = filter_multiple_of_three(original_numbers, size, filtered_size);
  cout << "Numbers multiple of three: ";
  print_array(filtered_multiples_of_three, filtered_size);
  delete[] filtered_multiples_of_three;

  int* filtered_evens = filter_even(original_numbers, size, filtered_size);
  cout << "Even numbers: ";
  print_array(filtered_evens, filtered_size);
  delete[] filtered_evens;

  return 0;
}
