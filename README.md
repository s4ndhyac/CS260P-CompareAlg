# CompareAlg 
### To find k-largest elements in an array

## Build Instructions
Compile using:
`gcc MAIN.c -o MAIN`

Run using: `./MAIN`

## Algorithm

The Algorithm used is as follows:

1. Build a Min Heap consisting of the indexes of the first k elements in the array
2. From the (k+1)th to nth element compare each element against the root of the Min Heap
3. If the element is greater than the root of the Min Heap then replace the root of the Min Heap with it's index and re-balance the Min Heap
4. At the end, the Min Heap will contain the indexes of the K largest elements
5. The K largest elements are then sorted using Binary Insertion sort to obtain the indexes of the K largest elements in descending order

## Analysis

Now lets assume that the array has n random elements and the k largest elements are equally likely to be in any of the n positions.

- The Min Heap of the indices of the first k elements is formed at worst in O(k) time
- The re-balancing of Min Heap on addition of (n-k) elements at worst case happens in O(((n-k)*logk) 
- Finally the Binary Insertion sort of k elements in the Min Heap is performed in O(k^2 + klogk) in which O(k^2) dominates

