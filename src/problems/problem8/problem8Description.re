let src = {|
# Problem 8 - Can you take me higher?

## Requirements
* pass a react component into another as a prop, render both

## Instructions

A more relaxing problem after that last one. This problem will teach you the syntax to pass React components as props. In the React library, we can pass constructors around willy-nilly, but not so in ReasonML. To pass a component as a prop in react we have to pass a function containing that component. This is a side effect of the way the JSX ppx operates.

```reason
/* no good */
let logProps = Component => {
  props => {
    Js.log(props);
    <Component />;
  };
};

/* correct way */
let logProps = componentFunction => {
  props => {
    Js.log(props);
    componentFunction(props);
  };
};

/* where componentFunction is defined at */
let componentFunction = (props) => <Component prop1=props.prop1 props2... />;
```

Using this example, write your own react component, and pass it in as props into the Problem8Inner component. Make sure to update the Problem8Inner component's proptypes to accept a prop of the correct type.
|};
