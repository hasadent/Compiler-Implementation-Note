#include <cstdio>
#include <cstdlib>
using namespace std;


template <int A, int B>
struct INODE{
   static const int x = A;
   static const int y = B;
   static const int z = A*B;
   INODE <A,B+1> next;

   void print() { printf("%dx%d=%2d, ", A, B, A*B); next.print(); }
};

template <int A>
struct INODE<A,9>{
    void print() { printf("%dx%d=%2d\n", A, 9, A*9);}
};

template <int A>
struct ONODE{
    INODE<A,1> content;
    ONODE<A+1> next;

    void print(){
        content.print();
        next.print();
    }
};

template <>
struct ONODE<10>{
    void print() {}
};

int main()
{
    ONODE<1> start;
    start.print();

    system("pause");
    return 0;
}

