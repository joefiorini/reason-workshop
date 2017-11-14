let src = {|
# Problem 2 - Making Things Stylish

## Requirements
* Render a 50x50 px square with a grey background

## Instructions

Great! In the last problem we learnt how to render a string inside a div. This time, we want to apply some style to the div to make it a square box with gray internals. To do this, we use the ReactDOMRe.Style.make function to create an inline style object. This function is really interesting, it uses one of the coolest features from OCaml, optional labeled arguments to functions.

Functions in OCaml have a fairly simple format:

```reason
let functionName = (arg1, arg2) => {
  /* function body */
};
```

Functions in OCaml are curried by default, so they can be applied as so:

```reason
let add = (x, y) => {
  x + y;
};

let add1 = add(1);
let three = add1(2);
```

A labeled function is defined and used like so:

```reason
let add = (~first:int, ~second:int) => {
  first + second;
};

let add1 = add(~first=1);
let three = add1(~second=2);
let otherThree = add1(~first=1, ~second=2);
/* with labeled args, the order doesn't matter at all */
let anotherThree = add1(~second=2, ~first=1);
```

Finally, if the labeled arguments are optional, and the last argument is not, then the labeled arguments don't need to be applied, and will default to whatever their provided default value is:

```reason
let add = (~first as first : int = 1, ~second as second : int = 2, ()) => {
  first + second;
};
let three = add();
```

Styles in reason's react bindings are defined in the same way as this last example. A number of css properties are defined as optional in node_modules/reason-react/reactDomRe.re in the Style module. You can apply the styles you need to by passing them as labeled args to the `ReactDOMRe.Style.make` function and passing () as the final arg to signify the function is finished being applied.

```reason
ReactDOMRe.Style.make(
  ~display="block",
  ()
);
```

Using this information, edit the style expression to create a 50x50px square with a black border. The properties you will want to use are `width`, `height` and `border`. If you aren't familiar with css or styling let me know and I'll let you know the correct arguments to those properties.
|};
