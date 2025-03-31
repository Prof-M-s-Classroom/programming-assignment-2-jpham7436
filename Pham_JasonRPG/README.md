
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Jason Pham**
### **Student ID:132526911**

---

## **1. Project Overview**
This is a text-based RPG that uses a binary tree to create pathways. The information on the storylines and pathways is contained in a story.txt file. The GameDecisionTree.h file contains most of the code that runs the program. This file is what loads the data from the story.txt file into a binary decision tree (more about how this works later). This file also contains the function that allows the user to play the game (called playGame() ). All the user needs to do is run the program, enter 1 or 2 to decide a path, and continue until they reach an ending. If they enter anything other than 1 or 2, the console will loop, asking the user to input either 1 or 2.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`  
- **`GameDecisionTree.h`** → `[Explain what this file contains]`  
- **`Node.h`** → `[Explain what this file contains]`  
- **`Story.h`** → `[Explain what this file contains]`  
- **`story.txt`** → `[Explain how the game loads story events from this file]`  

---

## **3. Decision Tree Construction**

GameDecisionTree.h has a function (called loadStoryFromFile() ) that loads the data by opening a filestream and using getline() along with delimiters repeatedly. Each line is loaded into a Story object, and every Story object is the data for a Node. Each Node is inserted into a vector of Node pointers. After establishing the root Node as the first Node in the vector, the function then iterates through every Node and attaches the left and right children to the correct Nodes by accessing their index. For example, line 1 of the story.txt file ends with |2|3|. This tells the file that the left child will be on line 2 (which is index 1 of the vector) and that the right child will be on line 3 (index 2). The leaf Nodes will point to null, which is represented as -1 in the story.txt file. 

---

## **4. Game Traversal**

As soon as the user runs the program, the console will display the root Node Story and ask for a decision. The user can either enter 1 or 2 to proceed, and if they do not, the console will loop infinitely asking for a 1 or 2. When the player reaches a leaf Node, the game will notify the player that they have reached the ending and then exit.

There is one special case where multiple events lead to the same outcome. This is on line 15, and both children of this Node are on line 30. For the user, this is when they input 2,2,2 in that order. After inputting 2,2,2, their next option will not matter as both children point to the same Node and the same ending.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

The file reads each line by using getline, which puts the line into a string. Using getline again, but with the delimiter '|', each line is separated into its respective parts. These parts are passed into a Story constructor argument. The Nodes have to be properly linked IN THE FILE rather than by the code. In other words, if one line of the story.txt file has incorrect information, the game will work incorrectly. The game will still run, but the path will not be correct. It is important that the story.txt file is created correctly to ensure that the game runs correctly.

The only difficulty while handling file input was initially opening the file, as the file name itself is not enough to work with. The file must be placed in the same folder as the CS210PA2.exe file in order to run like that. As per assignment instructions, our story.txt file must be in the LastName_FirstNameRPG folder. Therefore, I had to add "../Pham_JasonRPG/" to the file name, which essentially tells the program to back out of the folder that contains the CS210PA2.exe file and enter the folder named Pham_JasonRPG to look for the correct file.

---

## **6. Debugging Process (Errors & Fixes)**

Most code worked as intended in the first run. There were three times when it didn't.
1. The first was detailed in #5, which is when I wasn't able to open the file correctly. I was able to figure out why the file wasn't opening and changed the file name accordingly.
   
2. The second is actually separating the lines into their respective data. I didn't know that the getline() method would only work when the first argument passes a stream rather than a string. I had to convert the string I had containing the relevant line into a stringstream, which worked.

3. The last is when the code gave an error that it was accessing indexes in the vector that didn't exist. As mentioned before, errors like this happen because the .txt file was created incorrectly. I had mistyped a number (7 instead of 6), so the code looked for the Node at index 6 instead of 5. This caused an error, and I was able to fix it by adjusting the .txt file accordingly.

## **7. Sample Output & Walkthrough**
You wake up in a tent. There is a table with some objects to your left. Investigate the table (1) or exit the tent (2)?
1 or 2? **-2**

You find the tent in the middle of a park. There are castle walls around you. Explore the park (1) or explore the castle
 (2)? 1 or 2? **-1**

The park is larger than you thought. There is a small river flowing through it and a path that goes in front of you and
behind you. Do you follow the path in front (1) or behind you (2)? 1 or 2? **-2**

You follow the path behind you and eventually reach a gate. Behind it, you can only see a thick forest. All you can do i
s enter the forest (1). Enter 1 to continue.**2**

Please press enter 1 to continue.**3**

Please press enter 1 to continue.**-1**

Please press enter 1 to continue.**0**

Please press enter 1 to continue.**1**

You enter the forest, and very quickly, you get lost. The castle walls are nowhere in sight, and you fear that you are o
nly getting more and more lost. As night falls, you find a small stream for water and continue to walk. You come across
a small cave and choose to rest there for the night. Your new life begins in the wilderness.
You've reached the end. Thanks for playing!
Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**
There are three core methods: loadStoryFromFile(), playGame(), and validateUserInput().

loadStoryFromFile(): **Big O (n)** where n is the number of Nodes/the number of lines in the .txt file. This is because it has one while loop that iterates through every line in the .txt file. This loop has a time complexity of O(n). The second loop is a for loop that iterates through every Node in the vector of Node pointers. This loop also has a time complexity of O(n). These two loops account for most of the code in the method, aside from a few variable declarations that ultimately have a time complexity of O(1).

playGame(): **Big O (n)** where n is the number of times the user enters information. While the method would normally have a Big O of O(log n), where n is the number of Nodes in the BST, the playGame() function calls validateUserInput() multiple times anytime the game wants to receive user input. This is to ensure that the user inputs either 1 or 2 and nothing else. The validateUserInput() method has the potential to run an infinite number of times if the user never enters 1 or 2. However, each iteration only has a time complexity of O(1). Thus, the validateUserInput() method has a time complexity of O(n), where n is the number of times the user enters information, which makes playGame() have a Big O of O(n).

validateUserInput(): **Big O (n)**. The validateUserInput() method has the potential to run an infinite number of times if the user never enters 1 or 2. However, each iteration only has a time complexity of O(1). Thus, the validateUserInput() method has a time complexity of O(n), where n is the number of times the user enters information, which makes playGame() have a Big O of O(n).


---
## **9. Edge Cases & Testing**
There are two important edge cases that I accounted for when programming. 

1. The player reaches a dead-end. The playGame() function utilizes a while loop to traverse through the binary decision tree. I ensured that, if the player reaches a Node where both children are NULL, the while loop would tell the user that they've reached the end and exit accordingly.

2. The player never enters 1 or 2. The playGame() function calls a method called validateUserInput() anytime it wants to take in the user's decision. Depending on whether or not there is one or two options available to the user, the validateUserInput() function will loop infinitely until the user inputs one of the correct options. This ensures that the user doesn't try to make a decision that doesn't exist and crash the game.


---

## **10. Justification of Additional Features (If Any)**
The only extra feature I added was the validateUserInput() method, which infinitely loops until the user enters one of the available options (either 1 or 2). 

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
