let normalStyle = ReactDOMRe.Style.make();

let clickedStyle = ReactDOMRe.Style.make();

let hoveredStyle = ReactDOMRe.Style.make();

let boxStyle =
  ReactDOMRe.Style.make(
    ~width="50px",
    ~height="50px",
    ~border="1px black solid",
    (),
  );

type state = {
  hovered: bool,
  clicked: bool,
};

let switchStyle = state =>
  switch (state.clicked, state.hovered) {
  /* add the cases so that:
     clicked: true hovered: false => clicked style
     clicked: true hovered: true => hovered style
     clicked: false hovered: true => hovered style
     clicked: false hovered: false => empty style */
  | _ => normalStyle
  };

type action =
  | Clicked
  | Hovered;

let component = ReasonReact.reducerComponent("Problem4");

let make = _children => {
  ...component,
  initialState: () => {hovered: false, clicked: false},
  reducer: (action, _state) =>
    switch (action) {
    /* change this branch to return the existing state
       with the clicked prop set to true. you can use the object spread operator
       { ...state, foo: bar } */
    | Clicked => ReasonReact.NoUpdate
    /* change this branch to return the existing state
       with the hovered prop set to true. you can use the object spread operator
       { ...state, foo: bar } */
    | Hovered => ReasonReact.NoUpdate
    },
  render: ({state, send}) => {
    let style = switchStyle(state);
    <div
      style=(ReactDOMRe.Style.combine(boxStyle, style))
      onClick=(_ => send(Clicked))
      onMouseEnter=(_ => send(Hovered))
      onMouseLeave=(_ => send(Hovered))
    />;
  },
};
