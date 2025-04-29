#include "../include/allocator.h"
#include <iostream>

int main() {
    void* p1 = shivams_malloc(200);
    void* p2 = shivams_malloc(100);
    print_shivams_blocks();

    shivams_free(p1);
    print_shivams_blocks();

    void* p3 = shivams_malloc(50);
    print_shivams_blocks();

    return 0;
}
