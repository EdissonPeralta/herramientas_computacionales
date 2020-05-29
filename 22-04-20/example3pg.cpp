#include <cstdlib>
#include <chrono>
#include <iostream>

/*
   Tests cache misses.
*/

void print_elapsed(auto start, auto end );
void option1(long * arr, int ix, int iy);
void option2(long * arr, int ix, int iy);
void option3(long * arr, int ix, int iy);


int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  auto start = std::chrono::steady_clock::now();
 
  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);

  long *arr = new long[sI*sJ]; // double array.
 
  auto end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
 
  // option 1
  start = std::chrono::steady_clock::now();
  option1(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
 
  // option 2
  start = std::chrono::steady_clock::now();
  option2(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);

  // option 3
  start = std::chrono::steady_clock::now();
  option3(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);

  printf("%ld\n", arr[0]);
 
  return 0;
}
 

void print_elapsed(auto start, auto end )
{
  std::cout << "Elapsed time in ms: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
            << "\n";
}

void option1(long * arr, int ix, int iy)
{
  for (long i=0; i < ix; ++i)
    for (long j=0; j < iy; ++j)
      arr[(i * (iy)) + j ] = i;
}

void option2(long * arr, int ix, int iy)
{
    for (long i=0; i < ix; ++i)
      for (long j=0; j < iy; ++j)
         arr[(j * (ix)) + i ] = i;
}
void option3(long * arr, int ix, int iy)
{
   for (int i=0; i < ix*iy; ++i) arr[i] = i;
}
