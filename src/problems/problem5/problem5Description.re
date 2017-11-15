let src = {|
# Problem 5 - Composing Components

## Requirements
* Define a React Component inside the problem5 file that renders a square with a black border that takes its width as a prop
* Use that component to make the Problem5 Component render two squares next to each other, one half the size of the other

## Instructions

It's time for a proper introduction to modules. These are the building blocks of the language and of the most interesting aspects of ReasonML/OCaml. Modules in ReasonML form the backbone of most of the the patterns for abstraction. In fact, every single file in your project is implicitly a module. This is referred to as `first class files`. Files are transformed at compile time into modules, where the name of the module is the name fo the file with a capitalised first letter. So the problem file for this problem `(problem5.re)` becomes the module Problem5. Modules are automatically available to any scope in a project, and become global to the project (barring some cleverness and complexity in the build system). This means that your filenames need to be unique within your program, and can't clash with any of your dependencies.contents

You'll have noticed by now that ReasonML files have the extension `.re`. There's another extenstion that signifies a type file, `.rei`. A `.rei` file is used to place constraints on the corresponding `.re` file, or to define reusable types across a project. For instance, a pair of files could be declared as follows:

```reason
/* inside file.rei */
type encoding = string;
type path = string;

let read : (path, encoding) => string;

/* inside file.re */

/* we need to redeclare types between .re and .rei files */
type encoding = string;
type path = string;

let read = (path, encoding) => {
  /* your implementation of File.read */
};
```

This pair defines a module File that has one expression export `read` and two type exports `encoding` and `path`. We can use this module in a file like so:

```reason
let contents = File.open("utf-8", "/home/user/file.txt");
```

Modules are used to collect related functions and types. For instance, a list module might look like:

```reason
/* list.re */
type t('a) =
  | Null
  | Cons('a, t('a));
let rec map = (f: 'a => 'b, list: t('a)) : t('b) =>
  switch list {
  | Null => Null
  | Cons(a, rest) => Cons(f(a), map(f, rest))
  };
```

This way, we can co-locate the List type `t` next to the functions that use it, making it easier to consume and to refactor. This is a common pattern in ReasonML and is considered idiomatic.

For this Problem, we're going to create two new files inside the problem5 folder. We want to have a module called Problem5Square that contains a react component that renders a 50x50 px square (are you noticing a pattern :P). To do this, you can reuse the code from [problem 1](/problems/1) and [problem 2](/problems/2) by copying and pasting it into the new file.
|};
