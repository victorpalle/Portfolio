# NAVY

  The goal of this project is to code a terminal version of the very famous "Battleship game". The two players are ONLY allowed to comunicate using thesignals SIGUSER1 and SIGUSER2.The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions. At the end of the game (when all the ships of a player have been hit), you must display whether “I won” (and return 0) or “Enemy won” (and return 1).

***

To compile use : <br>

```python
make
```
<br>then :<br>

```python
./navy [pos1]
```
<br>and on an other terminal :<br>

```python
./navy [pos1] [player1_pid]
```


***

### Screenshot

<kbd>
<img
src="navy.png"
raw=true
alt="screenshoot"
width="700"
/>
</kbd>