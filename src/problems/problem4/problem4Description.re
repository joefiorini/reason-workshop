let src = {j|
# Problem 4 - In a Dangerous State

## Requirements
* A 50x50 px square rendered on the screen
* when the square is clicked, the background is permenantly green
* when the square is hovered, the background is blue

## Instructions
Building off the work done last 3, this problem wraps up what you've learnt so far. In this problem we introduce the concept of state. State in this system is essentially used as a sentinel for an internal data change that should force a re-render. The canonical example is a button that increments a counter. On each press of the button, the counter should inrement, causing the counter to re-render.

In reason's react bindings, state is defined as a record type available to the make function of a component. The shape of the make function is similar to what we saw in [problem1](/problems/1) with the addition of two new properties: state and initialState.

```reason
type state = { count: int, startingCount: int };
/*
  creates a stateful component with a displyName "Counter".
  requires the make function that spreads the component to define:
    * let initialState = () => state;
    * let render = (componentBag) => ReasonReact.reactElement;
*/
let component = ReasonReact.statefulComponent("Counter");

/*
  define a function make that takes one prop, startingCount which has a default value of 0.
  also takes children, which we prepend with an underscore, so it is treated as an ignored var.
*/
let make = (~startingCount=0, _children) => {
  let handleClick = (_event, self) => {
    let state = self.ReasonReact.state;
    ReasonReact.Update({...state, count: state.count + 1})
  };
  {
    ...component,
    initialState: () => { count: 0, startingCount },
    render: ({state, update}) => {
      <div onClick=(update(handleClick))>
        (ReasonReact.string({| Started on \$(state.startingCount). |}))
        (ReasonReact.string("Click Me"))
        (ReasonReact.string({| Clicked \$(state.count) times! |}))
      </div>
    }
  }
}

/*
  now, we can conditionally render as a result of state,
  and bind state mutating functions using updater
*/
```

This opens up some new abilities to us. We can now store the state of the component close in code to where it's used. It's important to note that from the perspective of the component, even though we've termed it "stateful", no variables are mutated. The component itself treats state as an implementation detail left up to the React library.

Using the snippet above as a guide, edit the Problem code to return state objects that toggle the clicked state, and toggle the hovered state based on the onMouseEnter and onMouseLeave events. Also edit the switchStyle function so that it returns the correct styles according to the comment inside that function.
|j};
