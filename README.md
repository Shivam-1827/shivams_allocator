# Memory Allocator

A custom memory allocator implementation that demonstrates fundamental memory management concepts. This project provides a simple yet functional alternative to the standard `malloc` and `free` functions.

## Overview

This memory allocator implements a basic memory management system that:
- Manages a predefined heap space (1MB)
- Allocates memory blocks on request
- Frees previously allocated memory
- Coalesces adjacent free blocks to prevent fragmentation
- Provides debugging utilities to view memory state

## Features

- **Simple API**: Just three functions to allocate, free, and debug memory
- **Memory Splitting**: Efficiently splits blocks to minimize wasted space
- **Block Coalescing**: Combines adjacent free blocks to reduce fragmentation
- **Memory Visualization**: Debug function to inspect the current state of memory blocks

## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler with C++17 support

### Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

### Running the Test

```bash
./allocator_test
```

## API Reference

### `void* shivams_malloc(size_t size)`

Allocates a block of memory of the specified size.

- **Parameters**: `size` - Number of bytes to allocate
- **Returns**: Pointer to the allocated memory, or `nullptr` if allocation fails

### `void shivams_free(void* ptr)`

Frees a previously allocated memory block.

- **Parameters**: `ptr` - Pointer to the memory block to free
- **Returns**: None

### `void print_shivams_blocks()`

Prints the current state of all memory blocks for debugging.

- **Parameters**: None
- **Returns**: None

## Implementation Details

The allocator uses a linked list of memory blocks to keep track of allocated and free memory regions. Each block contains:

- Size of the data area
- Flag indicating whether the block is free
- Pointer to the next block

When memory is allocated:
1. The allocator searches for a free block of sufficient size
2. If the block is significantly larger than requested, it splits the block
3. The allocated block is marked as not free

When memory is freed:
1. The block is marked as free
2. Adjacent free blocks are coalesced into a single larger block

## Example Usage

```cpp
#include "allocator.h"
#include <iostream>

int main() {
    // Allocate memory
    void* ptr1 = shivams_malloc(100);
    void* ptr2 = shivams_malloc(200);
    
    // Use the memory...
    
    // View memory state
    print_shivams_blocks();
    
    // Free memory
    shivams_free(ptr1);
    shivams_free(ptr2);
    
    return 0;
}
```

## License

This project is released under the MIT License.
