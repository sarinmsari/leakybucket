#include <stdio.h>
void main()
{
    int incoming, outgoing, bucket_size, n, store = 0;
    printf("\nEnter  bucket_size, outgoing, n\n");
    scanf("%d %d %d", &bucket_size, &outgoing, &n);

    while (n != 0)
    {
        printf("\nEnter incoming:");
        scanf("%d", &incoming);
        if (incoming <= (bucket_size - store))
        {
            store += incoming;
            printf("\nBucket buffer size %d out of %d", store, bucket_size);
        }
        else
        {
            printf("\nDropped %d no.of packets", incoming - (bucket_size - store));
            store = bucket_size;
            printf("\nBucket buffer size %d out of %d", store, bucket_size);
        }
        if (store < outgoing)
        {
            store = 0;
        }
        else
        {
            store -= outgoing;
        }
        printf("\nAfter outgoing %d packets left out of %d in buffer", store, bucket_size);
        n--;
    }
}