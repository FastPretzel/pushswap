# pushswap
This project is about making a program for sorting numbers and a checker to evaluate previous one.
## Rules
There are two stacks ```a``` and ```b```

The goal of the program is to sort in ascending order numbers into stack ```a```. To do so you have the
following operations at your disposal:

```sa``` (swap a): Swap the first 2 elements at the top of stack ```a```. Do nothing if there is only one or no elements.

```sb``` (swap b): Swap the first 2 elements at the top of stack ```b```. Do nothing if there is only one or no elements.

```ss``` : ```sa``` and ```sb``` at the same time.

```pa``` (push a): Take the first element at the top of ```b``` and put it at the top of ```a```.
Do nothing if b is empty.

```pb``` (push b): Take the first element at the top of ```a``` and put it at the top of ```b```.
Do nothing if a is empty.

```ra``` (rotate a): Shift up all elements of stack ```a``` by 1.
The first element becomes the last one.

```rb``` (rotate b): Shift up all elements of stack ```b``` by 1. The first element becomes the last one.

```rr``` : ```ra``` and ```rb``` at the same time.

```rra``` (reverse rotate a): Shift down all elements of stack ```a``` by 1.
The last element becomes the first one.

```rrb``` (reverse rotate b): Shift down all elements of stack ```b``` by 1. The last element becomes the first one.

```rrr``` : ```rra``` and ```rrb``` at the same time.

The program should print operations in right order to sort stack ```a```
## Usage
### push_swap
To compile the programm you should do ```make``` then ```./push_swap <numbers of stack a begins from top>```

For example:
```
$> ./push_swap 5 7 0 13 99
ra
ra
pb
ra
ra
pb
pa
pa
```

The arguments should be a digits. Else the program will print ```Error```
### checker
To compile the programm you should do ```make``` then ```./checker <numbers of stack a begins from top>```. The program will ask you to print an operations for sorting stack a.

If after executing these operations stack ```a``` will be sorted, checker will print ```OK```, else ```KO```
```
$> ./push_swap 5 7 0 13 99 | ./checker 5 7 0 13 99
OK
$> ./checker 5 7 0 13 99
> ra
> sa
KO
```
