# 

#### Step by step

Start with code from _frameBufferDelay_  code example covered in lecture as we are going to be building the same structure. Make the following changes:

1. Inside the _ofApp.h_ file create the `numOfTiles` variable of type `int` (where we are going to store the number of tiles/frames on each direction.
2. In _main.cpp_ set the size of the window to 1280x720. You can later modify
   the size, as long as you keep the ratio so that the image that comes from the
   camera is not deformed.
3. In `setup()` function set the frame rate to 60 and initialize the
   `numOfTiles` to 10. Modify the `videoGrabber.initGrabber(...)` line and set
   the size you request from the camera to `(640, 480)`. This will define the
   size that we want the frame to be when it comes out of the camera. Since
   we're going to be using small size images there's no reason to ask for higher
   res. Modify the `maxBufferSize` line to be like this: 
   ``` maxBufferSize =
   numOfTiles * numOfTiles; ``` Since the `numOfTiles` is 10 it means that we'll
   fit 10x10 images on our screen, therefore `maxBufferSize` would be 100.
   
4. You don't need to do anything in the `update()` function, but sure you understand what is already included.
5. And now for the meaty part! Inside the `draw()` function create two variables of type `int` called `imgWidth` and `imgHeight`. We will need to store the width and height of the video tiles in those variables. For the width we can calculate that by doing a division: `ofGetWidth()/numOfTiles`. Do something similar to calculate the height. Still in the `draw()` create a variable of type `int` called `imgIndex` which is initialized to 0. Create a nested for loop (a loop within a loop) at the heart of which will be the `draw()` command (see [documentation](http://openframeworks.cc/documentation/graphics/ofImage.html#!show_draw)) on the first element (first image) of the deque we created. You'll need to use the `imgWidth` or `imgHeight` in your for loops as well as the `ofGetWidth()` or `ofGetHeight()` to achieve the grid shown below. If you run it now it will crash. The reason for that is that the camera is initialised a few seconds after openFrameworks runs which means that at the start the buffer won't have any data and you're asking it to draw the image at index 0. You can fix that by adding an if statement around your draw command checking that the buffer size is greater than 0 (ie that it has at least 1 value).
<br>
<br>
<img src="https://learn.gold.ac.uk/draftfile.php/1050235/user/draft/378380831/Screenshot%202021-11-21%20at%2012.31.46.png" alt="Hand grid" width="600" height="450" class="img-fluid atto_image_button_text-bottom">
<br>
<br>
   Notice that all the images are the same because we're always drawing the first frame. Right under the image draw command add this line:
   ```
   imgIndex++;
   ```
   This will update the index of the image that we want to draw. As we're looping on the x and y axis within the loop, this value is updated so that we can draw the next frame in the queue. Use this value as an index in the image draw operation. If you run the program now it will crash again. This is because it asks from the very beginning for all of the frames. We know that we have to wait a few seconds before the 4-5 seconds of video have filled the memory and can be displayed on a grid. Therefore, you'll need to modify your if-statement to do some sort of comparison between the size of the `imgBuffer` (which is of type `deque` - see [documentation](http://www.cplusplus.com/reference/deque/deque/)) and the `imgIndex`. You will see that we can get the size or the number of elements in our deque using the size functionality, so replace the previous check you were doing in your if statement with this: `imgBuffer.size()>imgIndex` 

   Once you have added this if-statement your program is ready to go!

----
### Random Buffer Grid
Modify the program above to mix-up the order of how the frames are displayed as shown in the video below:

<p dir="ltr" style="text-align: left;">&nbsp;<video controls="true">
        <source src="https://learn.gold.ac.uk/draftfile.php/1050235/user/draft/378380831/FrameBufferGridRandom.mp4">https://learn.gold.ac.uk/draftfile.php/1050235/user/draft/378380831/FrameBufferGridRandom.mp4
    </video>&nbsp;<br></p>

<br>

#### Step-by-step
Start a new project and copy the code you worked on for the _frameBufferGrid_. The code is 95% there already. All we'll need to do is add the random element. You can't just use `ofRandom()` inside the `imgBuffer[imgIndex].draw(x,y);` because this will just select random images from the queue at every iteration of the draw() loop of ofx. What we need is a look-up table where we will store the random values and use this table __every__ time we want to draw the grid. Therefore:

1. Create a vector of type `int` inside the _ofApp.h_ and call it `table`.
2. Inside the `setup()` function create a for loop to fill the `table` (using
`push_back()`) with random values. We are essentially going to mix up or
randomise the order of the index values that we will use to get an image out of
our deque, we will do this by filling our table vector with a collection of
random values between 0 and maxBufferSize. The values inside the `ofRandom()`
call should range from 0 to `maxBufferSize`. We'll use that table to store the
"new correspondence" between frame location and frame order. <br> <br> <a
href="http://doc.gold.ac.uk/~tpapa001/teaching-assets/week06/lookupTable.png"><img
src="http://doc.gold.ac.uk/~tpapa001/teaching-assets/week06/lookupTable.png"
style="width:33%; margin-left:33.5%;"></a> <br> <br> The red arrow is where our
`imgIndex` variable is pointing in our table vector, while the green arrow is
the lookup operation that uses the value stored in our table vector to return a
frame at that index in our deque.

3. Modify the following line in your draw() loop: 
```
  imgBuffer[imgIndex].draw(x,y, imgWidth, imgHeight); ``` So that is uses the
  random position in the lookup table we created (instead of just the imgIndex
  as we currently see in the line of code above). Can you figure it out?
  __Important:__ You'll also need to modify the if statement to make sure the
  buffer is full before starting to display images, you will need to do a check
  against `maxBufferSize`. This is because we can't have our program calling
  random frames in the buffer before we make sure that they actually exist!

----
#### Ideas for further development (optional)
* There is nothing that guarantees us that the random numbers generated for the table in the random grid exercise has unique values. We're using ofRandom() to get them, it's quite possible that a frame might appear twice in that list which means some tiles show the same image. A better way to do it would be to fill up the random table with sequential values (0, 1, 2, 3, 4....) using a for loop in the setup function and then use the [shuffle](https://www.techiedelight.com/shuffle-vector-cpp/) function to mix the order.
* How about using red, green, or blue to give each frame a different tint before
  displaying it? It should be one of these 3 or 3 of your choice. One way of
  doing it is randomly generate a number between 0-2 and depending of what that
  number is assign a color right before displaying the frame.
* How about using `drawSubsection` (seen on the next exercise) to draw random parts of each image on each frame. Perhaps one frame could show from pixel (0,0) to (20,20) (don't worry about stretching). Make sure each location always draw the same random assigned part of the image. You'll have to create some new vectors for all the random data that you'll be using.
* Can you think of any other extensions?



