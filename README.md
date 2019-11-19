RuleEngine is a software supported by lex and yacc. It provides users with flexible functions to read and parse configuration files, and performs calculation and reasoning. And it provides support for many data types which includes double, string, and list of double etc. It also plans space for our missions to accomplish tasks more efficiently.

RuleEngine was originally developed by professor Chengliang, Wang working in Chongqing University and perfected through several generations of graduate students. This software has been put into use in our laboratory's sleep monitoring program and is general enough to be applicable in a more wide variety of domains.

RuleEngine provides stable C++ APIs.

RuleEngine will keep up-to-date by students in our laboratory.



## How to run

We have generated a shared library called `libRuleEngine.so` for this software, which is convenient for users to use flexibly.

To link your application with the shared library:

```bash
$ g++ -L/[your workspace] -o test main.cpp -lRuleEngine
```

we use `-L` option to the the GNU where to find our shared library and `-lRuleEngine` to find `libRuleEngine.so`

GNU assumes that all libraries start with lib and end with `.so` or `.a`

Here I use the program name `main.cpp` and the shared library name `libRuleEngine.so` as example.

And, Making your library available at runtime:

```bash
$ export LD_LIBRARY_PATH=[your workspace]:$LD_LIBRARY_PATH
```

Before we execute our program. We need to tell the compiler where our shared file is so our program can link with the library at the run time.

We use environment variable `LD_LIBRARY_PATH` to do this.

Then you can execute your application with our shared library.



## Recompile

If your shared library is missing, or you want to make changes to the RuleEngine, we have Makefile for you.

```bash
$ make clean
```

```bash
$ make
```

Done.

If you wan to add or delete files, you'd better to learn about `make`.



## Examples

Here we have several simple examples for you. And you can find them in the folder named `examples`.

