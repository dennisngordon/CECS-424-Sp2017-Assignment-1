qsort :: (Ord a) => [a] -> [a]  --quick sort in haskell
qsort [] = []  --an empty list is a sorted list
qsort (p:xs) =   --the head element is the pivot for quick sort
--call qsort on list of elements smaller than pivot element and also on list larger than element
    let left = qsort [a | a <- xs, a <= p]
        right = qsort [a | a <- xs, a > p]
--take head of list to be pivot and concat between list thats smaller than pivot and list thats bigger than pivot
    in  left ++ [p] ++ right 