## EXERCISE 09

* Create a file **b**, so that:
```
%>cat -e a
STARWARS$
Episode IV, A NEW HOPE It is a period of civil war.$
$
Rebel spaceships, striking from a hidden base, have won their first victory against the evil
Galactic Empire.$
During the battle, Rebel spies managed to steal secret plans to the Empires ultimate weapon, the
DEATH STAR,$
an armored space station with enough power to destroy an entire planet.$
$
Pursued by the Empires sinister agents, Princess Leia races home aboard her starship, custodian of
the stolen plans that can save her people and restore freedom to the galaxy...$ $
%>diff a b > sw.diff
```

HINT: man patch

------------------------------------------
#### If we RTFM!(`man diff`) we will see that:
```
DESCRIPTION
		Compare FILES line by line.
```

> And since there is no argument required for `diff a b > sw.diff` we just
create a bile called `b` that is just different enough to file `a` so that the
command may work correctly.

------------------------------------------

