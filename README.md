This is a project that has been created by Josua Kaden, Moritz Zitzow, and Matteo D'Urso for the intersession C-programming course.

You can build the project by executing 
```
make a_sanitize
```
in the ```cproject/src``` directory.

To execute the pathfinding algorithm execute:
```
./main ../testdata/<name of canvas>.txt
```

You can use predefined maps in the testdata directory, we tried to implement a little bit of every edge case that we could think of.
Otherwise feel free to define your own canvas.
You have to follow these simple rules.
You have the following symbols at you disposal:
<li>
  '#' are walls.
  'E' is the End.
  'S' is the Start.
  ' ' are unvisited pixels.
</li>

<li>
  the canvas has to be surrounded by a border of exclusively walls '#'.
  Make sure that there is exactly one start point and end point on the canvas.
  every row has to have the same width.
  After every row there has to be a newline.
  At the end of the file there have to be two trailing newlines.
</li>
