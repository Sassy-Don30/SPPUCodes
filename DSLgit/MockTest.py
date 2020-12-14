""" Write a Python program to compute following operations on String: 
a)Change Case
b)Palindrome
c)Compare """


def SwapCase(letter):
    if letter.islower():
        return letter.upper()
    elif letter.isupper():
        return letter.lower()
    return letter


def Palindrome(str1):
    for i in range(len(str1)):
        if str1.lower()[i] != str1.lower()[len(str1) - 1 - i]:
            return False
    return True


def CompareStr(str1, str2):
    if len(str1) != len(str2):
        return False

    else:
        for i in range(len(str1)):
            if str1.lower()[i] != str2.lower()[i]:
                return False
        return True


def main():
    while True:
        print("\nMenu: \n1.Change Case \n2.Palindrome \n3.Compare \n0.Exit")
        ch = int(input("Enter choice:"))
        if ch == 1:
            # print(str.swapcase())
            inputStr = input("\nEnter string: ")
            for i in inputStr:
                print(SwapCase(i), end='')

        elif ch == 2:
            inputStr = input("\nEnter string: ")
            print(Palindrome(inputStr))
            # print(inputStr.lower() == inputStr.lower()[::-1])

        elif ch == 3:
            inputStr = input("\nEnter string: ")
            str2 = input("Enter second string: ")
            print(CompareStr(inputStr, str2))
            # print(inputStr.lower() == str2.lower())

        elif ch == 0:
            print("BYE!\n")
            break

        else:
            print("Enter appropriate value\n")


if __name__ == '__main__':
    main()
