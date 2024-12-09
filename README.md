# NaiBench

NaiBench (Naive Benchmark), simple header-only benchmark library to time function executions.

# Usage

You can simply grab the headers and use on your project.

Or you can also use CMake solution.

## C/Cmake Usage

Simple CMakeLists.txt as example:

```cmake
cmake_minimum_required(VERSION 3.14...3.30)

project(
    helloworld
    LANGUAGES C
)

include(FetchContent)

FetchContent_Declare(
    naibench
    GIT_REPOSITORY "https://github.com/ltsdw/naibench.git"
    GIT_TAG main
)

FetchContent_MakeAvailable(naibench)

add_executable(helloworld src/main.c)
target_link_libraries(helloworld NAIBENCH::naibench)
```

src/main.c content:

```c
#include "naibench.h"

int main()
{
    NAIBENCH_START();

    int a = 0;
    for (int i = 0; i < 1000000000; ++i)
    {
        // simulating real work here
        a += i * 13;
    }

    NAIBENCH_STOP();

    return 0;
}
```

Output:

```
main: 1.706591962 time elapsed.
```

# CPP/CMake Usage

```cmake
cmake_minimum_required(VERSION 3.14...3.30)

project(
    helloworld
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    naibench
    GIT_REPOSITORY "https://github.com/ltsdw/naibench.git"
    GIT_TAG main
)

FetchContent_MakeAvailable(naibench)

add_executable(helloworld src/main.cpp)
target_link_libraries(helloworld NAIBENCH::naibench)
```

src/main.cpp content:

```cpp

#include "naibench.hpp"

int main()
{
    NAIBENCH_START();

    int a = 0;
    for (int i = 0; i < 1000000000; ++i)
    {
        // simulating real work here
        a += i * 13;
    }

    // You don't need to call NAIBENCH_STOP(), but for consistency with the C code, it's included.
    // NAIBENCH_STOP();

    return 0;
}
```
Output:

```
main: 1.706591962 time elapsed.
```
