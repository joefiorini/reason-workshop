let src = {|
# Problem 3 - Handling Events

## Requirements
* render a 50x50 px square with a black border
* when the square is clicked, the program should log "clicked" to the JavaScript console
* when the square is hovered, the program should log "hovered" to the JavaScript console

## Instructions

In this problem we begin to _react_ to external stimuli. Namely, we handle three events, onClick, onMouseEnter and onMouseLeave. These are standard DOM events that get fired when the relevant action occurs in the browser. The browser will attach our functions to the elements that are rendered, and call them when an action occurs.

For reference, the logging function to use is `Js.log : 'a => unit`.

We use the builtin method `handle` to construct the event handlers. `handle` has a signature that boils down to

```reason
(
  (
    'a,
    ReasonReact.self(...)
  ) =>
  unit
) =>
ReasonReact.Callback.t('a)
```

You should read this as: "handle takes a function of two variables (of types 'a and ReasonReact.self(...)) that returns unit, and returns a ReasonReact.Callback.t('a)".

Event handlers (the function that handle takes) take two arguments.

### 'a - the event

a polymorphic type that contains the data of the event that took place, which is a synthetic event drawn from `ReactEventRe`.

Events in React are synthetic wrappers around the native browser event.

You can extract the type you need by calling `ReactEventRe.<EventType>._type` and passing in the event. `type` is a reserved word in reason, so we prefix it with an underscore and the compiler magically transforms this into `type` in the actual call.

### ReasonReact.self(...) - the self object

the `self` object, containing the update and handle functions, to be used to delegate the update behaviour other handlers by passing these functions, see <https://reasonml.github.io/reason-react/#reason-react-component-creation-self>

## Extracting the event type

```reason
ReactEventRe.Mouse._type(event)
```

This is an idiomatic pattern in reason, where a module will define a type, and then define the operations that extract and change the data bound by that type. When you need to affect a type, it's a safe bet that the function you're looking for is stored in the module that the type is defined in.

By combining the handle function and the new Js.log function, write a clickHandler that logs every time it's clicked. Also, write a hoverHandler than can differentiate between when a hover begins and ends, and logs different messages in each case.
|};
