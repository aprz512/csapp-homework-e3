#ifndef NUM_H
#define NUM_H

float u2f(unsigned u)
{
    return *(float *)(&u);
}

unsigned f2u(float f)
{
    return *(unsigned *)(&f);
}

#endif