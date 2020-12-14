class StringClass:
    def __init__(self, s):
        self.s = s

    @staticmethod
    def lengthOf(l):  # haar alphabet pe count increase
        count = 0
        for i in l:
            count += 1
        return count

    @staticmethod
    def formList(s):
        tempList = []
        tempStr = ""
        for i in range(StringClass.lengthOf(s)):  # word list banane ke liye
            if s[i] == " ":  # space aane pe word khatam toh add in list uske piche ka
                tempList += [tempStr]
                tempStr = ""  # reset kiya
            else:
                tempStr += s[i]  # agar space nahi aaya toh tempStr me next alphabet add
            if i == StringClass.lengthOf(s) - 1:
                tempList += [tempStr]  # last word ke baad space nahi hoga isleye uske liye alag case
        return tempList

    @staticmethod
    def longestWord(s):
        wordList = StringClass.formList(s)  # word list banai aur empty list aur index container
        lenList = []
        longestIndex = 0
        for word in wordList:  # iterate in wordList aur word length add hoga
            lenList += [StringClass.lengthOf(word)]
        for i in range(StringClass.lengthOf(lenList) - 1):  # iterate in length of words wali list
            if lenList[i] > lenList[i + 1]:  # agar is word ki lenght jada hui toh usko de denge value
                longestIndex = i
            else:
                longestIndex = i + 1
        return wordList[longestIndex]

    @staticmethod
    def freChar(s):
        userChar = input("Enter the character whose frequency is to be found : ")
        count = 0
        for i in s:  # string me iterate
            if i == userChar:  # match hone pe count increase
                count += 1
        return count

    @staticmethod
    def wordCount(s, word):
        wordList = StringClass.formList(s)  # list banai aur count = 0 kiya
        # userWord=input("Enter the word whose frequency is to be found : ")
        count = 0
        for i in wordList:  # wordList me iterate
            if i == word:  # match hone pe count increase
                count += 1
        return count

    @staticmethod
    def CharOccur(s):
        wordList = StringClass.formList(s)  # word list aur empty list
        noRepeat = []
        for i in wordList:  # iterate in word list
            if i not in noRepeat:
                noRepeat += [i]  # haar word ki ek copy dal di list me
        for i in noRepeat:  # haar word ke liye iterate
            print("Occurrences of", i, ":", StringClass.wordCount(s, i))  # word count wala function run

    @staticmethod
    def isPalindrome(s):
        revStr = ""  # empty string banai
        for i in range(StringClass.lengthOf(s) - 1, -1, -1):  # (start, end, step) ulta chale aur add kiya
            revStr += s[i]
        if revStr == s:
            print("String is a palindrome")
        else:
            print("String is not a palindrome")

    @staticmethod
    def IndexOfSubString(s):
        sub = input("Enter the substring : ")
        ind = 0
        for i in range(StringClass.lengthOf(s)):
            if s[i:(i + StringClass.lengthOf(sub))] == sub:
                ind = i
        return ind


i = "y"
while i == "Y" or i == "y":
    obj = StringClass(input("Enter string : "))
    j = "y"
    while j == "Y" or j == "y":
        choice = int(input(
            "Enter :\n1 for displaying word with longest length\n2 for finding occurence of character in the "
            "string\n3 for checking palindrome or not\n4 for displaying first index of the substring\n5 to find "
            "occurrence of each word in the string\n"))
        if choice == 1:
            print(StringClass.longestWord(obj.s))
        elif choice == 2:
            print(StringClass.freChar(obj.s))
        elif choice == 3:
            StringClass.isPalindrome(obj.s)
        elif choice == 4:
            print(StringClass.IndexOfSubString(obj.s))
        elif choice == 5:
            StringClass.CharOccur(obj.s)
        else:
            print("wrong input")
        j = input("Want to try again? (Y/N)")
    i = input("Want to enter new string? (Y/N)")
