#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    x = x>>n;
    //printf("%08x\n",x); //for test
    unsigned int one=1;
    unsigned ans=x & one;
    return ans;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    if(v==0){
        /*置0
        对于目标位：
        00->0
        10->0
        对于非目标位
        00->0
        11->1
        即不仅仅左移n位，而且使后续填补的位全为1
        
        eg:4e = 0100 1111
        第二位换成0
        0100 1011 4a
        但是我们得到了a，因为我们只考虑了后四位...
        */
        unsigned one=4294967295;//最大值
        int a[64]={1,2,4,8,16,32,64,128,256,512,1024,2048};//其实可以换一个函数，但是懒了
        unsigned another_one=4294967295;
        another_one = another_one ^ a[n];//只有第n位为0，其他都为1的东西
        one = another_one & one;
        //printf("%08x\n",one);
        *x = *x & one;
    }
    else if (v==1){
        v = v<<n;
        *x = *x | v;
    }
    else{
        printf("%s","发生异常");
    }
    


}
// Flip the nth bit of the value of x.(反转第n位？)
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    if(get_bit(*x,n)==0){
        set_bit(x,n,1);
    }
    else{
        set_bit(x,n,0);
    }
    //不可以使用~(get_bit(*x,n)，因为这玩意是0000...0x，x=0/1，这样取反得11111...
    
}

