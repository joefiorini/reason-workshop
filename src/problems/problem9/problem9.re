module Problem9Text = {
  let component = ReasonReact.statelessComponent("Problem9Text");
  let make = (~onClick, ~color, _children) => {
    ...component,
    render: (_self) => {
      let style =
        ReactDOMRe.Style.make
          /* place the appropriate styles here */
          ();
      <div style />
    }
  };
};

type state = {color: string};

let component = ReasonReact.statefulComponent("Problem9");

let make = (_children) => {
  ...component,
  initialState: () => {color: "black"},
  render: ({state, update}) =>
    <div>
      <Problem9Text
        color=state.color
        onClick=(update((_event, {state}) => ReasonReact.Update(state)))
      />
    </div>
};
