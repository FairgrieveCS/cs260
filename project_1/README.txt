Jonathan Fairgrieve
Assignment 1


Bag of Marbles 
NOTE: I am still fairly uncomfortable with C++, so some of my ideas about how it could be implemented may be completely wrong!

1.) Representing a marble
- A "marble" in the case of the problem here is going to be an object, or as close as possible to one, with (semi)unique attributres
- A "bag of marbles" will be our data structure in which we store our data (marbles), I am currently considering an array
- For my marbles, I want them to have a color(RGB) as well as a number(1-10)
- I would like these two attributes to be randomly generated(Although I'm not sure how to implement this in C++ yet)

2.) Adding marbles to bag
- We declare each marble as an object of the marbles class and declare their specific attributes
- We create an arrow to act as the bag
- Add one marble at a time (for loop) appending the objects to the list

|| SEE ATTACHED PAINT DRAWING FOR A DIAGRAM OF THESE PROCESSES ||

3.) Removing marbles from the bag
- I want the back to simulate a real bag, so this means shuffling the marbles within the array
- This will allow marbles to be removed seemingly at randomly
- I want the information of the specific marbles to be retained
- We can remove the object from the array and place it into a seperate data type when we want to analyze it

4.) Testing
- The easiest way to test would be to set known values to the marbles instead of randomly to begin
- We could assign numbers 1-10 and red, blue, green alternating to the marbles with a for loop
- Testing to make sure adding the marble to the array we could just use one marble at first to verify
