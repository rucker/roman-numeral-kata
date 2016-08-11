# roman-numeral-kata

This kata allows for the addition and subtraction of Roman numerals. I chose to do this by converting each numeral to its integer value, doing the math, and then converting back.

In instances where an invalid numeral is input, or the numeral math results in a number that can't be represented in the Roman system (i.e. a number less than 1 or greater than 3999), the value [nullus](https://en.wiktionary.org/wiki/nullus#Etymology) will be returned.

## Tech stack:  
Ubuntu 14.04 (Dockerfile [here](https://github.com/rucker/docker-ubuntu/blob/master/Dockerfile))  
git  
gcc  
[check](https://libcheck.github.io)

