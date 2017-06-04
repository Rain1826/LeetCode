/*There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]  nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]  nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

/*
思路：
首先假设数组A和B的元素个数都大于k/2，我们比较A[k/2-1]和B[k/2-1]两个元素，这两个元素分别表示A的第k/2小的元素和B的第k/2小的元素。这两个元素比较共有三种情况：>、<和=。如果A[k/2-1]<B[k/2-1]，这表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中。换句话说，A[k/2-1]不可能大于两数组合并之后的第k小值，所以我们可以将其抛弃。

当A[k/2-1]>B[k/2-1]时存在类似的结论。

当A[k/2-1]=B[k/2-1]时，我们已经找到了第k小的数，也即这个相等的元素，我们将其记为m。由于在A和B中分别有k/2-1个元素小于m，所以m即是第k小的数。(这里可能有人会有疑问，如果k为奇数，则m不是中位数。这里是进行了理想化考虑，在实际代码中略有不同，是先求k/2，然后利用k-k/2获得另一个数。)

通过上面的分析，我们即可以采用递归的方式实现寻找第k小的数。此外我们还需要考虑几个边界条件：

（1）如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
（2）如果k为1，我们只需要返回A[0]和B[0]中的较小值；
（3）如果A[k/2-1]=B[k/2-1]，返回其中一个；
*/

class Solution
{
public:
    //找到合并后第k大的数
    double findKth(int a[], int m, int b[], int n, int k)
    {
        //始终令 m <= n
        if (m > n)
            return findKth(b, n, a, m, k);
        if (m == 0)
            return b[k - 1];
        if (k == 1)
            return min(a[0], b[0]);
        //将a、b数组进行划分
        int pa = min(k / 2, m), pb = k - pa;
        if (a[pa - 1] < b[pb - 1])
            return findKth(a + pa, m - pa, b, n, k - pa);
        else if (a[pa - 1] > b[pb - 1])
            return findKth(a, m, b + pb, n - pb, k - pb);
        else
            return a[pa - 1];
    }
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
        int *a = new int[A.size()];
        int *b = new int[B.size()];
        if(!A.empty())
            memcpy(a, &A[0], A.size()*sizeof(int));
        if(!B.empty())
            memcpy(b, &B[0], B.size()*sizeof(int));
        int total = A.size() + B.size();
        if (total % 2 != 0)
            return findKth(a, A.size(), b, B.size(), total / 2 + 1);
        else
            return (findKth(a, A.size(), b, B.size(), total / 2) + findKth(a, A.size(), b, B.size(), total / 2 + 1)) / 2;
    }
};
