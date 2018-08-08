let src = {|
# Problem 1 - Making Things Appear

## Requirements
* Make the text "ReasonML" appear in the pane to the right

## Instructions

Welcome to the Reason workshop. This screen displays the workshop. As you complete a problem in the workshop, you can click the following link in the navigation on the left. This pane will give you the instructions on how to complete the problem. As you update the solution file, it will be rendered in the pane to the right.

If at any time you're stuck or unsure how something works, check if it's covered in the related koan section at the top of the description. If it isn't, check with your neighbours or ask one of the instructors for assistance :)

If you open the file `src/problems/problem1/problem1.re` in your editor, you'll come face to face with your first React component using reason bindings. We're going to see a lot of these as we build up this application, so I'll explain a little bit of what you're looking at.

```reason
/*
  create a component with a displayName "Problem1"
  requires the make function the "spreads" the component to implement:
    * let render = self => ReasonReact.reactElement;
  */
let component = ReasonReact.statelessComponent("Problem1");
let make = (_children) => {
  ...component,
  render: (_self) => {
    <div />
  }
}
```

We'll touch on modules, records and everything else as we go through this workshop. For now, let's begin by getting some text to render on the screen. Open the file: src/problem1/problem1.re and edit the file so that the render method returns some JSX that will print "ReasonML". Bear in mind that you can't embed a string inside reason's JSX, and must instead make a call to ReasonReact.string like below:

```reason
<div>
  (ReasonReact.string("a string to render"))
</div>
```
|};
