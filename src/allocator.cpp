#include "allocator.h"
#include<iostream>

constexpr size_t HEAP_SIZE = 1024*1024;
static char heap[HEAP_SIZE];

struct Block{
    size_t size;
    bool is_free;
    Block* next;
};

static Block* free_list = nullptr;

void initialize(){
    free_list = (Block*)heap;
    free_list -> size = HEAP_SIZE - sizeof(Block);
    free_list -> is_free = true;
    free_list -> next = nullptr;
}

void* shivams_malloc(size_t size){
    if(!free_list) initialize();

    Block* curr = free_list;

    while(curr){
        if(curr -> is_free && curr ->size >= size){
            // here splitting memory
            if(curr -> size >= size + sizeof(Block) + 1){
                Block* new_block = (Block*)((char*)curr + sizeof(Block) + size);
                new_block ->size = curr -> size - size - sizeof(Block);
                new_block -> is_free = true;
                new_block -> next = curr -> next;

                curr -> size = size;
                curr -> next = new_block;
            }

            curr -> is_free = false;
            return (char*)curr + sizeof(Block);
        }
        curr = curr -> next;
    }

    return nullptr;
}

void shivams_free(void* ptr){
    if(!ptr) return;

    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block -> is_free = true;

    Block* curr = free_list;
    while(curr && curr -> next){
        if(curr -> is_free && curr -> next -> is_free){
            curr -> size += sizeof(Block) + curr -> next -> size;
            curr -> next = curr -> next -> next;
        } else{
            curr = curr -> next;
        }
    }
}

void print_shivams_blocks(){
    Block* curr = free_list;
    std::cout<<"Printing Memory Blocks:"<<std::endl;

    while(curr){
        std::cout<<"Block at"<< curr << " | size: "<< curr -> size << " | free: "<<curr->is_free<<std::endl;
        curr = curr -> next;
    }
}