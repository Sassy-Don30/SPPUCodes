class Matrix:
    lst = []

    def __init__(self):
        self.len = int(input("Enter number of elements:"))  # declare list and append stuff in it
        for i in range(self.len):
            self.lst.append(int(input("Enter element at position " + str(i + 1) + ":")))

    def BubbleSort(self):
        for i in range(self.len - 1):  # 0 se lekar end se ek kam tak gay
            for j in range(self.len - 1 - i):  # similarly j ko leke gay, max ke bahar na jay isleye aise kiya
                if self.lst[j] > self.lst[j + 1]:  # agar order galat hai toh change
                    self.lst[j], self.lst[j + 1] = self.lst[j + 1], self.lst[j]
            print(self.lst)

    def InsertionSort(self):
        for i in range(1, self.len):  # pehle element se end tak gay
            current = self.lst[i]  # var ko value di ith value ki
            j = i - 1  # j ko uske ek pehle ghumaya
            while j >= 0 and current <= self.lst[j]:  # aage se piche jayenge isleye j ki condition aur agar key
                self.lst[j + 1] = self.lst[j]  # choota hai toh use piche le liya
                j -= 1  # j ko kam karte gay taaki uske piche wala dekh sake
            self.lst[j + 1] = current  # jab khatam ho jay j ka kaam, toh value de denge usko key ki
            print(self.lst)

    def SelectionSort(self):
        for i in range(self.len):  # 0 se aage tak jayenge
            minIndex = i  # current wale ko minimum
            for j in range(i + 1, self.len):  # doosra loop uske ek aage se end tak
                if self.lst[minIndex] > self.lst[j]:  # agar minIndex wala pe element bada hai jth element se
                    minIndex = j  # toh min wala change karenge kyuki min sabse choota chahiye (obviously)
            self.lst[i], self.lst[minIndex] = self.lst[minIndex], self.lst[i]  # jab sabse choota mil gaya toh swap karo
        print(self.lst)

    def ShellSort(self):
        gap = self.len // 2
        while gap >= 1:
            for i in range(0, self.len - gap):
                if self.lst[i] > self.lst[i + gap]:
                    self.lst[i], self.lst[i + gap] = self.lst[i + gap], self.lst[i]
            gap //= 2
        print(self.lst)

    def Partition(self, start, end):
        pivot = self.lst[start]
        low = start + 1
        high = end

        while True:

            while low <= high and self.lst[high] >= pivot:
                high -= 1

            while low <= high and self.lst[low] <= pivot:
                low += 1

            if low <= high:
                self.lst[low], self.lst[high] = self.lst[high], self.lst[low]

            else:
                break

        self.lst[start], self.lst[high] = self.lst[high], self.lst[start]

        return high

    def QuickSort(self, start, end):
        if start >= end:
            return

        part = self.Partition(start, end)
        self.QuickSort(start, part - 1)
        self.QuickSort(part + 1, end)


testMat = Matrix()
# testMat.BubbleSort()
# testMat.InsertionSort()
# testMat.SelectionSort()
# testMat.ShellSort()
testMat.QuickSort(0, testMat.len-1)
print(testMat.lst)
