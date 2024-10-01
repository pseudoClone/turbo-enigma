#include <iostream>
#include <vector>

std::vector<std::vector<int>> strassenAdd(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B)
{
        int n = A.size();
        std::vector<std::vector<int>> C(n, std::vector<int> (n));
        for(size_t i = 0; i < n; i++){
                for(size_t j = 0; j < n; j++){
                        C[i][j] = A[i][j] + B[i][j];
                }
        }
        return C;
}

std::vector<std::vector<int>> strassenSub(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B)
{
        int n = A.size();
        std::vector<std::vector<int>> C(n, std::vector<int>(n));
        for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                        C[i][j] = A[i][j] - B[i][j];
                }
        }
        return C;
}

std::vector<std::vector<int>> strassenMul(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B)
{
        int n = A.size();
        std::vector<std::vector<int>> C(n, std::vector<int>(n));
        if(n == 1){
                return std::vector<std::vector<int>>(1, std::vector<int>(1, A[0][0] * B[0][0]));
                /*Balla Bujhyo, vector of vector containing, 1 vector inside and that vector is 1 element only i.e A*B*/
        }
        int k = n / 2;
        std::vector<std::vector<int>> A11(k, std::vector<int>(k));
        std::vector<std::vector<int>> A12(k, std::vector<int>(k));
        std::vector<std::vector<int>> A21(k, std::vector<int>(k));
        std::vector<std::vector<int>> A22(k, std::vector<int>(k));


        std::vector<std::vector<int>> B11(k, std::vector<int>(k));
        std::vector<std::vector<int>> B12(k, std::vector<int>(k));
        std::vector<std::vector<int>> B21(k, std::vector<int>(k));
        std::vector<std::vector<int>> B22(k, std::vector<int>(k));

        //Divide process for quadrants, remember that always in a square matrix, this will be possible, okay?
        for (size_t i = 0; i < k; i++) {
                for (size_t j = 0; j < k; j++) {
                        A11[i][j] = A[i][j];
                        A12[i][j] = A[i][j + k];
                        A21[i][j] = A[i + k][j];
                        A22[i][j] = A[i + k][j + k];

                        B11[i][j] = B[i][j];
                        B12[i][j] = B[i][j + k];
                        B21[i][j] = B[i + k][j];
                        B22[i][j] = B[i + k][j + k];
                }

        }

        // 7 products as opposed to 8 in traditional method; Refer to CLRS ko ALgorithm book for this section, ramro theory chha
        std::vector<std::vector<int>> M1 = strassenMul(strassenAdd(A11, A22), strassenAdd(B11, B22));
        std::vector<std::vector<int>> M2 = strassenMul(strassenAdd(A21, A22), B11);
        std::vector<std::vector<int>> M3 = strassenMul(A11, strassenSub(B12, B22));
        std::vector<std::vector<int>> M4 = strassenMul(A22, strassenSub(B21, B11));
        std::vector<std::vector<int>> M5 = strassenMul(strassenAdd(A11, A12), B22);
        std::vector<std::vector<int>> M6 = strassenMul(strassenSub(A21, A11), strassenAdd(B11, B12));
        std::vector<std::vector<int>> M7 = strassenMul(strassenSub(A12, A22), strassenAdd(B21, B22));

        /* What fucking sorcerry is this? adding const solves the problem of strassenMul's call not matching to any of the defined functions */
        /* Remove the const from the parameters and you have problems, also remove the const and remove the &, your problem is solved */
        /* Your problem is solved but what at what cost? Like you are already using recursion and add copying of vectors to functions to that */
        /* Yes time complexity is 0^(log 7) but your memory will be fucked, imagine that in embedded systems */
        
        for (size_t i = 0; i < k; i++) {
                for (size_t j = 0; j < k; j++) {
                        C[i][j]     = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
                        C[i][j + k] = M3[i][j] + M5[i][j];
                        C[i+k][j]   = M2[i][j] + M4[i][j];
                        C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
                }
        }
        /*For fuck sake, the reduced matrix has the size k, not n, I was putting i < n and j < n*/
        return C;
}

void printProduct(const std::vector<std::vector<int>>& C)
{
        for (size_t i = 0; i < C.size(); i++) {
                for (size_t j = 0; j < C[i].size(); j++) {
                        std::cout<<C[i][j]<<"   ";                
                }
                std::cout<<std::endl;
        }
}

int main (int argc, char *argv[]) {

        int n; //Order
        std::cout<<"Enter the order of both matrices: ";
        std::cin>>n;
        std::vector<std::vector<int>> A(n, std::vector<int>(n));
        std::vector<std::vector<int>> B(n, std::vector<int>(n));
        std::cout<<"Enter the first matrix A(row-wise): "<<std::endl;
        for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                        std::cin>>A[i][j];
                }
        }
        std::cout<<"Enter the first matrix B(row-wise): "<<std::endl;
        for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                        std::cin>>B[i][j];
                }
        }
        std::vector<std::vector<int>> C = strassenMul(A, B);
        std::cout<<"The product matrix is: "<<std::endl;
        printProduct(C);

        return 0;
}
