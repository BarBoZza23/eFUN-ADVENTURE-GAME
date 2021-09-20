# eFUN-ADVENTURE-GAME
Creation of an adventure console game for a fantasy company. 

The project was writen in cpp programming language

The aim of the game is to achieve a goal that is set by the user through the options menu.

There are four different goals.
i) Creation of Fire.
ii) Creation of Grilled Fish.
iii) Creation of Roast Meat.
iv) Burn all your money (funny addition to the game).

1. The commands given in the terminal should be Greeklish CAPITALS.

2. Only Vectors were used to implement all the functions.

3. For the above reason the "+" operator for a combination of objects was NOT overloaded. (No need).

OBJECT COMBINATION FUNCTION: 
Vector checks if there are objects that the user wants to combine. 
If they exist then it creates the new Object and deletes from the Vector the Objects with which the new one was created. 
If they do not exist, an appropriate message is displayed.

4. After initialization if the user wants to add an object to a Vector there is the possibility. 
   I read the file again, I find the object and if it does NOT already exist then it is added and removed by the other Vector.
   In the file that I read the objects that will be assigned to the Vectors, there are also two objects that are NOT assigned to the Vectors of the Environment and the Backpack.
   The reason they entered the file was to be able to move from one Vector to another.
   
5. Operator overload function << performed, but not working properly. Vectors addresses are displayed, not their contents.
   Corresponding implementation with Tables works without problems. (Not presented in this paper).
   Another method is used to display the data.

6. STEPS IN ORDER TO ACHIEVE THE GAME GOALS
