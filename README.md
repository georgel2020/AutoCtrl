# AutoCtrl
__Simple tool to simulate mouse and keyboard operation.__ 
## Usage
Type commands in the `AutoCtrl.txt` file. 
Each command has a full one and a shorter one. 
### Enter debug mode
Debug mode can show the cursor position on the window. 
```
debug
d
```
### Show console Window
Console window is hidden by default. 
```
window
w
```
### Mouse
#### Set mouse position
```
mouse [x] [y]
m [x] [y]
```
#### Move mouse
```
mousemove [x] [y]
mm [x] [y]
```
#### Mouse left button click
```
mouseleft [x] [y]
ml [x] [y]
```
#### Mouse left button double click
```
mouseleftdouble [x] [y]
mldb [x] [y]
```
#### Mouse left button down
```
mouseleftdown [x] [y]
mld [x] [y]
```
#### Mouse left button up
```
mouseleftup [x] [y]
mlu [x] [y]
```
#### Mouse right button click
```
mouseright [x] [y]
mr [x] [y]
```
#### Mouse right button down
```
mouserightdown [x] [y]
mrd [x] [y]
```
#### Mouse right button up
```
mouserightup [x] [y]
mru [x] [y]
```
### Keyboard
Keycode: see [Virtual key codes](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes). 
#### Key press
```
key [keycode]
k [keycode]
```
#### Key down
```
keydown [keycode]
kd [keycode]
```
#### Key up
```
keyup [keycode]
ku [keycode]
```
### System command
```
command [command]
c [command]
```
### Sleep
Time (ms). 
```
sleep [time]
s [time]
```
### Exit
```
exit
e
```
