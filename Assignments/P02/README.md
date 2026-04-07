## Program 2 

Description: 
The goal of this program is to track stats for each of the data structures we have been discussing as they process the same data sets. The general idea is to learn and understand certain choices we make when determining what structures would work best in specific conditions. But before we compare structures, we need to determine what data points are important enough to track.

- Avl
- Binary heap
- Binary Search Tree
- Counters
- Hash Table
- Linked List
- Sorted Array Set
- Term color
- Usage printer
- Ordered Dynamic Array

Report/Analysis of the data structures:
- Binary Search Tree

It is best to use a binary search tree for fast, organized data storage where values will be frequently searched, inserted, and deleted. If the structure is balanced, it would take on average O(log n) for search time.

Best dataset:
As a result, a randomly ordered dataset would work best for this structure, because it helps produce a reasonably balanced tree and maximizes its efficiency.

Where does the work happen?
The work really happens from the root all the way to the relevant nodes, performing comparisons and updating pointers or memory when inserting or deleting.

Why does one structure outperform another?
A BST outperforms other data structures when you need fast searches along with frequent insertions and deletions, and when maintaining order or performing range queries is important.


- Counters
Counters are best to use to measure and analyze how your data structure behaves. Mainly to observe the performance. Counters can be used to observe comparisons, modifications (insertions, deletions), and structural_ops.


- Hash Table
A hash table is best when order doesn't matter, and you're seeking fast lookups, insertions, and deletions. It uses O(1) complexity.

It is best to use a hash table for very fast data lookup, insertion, and deletion when the order of elements does not matter. Operations on a good hash table take O(1) on average for search, insert, and delete.

Best dataset:
A hash table works best with a dataset that has a good distribution of keys and minimal collisions. Datasets with unique or well-distributed keys maximize efficiency.

Where does the work happen?
The work happens in the hashing process to compute the key’s index and in resolving collisions, if they occur. Actual insertion, search, or deletion usually affects only one bucket or linked list/node in that bucket.

Why does one structure outperform another?
A hash table outperforms other data structures when you need extremely fast lookups, insertions, and deletions and ordering of elements is not required. Unlike BSTs or arrays, hash tables provide near-constant-time performance even for large datasets, assuming collisions are rare.


- Linked List
A linked list is best used when data is often modified and if random access is not a must. 

It is best to use a linked list for dynamic data storage where elements are frequently inserted or deleted, especially at the beginning or end of the list. Searching for a specific element, however, takes O(n) time because the list must be traversed.

Best dataset:
A linked list works best with a dataset where order matters less and frequent insertions and deletions are required, particularly when elements are added or removed at the head or tail rather than in the middle.

Where does the work happen?
The work happens along the nodes that need to be accessed or modified. Insertion or deletion requires updating pointers of adjacent nodes, while searching requires traversing the list node by node.

Why does one structure outperform another?
A linked list outperforms other data structures when you need efficient insertions and deletions without resizing and when random access is not required. Unlike arrays or BSTs, you can insert or delete nodes in O(1) time if the position is known.

- Sorted Array Set
A sorted array is

It is best to use a sorted array for datasets where fast searching is needed and insertions or deletions are infrequent. Searching can be done using binary search in O(log n) time, but inserting or deleting an element requires shifting elements, which takes O(n) time.

Best dataset
A sorted array works best with a mostly static dataset that does not change often but requires frequent searches or ordered traversal. Pre-sorted or nearly sorted data maximizes efficiency.

Where does the work happen?
The work happens when shifting elements to insert or delete, while searching only requires comparisons along the binary search path.

Why does one structure outperform another?
A sorted array outperforms other data structures when you need fast search and ordered access and modifications are rare. Compared to linked lists, it provides O(log n) search; compared to hash tables, it allows ordered traversal and range queries.

- Term color
It is best to use a term color structure for storing and managing unique identifiers or categories, especially when you need to quickly check membership or assign properties to specific terms. Depending on the implementation, it can provide fast lookup and insertion.

Best dataset
A term color set works best with a moderately sized collection of distinct terms where frequent membership checks or category assignments are needed. Datasets with unique, non-repeating terms maximize efficiency.

Where does the work happen?
The work happens when adding a new term, checking if a term exists, or updating a term’s properties. If implemented as a hash set or map, work mainly occurs in the hashing process and collision resolution; if implemented as a tree, it happens along the path from root to the relevant node.

Why does one structure outperform another?
A term color structure outperforms other data structures when you need fast membership checks and efficient updates on a dynamic collection of unique elements. Unlike arrays, it avoids full scans; unlike linked lists, it provides faster search; and unlike a plain BST, a hash-based implementation can achieve near-constant-time operations.


- Ordered Dynamic Array
Ordered dynamic arrays are best used when fast lookups are needed and updates don't happen often.





