# AutostopMeter
AutoStopMeter is a script for measuring and tracking autostop, helping optimize performance and timing accuracy.

## Usage
First, you need to modify the content of `queue.cfg`.

Here is its structure:

```
clear
sleep 1000
echoln [begin];echoln " ";echoln " "
sleep 500
slot3

//START

//Your Test

//END

echoln [exit]
toggleconsole
```
You need to insert your Autostop test block in the `//Your Test` section.

> ### Test Code Block
> The test code block follows a fixed structure:
> 
> ```
> initpos
> sleep 200
> echoln [TestStart]
> echoln [NAME]
> alias $cmd "+forward";runcmd
> sleep 1000
> alias $cmd "echoln [begin];-forward;echopos";runcmd
> sleep 1000
> alias $cmd "echoln [end];echopos";runcmd
> echoln [TestCompleted];echoln " ";echoln " ";
> ```
> 
> - The `[NAME]` on the fourth line is the name of this block of code, for example `[my-autostop-script]`. Data with the same name will be merged during the later data analysis.
> - The `+forward` on the fifth line and `-forward` on the sixth line should be replaced with your corresponding commands, for example, `+myautostop_forward` and `-myautostop_forward`.

You can repeat the same code block multiple times to reduce data error. The more repetitions, the smaller the error.
You can also insert different named blocks.

Now, launch the game, open the console, and go to `de_nuke`. In the console, type `exec AutostopMeter/main`, and the console will automatically close and start the test. Please wait for the game to open the console again, then copy the console output.

> If the console shows nothing, try `echo 1`.
> Don't worry about extra console output, the data analysis software should be able to handle them correctly.

Next, go to the `data` folder, create a `dat.txt` file, and paste the console output you just copied. It should look something like this:

```
[begin]
 
[TestStart]
[desubtick-joy-0.0001]
[begin]
[coord1]
1221.946655
[coord2]
-1243.617065
[end]
[coord1]
1221.948364
[coord2]
-1254.566772
[TestCompleted]
 
[TestStart]
[desubtick-joy-0.0001]
[begin]
[coord1]
1221.946777
[coord2]
-1244.471558
[end]
[coord1]
1221.948364
[coord2]
-1254.566772
[TestCompleted]
 
[exit]
```

Double-click `data/run.bat` to view the results in `data/res.txt`!

You should see an analysis result like this (this is the analysis result of my Autostop script Horizon, please ignore the Chinese text):

```
Format Confirmed
[desubtick-Horizon-0.0001] [12 times]:
  [Average Glide Distance (smaller is better)]:  9.745066
  [Maximum Glide Distance]:  11.514282
  [Minimum Glide Distance]:  7.983764
  [Range (Max - Min)]:  3.530518
  [Variance]:  1.670534
  [Standard Deviation]:  1.292491
```

## Customization

Please refer to `data/analyze.cpp`, which requires basic C++ knowledge :)