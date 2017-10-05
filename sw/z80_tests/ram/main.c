
void main(void)
{
    unsigned char j;
    unsigned char *mem;
    
    j = 0;
    mem = (unsigned char *) 0x8200; // somwhere in ram

    while (1) {
        *mem = j++;
    }
}
