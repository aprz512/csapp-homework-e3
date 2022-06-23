typedef union 
{
    struct 
    {
        long u;
        short v;
        char w;
        /* data */
    } t1;
    
    struct 
    {
        int a[2];
        long *p;
        /* data */
    } t2;
    
    /* data */
} u_type;

void get(u_type *up, long *dest) {
    *dest = *up->t2.p;
}
