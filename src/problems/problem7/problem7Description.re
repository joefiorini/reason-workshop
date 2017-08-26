let src = {|
# Problem 7 - Getting Functor-y

## Requirements

* Describe two new components inside the Problem7 file, Square and circle, using the Shape.Make functor
* Square should render a 50x50px square
* Circle should render a 50px radius Circle
* When clicking the relevant button in the ui, the correct shape should render

## Instructions

Up to now, we've treated modules as a convenient way to organise expressions around a common theme. We're going to delve a little deeper now and look into one of the things that makes Reason special. Functors.

A `Functor` is a module function, a map from one module to another. This is one of the more powerful techniques for abstraction and generic problem solving available to the language. Let's look at a motivating example, we want to be able to print various types to string right? Let's implement Show:

```reason
module Show = {
  module type S = {type t; let show: t => string;};
  module type Showable = {include S; let print: t => unit;};
  module Make (S: S) :(Showable with type t = S.t) => {
    include S;
    let print (value: t) :unit => Js.log @@ show value;
  };
};

let doSomethingWithShow
  (type t')
  ((module X):
  (module Show.Showable with type t =t')) y =>
    X.print y;

module ShowInt =
  Show.Make {
    type t = int;
    let show = string_of_int;
  };

module ShowFloat =
  Show.Make {
    type t = float;
    let show = string_of_float;
  };

doSomethingWithShow (module ShowInt) 1;

doSomethingWithShow (module ShowFloat) 1.0;
```

That looks suspiciously like a typeclass. A functor is as close as OCaml comes to offfering that level of abstraction. There's a lot going on here, so let's take it step by step. First, we define our Functor `Make`, by writing a module function that takes a module `S` and returns a module of type `Showable`. We defined S as have a `type t` and a function `show` from t to a string; We include this definition in our return type, adding in a helper method print that takes us from `t => unit`;

Inside Make, we write out the instance that satisfies the constraints. The return value from a Functor is always a new module.

```reason
module Show = {
  module type S = {type t; let show: t => string;};
  module type Showable = {include S; let print: t => unit;};
  module Make (S: S) :(Showable with type t = S.t) => {
    include S;
    let print (value: t) :unit => Js.log @@ show value;
  };
};
```

We then define a function `doSomethingWithString` that takes a module and a value, and applies the modules print function to the value. But something interesting is happening here. OCaml will not let us apply a module or a functor when the result of that would leak the type variable.

```reason
let doSomethingWithShow
  (type t')
  ((module X): (module Show.Showable with type t =t'))
  y =>
    X.print y;
```

Using this information, let's create a functor that generates a react component for a shape. We'll build a custom module Shape that has an inner functor (Make) by using the provided functor.contents

Follow the instructions in the problem file, and update the problem to display a square and a circle;
|};
