let normalStyle = ReactDOMRe.Style.make();

let clickedStyle = ReactDOMRe.Style.make();

let hoveredStyle = ReactDOMRe.Style.make();

let boxStyle = ReactDOMRe.Style.make(~width="50px", ~height="50px", ~border="1px black solid", ());

type state = {
  hovered: bool,
  clicked: bool
};

let handleClick = (_event, {ReasonReact.state}) =>
  /* change this function to return the existing state
     with the clicked prop set to true. you can use the object spread operator
     { ...state, foo: bar } */
  ReasonReact.Update(state);

let handleHover = (_event, {ReasonReact.state}) =>
  /* change this function to return the existing state
     with the hovered prop set to true. you can use the object spread operator
     { ...state, foo: bar } */
  ReasonReact.Update(state);

let switchStyle = (state) =>
  switch (state.clicked, state.hovered) {
  /* add the cases so that:
     clicked: true hovered: false => clicked style
     clicked: true hovered: true => hovered style
     clicked: false hovered: true => hovered style
     clicked: false hovered: false => empty style */
  | _ => normalStyle
  };

let component = ReasonReact.statefulComponent("Problem4");

let make = (_children) => {
  ...component,
  initialState: () => {hovered: false, clicked: false},
  render: ({state, update}) => {
    let style = switchStyle(state);
    <div
      style=(ReactDOMRe.Style.combine(boxStyle, style))
      onClick=(update(handleClick))
      onMouseEnter=(update(handleHover))
      onMouseLeave=(update(handleHover))
    />
  }
};
