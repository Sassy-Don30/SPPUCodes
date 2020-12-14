class Matrix:
    mat = []

    def __init__(self, name):
        self.name = name
        print("For matrix", self.name)  # matrix ka input lene ke liye
        self.m = int(input("enter no. of rows:"))
        self.n = int(input("enter no. of column:"))
        self.mat = []
        tempRowMat = []
        for i in range(self.m):
            for j in range(self.n):
                e = int(input("Enter the element i[%d][%d]:" % (i + 1, j + 1)))  # isko kya khete hai bhool gaya
                tempRowMat.append(e)
            self.mat.append(tempRowMat)
            tempRowMat = []

    @staticmethod
    def AddMat(m1, m2):  # 2 empty mat declare fir loops lagake add kiya sabko
        addMatrix = []
        tempRowMat = []
        for i in range(m1.m):
            for j in range(m1.n):
                e = m1.mat[i][j] + m2.mat[i][j]
                tempRowMat.append(e)
            addMatrix.append(tempRowMat)
            tempRowMat = []
        return addMatrix

    @staticmethod
    def subMat(m1, m2):  # similar to add
        subMatrix = []
        tempRowMat = []
        for i in range(m1.m):
            for j in range(m1.n):
                e = m1.mat[i][j] - m2.mat[i][j]
                tempRowMat.append(e)
            subMatrix.append(tempRowMat)
            tempRowMat = []
        return subMatrix

    @staticmethod
    def MultiMat(m1, m2):  # sum declare karke nikala fir append temp wala mat me, fir use append final mat me
        productMat = []
        tempRowMat = []
        tempSum = 0
        for i in range(m1.m):
            for j in range(m2.n):
                for k in range(m2.m): # m2.m nahi karna tha
                    tempSum += m1.mat[i][k] * m2.mat[k][j]
                tempRowMat.append(tempSum)
                tempSum = 0
            productMat.append(tempRowMat)
            tempRowMat = []
        return productMat

    @staticmethod
    def Transpose(mat):  # 2 empty banay, loop lagaya, fir ulta append shuru kiya
        transMat = []
        tempRowMat = []
        for i in range(mat.m):
            for j in range(mat.m):
                e = mat.mat[j][i]
                tempRowMat.append(e)
            transMat.append(tempRowMat)
            tempRowMat = []  # reset kiya taaki next time bhi append kar sake
        return transMat


def CompareAdd(m, n, p, q):  # compare kar rahe taaki add ka dekh sake
    if m == p and n == q:
        return 1
    else:
        return 0


def CompareMultiplication(n, p):
    if n == p:
        return 1
    else:
        return 0


again = "y"
while again == "Y" or again == "y":
    mat1 = Matrix(1)
    mat2 = Matrix(2)
    m = mat1.m
    n = mat1.n
    p = mat2.m
    q = mat2.n
    opAgain = "y"
    while opAgain == "Y" or opAgain == "y":
        option = int(input("Enter\n1 for addition\n2 for subtraction\n3 for multiplication\n4 for transpose"))
        if option == 1:
            check = CompareAdd(m, n, p, q)
            if check:
                print("Addition of matrices is", Matrix.AddMat(mat1, mat2))
            else:
                print("cannot be added")

        elif option == 2:
            check = CompareAdd(m, n, p, q)
            if check:
                print("Subtraction of matrices is", Matrix.subMat(mat1, mat2))
            else:
                print("cannot be subtracted")

        elif option == 3:
            check = CompareMultiplication(n, p)
            if check:
                print("Multiplication of matrices is", Matrix.MultiMat(mat1, mat2))
            else:
                print("cannot be multiplied")

        elif option == 4:
            print("Transpose of matrix 1 is", Matrix.Transpose(mat1))
            print("Transpose of  matrix 2 is", Matrix.Transpose(mat2))

        else:
            print("Wrong input")
        opAgain = input("Do you want to perform other operations? (Y/N)") # operations unhi 2 matrix pe
    again = input("Do you want to perform operation of different matrices? (Y/N)") # Alag input lene ke liye matrices ke
