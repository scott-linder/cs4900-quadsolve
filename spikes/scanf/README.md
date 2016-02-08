scanf
=====

single precision occupy 32bits of space:
        1 bit for sign, 8 bits for exponent, 23 bits for fraction

double precision occupy 64 bits of space:
        1 bit for sign, 11 bits for exponent, 52 bits for fraction

scanf() seems to be able to read INFs and NANs into floats

NaN example divide by zero and sqrt(-1)

INFs and -INFs
