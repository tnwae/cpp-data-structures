cpp-data-structures
===================

Simple demos of data structures in C++.

This repo is designed to demonstrate basic data structures in a way amenable to the learning needs of young programmers, but without skipping the advanced features they'll need to be productive C++ programmers

To that end, I don't shy away from using templates (probably the most advanced C++ feature) or function pointers to show how things can be done, and both the libraries and testing programs use pointers extensively.

If you are an instructor and wish to use this code or modify it for your course, please go ahead and do so by forking this repo or submitting a pull request.  This code is licensed under the MIT License, so you can basically do as you please with it with the caveat that you should attribute me as its originator.

Motivation
----------

I started blogging about data structures both as a way to give back to the community and to recapitulate the basics for myself.  The relevant blog posts follow:

* ["Linked Lists"](http://rt38.org/2013/08/linked-lists)
* ["Stacks & Queues"](http://rt38.org/2013/08/stacks-and-queues)
* ["Playing with lambdas in C++"](http://rt38.org/2013/08/playing-with-lambdas-in-cpp)

Contents
--------

* `blist`: circular doubly linked lists.
* `bstack`: stacks implemented on top of `blist`
* `bqueue`: queues implemented on top of `blist`

Tested and working...
---------------------

The following is a list of compilers I've tested with:

* Microsoft Visual C++ compiler (Visual Studio 2010)
* GNU C++ compiler (Ubuntu/Linaro 4.7.2, compiled with `-std=c++11`
