// Very interesting algorithm that go through every block within the memory region
//  defined in RAM_LFSR_MASK.
// This algorithm does its work efficiently through bitwise manipulation.

#include <iostream>
#include <stack>

#define RAM_4MB_MASK    0x300000u
#define RAM_8MB_MASK    0x420000u
#define RAM_16MB_MASK   0xE10000u
#define RAM_128MB_MASK  0x4000013u
#define RAM_256MB_MASK  0x9000000u
#define RAM_MASK        RAM_256MB_MASK      // density of the memory

void printBits( unsigned long *b )
{
    unsigned long &bits = *b;
    std::stack<bool> bitStack;
    for( unsigned long mask = 1, i = 0; mask != 0; ++i ) {
        bitStack.push( ( bits & mask ) >> i );
        mask = mask << 1;
    }
    while (bitStack.size() > 0) {
        std::cout << bitStack.top();
        bitStack.pop();
    }
    std::cout << std::endl;
}

void bitwise_manipulate_addr()
{
    unsigned long rand_addr = 1;
    do {
        // Highly interesting way of going through the addresses until address
        //  defined in RAM_MASK.
        // NOTE: -( rand_addr & 1u ) is a logical negation of a result from
        //        a bitwise operation.
        //       For example, the logical negation of a binary 1 (in int)
        //        would be 1111111111111111b instead of 1111111111111110b
        //        which is the binary negation.
        rand_addr = ( rand_addr >> 1 ) ^ ( -( rand_addr & 1u ) & RAM_MASK );

        // The address needs to align with unsigned long
        //  (Ensure sure it has at least sizeof( unsigned long ) of bytes
        //   until the next memory location).
        if ( ( rand_addr &  sizeof( unsigned long ) - 1 ) == 0 ) {
            printBits( &rand_addr );
        }
    }
    while( rand_addr != 1 );
}

int main()
{
    bitwise_manipulate_addr();
    return 0;
}
