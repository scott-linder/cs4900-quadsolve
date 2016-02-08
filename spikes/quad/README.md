quad
====

naive
-----

naive.c

Naive solver, based on http://bose.physics.ucdavis.edu/quadratic.pdf

Does not check or report on accuracy of results, or number of types of roots.

roots
-----

roots.c

Extends naive solver to identify different classes of roots, as
per https://en.wikipedia.org/wiki/Quadratic_equation#Discriminant

Does not verify accuracy of results wrt. rounding.
