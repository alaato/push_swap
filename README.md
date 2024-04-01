# 42 Push_Swap

Given a set of integers, sort it using a predefined set of instructions using
two stacks.

* You have 2 stacks named a and b.
* At the beginning:
  - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack b is empty.
* The goal is to sort in ascending order numbers into stack a

## Instruction set

the instructions allowed are the following :

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |
## Example :

![image](https://github.com/alaato/push_swap/assets/68467723/457b84e6-63b5-4e2f-9c85-811905c25c62)
![image](https://github.com/alaato/push_swap/assets/68467723/10d9a565-c27c-4dd8-b33b-9c19d31d9292)
![image](https://github.com/alaato/push_swap/assets/68467723/bebbc975-f479-4a1d-8591-765ce1d79780)
![image](https://github.com/alaato/push_swap/assets/68467723/e9717137-1c60-4f58-9983-7deb20d6d598)
![image](https://github.com/alaato/push_swap/assets/68467723/7216bc98-8c9e-4602-84d2-ad22c25d3112)




