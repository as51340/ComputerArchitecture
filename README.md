# Memory management in C

Seminar for subject Computer Architecture 2 with mentor professor Siniša Šegvić. I covered topics such as x86 architecture, dynamic allocation on stack, differences between stack and heap. I also made little research about memory mapped files. Last part is explaining why are binary files better to use comparing them to txt files. You can download pptx seminar version with cloning this repository. There are also different programs for benchamrking included in repo. For pdf version visit check out this link [ARH2 repository](http://www.zemris.fer.hr/~ssegvic/ar2/2021Skrgat.pdf) 

```javascript
git clone https://github.com/as51340/Memory-management-in-C.git
cd build
cmake .. // in every builder folder
make
```

## Content

```javascript
1. x86 architecture
2. Heap vs stack
3. How malloc works?
4. Memory mapping in C++
5. Binary files
```

### X86 architecture

X86 architecture can be used on both AMD's and INTEL's processors. It is backward compatible with older 32-bit, 16-bit and 8-bit versions. There are many addressing modes so loading effective address can be executed in one period of CPU's tick. There are many conventions calling modes, some of the most recognizable are cdecl for caller clean-up mode and stdcall for callee clean-up. Stdcall is used 32-bit versions of Windows.

### Compiler optimisations

GCC defaultly doesn't use any optimisitation. You can use six different optimisation level for reducing execution time and code size. Flag -march=native uses system dependent instructions for accelerating compilation time. 

### Heap vs. stack

Stack allows us allocating at most 2MB. It is very fast and it literally means moving stack pointer from one address to another. Heap is slow but it expands lifetime of objects. You can take care of heap's speed by dynamically alocating space on stack by using _alloca_ and _malloca_ functions. 

### Custom allocators

Custom allocators are operators for allocating and deallocating memory. When you have specific way of using chunks of memory you can write your own allocator. New encapsulates malloc and are generally slow because of their general usage. You can check this guy's great project about allocators in C++ [Check memory allocators implementations from this guy](https://github.com/mtrebi/memory-allocators).

### Mmap in C++

Memory mapping is process in which file from disk is loaded into RAM memory so every process can use it and can see changes from another process. When you have big file (e.g 1GB) you can use mapping for accelating reading process from file. When you don't map you are constantly copying bytes from kernel to user which is why reading is slow operation.

### Binary vs txt

Binary files are faster to use because such files are smaller. For example when you have 12345 txt file would use 5B while binary file would use only 2B because 12345 = 0b0000 0011 0000 0011 1001. User needs to be careful when using FP values.
