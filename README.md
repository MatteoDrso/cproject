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
<ul>
  <li> '#' are walls. </li>
  <li> 'E' is the End. </li>
  <li> 'S' is the Start. </li>
  <li> ' ' are unvisited pixels. </li>
</ul>

<ul>
  <li> The canvas has to be surrounded by a border of exclusively walls '#'. </li>
  <li> Make sure that there is exactly one start point and end point on the canvas. </li>
  <li> every row has to have the same width. </li>
  <li> After every row there has to be a newline. </li>
  <li> At the end of the file there have to be two trailing newlines. </li>
</ul>
