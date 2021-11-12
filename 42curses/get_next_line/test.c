#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myfree(void * p) {
    size_t * in = p;
    if (in) {
        --in; free(in);
    }
}

void * mymalloc(size_t n) {
    size_t * result = malloc(n + sizeof(size_t));
    if (result) { *result = n; ++result; memset(result,0,n); }
    return result;
}

size_t getsize(void * p) {
    size_t * in = p;
    if (in) { --in; return *in; }
    return -1;
}

#define malloc(_x) mymalloc((_x))
#define free(_x) myfree((_x))

void *reallocation(void *ptr,size_t size) {
    void *newptr;
    size_t msize;
    msize = getsize(ptr);
    printf("msize=%zu\n", msize);
    if (size <= msize)
        return ptr;
    newptr = malloc(size);
    memcpy(newptr, ptr, msize);
    free(ptr);
    return newptr;
}
int main() {
    char * aa = malloc(50);
    char * bb ;
    printf("aa size is %zu\n",getsize(aa));
    strcpy(aa,"my cookie");
    bb = reallocation(aa,100);
    printf("bb size is %zu\n",getsize(bb));
    printf("<%s>\n",bb);
    free(bb);
}
