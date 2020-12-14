def MergeArray(pehliArray, doosriArray):
    temp = []  # empty list aur 2 variables liye, for loop isleye nahi lagaya kyuki confuse ho gaya :P
    i = 0
    j = 0

    while i < len(pehliArray) and j < len(doosriArray):  # dono list me ghoome
        if pehliArray[i] < doosriArray[j]:  # agar current element of pehli array choota hai toh
            temp.append(pehliArray[i])  # voh append ho jayga
            print("Increment i :" + str(i))
            i += 1  # aur i increase karenge aage jaane ke liye

        elif pehliArray[i] == doosriArray[j]:
            temp.append(pehliArray[i])
            temp.append(doosriArray[j])
            print("Increment i :" + str(i))
            print("Increment j :" + str(j))
            i += 1
            j += 1

        else:  # agar doosri array ka choota hai toh
            temp.append(doosriArray[j])  # voh append karenge
            print("Increment j :" + str(j))
            j += 1  # j increase

    # jab upar wala ho jayga, kuch elements bach rahe the append hone, sirf pehli arr tak ke aa rahe the
    # kyuki j agar koi ek chooti hui toh kya hoga upar
    while i < len(pehliArray):  # toh iski length me firse ghoome
        temp.append(pehliArray[i])  # append karte gay
        print(i)
        i += 1

    while j < len(doosriArray):  # similar yaha bhi
        temp.append(doosriArray[j])
        print(j)
        j += 1

    print(temp)


def BubbleSort(pehliArr):
    for i in range(len(pehliArr) - 1):
        for j in range(len(pehliArr) - 1 - i):
            if pehliArr[j] > pehliArr[j + 1]:
                pehliArr[j], pehliArr[j + 1] = pehliArr[j + 1], pehliArr[j]
    return pehliArr


arr1 = [1, 4, 6, 8]
arr2 = [1, 2, 3, 9, 8]
MergeArray(BubbleSort(arr1), BubbleSort(arr2))
