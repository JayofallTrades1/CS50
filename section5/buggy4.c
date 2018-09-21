int main(void)
{
    int i;
    int array[5];

    for (i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        array[i] = 0;
    }
   
    return 0;
}
