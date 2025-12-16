# Push_swap
The main respository for my push_swap project and stack ordering

# Requirements
1. Simple algorithm (O(n2)): --DONE
Implement at least one baseline algorithm in the O(n2) class. Examples include:
• Insertion sort adaptation
• Selection sort adaptation
• Bubble sort adaptation --SELECTED
• Simple min/max extraction methods

2. Medium algorithm (O(n√n)): --DONE
Implement at least one algorithm in the O(n√n) class. Examples include:
• Chunk-based sorting (divide into √n chunks)
• Block-based partitioning methods
• Bucket sort adaptations with √n buckets
• Range-based sorting strategies

3. Complex algorithm (O(n log n)): --DONE
Implement at least one algorithm in the O(n log n) class. Examples include:
• Radix sort adaptation (LSD or MSD)
• Merge sort adaptation using two stacks
• Quick sort adaptation with stack partitioning
• Heap sort adaptation
• Binary indexed tree approaches

4. Custom adaptive algorithm (learner’s design): Design an adaptive strategy that selects
different internal methods depending on the measured disorder. You are not constrained
to any specific named algorithm; the internal techniques are entirely up to you. However,
your design must respect the following complexity targets per regime (in the Push_swap
operation model):

- Low disorder: if disorder < 0.2, your chosen method must run in O(n) time.

- Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in O(n√n)
time.

- High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n) time.
You must document in your repository (e.g., README.md) the rationale for your thresholds,
the internal techniques used in each regime, and a brief complexity argument (upper
bounds) for time and space within the Push_swap model.