let component = ReasonReact.statelessComponent("Problem1");

let make = _children => {
  ...component,
  render: _self =>
    <div
      /* reason ships with JSX support, similar to React's */
      /* use the ReasonReact.string function here to make this component render "ReasonML"  */
    />,
};
