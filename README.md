Built and tested various container types including Stacks/Queues, Hash Functions, Binary Search Trees, and AVL Trees.
Additionally, built/tested Sorting Algorithms and Dijkstra's and Kruskal's Searching Algorithms.


All container types adhere to these basic contraints:
functions: 
  1. insert: inserts into container
  2. remove: removes from container
  3. find (not in Stacks/Queues): depending on implementation, either returns reference, index, or boolean value

Testing:
All containers were emperically tested and analyzed to determine time complexity. Tested with file of roughly 40,000 words. Inserting, finding, and removing all words at a step of 1/10. For instance, the first step would analyze the time to add 4,000 words, then the second step would add 8,000, etc. This gives us a way of measuring insert, find, and remove in O(n) time (n being all 40,000 words), meaning if we graph an O(n) complexity to insert all words, inserting 1 word would be an O(1) process. The testing framework is provided in the Testing Folder.

All other code is in designated folders for each container/algorithm.
