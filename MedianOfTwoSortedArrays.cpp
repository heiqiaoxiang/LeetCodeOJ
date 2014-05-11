class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1) //奇数
            return find_kth(A, m, B, n, total / 2 + 1);
        else //偶数
            return (find_kth(A, m, B, n, total / 2) 
                    + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) //返回有序数列A和B中第k大的数。 
    {
        if (m > n) return find_kth(B, n, A, m, k); //假定总有m<=n。
        if (m == 0) return B[k - 1]; //A为空时，B的第k大数就是A和B的第k大数。
        if (k == 1) return min(A[0], B[0]); //?不加这句可以吗？
        
        // 比较A和B的第k/2个数，（1）当二者相等时即为第k大的数；
        // （2）当A[k/2]较小时，由于A是有序数组，所以A中前k/2个数都小于实际的第k大的数，
        // 所以可以将A的前k/2个数删除，然后就是查找A剩下的数据和B中的第k/2大的数。
        // 当B[k/2]较小时，类似（2）。
        // cout<<k<<endl;
        int a_i = min(k / 2, m), b_i = k - a_i; // 考虑了k为奇数的情况。
        if (A[a_i - 1] < B[b_i - 1])
            return find_kth(A + a_i, m - a_i, B, n, b_i);
        else if (A[a_i - 1] > B[b_i - 1])
            return find_kth(A, m, B + b_i, n - b_i, a_i);
        else
            return A[a_i - 1];
    }
};

