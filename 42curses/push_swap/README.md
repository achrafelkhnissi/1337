
<h1 align="center">
	42cursus' push_swap
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' push_swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/42curses"><b>42cursus repo</b></a>.
</p>


<h3 align="center">
	<a href="#summary">Summary</a>
	<span> · </span>
	<a href="#resources">Resources</a>
	<span> · </span>
	<a href="#rules">Rules</a>
	<span> · </span>
	<a href="#operations">Operations</a>
</h3>

---

## SUMMARY
The project will make you sort data on a stack, with a limited set of instructions, using the lowest number of actions. To succeed you will have to manipulate various types of algorithms and choose the most appropriate solution for an optimized data sorting.

## RULES
- The game is composed of 2 stacks named __A__ and __B__.
- To start with:
	- A contains a random number of either positive or negative numbers without any duplicates.
	- B is empty.
- The goal is to sort in ascending order numbers into stack __A__.
- To do this, you have the following operations.

## OPERATIONS
* [`sa`](srcs/operations/sa_swap_a.c) - swap __a__: swap the first 2 elements at the top of stack __a__. (do nothing if there is only one or no elements).
* [`sb`](srcs/operations/sb_swap_b.c) - swap __b__: swap the first 2 elements at the top of stack __b__. (do nothing if there is only one or no elements).
* [`ss`](srcs/operations/ss_sa_sb.c) - ss: swap __a__ and swap __b__ at the same time.
* [`pa`](srcs/operations/pa_push_a.c) - push __a__: take the first element at the top of __b__ and put it at top of __a__. (do nothing if __b__ is empty).
* [`pb`](srcs/operations/pb_push_b.c) - push __b__: take the first element at the top of __a__ an dput it at top of __b__. (do nothing if __a__ is empty).
* [`ra`](srcs/operations/ra_rotate_a.c) - rotate __a__: shift up all elements of stack __a__ by 1. the first element becomes the last one.
* [`rb`](srcs/operations/rb_rotate_b.c) - rotate __b__: shift up all elements of stack __b__ by 1. the first element becomes the last one.
* [`rr`](srcs/operations/rr_ra_rb.c) - rr: rotate __a__ and rotate __b__ at the same time.
* [`rra`](srcs/operations/rra_reverse_rotate_a.c) - reverse rotate __a__: shift down all elements of stack __a__ by 1. the last element becomes the first one.
* [`rrb`](srcs/operations/rrb_reverse_rotate_b.c) - reverse rotate __b__: shift down all elements of stack __b__ by 1. the last element beoomes the first one.
* [`rrr`](srcs/operations/rrr_rra_rrb.c) - rrr: reverse rotate __a__ and reverse rotate __b__ at the same time.

## TESTING
- Change the `<number_of_random_args>` with any number u want!
```bash
make test ARG=<number_or_random_args>
```

## RESOURCES

- [medium - understanding push_swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [medium - Understanding Sorting Algorithms](https://medium.com/jl-codes/understanding-sorting-algorithms-af6222995c8)
- [youtube - push_swap](https://www.youtube.com/watch?v=7KW59UO55TQ)
- [push_swap visualizer](https://2g2uk.csb.app)
