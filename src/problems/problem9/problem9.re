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
type action = ChangeColor;

let component = ReasonReact.reducerComponent("Problem9");

let make = (_children) => {
  ...component,
  initialState: () => {color: "black"},
  reducer: (action, _state) => {
    switch (action) {
    | ChangeColor => ReasonReact.NoUpdate
    }
  },
  render: ({state, send}) =>
    <div>
      <Problem9Text
        color=state.color
        onClick=(send(ChangeColor))
      />
    </div>
};
