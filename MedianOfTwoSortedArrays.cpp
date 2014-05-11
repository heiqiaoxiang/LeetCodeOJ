class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1) //����
            return find_kth(A, m, B, n, total / 2 + 1);
        else //ż��
            return (find_kth(A, m, B, n, total / 2) 
                    + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) //������������A��B�е�k������� 
    {
        if (m > n) return find_kth(B, n, A, m, k); //�ٶ�����m<=n��
        if (m == 0) return B[k - 1]; //AΪ��ʱ��B�ĵ�k��������A��B�ĵ�k������
        if (k == 1) return min(A[0], B[0]); //?������������
        
        // �Ƚ�A��B�ĵ�k/2��������1�����������ʱ��Ϊ��k�������
        // ��2����A[k/2]��Сʱ������A���������飬����A��ǰk/2������С��ʵ�ʵĵ�k�������
        // ���Կ��Խ�A��ǰk/2����ɾ����Ȼ����ǲ���Aʣ�µ����ݺ�B�еĵ�k/2�������
        // ��B[k/2]��Сʱ�����ƣ�2����
        // cout<<k<<endl;
        int a_i = min(k / 2, m), b_i = k - a_i; // ������kΪ�����������
        if (A[a_i - 1] < B[b_i - 1])
            return find_kth(A + a_i, m - a_i, B, n, b_i);
        else if (A[a_i - 1] > B[b_i - 1])
            return find_kth(A, m, B + b_i, n - b_i, a_i);
        else
            return A[a_i - 1];
    }
};

