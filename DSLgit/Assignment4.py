class Array:
    lst = []  # jis list me sab dalenge

    def __init__(self):
        self.len = int(input("Enter number of elements:"))


    def SortedInput(self):
        for i in range(self.len):  # list length me loop lagaya
            x = int(input("Enter element at position " + str(i + 1) + ":"))
            self.lst.append(x)
        print(self.lst)  # show kiya pura input

    def UnsortedInput(self):
        for i in range(self.len):  # input process same
            x = int(input("Enter element at position " + str(i + 1) + ":"))
            self.lst.append(x)
        for j in range(self.len - 1, 0, -1):  # length se ek kaam se lekar ulte chale
            for k in range(j):  # ek loop lagaya taaki compare kar sake
                if self.lst[k] > self.lst[k + 1]:  # ascending order me dalne ki condition
                    self.lst[k], self.lst[k + 1] = self.lst[k + 1], self.lst[k]  # tuple wala method se exchange
        print(self.lst)

    def UnsortedInput2(self):
        for i in range(self.len):
            x = int(input("Enter element at position " + str(i + 1) + ":"))
            self.lst.append(x)
            for j in range(i, 0, -1):
                if self.lst[j] < self.lst[j - 1]:
                    self.lst[j], self.lst[j - 1] = self.lst[j - 1], self.lst[j]
            print(self.lst)

    def LinearSearch(self, toFind):
        for i in range(self.len):  # list me ghoome uske baad agar mila toh uski position return
            if self.lst[i] == toFind:
                return i + 1
        else:
            return -1

    def BinarySearch(self, toFind):
        start = 0  # 0 se start aur length se ek piche khatam
        end = self.len - 1
        while start <= end:  # condition ki kab tak run hoga
            mid = (start + end) // 2  # floor division kiya aur middle value allot kiya mid ko
            if toFind > self.lst[mid]:  # jo dhoondhna hai agar middle se bada hai, to piche ka gayab
                start = mid + 1  # middle wale se ek aage kiya start ko
            elif toFind < self.lst[mid]:  # jo dhoondhna agar middle se choota hai, toh aage wala gayab
                end = mid - 1  # middle wale ke ek piche kiya end
            else:
                return mid + 1  # agar mil gaya toh voh return
        return -1

    def BinarySearchRecursive(self, start, end, toFind):
        if start <= end:
            mid = (start + end) // 2
            if self.lst[mid] == toFind:
                return mid + 1

            elif self.lst[mid] > toFind:
                return self.BinarySearchRecursive(start, mid - 1, toFind)

            else:
                return self.BinarySearchRecursive(mid + 1, end, toFind)

    def SentinelSearch(self, toFind):
        last = self.lst[self.len - 1]  # last element fix kiya as array ka last element
        self.lst[self.len - 1] = toFind  # usko searching element ka allot kiya
        i = 0
        while self.lst[i] != toFind:  # loop to compare elements
            i += 1
        self.lst[self.len - 1] = last  # original jo last tha usko allot kiya
        if (i < self.len - 1) or (
                toFind == self.lst[self.len - 1]):  # agar last se pehle compare hua, aur true aaya toh return
            return i + 1
        else:
            return -1  # nahi mila toh error

    def FibonacciSearch(self, toFind):
        fibM_minus_2 = 0  # m-2 allot kiya 0
        fibM_minus_1 = 1  # m-1 ko kiya 1
        fibM = fibM_minus_1 + fibM_minus_2  # next no. pichle 2 ka sum, m hai ye

        while fibM < self.len:  # values increase ki tab tak jab tak array length ke barabar nahi ho jata
            fibM_minus_2 = fibM_minus_1  # m-2 ko banaya m-1
            fibM_minus_1 = fibM  # m-1 ko banaya m
            fibM = fibM_minus_1 + fibM_minus_2  # aur agla wala increase

        offset = -1  # offset -1 allot kiya
        while fibM > 1:  # condition lagai kyuki iske baad array ke bahar jayga
            i = min(offset + fibM_minus_2, self.len - 1)  # minimum ka inbuilt hai, niceeeee
            if self.lst[i] < toFind:  # un dono me se minimum wale ko index leke compare aur agar toFind se choota hai
                fibM = fibM_minus_1  # to offset se lekar i tak array gayab kar do
                fibM_minus_1 = fibM_minus_2  # m ko m-1 kar diya aur m-1 ko m-2 kar diya
                fibM_minus_2 = fibM - fibM_minus_1  # m-2 ko sabse kam value di
                offset = i  # offset change kiya taaki us point ke aage compare kare fir

            elif self.lst[i] > toFind:  # agar us index pe bada hua voh toFind se, toh i ke aage gayab
                fibM = fibM_minus_2  # m ko m-2 kiya
                fibM_minus_1 -= fibM_minus_2  # m-1 ko m-2 kiya
                fibM_minus_2 = fibM - fibM_minus_1  # m-2 ko normally allot kiya

            else:
                return i + 1  # agar turant mil gaya toh uski location return kar di, index +1 taaki position aay
        if fibM_minus_1 and self.lst[offset + 1] == toFind:  # last element pe toFind ke same ho rahe
            return offset + 2  # toh return uski position karenge

        return -1  # nahi mila array me


while True:
    print("Menu: \n1.Sorted Input \n2.Unsorted Input \n0.Exit")
    choice = int(input("Enter choice:"))  # menu ke choice li
    if choice == 1:
        arr1 = Array()  # object banaya aur input liya
        arr1.SortedInput()
        op = int(input("\nEnter operation to perform:\n3.Linear Search \n4.Binary Search \n5.Sentinel Search "
                       "\n6.Binary Search Recursive \n7.Fibonacci Search \n"))
        if op == 3:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr1.LinearSearch(find)))
        elif op == 4:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr1.BinarySearch(find)))
        elif op == 5:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr1.SentinelSearch(find)))
        elif op == 6:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr1.BinarySearchRecursive(0, arr1.len-1, find)))
        elif op == 7:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr1.FibonacciSearch(find)))
        else:
            print("Enter appropriate choice....")
    elif choice == 2:
        arr2 = Array()
        arr2.UnsortedInput2()
        op = int(input("\nEnter operation to perform:\n3.Linear Search \n4.Binary Search \n5.Sentinel Search "
                       "\n6.Binary Search Recursive \n7.Fibonacci Search \n"))
        if op == 3:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr2.LinearSearch(find)))
        elif op == 4:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr2.BinarySearch(find)))
        elif op == 5:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr2.SentinelSearch(find)))
        elif op == 6:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr2.BinarySearchRecursive(0, arr2.len-1, find)))
        elif op == 7:
            find = int(input("Enter element to find:"))
            print("Element found at " + str(arr2.FibonacciSearch(find)))
        else:
            print("Enter appropriate choice....")
    else:
        print("Bye")
        break


