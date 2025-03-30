
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

GameDecisionTree.h has a function (called loadStoryFromFile() ) that loads the data by opening a filestream and using getline() along with delimiters repeatedly. Each line is loaded into a Story object, and every Story object is the data for a Node. Each Node is inserted into a vector of Node pointers. After establishing the root Node as the first Node in the vector, the function then iterates through every Node and attaches the left and right children to the correct Nodes by accessing their index. For example, line 1 of the story.txt file ends with |2|3|. This tells the file that the left child will be on line 2 (which is index 1 of the vector) and that the right child will be on line 3 (index 2). The leaf nodes will point to null, which is represented as -1 in the story.txt file. 

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)
As soon as the user runs the program, the console will display the root Node Story and ask for a decision. The user can either enter 1 or 2 to proceed, and if they do not, the console will loop infinitely asking for a 1 or 2. When the player reaches a leaf node, the game will notify the player that they have reached the ending and then exit.

There is one special case where multiple events lead to the same outcome. This is on line 15, and both children of this node are on line 30. For the user, this is when they input 2,2,2 in that order. After inputting 2,2,2, their next option will not matter as both point to the same Node and the same ending.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

The file reads each line by using getLine, which puts the line into a string. Using getLine again, but with the delimiter '|', each line is separated into its respective parts. These parts are passed into a Story constructor argument. The Nodes have to be properly linked IN THE FILE rather than by the code. In other words, if one line of the story.txt file has incorrect information, the game will work incorrectly. The game will still run, but the path will not be correct. It is important that the story.txt file is created correctly to ensure that the game runs correctly.

The only difficulty while handling file input was initially opening the file, as the file name is not enough to work. The file must be placed in the same folder as the CS210PA2.exe file in order to run like that. As per assignment instructions, our story.txt file must be in the LastName_FirstNameRPG folder. Therefore, I had to add "../Pham_JasonRPG/" to the file name, which essentially tells the program to back out of the folder that contains the CS210PA2.exe file and enter the folder named Pham_JasonRPG to look for the correct file.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Most code worked as intended in the first run. There were about three times when they didn't.
1. The first was detailed in #5, which is when I wasn't able to open the file correctly.
2. The second is actually separating the lines into their respective data. I didn't know that the getline method can only work when the first argument passes a stream rather than a string. I had to convert the string I had containing the relevant line into a stringstream, which worked.
3. The last is when the code gave an error that it was accessing indexes in the vector that didn't exist. As mentioned before, errors like this happen because the .txt file was created incorrectly. I had mistyped a number (7 instead of 6), so the code looked for the Node at index 6 instead of 5. This caused an error, and I was able to fix it by adjusting the .txt file accordingly.

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
- **Searching for an event in the tree** → `O(?)`  
- **Game traversal efficiency** → `O(?)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
