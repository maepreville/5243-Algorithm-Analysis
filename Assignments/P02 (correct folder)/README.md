## Program 2 

Description: 
The goal of this program is to track stats for each of the data structures we have been discussing as they process the same data sets. Below is the list of arrays and the workloads/datasets that worked well for each.

- AVL
- Binary heap
- Binary Search Tree
- Hash Table
- Linked List
- Sorted Array Set

## Report/Analysis of the data structures:
# AVL

It is a self-balancing variant of the Binary Search Tree. It enforces a strict structural invariant where the heights of any node's two subtrees differ by at most one, performing single or double pointer rotations during updates to fix imbalances.

Best dataset: 
The workload/dataset that worked best was workload B.

Where does the work happen?
The AVL tree guarantees a tight logarithmic search boundary under all circumstances. On highly sequential workloads (Workload B), the tree structures its structural adjustments deterministically and handles lookups efficiently.

Why does one structure outperform another?
It excels on workload D due to its minimal lookup depth.

# Binary Heap

It is a self-balancing variant of the Binary Search Tree. It enforces a strict structural invariant where the heights of any node's two subtrees differ by at most one, performing single or double pointer rotations during updates to fix imbalances.

Best dataset: 
This algorithm worked well with Workload C. It works well with pure batch sequence files or heavy mutation schedules.

Where does the work happen?
Heaps excel at handling structural changes efficiently, processing insertions and peak deletions.

# Binary Search Tree

It is best to use a binary search tree for fast, organized data storage where values will be frequently searched, inserted, and deleted. If the structure is balanced, it would take on average O(log n) for search time.

Best dataset: 
Workload A (Randomized distribution sets: 1000, 5000, 10000, 20000). Unbalanced BSTs rely entirely on the randomness of the insertion sequence to maintain a relatively uniform layout. A randomly ordered dataset would work best for this structure, because it helps produce a reasonably balanced tree and maximizes its efficiency. 

Where does the work happen?
The work really happens from the root all the way to the relevant nodes, performing comparisons and updating pointers or memory when inserting or deleting.

Why does one structure outperform another?
A BST outperforms other data structures when you need fast searches along with frequent insertions and deletions, and when maintaining order or performing range queries is important. Workload B is sorted, which forces the plain BST to degenerate into a linear chain (resembling a linked list) with an efficiency profile of O(n).

# Hash Table
A hash table is best when order doesn't matter, and you're seeking fast lookups, insertions, and deletions. It uses O(1) complexity.

It is best to use a hash table for very fast data lookup, insertion, and deletion when the order of elements does not matter. Operations on a good hash table take O(1) on average for search, insert, and delete.

Best dataset: 
The best work file were Workload A and Workload C. These workloads had spread values across varying capacities which worked well.

Where does the work happen?
It functions best when operations are scattered symmetrically across the bucket structure, minimizing single-bucket collision chains. It handles mixed mutations (Workload C) smoothly because indexing logic operates at a constant O(1) time complexity before bucket chain evaluation.

# Linked List
A linked list is best used when data is often modified and if random access is not a must. 

It is best to use a linked list for dynamic data storage where elements are frequently inserted or deleted, especially at the beginning or end of the list. Searching for a specific element, however, takes O(n) time because the list must be traversed.

Best dataset: 
Small-scale variants (workload_A_1000, workload_D_1000). A linked list works best with a dataset where order matters less and frequent insertions and deletions are required, particularly when elements are added or removed at the head or tail rather than in the middle.

Where does the work happen?
The work happens along the nodes that need to be accessed or modified. Insertion or deletion requires updating pointers of adjacent nodes, while searching requires traversing the list node by node.

Why does one structure outperform another?
It runs efficiently only on small inputs (N <= 1000). On larger workloads (N = 20000), its O(n) search complexity degrades performance significantly.

# Sorted Array Set
A sorted array is an algorithm that keeps elements in a contiguous block of memory sorted in ascending order.

It is best to use a sorted array for datasets where fast searching is needed and insertions or deletions are infrequent. Searching can be done using binary search in O(log n) time, but inserting or deleting an element requires shifting elements, which takes O(n) time.

Best dataset: 
Workload D (search-heavy). A sorted array works best with a mostly static dataset that does not change often but requires frequent searches or ordered traversal. Pre-sorted or nearly sorted data maximizes efficiency.

Where does the work happen?
The work happens when shifting elements to insert or delete, while searching only requires comparisons along the binary search path. Insertions and deletions require shifting data, which takes O(n) time.