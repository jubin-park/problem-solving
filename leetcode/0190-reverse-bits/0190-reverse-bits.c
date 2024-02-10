#define REV8BITS(p) (*(p) & 16) >> 1 | (*(p) & 8) << 1 | \
                    (*(p) & 32) >> 3 | (*(p) & 4) << 3 | \
                    (*(p) & 64) >> 5 | (*(p) & 2) << 5 | \
                    (*(p) & 128) >> 7 | (*(p) & 1) << 7

#define SWAP8BITS(p, q) \
    do { \
        *(p) ^= *(q); \
        *(q) ^= *(p); \
        *(p) ^= *(q); \
    } while (0)

uint32_t reverseBits(uint32_t n)
{
    char* p = (char*)&n;
    *p = REV8BITS(p);
    *(p + 1) = REV8BITS(p + 1);
    *(p + 2) = REV8BITS(p + 2);
    *(p + 3) = REV8BITS(p + 3);

    SWAP8BITS(p, p + 3);
    SWAP8BITS(p + 1, p + 2);

    return n;
}